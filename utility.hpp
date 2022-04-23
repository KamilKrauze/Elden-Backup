#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

#include "color.hpp"

using namespace std::chrono;

enum class messageType
{
    info,
    output,
    prompt,
    normal,
    error,
    success,
};

void clear()
{
#if defined _WIN32
	system("cls");
	//clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined(_APPLE_)
	system("clear");
	//std::std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#endif
}

void consolelog(const char* msg, messageType type)
{
    if (type == messageType::error)
    {
        std::cout << dye::light_red(msg) << std::endl;
    }
    else if (type == messageType::success)
    {
        std::cout << hue::light_green << msg << std::endl;
        std::this_thread::sleep_until(system_clock::now() + seconds(2));
    }
    else if (type == messageType::info)
    {
        std::cout << dye::light_blue(msg) << std::endl;
    }
    else if (type == messageType::prompt)
    {
        std::cout << dye::light_yellow(msg) << std::endl;
    }
    else if (type == messageType::output)
    {
        std::cout << dye::light_aqua(msg) << std::endl;
    }
    else
    {
        std::cout << msg << std::endl;
    }
}

void consolelog(const char* msg, tm* now)
{
    std::cout << hue::light_aqua << msg << "\t\t\t\t\t" << "at time - " << hue::reset << hue::purple <<now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << ":" << hue::reset << std::endl;
}

void logtoFile(bool result)
{
    if(result == NULL)
        return;

    //ofstream logFile; // Do some shit...

    if (result == true) // Success
    {
    }
    else // Failure
    {

    }
}


#endif // !UTIL_H