//
// Created by mnm on 5/5/23.
//

#ifndef REYADEYAT_C_REYADEYAT_LOG_H
#define REYADEYAT_C_REYADEYAT_LOG_H

#define REYADEYAT_LOG_FUNCTION_NAME_LENGTH 128
#define REYADEYAT_LOG_FILE_NAME_LENGTH 512
#define REYADEYAT_LOG_MESSAGE_LENGTH 1024

REYADEYAT_DATA_TYPE(Reyadeyat_Log) {
    int line_number;
    char function_name[REYADEYAT_LOG_FUNCTION_NAME_LENGTH];
    char file_name[REYADEYAT_LOG_FILE_NAME_LENGTH];
    char log_message[REYADEYAT_LOG_MESSAGE_LENGTH];
};

REYADEYAT_DATA_TYPE(Reyadeyat_Log_List) {
    int size;
    int cursor;
    Reyadeyat_Log *log_list;
};

void reyadeyat_log_add_log_to_list(int line_number, const char *function_name, const char *file_name, Reyadeyat_Log_List *reyadeyat_log_list, const char* log_message, ...);
void reyadeyat_log_print_log_list(FILE *stream, Reyadeyat_Log_List *reyadeyat_log_list);

#endif //REYADEYAT_C_REYADEYAT_LOG_H
