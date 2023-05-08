/*
 * Copyright (C) 2023 Reyadeyat
 *
 * Reyadeyat/REYADEYAT-C-Lib is licensed under the
 * BSD 3-Clause "New" or "Revised" License
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * https://reyadeyat.net/LICENSE/REYADEYAT-C-Lib.LICENSE
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 *
 * Description
 *
 *
 * @author Mohammad Nabil Mostafa
 * <a href="mailto:code@reyadeyat.net">code@reyadeyat.net</a>
 *
 * @since 2023.04.01
 */

#include "reyadeyat/reyadeyat.h"

void reyadeyat_log_add_log_to_list(Reyadeyat_Log_Severity_Level severity_level, const char *module_name, const char *file_name, const char *function_name, int line_number, Reyadeyat_Log_List *reyadeyat_log_list, const char* log_message, ...) {
    char str[REYADEYAT_LOG_MESSAGE_LENGTH];
    va_list argument_list;
    va_start(argument_list, log_message);
    vsprintf(str, log_message, argument_list);
    va_end(argument_list);

    if (reyadeyat_log_list->size == reyadeyat_log_list->cursor) {
        char *_str = "log log cursor overflow log_log max array reached";
        memcpy(reyadeyat_log_list->log_list[0].log_message, _str, MIN(REYADEYAT_LOG_MESSAGE_LENGTH, strlen(_str)));
        return;
    }
    Reyadeyat_Log *reyadeyat_log = &reyadeyat_log_list->log_list[reyadeyat_log_list->cursor++];
    reyadeyat_log->severity_level = severity_level;
    reyadeyat_log->line_number = line_number;
    memcpy(reyadeyat_log->module_name, module_name, MIN(REYADEYAT_LOG_MODULE_NAME_LENGTH, strlen(module_name)));
    memcpy(reyadeyat_log->function_name, function_name, MIN(REYADEYAT_LOG_FUNCTION_NAME_LENGTH, strlen(function_name)));
    memcpy(reyadeyat_log->file_name, file_name, MIN(REYADEYAT_LOG_FILE_NAME_LENGTH, strlen(file_name)));
    memcpy(reyadeyat_log->log_message, str, MIN(REYADEYAT_LOG_MESSAGE_LENGTH, strlen(str)));
}

void reyadeyat_log_print_log_list(FILE *stream, Reyadeyat_Log_List *reyadeyat_log_list) {
    for (int i = 0; i < reyadeyat_log_list->cursor; i++) {
        Reyadeyat_Log reyadeyat_log = reyadeyat_log_list->log_list[i];
        fprintf (stream, "Reyadeyat %s log cursor = %d {.file_name = %s, .function_name = %s, .line_number = %d, .log_message=%s}\n",
                 reyadeyat_log.module_name, i, reyadeyat_log.file_name, reyadeyat_log.function_name, reyadeyat_log.line_number, reyadeyat_log.log_message);
    }
}