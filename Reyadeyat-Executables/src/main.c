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
    char utilities_library_file[2048];
    memcpy(utilities_library_file, lib_path, lib_path_len+1);
    char *utilities_library_file_suffix = "/reyadeyat-utilities-lib.so";
    strncpy(utilities_library_file+lib_path_len-1, utilities_library_file_suffix, strlen(utilities_library_file_suffix));
    printf ("Utilities Library loading file: %s\n", utilities_library_file);
    void* reyadeyat_utilities_module_library = dlopen(utilities_library_file, RTLD_LAZY);
    dl_error = (char*) dlerror();
    if (reyadeyat_utilities_module_library == NULL) {
        printf("Error Loading lib file '%s' => %s\n", lib_path, dl_error);
        return 1;
    }

    //Load File Library
    char file_library_file[2048];
    memcpy(file_library_file, lib_path, lib_path_len);
    char *file_library_file_suffix = "/reyadeyat-file-lib.so";
    strncpy(file_library_file+lib_path_len-1, file_library_file_suffix, strlen(file_library_file_suffix)+1);
    printf ("File Library loading file: %s\n", file_library_file);
    void* reyadeyat_file_module_library = dlopen(file_library_file, RTLD_LAZY);
    dl_error = (char*) dlerror();
    if (reyadeyat_file_module_library == NULL) {
        printf("Error Loading lib file '%s' => %s\n", lib_path, dl_error);
        return 1;
    }

    //Load Memory Library
    char memory_library_file[2048];
    memcpy(memory_library_file, lib_path, lib_path_len);
    char *memory_library_file_suffix = "/reyadeyat-memory-lib.so";
    strncpy(memory_library_file+lib_path_len-1, memory_library_file_suffix, strlen(memory_library_file_suffix)+1);
    printf ("Memory Library loading file: %s\n", memory_library_file);
    void* reyadeyat_memory_module_library = dlopen(memory_library_file, RTLD_LAZY);
    dl_error = (char*) dlerror();
    if (reyadeyat_memory_module_library == NULL) {
        printf("Error Loading lib file '%s' => %s\n", lib_path, dl_error);
        return 1;
    }

    Reyadeyat_Log reyadeyat_log[100];
    //&((Reyadeyat_Log_List){.size = 100, .cursor = 1, .log_list = reyadeyat_log_memory_process});
    Reyadeyat_Log_List reyadeyat_log_list = {.size = 10, .cursor = 1, .log_list = reyadeyat_log};
    Reyadeyat_Kernel reyadeyat_kernel;
    Reyadeyat_Process reyadeyat_process = {.kernel = &reyadeyat_kernel, .log_list = &reyadeyat_log_list};

    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process.log_list, "Initializing Main Program");

    FILE *stream = stdout;

    //Load Utilities Module
    char utilities_library_file_path[1024];
    char *utilities_library_version_number = "0.0.0";
    memcpy(utilities_library_file_path, lib_path, lib_path_len);
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process.log_list, "Loading Utilities Module start");
    //Load Utilities Module Library
    Reyadeyat_Utilities_Module* (*load_reyadeyat_utilities_module)(char *, char *, Reyadeyat_Process *) = dlsym(reyadeyat_utilities_module_library, "load_reyadeyat_utilities_module");
    if (load_reyadeyat_utilities_module == NULL) {
        printf ("Error loading function load_reyadeyat_utilities_module version \"%s\"\n", utilities_library_version_number);
        reyadeyat_log_print_log_list(stream, reyadeyat_process.log_list);
    }
    printf ("Calling load_reyadeyat_utilities_module \"%s\" utilities_library_file_path => %s\n", utilities_library_version_number, utilities_library_file_path);
    reyadeyat_process.kernel->utilities_module = load_reyadeyat_utilities_module(utilities_library_file_path, utilities_library_version_number, &reyadeyat_process);
    if (reyadeyat_process.kernel->utilities_module == NULL) {
        printf ("Failed running load_reyadeyat_utilities_module \"%s\" utilities_library_file_path => %s\n", utilities_library_version_number, utilities_library_file_path);
        reyadeyat_log_print_log_list(stream, reyadeyat_process.log_list);
        return 1;
    }
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process.log_list, "Loading Utilities Module end");
    reyadeyat_log_print_log_list(stream, reyadeyat_process.log_list);

    //Load File Module
    char file_library_file_path[1024];
    char *file_library_version_number = "0.0.0";
    memcpy(file_library_file_path, lib_path, lib_path_len);
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process.log_list, "Loading File Module start");
    //Load File Module Library
    Reyadeyat_File_Module* (*load_reyadeyat_file_module)(char *, char *, Reyadeyat_Process *) = dlsym(reyadeyat_file_module_library, "load_reyadeyat_file_module");
    if (load_reyadeyat_file_module == NULL) {
        printf ("Error loading function load_reyadeyat_file_module version \"%s\"\n", file_library_version_number);
        reyadeyat_log_print_log_list(stream, reyadeyat_process.log_list);
    }
    printf ("Calling load_reyadeyat_file_module \"%s\" file_library_file_path => %s\n", file_library_version_number, file_library_file_path);
    reyadeyat_process.kernel->file_module = load_reyadeyat_file_module(file_library_file_path, file_library_version_number, &reyadeyat_process);
    if (reyadeyat_process.kernel->file_module == NULL) {
        printf ("Failed running load_reyadeyat_file_module \"%s\" file_library_file_path => %s\n", file_library_version_number, file_library_file_path);
        reyadeyat_log_print_log_list(stream, reyadeyat_process.log_list);
        return 1;
    }
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process.log_list, "Loading File Module end");
    reyadeyat_log_print_log_list(stream, reyadeyat_process.log_list);

    //Load Memory Module
    char memory_library_file_path[1024];
    char *memory_library_version_number = "0.0.0";
    memcpy(memory_library_file_path, lib_path, lib_path_len);
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process.log_list, "Loading Memory Module start");
    //Load Memory Module Library
    Reyadeyat_Memory_Module* (*load_reyadeyat_memory_module)(char *, char *, Reyadeyat_Process *) = dlsym(reyadeyat_memory_module_library, "load_reyadeyat_memory_module");
    if (load_reyadeyat_memory_module == NULL) {
        printf ("Error loading function load_reyadeyat_memory_module version \"%s\"\n", memory_library_version_number);
        reyadeyat_log_print_log_list(stream, reyadeyat_process.log_list);
    }
    printf ("Calling load_reyadeyat_memory_module \"%s\" memory_library_file_path => %s\n", memory_library_version_number, memory_library_file_path);
    reyadeyat_process.kernel->memory_module = load_reyadeyat_memory_module(memory_library_file_path, memory_library_version_number, &reyadeyat_process);
    if (reyadeyat_process.kernel->memory_module == NULL) {
        printf ("Failed running load_reyadeyat_memory_module \"%s\" memory_library_file_path => %s\n", memory_library_version_number, memory_library_file_path);
        reyadeyat_log_print_log_list(stream, reyadeyat_process.log_list);
        return 1;
    }
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process.log_list, "Loading Memory Module end");
    reyadeyat_log_print_log_list(stream, reyadeyat_process.log_list);

    //Start Program Processing
    int number = 789542;
    char number_str[30];
    int number_str_length;
    reyadeyat_process.kernel->utilities_module->number_to_char("integer", &number, number_str, &number_str_length, &reyadeyat_process);
    printf ("Calling reyadeyat_utilities_process_0_0_0 integer %d is '%s'\n", number, number_str);

    Reyadeyat_File_Data reyadeyat_file_data;
    reyadeyat_process.kernel->file_module->close_memory_file(&reyadeyat_file_data, &reyadeyat_process);

    Reyadeyat_Memory_Data reyadeyat_memory_data_0_0_0 = {"0.0.0", "Reyadeyat_Memory_Data_0_0_0", 32};
    reyadeyat_process.kernel->memory_module->process(&reyadeyat_memory_data_0_0_0, &reyadeyat_process);

    reyadeyat_process.kernel->memory_module->destruct(&reyadeyat_memory_data_0_0_0, &reyadeyat_process);

    printf("Completed Successfully\n");
    return 0;
}

