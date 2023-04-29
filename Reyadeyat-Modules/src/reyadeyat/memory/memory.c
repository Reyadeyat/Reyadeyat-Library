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


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reyadeyat/memory/memory.h"
#include "reyadeyat/reyadeyat.h"

#if MODE == LIBRARY

#include <dlfcn.h>
Reyadeyat_Memory_Process *get_reyadeyat_memory_process(char *lib_path, char *version_number) {
    printf("Mode LIBRARY defined %d\n", LIBRARY);
    printf("get_reyadeyat_memory_process lib_path => %s\n", lib_path);
    if (strcmp(version_number, "0.0.0") == 0) {
        strcat(lib_path, "reyadeyat-memory-lib.0.0.0.so");
        printf("lib_path => %s\n", lib_path);
        void *handle = dlopen(lib_path, RTLD_NOW);
        char *dl_error = dlerror();
        if (handle == NULL) {
            printf("Error Loading lib file '%s' => %s\n", lib_path, dl_error);
            return NULL;
        }
        void (*external_reyadeyat_memory_construct)(Reyadeyat_Memory_Data *);
        void (*external_reyadeyat_memory_destruct)(Reyadeyat_Memory_Data *);
        int (*external_reyadeyat_memory_process)(Reyadeyat_Memory_Data *);
        external_reyadeyat_memory_construct = dlsym(handle, "external_reyadeyat_memory_construct_v_0_0_0");
        external_reyadeyat_memory_destruct = dlsym(handle, "external_reyadeyat_memory_destruct_v_0_0_0");
        external_reyadeyat_memory_process = dlsym(handle, "external_reyadeyat_memory_process_v_0_0_0");
        Reyadeyat_Memory_Process *reyadeyat_memory_process = malloc(sizeof(Reyadeyat_Memory_Process));
        reyadeyat_memory_process->construct = external_reyadeyat_memory_construct;
        reyadeyat_memory_process->destruct = external_reyadeyat_memory_destruct;
        reyadeyat_memory_process->process = external_reyadeyat_memory_process;
        return reyadeyat_memory_process;
    }
    return NULL;
}

#elif MODE == INCLUDE

#include "reyadeyat/memory/memory.0.0.0/external-memory.0.0.0.h"
#include "reyadeyat/memory/memory.0.0.0/external-memory-tools.0.0.0.h"
Reyadeyat_Memory_Process *get_reyadeyat_memory_process(char *lib_path, char *version_number) {
    printf("Mode INCLUDE defined %d\n", INCLUDE);
    printf("get_reyadeyat_memory_process lib_path => %s\n", lib_path);
    if (strcmp(version_number, "0.0.0") == 0) {
        void (*external_reyadeyat_memory_construct)(Reyadeyat_Memory_Data *);
        void (*external_reyadeyat_memory_destruct)(Reyadeyat_Memory_Data *);
        int (*external_reyadeyat_memory_process)(Reyadeyat_Memory_Data *);
        external_reyadeyat_memory_construct = external_reyadeyat_memory_construct_v_0_0_0;
        external_reyadeyat_memory_destruct = external_reyadeyat_memory_destruct_v_0_0_0;
        external_reyadeyat_memory_process = external_reyadeyat_memory_process_v_0_0_0;
        Reyadeyat_Memory_Process *reyadeyat_memory_process = malloc(sizeof(Reyadeyat_Memory_Process));
        reyadeyat_memory_process->construct = external_reyadeyat_memory_construct;
        reyadeyat_memory_process->destruct = external_reyadeyat_memory_destruct;
        reyadeyat_memory_process->process = external_reyadeyat_memory_process;
        return reyadeyat_memory_process;
    }
    return NULL;
}

#endif



