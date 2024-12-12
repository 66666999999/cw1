#include "seekFrame.h"
SeekFrame::SeekFrame(QString fileName, int maxFindTimes, double minDistance)
{
    std::string fileName_str = fileName.toStdString();
    const char* fileName_const = fileName_str.c_str();
    init(fileName_const);
    this->maxFindTimes = maxFindTimes;
    this->minDistance = minDistance;
}

/**
 * @brief 初始化SeekFrame类
 * @param fileName    视频文件路径
 */
void SeekFrame::init(const char* fileName) {
    formatContext = avformat_alloc_context();
    AVCodec* codec = NULL;  // 视频流的decoder
    AVCodecParameters* codecParameters = NULL;
    videoStreamIndex = -1; // 视频流index

    // 读入文件header
    avformat_open_input(&formatContext, fileName, NULL, NULL);
    //获取视频流信息
    avformat_find_stream_info(formatContext, NULL);
    std::cout << "Format: " << formatContext->iformat->name
        << "duration" << formatContext->duration
        << "bitrate" << formatContext->bit_rate;
    // 寻找视频流index, 以及视频流的decoder
    for (int i = 0; i < (int)formatContext->nb_streams; i++)
    {
        AVCodecParameters* localCodecParameters = NULL;
        localCodecParameters = formatContext->streams[i]->codecpar;

        AVCodec* localCodec = NULL;
        localCodec = avcodec_find_decoder(localCodecParameters->codec_id);
        if (localCodec == NULL)
        {
            printf("Error: Unsupported codec");
            continue;
        }
        if (localCodecParameters->codec_type == AVMEDIA_TYPE_VIDEO)
        {
            if (videoStreamIndex == -1)
            {
                videoStreamIndex = i; // 找到了视频流的index
                codec = localCodec; // 找到了视频流的decoder
                codecParameters = localCodecParameters;
                // 记录视频的高和宽
                video_width = localCodecParameters->width;
                video_height = localCodecParameters->height;
            }
        }
    }
    //利用已有decoder的信息;来分配一个AVCodecContext
    codecContext = avcodec_alloc_context3(codec);
    if (!codecContext) { std::cout << "Failed to allocate memory for AVCodecContext"; return ;}
    int type = mediaType(fileName);
    if(type==1){ //如果是音频, 下面的不用做了
        return;
    }
    if (avcodec_parameters_to_context(codecContext, codecParameters) < 0)
    {
        std::cout << "Failed to copy codec paramters to codec context";
        return ;
    }
    // 初始化刚刚分配完空间的AVCodecContext, 仍然是用pCodec来初始化
    if (avcodec_open2(codecContext, codec, NULL) < 0)
    {
        std::cout<< "failed to open codec throught avcodec_open2";
    }


    // 图片格式转换器(转换成RGB)
    sws_ctx = sws_getContext
    (
        codecContext->width,
        codecContext->height,
        codecContext->pix_fmt,
        codecContext->width,
        codecContext->height,
        AV_PIX_FMT_RGB24,
        SWS_BILINEAR,
        NULL,
        NULL,
        NULL
    );
    // 初始化avd
    avd = av_q2d(formatContext->streams[videoStreamIndex]->time_base);



}

