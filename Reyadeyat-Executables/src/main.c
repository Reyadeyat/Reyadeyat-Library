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

#if MODE == LIBRARY

int memory_main(int argc, char **argv) {
    printf ("Calling Reyadeyat Program MODE = LIBRARY\n");
    char* dl_error;
    char lib_path[2048];
    memcpy(lib_path, argv[0], strlen(argv[0])+1);
    char* needle = "/Reyadeyat-Executables";
    char *start = strstr(lib_path, needle);
    memcpy(start, "/lib", strlen("/lib")+1);
    printf ("Program at lib_path: %s\n", lib_path);
    int lib_path_len = strlen(lib_path)+1;

    //Load Utilities Library
    char utilities_lib_file[2048];
    memcpy(utilities_lib_file, lib_path, lib_path_len+1);
    char *utilities_lib_file_suffix = "/reyadeyat-utilities-lib.so";
    strncpy(utilities_lib_file+lib_path_len-1, utilities_lib_file_suffix, strlen(utilities_lib_file_suffix));
    printf ("Utilities Library loading file: %s\n", utilities_lib_file);
    void* reyadeyat_utilities_module_library = dlopen(utilities_lib_file, RTLD_LAZY);
    dl_error = (char*) dlerror();
    if (reyadeyat_utilities_module_library == NULL) {
        printf("Error Loading lib file '%s' => %s\n", lib_path, dl_error);
        return 1;
    }

    //Load File Library
    char file_lib_file[2048];
    memcpy(file_lib_file, lib_path, lib_path_len);
    char *file_lib_file_suffix = "/reyadeyat-file-lib.so";
    strncpy(file_lib_file+lib_path_len-1, file_lib_file_suffix, strlen(file_lib_file_suffix)+1);
    printf ("File Library loading file: %s\n", file_lib_file);
    void* reyadeyat_file_module_library = dlopen(file_lib_file, RTLD_LAZY);
    dl_error = (char*) dlerror();
    if (reyadeyat_file_module_library == NULL) {
        printf("Error Loading lib file '%s' => %s\n", lib_path, dl_error);
        return 1;
    }

    //Load Memory Library
    char memory_lib_file[2048];
    memcpy(memory_lib_file, lib_path, lib_path_len);
    char *memory_lib_file_suffix = "/reyadeyat-memory-lib.so";
    strncpy(memory_lib_file+lib_path_len-1, memory_lib_file_suffix, strlen(memory_lib_file_suffix)+1);
    printf ("Memory Library loading file: %s\n", memory_lib_file);
    void* reyadeyat_memory_module_library = dlopen(memory_lib_file, RTLD_LAZY);
    dl_error = (char*) dlerror();
    if (reyadeyat_memory_module_library == NULL) {
        printf("Error Loading lib file '%s' => %s\n", lib_path, dl_error);
        return 1;
    }

    Reyadeyat_Process reyadeyat_process;

    Reyadeyat_Log reyadeyat_log[100];
    Reyadeyat_Log_List *reyadeyat_log_list_main = &((Reyadeyat_Log_List){.size = 10, .cursor = 1, .log_list = reyadeyat_log});
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "Initializing Main Program");

    FILE *stream = stdout;

    //Load Utilities Module
    char utilities_library_dir_copy[1024];
    char *utilities_library_version_number = "0.0.0";
    memcpy(utilities_library_dir_copy, lib_path, lib_path_len);
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "Loading Utilities Module start");
    //Load Utilities Process
    Reyadeyat_Utilities_Process* (*get_reyadeyat_utilities_process)(char *, char *, Reyadeyat_Log_List *) = dlsym(reyadeyat_utilities_module_library, "get_reyadeyat_utilities_process");
    if (get_reyadeyat_utilities_process == NULL) {
        printf ("Error loading function get_reyadeyat_utilities_process version \"%s\"\n", utilities_library_version_number);
        reyadeyat_log_print_log_list(stream, reyadeyat_log_list_main);
    }
    printf ("Calling get_reyadeyat_utilities_process \"%s\" utilities_lib_dir_copy => %s\n", utilities_library_version_number, utilities_library_dir_copy);
    reyadeyat_process.utilities_process = get_reyadeyat_utilities_process(utilities_library_dir_copy, utilities_library_version_number, reyadeyat_log_list_main);
    if (reyadeyat_process.utilities_process == NULL) {
        printf ("Failed running get_reyadeyat_utilities_process \"%s\" utilities_lib_dir_copy => %s\n", utilities_library_version_number, utilities_library_dir_copy);
        reyadeyat_log_print_log_list(stream, reyadeyat_log_list_main);
        return 1;
    }
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "Loading Utilities Module end");
    reyadeyat_log_print_log_list(stream, reyadeyat_log_list_main);

    //Load File Module
    char file_library_dir_copy[1024];
    char *file_library_version_number = "0.0.0";
    memcpy(file_library_dir_copy, lib_path, lib_path_len);
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "Loading File Module start");
    //Load File Process
    Reyadeyat_File_Process* (*get_reyadeyat_file_process)(char *, char *, Reyadeyat_Log_List *) = dlsym(reyadeyat_file_module_library, "get_reyadeyat_file_process");
    if (get_reyadeyat_file_process == NULL) {
        printf ("Error loading function get_reyadeyat_file_process version \"%s\"\n", file_library_version_number);
        reyadeyat_log_print_log_list(stream, reyadeyat_log_list_main);
    }
    printf ("Calling get_reyadeyat_file_process \"%s\" file_lib_dir_copy => %s\n", file_library_version_number, file_library_dir_copy);
    reyadeyat_process.file_process = get_reyadeyat_file_process(file_library_dir_copy, file_library_version_number, reyadeyat_log_list_main);
    if (reyadeyat_process.file_process == NULL) {
        printf ("Failed running get_reyadeyat_file_process \"%s\" file_library_dir_copy => %s\n", file_library_version_number, file_library_dir_copy);
        reyadeyat_log_print_log_list(stream, reyadeyat_log_list_main);
        return 1;
    }
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "Loading File Module end");
    reyadeyat_log_print_log_list(stream, reyadeyat_log_list_main);

    //Load Memory Module
    char memory_library_dir_copy[1024];
    char *memory_library_version_number = "0.0.0";
    memcpy(memory_library_dir_copy, lib_path, lib_path_len);
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "Loading Memory Module start");
    //Load Memory Process
    Reyadeyat_Memory_Process* (*get_reyadeyat_memory_process)(char *, char *, Reyadeyat_Log_List *) = dlsym(reyadeyat_memory_module_library, "get_reyadeyat_memory_process");
    if (get_reyadeyat_memory_process == NULL) {
        printf ("Error loading function get_reyadeyat_memory_process version \"%s\"\n", memory_library_version_number);
        reyadeyat_log_print_log_list(stream, reyadeyat_log_list_main);
    }
    printf ("Calling get_reyadeyat_memory_process \"%s\" memory_lib_dir_copy => %s\n", memory_library_version_number, memory_library_dir_copy);
    reyadeyat_process.memory_process = get_reyadeyat_memory_process(memory_library_dir_copy, memory_library_version_number, reyadeyat_log_list_main);
    if (reyadeyat_process.memory_process == NULL) {
        printf ("Failed running get_reyadeyat_memory_process \"%s\" memory_lib_dir_copy => %s\n", memory_library_version_number, memory_library_dir_copy);
        reyadeyat_log_print_log_list(stream, reyadeyat_log_list_main);
        return 1;
    }
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "Loading Memory Module end");
    reyadeyat_log_print_log_list(stream, reyadeyat_log_list_main);

    //Start Program Processing
    int number = 789542;
    char number_str[30];
    int number_str_length;
    reyadeyat_process.utilities_process->number_to_char("integer", &number, number_str, &number_str_length, &reyadeyat_process, reyadeyat_log_list_main);
    printf ("Calling reyadeyat_utilities_process_0_0_0 integer %d is '%s'\n", number, number_str);

    Reyadeyat_File_Data reyadeyat_file_data;
    reyadeyat_process.file_process->close_memory_file(&reyadeyat_file_data, &reyadeyat_process, reyadeyat_log_list_main);

    Reyadeyat_Memory_Data reyadeyat_memory_data_0_0_0 = {"0.0.0", "Reyadeyat_Memory_Data_0_0_0", 32};
    reyadeyat_process.memory_process->process(&reyadeyat_memory_data_0_0_0, &reyadeyat_process, reyadeyat_log_list_main);

    reyadeyat_process.memory_process->destruct(&reyadeyat_memory_data_0_0_0, &reyadeyat_process, reyadeyat_log_list_main);

    printf("Completed Successfully\n");
    return 0;
}

