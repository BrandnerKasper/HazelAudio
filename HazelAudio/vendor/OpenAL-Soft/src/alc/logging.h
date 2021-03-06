#ifndef LOGGING_H
#define LOGGING_H

#include <stdio.h>

#include "opthelpers.h"


extern FILE *gLogFile;

[[gnu::format(printf,2,3)]] void al_print(FILE *logfile, const char *fmt, ...);
#if !defined(_WIN32)
#define AL_PRINT fprintf
#else
#define AL_PRINT al_print
#endif

#ifdef __ANDROID__
#include <android/log.h>
#define LOG_ANDROID(T, ...) __android_log_print(T, "openal", "AL lib: " __VA_ARGS__)
#else
#define LOG_ANDROID(T, ...) ((void)0)
#endif

enum LogLevel {
    NoLog,
    LogError,
    LogWarning,
    LogTrace,
    LogRef
};
extern LogLevel gLogLevel;


#define TRACE(...)

#define WARN(...)

#define ERR(...) 

#endif /* LOGGING_H */

