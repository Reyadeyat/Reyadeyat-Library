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

extern Reyadeyat_Utilities_Process *get_reyadeyat_utilities_process(char *lib_path, char *version_number, Reyadeyat_Log_List *reyadeyat_log_list_main) {
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __UTILITIES_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "Utilities Module MODE=LIBRARY loading version \"%s\" lib_path => %s", version_number, lib_path);
    if (strcmp(version_number, "0.0.0") == 0) {
        strcat(lib_path, "/reyadeyat-utilities-lib.0.0.0.so");
        printf("lib_path => %s\n", lib_path);
        void *handle = dlopen(lib_path, RTLD_NOW);
        char *dl_error = dlerror();
        if (handle == NULL) {
            reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __UTILITIES_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "Utilities Module Error Loading lib version \"%s\" file '%s' => %s\n", version_number, lib_path, dl_error);
            return NULL;
        }
        Reyadeyat_Utilities_Process *reyadeyat_utilities_process = malloc(sizeof(Reyadeyat_Utilities_Process));
        reyadeyat_utilities_process->number_to_char = dlsym(handle, "external_reyadeyat_utilities_number_to_char_v_0_0_0");
        return reyadeyat_utilities_process;
    }
    return NULL;
}

#elif MODE == INCLUDE

#include "reyadeyat/utilities/utilities.0.0.0/external-utilities.0.0.0.h"

Reyadeyat_Utilities_Process *get_reyadeyat_utilities_process(char *lib_path, char *version_number, Reyadeyat_Log_List *reyadeyat_log_list_main) {
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __UTILITIES_MODULE__, __FILE_NAME__, __func__, __LINE__,reyadeyat_log_list_main, "Utilities Module Loading MODE=LIBRARY loading version \"%s\" lib_path => %s", version_number, lib_path);
    printf("Mode INCLUDE defined %d\n", INCLUDE);
    printf("get_reyadeyat_utilities_process lib_path => %s\n", lib_path);
    if (strcmp(version_number, "0.0.0") == 0) {
        Reyadeyat_Utilities_Process *reyadeyat_utilities_process = malloc(sizeof *reyadeyat_utilities_process);
        reyadeyat_utilities_process->number_to_char = external_reyadeyat_utilities_number_to_char_v_0_0_0;
        reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __UTILITIES_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_main, "Initializing Utilities Module - Done - returning");
        return reyadeyat_utilities_process;
    }
    return NULL;
}

#endif



