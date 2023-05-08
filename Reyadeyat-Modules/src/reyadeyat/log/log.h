//
// Created by mnm on 5/5/23.
//

#ifndef REYADEYAT_C_REYADEYAT_LOG_H
#define REYADEYAT_C_REYADEYAT_LOG_H

//Unix Syslog Severity Level
REYADEYAT_ENUM_TYPE(Reyadeyat_Log_Severity_Level) {
    REYADEYAT_EMERGENCY = 0,
    REYADEYAT_ALERT = 1,
    REYADEYAT_CRITICAL = 2,
    REYADEYAT_ERROR = 3,
    REYADEYAT_WARNING = 4,
    REYADEYAT_NOTICE = 5,
    REYADEYAT_INFORMATIONAL = 6,
    REYADEYAT_DEBUG = 7
};

#define REYADEYAT_LOG_MODULE_NAME_LENGTH 128
#define REYADEYAT_LOG_FUNCTION_NAME_LENGTH 128
#define REYADEYAT_LOG_FILE_NAME_LENGTH 512
#define REYADEYAT_LOG_MESSAGE_LENGTH 1024

REYADEYAT_DATA_TYPE(Reyadeyat_Log) {
    int severity_level;
    int line_number;
    char module_name[REYADEYAT_LOG_MODULE_NAME_LENGTH];
    char function_name[REYADEYAT_LOG_FUNCTION_NAME_LENGTH];
    char file_name[REYADEYAT_LOG_FILE_NAME_LENGTH];
    char log_message[REYADEYAT_LOG_MESSAGE_LENGTH];
};

REYADEYAT_DATA_TYPE(Reyadeyat_Log_List) {
    int size;
    int cursor;
    Reyadeyat_Log *log_list;
};

void reyadeyat_log_add_log_to_list(Reyadeyat_Log_Severity_Level log_level, const char *module_name, const char *file_name, const char *function_name, int line_number, Reyadeyat_Log_List *reyadeyat_log_list, const char* log_message, ...);
void reyadeyat_log_print_log_list(FILE *stream, Reyadeyat_Log_List *reyadeyat_log_list);

#endif //REYADEYAT_C_REYADEYAT_LOG_H
