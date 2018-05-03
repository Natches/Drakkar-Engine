#include <PrecompiledHeader/pch.hpp>

std::map<std::string, FILE*> Logbook::logs = std::map<std::string, FILE*>();

FILE* Logbook::OpenLogFile(std::string filename) {
	FILE* pLogFile = nullptr;
	if (fopen_s(&pLogFile, filename.c_str(), "w") == 0) {
		return pLogFile;
	}
	return nullptr;
}

void Logbook::CloseLogFile(FILE* file) {
	fclose(file);
}


void Logbook::CloseLogs() {
	std::map<std::string, FILE*>::iterator it = logs.begin();
	while (it != logs.end()) {
		CloseLogFile((*it).second);
		std::advance(it, 1);
	}
}

void Logbook::Log(Logbook::EOutput output, std::string filename, const char* message, ...) {
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
			logs.insert(std::pair<std::string, FILE*>(filename, OpenLogFile(filename)));
		fprintf_s(logs[filename], message, args);
		break;

	}
	default: {
		if (logs.count(filename) == 0)
			logs.insert(std::pair<std::string, FILE*>(filename, OpenLogFile(filename)));
		fprintf_s(logs[filename], message, args);
		printf_s("%s: ", filename);
		printf_s(message, args);
		break;
	}
	}
	va_end(args);
}