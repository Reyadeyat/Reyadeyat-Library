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

#ifndef REYADEYAT_INTERNAL_MEMORY_0_0_0_H
#define REYADEYAT_INTERNAL_MEMORY_0_0_0_H

#include "reyadeyat/reyadeyat.h"

void internal_reyadeyat_memory_process_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, void **abstract_data_structure_algorithm_mem_block, int abstract_data_structure_algorithm_mem_block_struct_length, void **abstract_data_structure_block, int abstract_data_structure_block_length, int size, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list);

void internal_reyadeyat_memory_create_memory_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list);
void internal_reyadeyat_memory_init_memory_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list);
void internal_reyadeyat_memory_fetch_memory_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list);
void internal_reyadeyat_memory_claim_memory_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list);
void internal_reyadeyat_memory_copy_memory_page_to_memory_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list);
void internal_reyadeyat_memory_copy_memory_page_to_file_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list);
void internal_reyadeyat_memory_copy_file_page_to_memory_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list);
void internal_reyadeyat_memory_copy_file_page_to_file_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list);

#endif //REYADEYAT_C_MEMORY_MEMORY_INTERNAL_0_0_0_H
