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

#include <dlfcn.h>
Reyadeyat_File_Process *get_reyadeyat_file_process(char *lib_path, char *version_number) {
    printf("Mode LIBRARY defined %d\n", LIBRARY);
    printf("get_reyadeyat_file_process lib_path => %s\n", lib_path);
    if (strcmp(version_number, "0.0.0") == 0) {
        strcat(lib_path, "reyadeyat-file-lib.0.0.0.so");
        printf("lib_path => %s\n", lib_path);
        void *handle = dlopen(lib_path, RTLD_NOW);
        char *dl_error = dlerror();
        if (handle == NULL) {
            printf("Error Loading lib file '%s' => %s\n", lib_path, dl_error);
            return NULL;
        }
        Reyadeyat_File_Process *reyadeyat_file_process = malloc(sizeof(Reyadeyat_File_Process));
        reyadeyat_file_process->create_memory_file = dlsym(handle, "external_reyadeyat_file_create_memory_file_v_0_0_0");
        reyadeyat_file_process->copy_memory_file = dlsym(handle, "external_reyadeyat_file_copy_memory_file_v_0_0_0");
        reyadeyat_file_process->save_memory_file = dlsym(handle, "external_reyadeyat_file_save_memory_file_v_0_0_0");
        reyadeyat_file_process->close_memory_file = dlsym(handle, "external_reyadeyat_file_close_memory_file_v_0_0_0");
        return reyadeyat_file_process;
    }
    return NULL;
}

#elif MODE == INCLUDE

#include "reyadeyat/file/file.0.0.0/external-file.0.0.0.h"
#include "reyadeyat/utilities//utilities.0.0.0/external-utilities.0.0.0.h"

Reyadeyat_File_Process *get_reyadeyat_file_process(char *lib_path, char *version_number, Reyadeyat_Log_List *reyadeyat_log_list_main) {
    //Reyadeyat_Log reyadeyat_log[100];
    //Reyadeyat_Log_List *reyadeyat_log_list_memory = &((Reyadeyat_Log_List){.size = 10, .cursor = 1, .log_list = reyadeyat_log});
    reyadeyat_log_add_log_to_list(__LINE__, __func__, __FILE_NAME__, reyadeyat_log_list_main, "Initializing File Module - Mode INCLUDE defined %d", INCLUDE);
    reyadeyat_log_add_log_to_list(__LINE__, __func__, __FILE_NAME__, reyadeyat_log_list_main, "get_reyadeyat_file_process lib_path => %s", lib_path);
    if (strcmp(version_number, "0.0.0") == 0) {
        Reyadeyat_File_Process *reyadeyat_file_process = malloc(sizeof(Reyadeyat_File_Process));
        reyadeyat_file_process->create_memory_file = external_reyadeyat_file_create_memory_file_v_0_0_0;
        reyadeyat_file_process->copy_memory_file = external_reyadeyat_file_copy_memory_file_v_0_0_0;
        reyadeyat_file_process->save_memory_file = external_reyadeyat_file_save_memory_file_v_0_0_0;
        reyadeyat_file_process->close_memory_file = external_reyadeyat_file_close_memory_file_v_0_0_0;
        reyadeyat_log_add_log_to_list(__LINE__, __func__, __FILE_NAME__, reyadeyat_log_list_main, "Initializing File Module - Done - returning");
        return reyadeyat_file_process;
    }
    return NULL;
}

#endif



