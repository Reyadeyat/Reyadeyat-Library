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

extern Reyadeyat_Algorithms_Module *load_reyadeyat_algorithms_module(char *library_file_path, char *version_number, Reyadeyat_Process *reyadeyat_process) {
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __ALGORITHMS_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process->log_list, "Utilities Module MODE=LIBRARY loading version \"%s\" library_file_path => %s", version_number, library_file_path);
    if (strcmp(version_number, "0.0.0") == 0) {
        strcat(library_file_path, "/reyadeyat-algorithms-lib.0.0.0.so");
        printf("library_file_path => %s\n", library_file_path);
        void *handle = dlopen(library_file_path, RTLD_NOW);
        char *dl_error = dlerror();
        if (handle == NULL) {
            reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __ALGORITHMS_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process->log_list, "Utilities Module Error Loading lib version \"%s\" file '%s' => %s\n", version_number, library_file_path, dl_error);
            return NULL;
        }
        Reyadeyat_Algorithms_Module *reyadeyat_algorithms_module = malloc(sizeof(Reyadeyat_Algorithms_Module));
        reyadeyat_algorithms_module->bubble_sort = dlsym(handle, "bubble_sort_v_0_0_0");
        reyadeyat_algorithms_module->merge_sort = dlsym(handle, "merge_sort_v_0_0_0");
        return reyadeyat_algorithms_module;
    }
    return NULL;
}

#elif MODE == INCLUDE

#include "reyadeyat/algorithms/algorithms.0.0.0/algorithms.0.0.0.h"

Reyadeyat_Algorithms_Module *load_reyadeyat_algorithms_module(char *library_file_path, char *version_number, Reyadeyat_Process *reyadeyat_process) {
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __ALGORITHMS_MODULE__, __FILE_NAME__, __func__, __LINE__,reyadeyat_process->log_list, "Utilities Module Loading MODE=LIBRARY loading version \"%s\" library_file_path => %s", version_number, library_file_path);
    printf("Mode INCLUDE defined %d\n", INCLUDE);
    printf("load_reyadeyat_algorithms_module library_file_path => %s\n", library_file_path);
    if (strcmp(version_number, "0.0.0") == 0) {
        Reyadeyat_Algorithms_Module *reyadeyat_algorithms_module = malloc(sizeof *reyadeyat_algorithms_module);
        reyadeyat_algorithms_module->bubble_sort = bubble_sort_v_0_0_0;
        reyadeyat_algorithms_module->merge_sort = merge_sort_v_0_0_0;
        reyadeyat_algorithms_module->quick_sort = quick_sort_v_0_0_0;
        reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __ALGORITHMS_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process->log_list, "Initializing Utilities Module - Done - returning");
        return reyadeyat_algorithms_module;
    }
    return NULL;
}

#endif



