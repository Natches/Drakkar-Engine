#pragma once
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>

/*!
*	@file
*/

enum class ELoggerVerbosity {
	RELEASE = 0, /*!< Release level verbosity: outputs to file */
	DEBUG = 10, /*!< Debug level verbosity: outputs to file and console */
	FATAL = 20 /*!< Fatal level verbosity: outputs to file and crashes program */
};

inline constexpr bool operator<(ELoggerVerbosity& a, ELoggerVerbosity& b) {
	return (int)a < (int)b;
}

inline constexpr bool operator>(ELoggerVerbosity& a, ELoggerVerbosity& b) {
	return (int)a > (int)b;
}


template <typename T>
struct LogCategory {
	static const ELoggerVerbosity compileMaxVerbosity;
};

 
inline FILE* OpenLogFile(const char* filenameFromCategory = nullptr) {
	FILE* pLogFile = nullptr;
	if (fopen_s(&pLogFile, filenameFromCategory, "a+") == 0) {
		return pLogFile;
	}
	return nullptr;
}
inline void CloseLogFile(FILE* file) {
	fclose(file);
}

#define DK_LOG_CATEGORY_DEFINE(name)		\
 struct name : public LogCategory<name> {	\
	using Category = LogCategory<name>;		\
};

#define DK_LOG_CATEGORY_DECLARE(name, comp) \
const ELoggerVerbosity name::Category::compileMaxVerbosity(comp);

#define DK_LOG(category, verbosity, outputString, ...){				\
	if constexpr(verbosity <= category::compileMaxVerbosity){		\
		FILE* logFile = OpenLogFile(#category);						\
		switch (verbosity) {										\
		case ELoggerVerbosity::DEBUG:								\
				fprintf_s(logFile, outputString, __VA_ARGS__);		\
				printf_s(outputString, __VA_ARGS__);				\
				CloseLogFile(logFile);								\
				break;												\
		case ELoggerVerbosity::RELEASE:								\
				fprintf_s(logFile, outputString, __VA_ARGS__);		\
				CloseLogFile(logFile);								\
				break;												\
		case ELoggerVerbosity::FATAL:								\
				fprintf_s(logFile, outputString, __VA_ARGS__);		\
				CloseLogFile(logFile);								\
				break;												\
		}															\
	}																\
}

/*!
	\enum LoggerVerbosity
	\brief An enum defining logging verbosity.
*/
/*!
	\def DEFINE_CATEGORY(name)
	Defines a log category
*/
/*!
	\def DECLARE_CATEGORY(name, comp)
	Declares a previously defined log category and sets its maximum verbosity
*/
/*!
	\def DRAK_LOG(category, warningLevel, outputString, ...)
	Logs a message to the console or the log file based on verbosity. Does not compile code if the verbosity is higher than the category's max verbosity.
*/