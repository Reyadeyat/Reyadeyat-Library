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

#ifndef REYADEYAT_H
#define REYADEYAT_H

#include <inttypes.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <stdint.h>
#include <assert.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct Reyadeyat_Process Reyadeyat_Process;

#include "reyadeyat/core.h"
#include "reyadeyat/log/log.h"
#include "reyadeyat/utilities/utilities-data-structures.h"
#include "reyadeyat/utilities/utilities.h"
#include "reyadeyat/algorithms/algorithms-data-structures.h"
#include "reyadeyat/algorithms/algorithms.h"
#include "reyadeyat/data-structures/data-structures-data-structures.h"
#include "reyadeyat/data-structures/data-structures.h"
#include "reyadeyat/file/file-data-structures.h"
#include "reyadeyat/file/file.h"
#include "reyadeyat/memory/memory-data-structures.h"
#include "reyadeyat/memory/memory.h"
#include "reyadeyat/computer/computer-data-structures.h"
#include "reyadeyat/computer/computer.h"

//MODE {LIBRARY, INCLUDE}
#define LIBRARY 1
#define INCLUDE 2

#ifndef MODE
#define MODE INCLUDE
#endif

//BUILD {DEBUG, RELEASE}
#define DEBUG 1
#define RELEASE 2

#ifndef BUILD
#define BUILD DEBUG
#endif

REYADEYAT_DATA_TYPE(Reyadeyat_Kernel) {
    Reyadeyat_Utilities_Module *utilities_module;
    Reyadeyat_Algorithms_Module *algorithms_module;
    Reyadeyat_Data_Structures_Module *data_structures_module;
    Reyadeyat_File_Module *file_module;
    Reyadeyat_Memory_Module *memory_module;
};

REYADEYAT_DATA_TYPE(Reyadeyat_Process) {
    Reyadeyat_Kernel *kernel;
    Reyadeyat_Log_List *log_list;
};

REYADEYAT_DATA_TYPE(ReyadeyatADSPage) {
    unsigned int weight;
    void *abstract_data_type;
};

#endif //REYADEYAT_H
