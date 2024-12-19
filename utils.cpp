#include "utils.h"
#include <QString>
#include <QFile>
#include <QDataStream>
#include <QDebug>

// Clear the queue used in Controller
void Controller::clear() {
    while (!Q.empty()) Q.pop();  // Remove all elements from the queue
}

// Initialize the Controller object
void Controller::init() {
    clear();  // Clear the queue
    isDecoderSeek = false;  // Reset decoder seek flag
    isDisplayerSeek = false;  // Reset display seek flag
    isQuit = false;  // Reset quit flag
}

// Print the current status of the Controller
void Controller::print() {
    qDebug() << "----------------";
    qDebug() << "isDecoderSeek" << isDecoderSeek;
    qDebug() << "isDisplayerSeek" << isDisplayerSeek;
    qDebug() << "isQuit" << isQuit;
    qDebug() << "Q.size" << Q.size();
    qDebug() << "----------------";
}

/**
 * @brief Check if a file is a valid video file
 * @param filename  Path to the file
 * @return true if the file has a valid video/audio format, otherwise false
 */
bool isValidVideoFile(QString filename) {
    filename = filename.toLower();  // Convert file name to lowercase
    int lastindex = filename.lastIndexOf(".");
    QString type = "";
    for (int i = lastindex + 1; i < filename.length(); i++) {
        type += filename[i];  // Extract file extension
    }
    // Supported file formats
    if (type == "avi" || type == "wmv" || type == "mpg" || type == "mpeg" || type == "mov" || type == "rm"
        || type == "ram" || type == "swf" || type == "flv" || type == "mp4" || type == "mp3" || type == "wma"
        || type == "rmvb" || type == "mkv") {
        return true;
    }
    return false;
}

/**
 * @brief Get the file name (with extension) from the full file path
 * @param Qpath  Full file path
 * @return File name with extension
 */
QString getFileName(QString Qpath) {
    std::string path = Qpath.toStdString();
    std::string name;
    for (int i = path.size() - 1; i > 0; i--) {
        if (path[i] == '\\' || path[i] == '/') {
            name = path.substr(i + 1);
            break;
        }
    }
    QString res = QString::fromStdString(name);
    return res;
}

/**
 * @brief Check if a file exists
 * @param fullFileName  Full path to the file
 * @return true if the file exists, otherwise false
 */
bool isFileExist(QString fullFileName) {
    QFileInfo fileInfo(fullFileName);
    if(fileInfo.isFile())
    {
        return true;
    }
    return false;
}

/**
 * @brief Read a local .dat file and retrieve the playlist
 * @param defaultPath  Path to the .dat file
 * @return Pointer to a QVector<QString> containing the playlist
 */
QVector<QString>* readPlayList(QString defaultPath) {
    QFile file(defaultPath);
    QVector<QString> *playList = new QVector<QString>;
    file.open(QIODevice::ReadOnly);
    QDataStream input(&file);
    QString name;
    QString str;
    while (!input.atEnd()) {
        QString buf;
        input >> buf;
        if (isFileExist(buf)) playList->append(buf);  // Add file to playlist if it exists
    }
    file.close();
    return playList;
}

/**
 * @brief Write a playlist to a local .dat file
 * @param playList  The playlist to write
 * @param defaultPath  File path where the playlist will be saved
 * @return true if successful, otherwise false
 */
