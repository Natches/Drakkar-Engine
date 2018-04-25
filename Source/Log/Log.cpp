#include <PrecompiledHeader/pch.hpp>

std::map<const char*, FILE*> Logbook::logs = std::map<const char*, FILE*>();

FILE* Logbook::OpenLogFile(const char* filename) {
	FILE* pLogFile = nullptr;
	if (fopen_s(&pLogFile, filename, "w") == 0) {
		return pLogFile;
	}
	return nullptr;
}

void Logbook::CloseLogFile(FILE* file) {
	fclose(file);
}


void Logbook::CloseLogs() {
	std::map<const char*, FILE*>::iterator it = logs.begin();
	while (it != logs.end()) {
		CloseLogFile((*it).second);
		std::advance(it, 1);
	}
}

void Logbook::Log(Logbook::EOutput output, const char* filename, const char* message, ...) {
	va_list args;
	va_start(args, message);
	switch (output) {
	case Logbook::EOutput::CONSOLE: {
		printf_s("%s: ", filename);
		printf_s(message, args);
		break;
	}
	case Logbook::EOutput::FILE: {
		if (logs.end() == logs.find(filename))
			logs.insert(std::pair<const char*, FILE*>(filename, OpenLogFile(filename)));
		fprintf_s(logs[filename], message, args);
		break;

	}
	default: {
		if (logs.end() == logs.find(filename))
			logs.insert(std::pair<const char*, FILE*>(filename, OpenLogFile(filename)));
		fprintf_s(logs[filename], message, args);
		printf_s("%s: ", filename);
		printf_s(message, args);
		break;
	}
	}
	va_end(args);
}