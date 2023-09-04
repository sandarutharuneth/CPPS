#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <algorithm> // Include this for std::find

namespace fs = std::filesystem;

int main() {
    std::string targetDirectory;

    // Ask user for the directory to organize
    std::cout << "Please input the directory you want to organize: ";
    std::getline(std::cin, targetDirectory);

    // Create folder names
    const std::string pictureFolder = "pictures";
    const std::string videoFolder = "videos";
    const std::string documentFolder = "documents";
    const std::string musicFolder = "musics";
    const std::string otherFolder = "others";

    // Create folders in the target directory
    fs::create_directory(targetDirectory + "/" + pictureFolder);
    fs::create_directory(targetDirectory + "/" + videoFolder);
    fs::create_directory(targetDirectory + "/" + documentFolder);
    fs::create_directory(targetDirectory + "/" + musicFolder);
    fs::create_directory(targetDirectory + "/" + otherFolder);

    // List of photo, video, document, music, and other file extensions
    std::vector<std::string> photoExtensions = { ".jpg", ".png", ".bmp", ".gif" };
    std::vector<std::string> videoExtensions = { ".mp4", ".avi", ".mkv", ".mov", ".wmv" };
    std::vector<std::string> documentExtensions = { ".doc", ".docx", ".txt", ".xls", ".xlsx", ".pdf" };
    std::vector<std::string> musicExtensions = { ".mp3", ".wav", ".flac", ".ogg" };

    // File moving operations
    for (const auto& dirEntry : fs::directory_iterator(targetDirectory)) {
        if (fs::is_regular_file(dirEntry)) {
            const std::string filename = dirEntry.path().filename().string();
            const std::string extension = dirEntry.path().extension().string();

            // Move photo files to 'pictures' folder
            if (std::find(photoExtensions.begin(), photoExtensions.end(), extension) != photoExtensions.end()) {
                fs::rename(dirEntry.path(), targetDirectory + "/" + pictureFolder + "/" + filename);
            }
            
            // Move video files to 'videos' folder
            else if (std::find(videoExtensions.begin(), videoExtensions.end(), extension) != videoExtensions.end()) {
                fs::rename(dirEntry.path(), targetDirectory + "/" + videoFolder + "/" + filename);
            }

            // Move document files to 'documents' folder
            else if (std::find(documentExtensions.begin(), documentExtensions.end(), extension) != documentExtensions.end()) {
                fs::rename(dirEntry.path(), targetDirectory + "/" + documentFolder + "/" + filename);
            }

            // Move music files to 'musics' folder
            else if (std::find(musicExtensions.begin(), musicExtensions.end(), extension) != musicExtensions.end()) {
                fs::rename(dirEntry.path(), targetDirectory + "/" + musicFolder + "/" + filename);
            }
            
            // Move other files to 'others' folder
            else {
                fs::rename(dirEntry.path(), targetDirectory + "/" + otherFolder + "/" + filename);
            }
        }
    }

    std::cout << "Files organized into their respective folders." << std::endl;

    return 0;
}
