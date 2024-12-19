# **README**

---

### **Project Name**
Qt Video Player Prototype Application

---

### **Project Overview**
This project is a video player application developed using the Qt framework. It has undergone three iterations of development and optimization, focusing on core functionality, user interface (UI) improvements, and enhanced user experience (UX). The final version ensures key features, improved interactivity, and compatibility across both mobile and desktop platforms.

---

### **Development Environment**
- **Qt Version**: Qt 5.15.2 (MinGW 32-bit only! (Because some 32-bit supported functions were used when building the video player))
- **Platform**: Windows / Mobile Devices
- **Language**: C++ / Qt Framework

---

### **Iteration Details**

#### **First Iteration**
![First iteration](https://github.com/Leo-Chen-cs/UI-finalcw/blob/main/image/First%20interation.png)
**Implemented Features**:
- Play/Pause button  
- Mute functionality  

**Known Issues**:
- **Previous/Next track buttons**: Non-functional due to hardcoded video paths, allowing only one video to be loaded.  
- **Progress bar bug**: Jumping via the progress bar causes playback issues.  
- **Video duration display**: Always shows 0.  

---

#### **Second Iteration**
![Second iteration](https://github.com/Leo-Chen-cs/UI-finalcw/blob/main/image/Second%20interation.png)
**New Features**:
- Slow rewind/fast forward functionality  
- Add video functionality  
- Video list display feature  
- Automatic fullscreen mode when double-clicking the video  
- Relocated control buttons (e.g., Close) to the left side  

**Bug Fixes**:
- Resolved hardcoded video path issue  
- Fixed progress bar functionality, allowing proper playback after seeking  

---

#### **Third Iteration**
![Third iteration](https://github.com/Leo-Chen-cs/UI-finalcw/blob/main/image/Third%20interation.png)
**Optimizations and Enhancements**:
- **UI Redesign**: Improved layout and enhanced interactive design.  
- **Loop playback feature**  
- **Video metadata display**: Shows video title and relevant information.  
- **Playback mode toggle**: Switch between loop and sequential playback modes.  
- **Compatibility**: Ensured proper rendering on both desktop and mobile platforms.  

---

### **Project Structure**
```
/Project-Directory
│
├── image/                      # Directory for resource images (icons, thumbnails, etc.)
├── lib/                        # Directory for libraries or third-party dependencies
├── Widget/                     # Contains custom UI components/widgets
│
├── 111.mp4                     # Sample video file used for testing playback
├── ImageResource.qrc           # Qt Resource file managing images and resources
│
├── main.cpp                    # Program's main entry point, initializes the application
├── mainwindow.cpp              # Implementation of the main window logic (UI functionality)
├── mainwindow.h                # Header file for the main window class
├── mainwindow.ui               # UI design file created using Qt Designer
│
├── Player_3.pro.user           # User-specific project configuration file (auto-generated)
├── Player_4.pro                # Project configuration file for Qt Creator
├── Player_4.pro.user           # User-specific configuration file (do not version-control)
├── Player_4.pro.user.3f21d0b   # Backup user configuration file
│
├── seekFrame.cpp               # Implementation of frame seek functionality for video playback
├── seekFrame.h                 # Header file for frame seek functionality
│
├── utils.cpp                   # Contains utility/helper function implementations
└── utils.h                     # Header file for utility functions

```

---

### **How to Run**

#### **Dependencies**
- Install **Qt 5.15.2(MinGW 32-bit only(Because some 32-bit supported functions were used when building the video player))**  
- LAV Filters:
Some video formats may require the installation of LAV Filters for proper playback.
Download here: [LAV Filters](https://www.videohelp.com/software/LAV-Filters)
If the decoder is already installed on your system, you can skip this step.  

#### **Build and Run Steps**
1. Clone the project to your local machine:  
   ```
   git clone https://github.com/Leo-Chen-cs/UI-finalcw.git
   cd QT-VideoPlayer-Project
   ```
2. Open the project using Qt Creator:  
   - Select the `.pro` file in the `src` directory.  
   - Configure the Qt 5.15.2 build environment (MinGW 32-bit only!(Because some 32-bit supported functions were used when building the video player)).  

3. Run the program:  
   - Click the **Run** button in Qt Creator.  
   - At startup, provide the video file directory path as a command-line argument.  

---

### **Project Highlights**
1. **Feature Complete**: Implements core video playback functionalities, including playback control, list management, and playback mode toggling.  
2. **User-Friendly**: Optimized UI design for a better user experience.  
3. **Cross-Platform**: Supports rendering on both desktop and mobile platforms.  
4. **Internationalization Support**: Placeholder for future multi-language support.  

---

### **Known Issues**
- Video playback relies on external video decoder configurations.  
- Potential performance limitations on low-end devices.  

---

### **Contributors**
- Team Leader: Haotian Chen
- Team Members:  
  - Bowen Ye
  - Mingyue Xu
  - Yuchen Cao
  - Qifeng Li

---

### **License**
This project is licensed under the MIT License.

---

### **Contact**:blush:
For questions, please contact:  
- Email: cht@my.swjtu.edu.cn
- GitHub Repository: [GitHub Repo](https://github.com/Leo-Chen-cs)  
