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

#ifndef REYADEYAT_MEMORY_H
#define REYADEYAT_MEMORY_H

REYADEYAT_DATA_TYPE(Reyadeyat_Memory_Process) {
    void (*construct)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list);
    void (*destruct)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list);
    void (*process)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list);
    void (*create_memory_page)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list);
    void (*init_memory_page)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list);
    void (*fetch_memory_page)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list);
    void (*claim_memory_page)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list);
    void (*copy_memory_page_to_memory_page)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list);
    void (*copy_memory_page_to_file_page)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list);
    void (*copy_file_page_to_memory_page)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list);
    void (*copy_file_page_to_file_page)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list);
};

extern Reyadeyat_Memory_Process* get_reyadeyat_memory_process(char* lib_path, char *version_number, Reyadeyat_Log_List *reyadeyat_log_list_main);

#endif //REYADEYAT_MEMORY_H
