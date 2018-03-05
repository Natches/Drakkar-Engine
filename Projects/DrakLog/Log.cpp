#include "Log.h"
#include <chrono>
#include <iomanip>
#include <string>
#include <time.h>

FILE * GetLogFile() {
	static FILE* logFile;
	if (!logFile) {
		std::tm* time = new std::tm;
		std::time_t now_c = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		localtime_s(time, &now_c);

		std::string filename = "Logs/Log " + std::to_string(time->tm_year + 1900) + "." + std::to_string(time->tm_mon)
			+ "." + std::to_string(time->tm_mday) + " " + std::to_string(time->tm_hour) + "."
			+ std::to_string(time->tm_min) + "." + std::to_string(time->tm_sec) + ".txt";
		delete time;

		if (fopen_s(&logFile, filename.c_str(), "w") == 0) {
			return logFile;
		}
	}
	return logFile;
}