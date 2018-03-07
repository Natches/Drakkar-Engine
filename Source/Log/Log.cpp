#include "Log.h"
#include <iomanip>
#include <string>
#include <time.h>

FILE * OpenLogFile(const char* filenameFromCategory) {
	FILE* pLogFile = new FILE;
	std::string filename;
	if (filenameFromCategory == nullptr)
	{
		std::time_t t = time(NULL);
		char* timeBuf = new char[100];
		std::tm componentWiseTime;
		localtime_s(&componentWiseTime, &t);
		asctime_s(timeBuf, 100, &componentWiseTime);
		std::string time(timeBuf);
		delete[] timeBuf;
		time.pop_back();
		size_t posOfSpace;
		do {
			posOfSpace = time.find(':');
			if (posOfSpace == std::string::npos)
				break;
			time[posOfSpace] = '_';
		} while (posOfSpace != std::string::npos);

		do {
			posOfSpace = time.find(' ');
			if (posOfSpace == std::string::npos)
				break;
			time[posOfSpace] = '_';
		} while (posOfSpace != std::string::npos);
		filename = std::string("Logs/Log_" + time + ".txt");
	}
	else
		filename = std::string(filenameFromCategory);
	if (fopen_s(&pLogFile, filename.c_str(), "w") == 0) {
		return pLogFile;
	}
	return nullptr;
}

void CloseLogFile(FILE * file) {
	fclose(file);
}
