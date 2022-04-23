#ifndef ELDENRINGBACKUP_H
#define ELDENRINGBACKUP_H

#include <iostream>
#include <fstream>
#include <thread>

#include "commands.h"
#include "utility.hpp"

constexpr const char* file1 = "/ER0000.sl2";
constexpr const char* file2 = "/ER0000.sl2.bak";

bool isRunning = true;
bool runBackup = false;
bool runBackupOnce = false;

void backupFiles()
{
	std::string fullPath_src = srcfilepath + file1;
	std::string fullPath_dst = dstFilepath + file1;

	std::ifstream src;
	std::ofstream dst;

	src.open(fullPath_src, std::ios::in | std::ios::binary);
	dst.open(fullPath_dst, std::ios::out | std::ios::binary);
	dst << src.rdbuf();

	src.close();
	dst.close();

	fullPath_src = srcfilepath + file2;
	fullPath_dst = dstFilepath + file2;

	src.open(fullPath_src, std::ios::in | std::ios::binary );
	dst.open(fullPath_dst, std::ios::out | std::ios::binary);

	src.close();
	dst.close();

	if (runBackupOnce != true)
	{
		std::this_thread::sleep_until(system_clock::now() + seconds(backup_interval));
	}
	else
		runBackup = false;
}

void userInput()
{
    bool hasStopped = false;
	std::string input = "";

	while (hasStopped != true)
	{
		std::cout << dye::light_yellow("--->: ") << hue::bright_white;
		std::cin >> input;

		if (input == commands[0] && runBackup == false) // Run
		{
			
			isRunning = true;
			runBackup = true;

		}
		else if (input == commands[1] && runBackup == false) // Backup
		{
			runBackupOnce = true;
			backupFiles();
			clear();
		}
		else if (input == commands[2]) // Settings
		{
			std::cout << settingCommands;
			settingsOption();
		}
		else if (input == commands[3]) // Help
		{
			std::cout << commands;
		}
		else if (input == commands[4]) // Stop
		{
			consolelog("Stopping backup...", messageType::info);
			runBackup = false;
			isRunning = false;
			std::this_thread::sleep_until(system_clock::now() + seconds(2));
			clear();
		}
		else if (input == commands[5]) // Exit
		{
			runBackup = false;
			isRunning = false;
			hasStopped = true;
			clear();
			std::cout << dye::light_green("Shutting down...") << std::endl;
			std::this_thread::sleep_until(system_clock::now() + seconds(2));
			exit(0);
		}
		else
		{
			std::cout << dye::light_purple("Type 'help' to get a list of commands") << std::endl;
		}
	}std::this_thread::yield();
}

#endif // !ELDENRINGBACKUP_H
