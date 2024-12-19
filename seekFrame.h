#ifndef SEEKFRAME_H
#define SEEKFRAME_H

#include <iostream>
#include <QImage>
#include "utils.h"

// Include FFmpeg libraries for media handling
extern "C" {
#include <libavcodec/avcodec.h>
#include <libavutil/avutil.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavutil/imgutils.h>
}

/**
 * @brief The SeekFrame class is responsible for locating and extracting specific frames 
 *        from a video stream based on a target timestamp.
 * 
 * This class utilizes FFmpeg APIs to perform frame seeking. It finds the nearest 
 * keyframe before the target time and iterates through subsequent frames until the 
 * frame closest to the desired timestamp (within a defined margin) is located.
 * 
 * The accuracy of the extracted frame can be controlled using `minDistance`. 
 * A smaller `minDistance` increases accuracy but may reduce performance.
 */
class SeekFrame {
public:
    int maxFindTimes;      // Maximum number of frames to search for a target frame
    double minDistance;    // Margin of error (in seconds) between the desired and actual frame time
    double avd;            // Time base of the video stream converted to double
    int videoStreamIndex;  // Index of the video stream in the media file
    int video_width = 0;   // Width of the video frame
    int video_height = 0;  // Height of the video frame

    AVFormatContext* formatContext = NULL;  // FFmpeg format context for handling media file
    AVCodecContext* codecContext = NULL;    // FFmpeg codec context for decoding video stream
    struct SwsContext* sws_ctx = NULL;      // Swscale context for converting pixel formats

    /**
     * @brief Constructor for SeekFrame
     * @param filename      Path to the video file
     * @param maxFindTimes  Maximum number of frames to search
     * @param minDistance   Allowed margin of error for locating the desired frame
     */
    SeekFrame(QString filename, int maxFindTimes, double minDistance);

    /**
     * @brief Default constructor
     */
    SeekFrame() {}

    /**
     * @brief Initialize FFmpeg contexts, codec, and pixel format converter.
     * @param filename Path to the video file
     */
    void init(const char* filename);

    /**
     * @brief Save an RGB frame to the disk (used for debugging purposes).
     * 
     * This static function writes the contents of an RGB buffer to a file in PPM format.
     * 
     * @param buf       Pointer to the RGB buffer
     * @param wrap      Line size (stride) of the buffer
     * @param xsize     Width of the frame
     * @param ysize     Height of the frame
     * @param filename  Path to save the output file
     */
    static void save_rgb_frame(unsigned char* buf, int wrap, int xsize, int ysize, const char* filename) {
        FILE* f;
        int i;

        // Open the output file
        f = fopen(filename, "wb");

        // Write PPM file header
        fprintf(f, "P6\n%d %d\n255\n", xsize, ysize);

        // Write pixel data: 3 bytes per pixel (RGB)
        for (i = 0; i < ysize; i++) {
            unsigned char* ch = (buf + i * wrap);
            fwrite(ch, 1, xsize * 3, f);
        }

        // Close the output file
        fclose(f);
    }
};

#endif // SEEKFRAME_H
