#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

void listDirectory(const std::string& path) {
    for (const auto& entry : fs::directory_iterator(path)) {
        std::cout << entry.path().filename() << std::endl;
    }
}

void createDirectory(const std::string& path) {
    if (!fs::exists(path)) {
        if (fs::create_directory(path)) {
            std::cout << "Directory created successfully.\n";
        } else {
            std::cerr << "Error: Failed to create directory.\n";
        }
    } else {
        std::cerr << "Error: Directory already exists.\n";
    }
}

void deleteFileOrDirectory(const std::string& path) {
    if (fs::exists(path)) {
        if (fs::is_directory(path)) {
            if (fs::remove_all(path)) {
                std::cout << "Directory deleted successfully.\n";
            } else {
                std::cerr << "Error: Failed to delete directory.\n";
            }
        } else {
            if (fs::remove(path)) {
                std::cout << "File deleted successfully.\n";
            } else {
                std::cerr << "Error: Failed to delete file.\n";
            }
        }
    } else {
        std::cerr << "Error: File or directory does not exist.\n";
    }
}

int main() {
    std::string path;
    char choice;

    std::cout << "Welcome to Simple File Manager\n";
    std::cout << "Enter directory path: ";
    std::cin >> path;

    do {
        std::cout << "\nOptions:\n";
        std::cout << "1. List files and folders\n";
        std::cout << "2. Create directory\n";
        std::cout << "3. Delete file or directory\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                listDirectory(path);
                break;
            case '2':
                std::cout << "Enter directory name to create: ";
                std::cin >> path;
                createDirectory(path);
                break;
            case '3':
                std::cout << "Enter file or directory name to delete: ";
                std::cin >> path;
                deleteFileOrDirectory(path);
                break;
            case '4':
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cerr << "Error: Invalid choice.\n";
        }
    } while (choice != '4');

    return 0;
}