#elif MODE == INCLUDE

int memory_main(int argc, char **argv) {
    printf ("Calling load_reyadeyat_memory_module 0.0.0 from header file - INCLUDE\n");

    Reyadeyat_Log reyadeyat_log[100];
    //&((Reyadeyat_Log_List){.size = 100, .cursor = 1, .log_list = reyadeyat_log_memory_process});
    Reyadeyat_Log_List reyadeyat_log_list = {.size = 10, .cursor = 1, .log_list = reyadeyat_log};
    Reyadeyat_Kernel reyadeyat_kernel;
    Reyadeyat_Process reyadeyat_process = {.kernel = &reyadeyat_kernel, .log_list = &reyadeyat_log_list};


    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process.log_list, "Initializing Main Program");

    FILE *stream = stdout;

    //Load Utilities Module
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process.log_list, "Loading Utilities Module start");
    reyadeyat_process.kernel->utilities_module = load_reyadeyat_utilities_module("", "0.0.0", &reyadeyat_process);
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process.log_list, "Loading Utilities Module end");

    reyadeyat_log_print_log_list(stream, reyadeyat_process.log_list);

    //Load File Module
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process.log_list, "Loading File Module start");
    reyadeyat_process.kernel->file_module = load_reyadeyat_file_module("", "0.0.0", &reyadeyat_process);
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process.log_list, "Loading File Module end");

    reyadeyat_log_print_log_list(stream, reyadeyat_process.log_list);

    //Load Memory Module
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process.log_list, "Loading Memory Module start");
    reyadeyat_process.kernel->memory_module = load_reyadeyat_memory_module("", "0.0.0", &reyadeyat_process);
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __REYADEYAT_MAIN_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process.log_list, "Loading Memory Module end");

    reyadeyat_log_print_log_list(stream, reyadeyat_process.log_list);

    //Start Program Processing
    int number = 789542;
    char number_str[30];
    int number_str_length;
    reyadeyat_process.kernel->utilities_module->number_to_char("integer", &number, number_str, &number_str_length, &reyadeyat_process);
    printf ("Calling reyadeyat_utilities_process_0_0_0 integer %d is '%s'\n", number, number_str);

    Reyadeyat_File_Data reyadeyat_file_data;
    reyadeyat_process.kernel->file_module->close_memory_file(&reyadeyat_file_data, &reyadeyat_process);

    Reyadeyat_Memory_Data reyadeyat_memory_data_0_0_0 = {"0.0.0", "Reyadeyat_Memory_Data_0_0_0", 32};
    reyadeyat_process.kernel->memory_module->process(&reyadeyat_memory_data_0_0_0, &reyadeyat_process);

    reyadeyat_process.kernel->memory_module->destruct(&reyadeyat_memory_data_0_0_0, &reyadeyat_process);

    printf("Completed Successfully\n");
    return 0;
}

#endif




int main(int argc, char **argv) {
    memory_main(argc, argv);
}

