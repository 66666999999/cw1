#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QVector>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <thread>
#include <ctime>
#include <mutex>
#include <condition_variable>
#include <QLabel>
#include <QFileInfo>

// Include FFmpeg libraries for multimedia processing
extern "C" {
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "libavutil/imgutils.h"
};

using namespace std;

// -----------------------------
// Structure Definitions
// -----------------------------

/**
 * @brief Structure to hold a single frame of video data.
 * 
 * IMAGE_FRAME includes the image frame, associated video clock,
 * presentation timestamp (PTS), and the frame rate.
 */
struct IMAGE_FRAME {
    QImage image;            // The image data of the frame
    double video_clock;      // Video clock for synchronization
    int64_t pts;             // Presentation timestamp of the frame
    AVRational frameRate;    // Frame rate of the video stream
};

// -----------------------------
// Global Variables
// -----------------------------

/**
 * @brief Supported audio file extensions.
 */
static QVector<QString> audioType = {"mp3", "wav"};

/**
 * @brief Supported video file extensions.
 */
static QVector<QString> videoType = {"mp4", "wmv", "mkv", "avi"};

// -----------------------------
// Class Definition: Controller
// -----------------------------

/**
 * @brief Controller class for managing video playback states, queues, and synchronization.
 * 
 * The Controller class is responsible for managing a queue of IMAGE_FRAME objects,
 * handling synchronization with mutexes and condition variables, and managing
 * seek and quit states during video playback.
 */
class Controller {
public:
    std::queue<vector<IMAGE_FRAME>> Q;  // Queue for storing reversed video frames
    mutex mutex_;                       // Mutex for condition variable protection
    bool isDecoderSeek = false;         // Flag: Is decoder seeking
    bool isDisplayerSeek = false;       // Flag: Is display seeking
    bool isQuit = false;                // Flag: Quit status
    qint64 seekPos;                     // Position to seek in the video

    mutex seekMutex;    // Mutex to protect seek-related flags and position
    mutex Q_mutex;      // Mutex to protect the frame queue
    mutex quitMutex;    // Mutex to protect the quit flag

    condition_variable cvfull;   // Condition variable for full state
    condition_variable cvempt;   // Condition variable for empty state

    /**
     * @brief Clear the frame queue and reset the Controller state.
     */
    void clear();

    /**
     * @brief Initialize the Controller's components and state variables.
     */
    void init();

    /**
     * @brief Print the current values of shared data and flags (for debugging).
     */
    void print();
};

// -----------------------------
// Function Prototypes
// -----------------------------

/**
 * @brief Check if the file is a valid video file based on its extension.
 * @param filename Path to the file.
 * @return true if the file has a supported video/audio format, otherwise false.
 */
bool isValidVideoFile(QString filename);

/**
 * @brief Extract the file name (with extension) from a full file path.
 * @param Qpath Full path to the file.
 * @return The file name with extension.
 */
QString getFileName(QString Qpath);

/**
 * @brief Read a playlist from a local .dat file.
 * @param defaultPath Path to the .dat file (default is "./playList.dat").
 * @return A pointer to a QVector<QString> containing the playlist.
 */
QVector<QString>* readPlayList(QString defaultPath = "./playList.dat");

/**
 * @brief Write a playlist to a local .dat file.
 * @param playList A QVector<QString> containing the playlist.
 * @param defaultPath Path to save the playlist (default is "./playList.dat").
 * @return true if the playlist is written successfully, otherwise false.
 */
bool writePlayList(QVector<QString> playList, QString defaultPath = "./playList.dat");

/**
 * @brief Extract the attached album cover from an MP3 file.
 * @param fn Path to the MP3 file.
 * @return A QImage containing the album cover.
 */
QImage getAttachedPic(QString fn);

/**
 * @brief Retrieve detailed information about a video/audio file.
 * @param fileName Path to the file.
 * @return A QString containing the file's metadata and properties.
 */
QString getVideoInfo(QString);

/**
 * @brief Get the file extension (suffix) of a file.
 * @param fileName Path to the file.
 * @return The file extension as a QString.
 */
QString getSuffix(QString fileName);

/**
 * @brief Check if a file exists.
 * @param fullFileName Path to the file.
 * @return true if the file exists, otherwise false.
 */
bool isFileExist(QString fullFileName);

/**
 * @brief Determine the type of media file.
 * @param fileName Path to the file.
 * @return 1 if the file is an audio file, 2 if it is a video file, 0 if it is invalid.
 */
int mediaType(QString fileName);

#endif // UTILS_H
