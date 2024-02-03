#ifndef ELDEN_BACKUP_H
#define ELDEN_BACKUP_H

#include <iostream>
#include <fstream>

#include "settings.hpp"

// Elden Backup Namespace
namespace EB {

	constexpr const char* FILE1 = "/ER0000.sl2";
	constexpr const char* FILE2 = "/ER0000.sl2.bak";

	void backupFiles()
	{
		std::string fullPath_src = srcfilepath + FILE1;
		std::string fullPath_dst = dstFilepath + FILE1;

		std::ifstream src;
		std::ofstream dst;

		src.open(fullPath_src, std::ios::in | std::ios::binary);
		dst.open(fullPath_dst, std::ios::out | std::ios::binary);
		dst << src.rdbuf();

		src.close();
		dst.close();

		fullPath_src = srcfilepath + FILE2;
		fullPath_dst = dstFilepath + FILE2;

		src.open(fullPath_src, std::ios::in | std::ios::binary);
		dst.open(fullPath_dst, std::ios::out | std::ios::binary);

		src.close();
		dst.close();
	}
};

#endif // !ELDEN_BACKUP_H