bool writePlayList(QVector<QString> playList, QString defaultPath) {
    QFile file(defaultPath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QDataStream out(&file);
        for (int i = 0; i < playList.size(); i++) {
            out << playList[i];
        }
        file.close();
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Retrieve the album cover from an MP3 file
 * @param fn  Path to the MP3 file
 * @return QImage containing the album cover
 */
QImage getAttachedPic(QString fn) {
    std::string fn_str = fn.toStdString();
    const char* fileName = fn_str.c_str();
    AVFormatContext* formatContext = avformat_alloc_context();
    QImage *notFoundImage = new QImage(":new/image/song.png");
    if (avformat_open_input(&formatContext, fileName, NULL, NULL) != 0) {
        qDebug() << "Couldn't open input stream.\n";
        return *notFoundImage;
    }
    if (avformat_find_stream_info(formatContext, NULL) < 0) {
        qDebug() << "Could not find stream information\n";
        return *notFoundImage;
    }
    int streamsCount = formatContext->nb_streams;
    for (int i = 0; i < streamsCount; ++i) {
        if (formatContext->streams[i]->disposition & AV_DISPOSITION_ATTACHED_PIC) {
            AVPacket pkt = formatContext->streams[i]->attached_pic;
            return QImage::fromData((uchar*)pkt.data, pkt.size);
        }
    }
    avformat_free_context(formatContext);
    return *notFoundImage;
}

/**
 * @brief Get detailed information about a video/audio file
 * @param fn  Path to the file
 * @return QString containing the file's detailed information
 */
QString getVideoInfo(QString fn) {
    QString info_return = "";
    std::string fn_str = fn.toStdString();
    const char* fileName = fn_str.c_str();
    AVFormatContext* formatContext = avformat_alloc_context();
    AVDictionaryEntry *tag = NULL;
    if (avformat_open_input(&formatContext, fileName, NULL, NULL) != 0) {
        qDebug() << "Couldn't open input stream.\n";
        return "-1";
    }
    if (avformat_find_stream_info(formatContext, NULL) < 0) {
        qDebug() << "Could not find stream information\n";
        return "-1";
    }
    while (tag = av_dict_get(formatContext->metadata, "", tag, AV_DICT_IGNORE_SUFFIX))
    {
        QString keyString = tag->key;
        QString valueString = QString::fromUtf8(tag->value);
        // info_return+=" "+keyString+": "+valueString+"\n";
        qDebug()<<info_return;
    }
    long duration=(formatContext->duration)/ AV_TIME_BASE;
    qDebug()<<formatContext;
    AVCodecParameters* pLocalCodecParameters_temp = NULL;
    int video_width  ;
    int video_height  ;
    int video_pixel_format ;
    int channel;
    for (int i = 0; i < (int)formatContext->nb_streams; i++)
    {
        pLocalCodecParameters_temp = formatContext->streams[i]->codecpar;
        AVCodec* localCodec = NULL;
        localCodec = avcodec_find_decoder(pLocalCodecParameters_temp->codec_id);
        if (localCodec == NULL)
        {
            printf("Error: Unsupported codec");
            continue;
        }
        if (pLocalCodecParameters_temp->codec_type == AVMEDIA_TYPE_AUDIO)
        {
            channel=pLocalCodecParameters_temp->channels;//num_channels;
            int sample_rate=pLocalCodecParameters_temp->sample_rate;//sample_rate;
        }
        else if (pLocalCodecParameters_temp->codec_type == AVMEDIA_TYPE_VIDEO)
        {
            //Get high resolution
             video_width = formatContext->streams[i]->codecpar->width;
             video_height = formatContext->streams[i]->codecpar->height;
             video_pixel_format=formatContext->streams[i]->codecpar->format;
        }
    }
    QString res = QString("%1 x %3").arg(video_width).arg(video_height);
    info_return+="\n\n";
    info_return+=" 标题:   "+ fn +"\n\n";
    info_return+=" 分辨率: "+ res +"\n\n";
    info_return+=" 帧速率: 30\n\n";
    info_return+=" 音频频道: "+ QString::number(channel) +"\n\n";
    info_return+=" 项目类型:  .mp4 \n\n";
    info_return+=" 文件位置:"+ fn +"\n\n";


    pLocalCodecParameters_temp = NULL;
    avformat_free_context(formatContext);
    delete tag;
    return info_return;

}

/**
 * @brief Get the file suffix (extension)
 * @param fileName  Path to the file
 * @return File suffix as QString
 */
QString getSuffix(QString fileName){
    std::string filename_str = fileName.toStdString();
    std::string res=filename_str.substr(filename_str.find_last_of('.') + 1);
    QString suffix = QString::fromStdString(res);
    return suffix;
}

/**
 * @brief Determine the media type of the file
 * @param fileName  Path to the file
 * @return 1 for audio files, 2 for video files, 0 for invalid files
 */
int mediaType(QString fileName) {
    QString suffix = getSuffix(fileName);
    if (audioType.indexOf(suffix) >= 0) {
        return 1;  // Audio file
    } else if (videoType.indexOf(suffix) >= 0) {
        return 2;  // Video file
    } else {
        return 0;  // Invalid file
    }
}
