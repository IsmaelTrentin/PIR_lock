#pragma once

typedef enum LogEventType {
    LOG_EVENT_TYPE_OPEN = 0,
    LOG_EVENT_TYPE_CLOSE,
} LogEventType;

typedef struct Log {
    int id;
    int timestamp;
    LogEventType type;
} Log;

char* log_enum_str(LogEventType type);

void log_init_arr();
void log_append(LogEventType type);
void log_erase_all();