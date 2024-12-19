#include "seekFrame.h"

// Constructor for SeekFrame class
SeekFrame::SeekFrame(QString fileName, int maxFindTimes, double minDistance) {
    // Convert QString fileName to a standard C++ string, then to a C-style string
    std::string fileName_str = fileName.toStdString();
    const char* fileName_const = fileName_str.c_str();

    // Initialize the SeekFrame object with the video file path
    init(fileName_const);

    // Set parameters for maximum search attempts and minimum frame distance
    this->maxFindTimes = maxFindTimes;
    this->minDistance = minDistance;
}

/**
 * @brief Initialize the SeekFrame class
 * @param fileName   Path to the video file
 */
void SeekFrame::init(const char* fileName) {
    formatContext = avformat_alloc_context();  // Allocate AVFormatContext for the video
    AVCodec* codec = NULL;  // Decoder for the video stream
    AVCodecParameters* codecParameters = NULL;  // Codec parameters
    videoStreamIndex = -1;  // Index for the video stream

    // Read the video file header and populate formatContext
    avformat_open_input(&formatContext, fileName, NULL, NULL);

    // Retrieve stream information from the input file
    avformat_find_stream_info(formatContext, NULL);

    std::cout << "Format: " << formatContext->iformat->name
              << " duration: " << formatContext->duration
              << " bitrate: " << formatContext->bit_rate;

    // Iterate through all the streams to find the video stream
    for (int i = 0; i < (int)formatContext->nb_streams; i++) {
        AVCodecParameters* localCodecParameters = NULL;
        localCodecParameters = formatContext->streams[i]->codecpar;  // Get stream codec parameters

        AVCodec* localCodec = NULL;
        localCodec = avcodec_find_decoder(localCodecParameters->codec_id);  // Find the decoder for the stream
        if (localCodec == NULL) {
            printf("Error: Unsupported codec\n");  // Unsupported codec
            continue;
        }

        if (localCodecParameters->codec_type == AVMEDIA_TYPE_VIDEO) {  // Check if the stream is a video stream
            if (videoStreamIndex == -1) {  // Set video stream index and decoder parameters
                videoStreamIndex = i;  // Store the video stream index
                codec = localCodec;  // Store the decoder for the video stream
                codecParameters = localCodecParameters;  // Store codec parameters

                // Record video width and height
                video_width = localCodecParameters->width;
                video_height = localCodecParameters->height;
            }
        }
    }

    // Allocate AVCodecContext using the video stream's decoder
    codecContext = avcodec_alloc_context3(codec);
    if (!codecContext) {
        std::cout << "Failed to allocate memory for AVCodecContext\n";
        return;
    }

    // Check if the file is an audio file
    int type = mediaType(fileName);
    if (type == 1) {  // If the file is audio, exit initialization
        return;
    }

    // Copy codec parameters to the codec context
    if (avcodec_parameters_to_context(codecContext, codecParameters) < 0) {
        std::cout << "Failed to copy codec parameters to codec context\n";
        return;
    }

    // Open the codec using avcodec_open2
    if (avcodec_open2(codecContext, codec, NULL) < 0) {
        std::cout << "Failed to open codec through avcodec_open2\n";
    }

    // Initialize the software scaling context to convert pixel format to RGB24
    sws_ctx = sws_getContext(
        codecContext->width,      // Source video width
        codecContext->height,     // Source video height
        codecContext->pix_fmt,    // Source pixel format
        codecContext->width,      // Destination width
        codecContext->height,     // Destination height
        AV_PIX_FMT_RGB24,         // Destination pixel format
        SWS_BILINEAR,             // Scaling algorithm (bilinear)
        NULL, NULL, NULL          // No additional parameters
    );

    // Initialize the average duration (time base) of the video stream
    avd = av_q2d(formatContext->streams[videoStreamIndex]->time_base);
}
