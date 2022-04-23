#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>

#include "utility.hpp"
#include "settings.hpp"

int constexpr commandListSize = 6;
int constexpr settingCommandsListSize = 3;

    std::string commands[commandListSize] = {
        "run",
        "backup",
        "settings",
        "help",
        "stop",
        "exit",
    };

    std::string settingCommands[settingCommandsListSize] = {
        "backup-interval",
        "backup-src",
        "backup-dest"
    };

    void changeBackupInterval()
    {
        std::string input = "";
        std::cout << "Interval time (seconds): ";
        std::cin >> input;

        int seconds = 0;
        bool result = isdigit(atoi(input.c_str()));
        if (result == false)
        {
            seconds = atoi(input.c_str());
        }
        else
        {
            consolelog("ERROR: Not a number, reverting to currently saved value", messageType::error);
            return;
        }

        if (seconds < 300)
        {
            consolelog("ERROR: Too short of an interval please enter a time that is at least greater than 2mins.", messageType::error);
            return;
        }

        consolelog("SUCCESS: New interval time set", messageType::success);
        backup_interval = seconds;
    }

    void settingsOption()
    {
        std::string input = "";
        bool choosenOption = false;
        while(choosenOption != true)
        {
            std::cout << dye::light_yellow("\n>>>>: ");
            std::cin >> input;

            if (input == "backup-interval")
            {
                choosenOption = true;
                changeBackupInterval();
                return;
            }
        }
    }


    // Output overloads
    std::ostream& operator<<(std::ostream& out, const std::string(& arr)[commandListSize])
    {
        clear();
        out << dye::light_purple("\tCOMMANDS\n");
        out << dye::light_purple("===============================\n");

        for (const auto& command : arr)
        {
            out << dye::light_aqua("  -> " + command) << std::endl;
        }
        out << "\n";

        return out;
    }

    std::ostream& operator<<(std::ostream& out, const std::string( & arr)[settingCommandsListSize])
    {
        clear();
        out << dye::light_purple("\tSETTINGS\n");
        out << dye::light_purple("===============================\n");

        for (const auto setting : arr)
        {
            out << hue::light_aqua << " -> " << setting << hue::reset << std::endl;
        }
        out << "\n";

        return out;
    }


#endif // !COMMANDS_H