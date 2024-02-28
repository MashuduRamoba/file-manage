// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem; // Alias for std::filesystem namespace

namespace FileManager {
	void listFiles(const std::string& directory) {
		for (const auto& entry : fs::directory_iterator(directory)) {
			std::cout << entry.path().filename() << std::endl;
		}
	}

	void createDirectory(const std::string& directory) {
		if (!fs::exists(directory)) {
			fs::create_directory(directory);
			std::cout << "Directory created: " << directory << std::endl;
		}
		else {
			std::cout << "Directory already exists: " << directory << std::endl;
		}
	}

	void copyFile(const std::string& sourceFile, const std::string& destinationFile) {
		fs::copy(sourceFile, destinationFile);
		std::cout << "File copied: " << sourceFile << " -> " << destinationFile << std::endl;
	}

	void moveFile(const std::string& sourceFile, const std::string& destinationFile) {
		fs::rename(sourceFile, destinationFile);
		std::cout << "File moved: " << sourceFile << " -> " << destinationFile << std::endl;
	}
}

using namespace std; // Using directive to bring std namespace into scope

int main() {
	string command;
	string directory = "."; // Current directory

	while (true) {
		cout << "Command (list/create/copy/move/exit): ";
		cin >> command;

		if (command == "list") {
			FileManager::listFiles(directory);
		}
		else if (command == "create") {
			string newDir;
			cout << "Enter directory name to create: ";
			cin >> newDir;
			FileManager::createDirectory(directory + "/" + newDir);
		}
		else if (command == "copy") {
			string sourceFile, destinationFile;
			cout << "Enter source file path: ";
			cin >> sourceFile;
			cout << "Enter destination file path: ";
			cin >> destinationFile;
			FileManager::copyFile(sourceFile, destinationFile);
		}
		else if (command == "move") {
			string sourceFile, destinationFile;
			cout << "Enter source file path: ";
			cin >> sourceFile;
			cout << "Enter destination file path: ";
			cin >> destinationFile;
			FileManager::moveFile(sourceFile, destinationFile);
		}
		else if (command == "exit") {
			break;
		}
		else {
			cout << "Invalid command. Please try again." << endl;
		}
	}

	return 0;
}


