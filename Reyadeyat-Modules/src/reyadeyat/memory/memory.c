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

Reyadeyat_Memory_Process *get_reyadeyat_memory_process(char *lib_path, char *version_number, Reyadeyat_Log_List *reyadeyat_log_list_main) {
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __MEMORY_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "Memory Module Loading MODE=LIBRARY loading version \"%s\" lib_path => %s", version_number, lib_path);
    if (strcmp(version_number, "0.0.0") == 0) {
        strcat(lib_path, "/reyadeyat-memory-lib.0.0.0.so");
        printf("lib_path => %s\n", lib_path);
        void *handle = dlopen(lib_path, RTLD_NOW);
        char *dl_error = dlerror();
        if (handle == NULL) {
            reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __MEMORY_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "Memory Module Error Loading lib version \"%s\" file '%s' => %s\n", version_number, lib_path, dl_error);
            return NULL;
        }
        Reyadeyat_Memory_Process *reyadeyat_memory_process = malloc(sizeof(Reyadeyat_Memory_Process));
        reyadeyat_memory_process->construct = dlsym(handle, "external_reyadeyat_memory_construct_v_0_0_0");
        reyadeyat_memory_process->destruct = dlsym(handle, "external_reyadeyat_memory_destruct_v_0_0_0");
        reyadeyat_memory_process->process = dlsym(handle, "external_reyadeyat_memory_process_v_0_0_0");
        reyadeyat_memory_process->create_memory_page = dlsym(handle, "external_reyadeyat_memory_create_memory_page_v_0_0_0");
        reyadeyat_memory_process->init_memory_page = dlsym(handle, "external_reyadeyat_memory_init_memory_page_v_0_0_0");
        reyadeyat_memory_process->fetch_memory_page = dlsym(handle, "external_reyadeyat_memory_fetch_memory_page_v_0_0_0");
        reyadeyat_memory_process->claim_memory_page = dlsym(handle, "external_reyadeyat_memory_claim_memory_page_v_0_0_0");
        reyadeyat_memory_process->copy_memory_page_to_memory_page = dlsym(handle, "external_reyadeyat_memory_copy_memory_page_to_memory_page_v_0_0_0");
        reyadeyat_memory_process->copy_memory_page_to_file_page = dlsym(handle, "external_reyadeyat_memory_copy_memory_page_to_file_page_v_0_0_0");
        reyadeyat_memory_process->copy_file_page_to_memory_page = dlsym(handle, "external_reyadeyat_memory_copy_file_page_to_memory_page_v_0_0_0");
        reyadeyat_memory_process->copy_file_page_to_file_page = dlsym(handle, "external_reyadeyat_memory_copy_file_page_to_file_page_v_0_0_0");
        reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __MEMORY_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "Initializing Memory Module - Done - returning");
        return reyadeyat_memory_process;
    }
    return NULL;
}

#elif MODE == INCLUDE

#include "reyadeyat/memory/memory.0.0.0/external-memory.0.0.0.h"
#include "reyadeyat/utilities/utilities.0.0.0/external-utilities.0.0.0.h"

Reyadeyat_Memory_Process *get_reyadeyat_memory_process(char *lib_path, char *version_number, Reyadeyat_Log_List *reyadeyat_log_list_main) {
    //Reyadeyat_Log reyadeyat_log[100];
    //Reyadeyat_Log_List *reyadeyat_log_list_memory = &((Reyadeyat_Log_List){.size = 10, .cursor = 1, .log_list = reyadeyat_log});
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __MEMORY_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "Initializing Memory Module - Mode INCLUDE defined %d", INCLUDE);
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __MEMORY_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "get_reyadeyat_memory_process lib_path => %s", lib_path);
    if (strcmp(version_number, "0.0.0") == 0) {
        Reyadeyat_Memory_Process *reyadeyat_memory_process = malloc(sizeof(Reyadeyat_Memory_Process));
        reyadeyat_memory_process->construct = external_reyadeyat_memory_construct_v_0_0_0;
        reyadeyat_memory_process->destruct = external_reyadeyat_memory_destruct_v_0_0_0;
        reyadeyat_memory_process->process = external_reyadeyat_memory_process_v_0_0_0;
        reyadeyat_memory_process->create_memory_page = external_reyadeyat_memory_create_memory_page_v_0_0_0;
        reyadeyat_memory_process->init_memory_page = external_reyadeyat_memory_init_memory_page_v_0_0_0;
        reyadeyat_memory_process->fetch_memory_page = external_reyadeyat_memory_fetch_memory_page_v_0_0_0;
        reyadeyat_memory_process->claim_memory_page = external_reyadeyat_memory_claim_memory_page_v_0_0_0;
        reyadeyat_memory_process->copy_memory_page_to_memory_page = external_reyadeyat_memory_copy_memory_page_to_memory_page_v_0_0_0;
        reyadeyat_memory_process->copy_memory_page_to_file_page = external_reyadeyat_memory_copy_memory_page_to_file_page_v_0_0_0;
        reyadeyat_memory_process->copy_file_page_to_memory_page = external_reyadeyat_memory_copy_file_page_to_memory_page_v_0_0_0;
        reyadeyat_memory_process->copy_file_page_to_file_page = external_reyadeyat_memory_copy_file_page_to_file_page_v_0_0_0;
        reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __MEMORY_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "Initializing Memory Module - Done - returning");
        return reyadeyat_memory_process;
    }
    return NULL;
}

#endif



