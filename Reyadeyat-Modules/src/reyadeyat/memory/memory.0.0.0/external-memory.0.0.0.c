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

#include "external-memory.0.0.0.h"
#include "internal-memory.0.0.0.h"

void external_reyadeyat_memory_construct_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data) {
    printf("Module A external construct version %s name %s buffer_size %u\n", reyadeyat_memory_data->version,
           reyadeyat_memory_data->name, reyadeyat_memory_data->buffer_size);
}

void external_reyadeyat_memory_destruct_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data) {
    printf("Module A external destruct version %s name %s buffer_size %u\n", reyadeyat_memory_data->version,
           reyadeyat_memory_data->name, reyadeyat_memory_data->buffer_size);
}

int external_reyadeyat_memory_process_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data) {
    printf("Module A external process version %s name %s buffer_size %u\n", reyadeyat_memory_data->version,
           reyadeyat_memory_data->name, reyadeyat_memory_data->buffer_size);
    internal_reyadeyat_memory_process_0_0_0(reyadeyat_memory_data);
    return 0;
}