#elif MODE == INCLUDE

int memory_main(int argc, char **argv) {
    printf ("Calling get_reyadeyat_memory_process 0.0.0 from header file - INCLUDE\n");

    Reyadeyat_Process reyadeyat_process;

    Reyadeyat_Log reyadeyat_log[100];
    Reyadeyat_Log_List *reyadeyat_log_list_main = &((Reyadeyat_Log_List){.size = 10, .cursor = 1, .log_list = reyadeyat_log});
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "Initializing Main Program");

    FILE *stream = stdout;

    //Load Utilities Module
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "Loading Utilities Module start");
    reyadeyat_process.utilities_process = get_reyadeyat_utilities_process("", "0.0.0", reyadeyat_log_list_main);
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "Loading Utilities Module end");

    reyadeyat_log_print_log_list(stream, reyadeyat_log_list_main);

    //Load File Module
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "Loading File Module start");
    reyadeyat_process.file_process = get_reyadeyat_file_process("", "0.0.0", reyadeyat_log_list_main);
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "Loading File Module end");

    reyadeyat_log_print_log_list(stream, reyadeyat_log_list_main);

    //Load Memory Module
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "Loading Memory Module start");
    reyadeyat_process.memory_process = get_reyadeyat_memory_process("", "0.0.0", reyadeyat_log_list_main);
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "Loading Memory Module end");

    reyadeyat_log_print_log_list(stream, reyadeyat_log_list_main);

    //Start Program Processing
    int number = 789542;
    char number_str[30];
    int number_str_length;
    reyadeyat_process.utilities_process->number_to_char("integer", &number, number_str, &number_str_length, &reyadeyat_process, reyadeyat_log_list_main);
    printf ("Calling reyadeyat_utilities_process_0_0_0 integer %d is '%s'\n", number, number_str);

    Reyadeyat_File_Data reyadeyat_file_data;
    reyadeyat_process.file_process->close_memory_file(&reyadeyat_file_data, &reyadeyat_process, reyadeyat_log_list_main);

    Reyadeyat_Memory_Data reyadeyat_memory_data_0_0_0 = {"0.0.0", "Reyadeyat_Memory_Data_0_0_0", 32};
    reyadeyat_process.memory_process->process(&reyadeyat_memory_data_0_0_0, &reyadeyat_process, reyadeyat_log_list_main);

    reyadeyat_process.memory_process->destruct(&reyadeyat_memory_data_0_0_0, &reyadeyat_process, reyadeyat_log_list_main);

    printf("Completed Successfully\n");
    return 0;
}

#endif




int main(int argc, char **argv) {
    memory_main(argc, argv);
}

