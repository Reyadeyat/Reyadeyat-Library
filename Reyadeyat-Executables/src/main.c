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
#include <dlfcn.h>

#include "reyadeyat/memory/memory.h"
#include "reyadeyat/reyadeyat.h"

#if MODE == LIBRARY

int memory_main(int argc, char **argv) {
    printf ("Calling get_reyadeyat_memory_process 0.0.0 from library file - LIBRARY\n");
    int len = 1024;
    char *path = malloc(sizeof(char)*len);
#if BUILD == DEBUG
    char* p = "./Reyadeyat-C-Executable/bin/reyadeyat-c";
    memcpy(path, p, strlen(p)+1);;
#else
    memcpy(path, argv[0], strlen(argv[0])+1);
#endif
    printf ("Program dir: %s\n", path);
    char *start = strstr(path, "/bin");
    char *lib_dir = "/lib/reyadeyat-memory-lib.so";
    strncpy(start, lib_dir, strlen(lib_dir)+1);
    printf ("Lib dir: %s\n", path);
    void* handle = dlopen(path, RTLD_LAZY);
    char* dl_error = (char*) dlerror();
    if (handle == NULL) {
        printf("Error Loading lib file '%s' => %s\n", path, dl_error);
    } else {

        int ret;
        start[5]='\0';
        printf ("Lib dir prefix is : %s\n", path);

        Reyadeyat_Memory_Process* (*get_reyadeyat_memory_process)(char *, char *);
        get_reyadeyat_memory_process = dlsym(handle, "get_reyadeyat_memory_process");
        if (get_reyadeyat_memory_process == NULL) {
            printf ("Error loading function get_reyadeyat_memory_process\n");
        }

        char path_copy[len];
        memcpy(path_copy, path, strlen(path)+1);
        printf ("Calling get_reyadeyat_memory_process 0.0.0 path => %s\n", path_copy);
        Reyadeyat_Memory_Process* reyadeyat_memory_process_0_0_0 = get_reyadeyat_memory_process((char*) path_copy, "0.0.0");
        Reyadeyat_Memory_Data reyadeyat_memory_data_0_0_0 = {"0.0.0", "Reyadeyat_Memory_Data_0_0_0", 32};
        ret = reyadeyat_memory_process_0_0_0->process(&reyadeyat_memory_data_0_0_0);
        if (ret < 0) {
            perror("Error: reyadeyat_memory_process_0_0_0->process\n");
            ret = -1;
            goto error_0_0_0;
        }

        /*memcpy(path_copy, path, strlen(path)+1);
        printf ("Calling get_reyadeyat_memory_process 0.0.1 path => %s\n", path_copy);
        Reyadeyat_Memory_Process* reyadeyat_memory_process_0_0_1 = get_reyadeyat_memory_process((char*) path_copy, "0.0.1");
        Reyadeyat_Memory_Data reyadeyat_memory_data_0_0_1 = {"0.0.1", "Module_A_Data_0_0_1", 0, 64};
        ret = reyadeyat_memory_process_0_0_1->process(&reyadeyat_memory_data_0_0_1);

        if (ret < 0) {
            perror("Error: reyadeyat_memory_process_0_0_1->process\n");
            ret = -1;
            goto error_0_0_1;
        }*/

        goto error0;

        /*error_0_0_1:
        printf("Error in reyadeyat_memory_process_0_0_1 ret=%d\n",ret);
        reyadeyat_memory_process_0_0_1->destruct(&reyadeyat_memory_data_0_0_1);*/
        error_0_0_0:
        printf("Error in reyadeyat_memory_process_0_0_0 ret=%d\n",ret);
        reyadeyat_memory_process_0_0_0->destruct(&reyadeyat_memory_data_0_0_0);
        error0:
        printf("Completed Successfully\n");
        return ret;
    }
    return 0;
}

#elif MODE == INCLUDE

int memory_main(int argc, char **argv) {
    int ret;
    printf ("Calling get_reyadeyat_memory_process 0.0.0 from header file - INCLUDE\n");
    Reyadeyat_Memory_Process* reyadeyat_memory_process_0_0_0 = get_reyadeyat_memory_process("", "0.0.0");
    Reyadeyat_Memory_Data reyadeyat_memory_data_0_0_0 = {"0.0.0", "Reyadeyat_Memory_Data_0_0_0", 32};
    ret = reyadeyat_memory_process_0_0_0->process(&reyadeyat_memory_data_0_0_0);
    if (ret < 0) {
        perror("Error: reyadeyat_memory_process_0_0_0->process\n");
        ret = -1;
        goto error_0_0_0;
    }

    /*memcpy(path_copy, path, strlen(path)+1);
    printf ("Calling get_reyadeyat_memory_process 0.0.1 path => %s\n", path_copy);
    Reyadeyat_Memory_Process* reyadeyat_memory_process_0_0_1 = get_reyadeyat_memory_process((char*) path_copy, "0.0.1");
    Reyadeyat_Memory_Data reyadeyat_memory_data_0_0_1 = {"0.0.1", "Module_A_Data_0_0_1", 0, 64};
    ret = reyadeyat_memory_process_0_0_1->process(&reyadeyat_memory_data_0_0_1);

    if (ret < 0) {
        perror("Error: reyadeyat_memory_process_0_0_1->process\n");
        ret = -1;
        goto error_0_0_1;
    }*/

    goto error0;

    /*error_0_0_1:
    printf("Error in reyadeyat_memory_process_0_0_1 ret=%d\n",ret);
    reyadeyat_memory_process_0_0_1->destruct(&reyadeyat_memory_data_0_0_1);*/
    error_0_0_0:
    printf("Error in reyadeyat_memory_process_0_0_0 ret=%d\n",ret);
    reyadeyat_memory_process_0_0_0->destruct(&reyadeyat_memory_data_0_0_0);
    error0:
    printf("Completed Successfully\n");
    return ret;
}

#endif




int main(int argc, char **argv) {
    memory_main(argc, argv);
}

