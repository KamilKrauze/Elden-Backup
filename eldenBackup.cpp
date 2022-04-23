#include "eldenRingBackup.hpp"

#include "color.hpp"

using namespace std;

int main()
{
	SetConsoleTitleA("Elden Ring Backup");

	thread t1(userInput);
	t1.joinable();

	while (isRunning != false)
	{
		if (runBackup == true)
		{
			backupFiles();
		}
	}
	

	return 0;
}