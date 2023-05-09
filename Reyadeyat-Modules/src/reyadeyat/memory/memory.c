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

Reyadeyat_Memory_Module *load_reyadeyat_memory_module(char *library_file_path, char *version_number, Reyadeyat_Process *reyadeyat_process) {
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __MEMORY_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process->log_list, "Memory Module Loading MODE=LIBRARY loading version \"%s\" library_file_path => %s", version_number, library_file_path);
    if (strcmp(version_number, "0.0.0") == 0) {
        strcat(library_file_path, "/reyadeyat-memory-lib.0.0.0.so");
        printf("library_file_path => %s\n", library_file_path);
        void *handle = dlopen(library_file_path, RTLD_NOW);
        char *dl_error = dlerror();
        if (handle == NULL) {
            reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __MEMORY_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process->log_list, "Memory Module Error Loading lib version \"%s\" file '%s' => %s\n", version_number, library_file_path, dl_error);
            return NULL;
        }
        Reyadeyat_Memory_Module *reyadeyat_memory_module = malloc(sizeof(Reyadeyat_Memory_Module));
        reyadeyat_memory_module->construct = dlsym(handle, "external_reyadeyat_memory_construct_v_0_0_0");
        reyadeyat_memory_module->destruct = dlsym(handle, "external_reyadeyat_memory_destruct_v_0_0_0");
        reyadeyat_memory_module->process = dlsym(handle, "external_reyadeyat_memory_module_v_0_0_0");
        reyadeyat_memory_module->create_memory_page = dlsym(handle, "external_reyadeyat_memory_create_memory_page_v_0_0_0");
        reyadeyat_memory_module->init_memory_page = dlsym(handle, "external_reyadeyat_memory_init_memory_page_v_0_0_0");
        reyadeyat_memory_module->fetch_memory_page = dlsym(handle, "external_reyadeyat_memory_fetch_memory_page_v_0_0_0");
        reyadeyat_memory_module->claim_memory_page = dlsym(handle, "external_reyadeyat_memory_claim_memory_page_v_0_0_0");
        reyadeyat_memory_module->copy_memory_page_to_memory_page = dlsym(handle, "external_reyadeyat_memory_copy_memory_page_to_memory_page_v_0_0_0");
        reyadeyat_memory_module->copy_memory_page_to_file_page = dlsym(handle, "external_reyadeyat_memory_copy_memory_page_to_file_page_v_0_0_0");
        reyadeyat_memory_module->copy_file_page_to_memory_page = dlsym(handle, "external_reyadeyat_memory_copy_file_page_to_memory_page_v_0_0_0");
        reyadeyat_memory_module->copy_file_page_to_file_page = dlsym(handle, "external_reyadeyat_memory_copy_file_page_to_file_page_v_0_0_0");
        reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __MEMORY_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process->log_list, "Initializing Memory Module - Done - returning");
        return reyadeyat_memory_module;
    }
    return NULL;
}

#elif MODE == INCLUDE

#include "reyadeyat/memory/memory.0.0.0/external-memory.0.0.0.h"
#include "reyadeyat/utilities/utilities.0.0.0/external-utilities.0.0.0.h"

Reyadeyat_Memory_Module *load_reyadeyat_memory_module(char *library_file_path, char *version_number, Reyadeyat_Process *reyadeyat_process) {
    //Reyadeyat_Log reyadeyat_log[100];
    //Reyadeyat_Log_List *reyadeyat_log_list_memory = &((Reyadeyat_Log_List){.size = 10, .cursor = 1, .log_list = reyadeyat_log});
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __MEMORY_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process->log_list, "Initializing Memory Module - Mode INCLUDE defined %d", INCLUDE);
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __MEMORY_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process->log_list, "load_reyadeyat_memory_module library_file_path => %s", library_file_path);
    if (strcmp(version_number, "0.0.0") == 0) {
        Reyadeyat_Memory_Module *reyadeyat_memory_module = malloc(sizeof(Reyadeyat_Memory_Module));
        reyadeyat_memory_module->construct = external_reyadeyat_memory_construct_v_0_0_0;
        reyadeyat_memory_module->destruct = external_reyadeyat_memory_destruct_v_0_0_0;
        reyadeyat_memory_module->process = external_reyadeyat_memory_module_v_0_0_0;
        reyadeyat_memory_module->create_memory_page = external_reyadeyat_memory_create_memory_page_v_0_0_0;
        reyadeyat_memory_module->init_memory_page = external_reyadeyat_memory_init_memory_page_v_0_0_0;
        reyadeyat_memory_module->fetch_memory_page = external_reyadeyat_memory_fetch_memory_page_v_0_0_0;
        reyadeyat_memory_module->claim_memory_page = external_reyadeyat_memory_claim_memory_page_v_0_0_0;
        reyadeyat_memory_module->copy_memory_page_to_memory_page = external_reyadeyat_memory_copy_memory_page_to_memory_page_v_0_0_0;
        reyadeyat_memory_module->copy_memory_page_to_file_page = external_reyadeyat_memory_copy_memory_page_to_file_page_v_0_0_0;
        reyadeyat_memory_module->copy_file_page_to_memory_page = external_reyadeyat_memory_copy_file_page_to_memory_page_v_0_0_0;
        reyadeyat_memory_module->copy_file_page_to_file_page = external_reyadeyat_memory_copy_file_page_to_file_page_v_0_0_0;
        reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __MEMORY_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process->log_list, "Initializing Memory Module - Done - returning");
        return reyadeyat_memory_module;
    }
    return NULL;
}

#endif



