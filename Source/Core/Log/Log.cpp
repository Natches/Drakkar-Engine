#include <Core/Log/Log.hpp>
#include <iomanip>
#include <string>
#include <time.h>

FILE* OpenLogFile(const char* filenameFromCategory) {
	FILE* pLogFile = nullptr;
	if (fopen_s(&pLogFile, filenameFromCategory, "a+") == 0) {
		return pLogFile;
	}
	return nullptr;
}

void CloseLogFile(FILE* file) {
	fclose(file);
}
