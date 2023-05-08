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

#include "external-memory.0.0.0.h"
#include "internal-memory.0.0.0.h"

void external_reyadeyat_memory_construct_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list) {
    printf("Module A external construct version %s name %s buffer_size %u\n", reyadeyat_memory_data->version,
           reyadeyat_memory_data->name, reyadeyat_memory_data->buffer_size);
}

void external_reyadeyat_memory_destruct_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list) {
    printf("Module A external destruct version %s name %s buffer_size %u\n", reyadeyat_memory_data->version,
           reyadeyat_memory_data->name, reyadeyat_memory_data->buffer_size);
}

void external_reyadeyat_memory_process_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list) {
    printf("Module A external process version %s name %s buffer_size %u\n", reyadeyat_memory_data->version,
           reyadeyat_memory_data->name, reyadeyat_memory_data->buffer_size);
    Reyadeyat_Node_Sequence *abstract_data_structure_algorithm_mem_block = malloc((sizeof *abstract_data_structure_algorithm_mem_block));
    Reyadeyat_Buffer_Block *abstract_data_structure_block = malloc((sizeof *abstract_data_structure_block));

    Reyadeyat_Log reyadeyat_log_memory_process[100];
    Reyadeyat_Log_List *reyadeyat_log_list_memory_process = &((Reyadeyat_Log_List){.size = 100, .cursor = 1, .log_list = reyadeyat_log_memory_process});

    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __MEMORY_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_memory_process, "Reyadeyat Memory Process Log List Initiator");

    internal_reyadeyat_memory_process_0_0_0(reyadeyat_memory_data, (void **) &abstract_data_structure_algorithm_mem_block, (sizeof *abstract_data_structure_algorithm_mem_block), (void **) &abstract_data_structure_block, (sizeof *abstract_data_structure_block), 100, reyadeyat_process, reyadeyat_log_list);

    Reyadeyat_Node_Sequence *abstract_data_structure_algorithm = abstract_data_structure_algorithm_mem_block;
    int count = 0;
    while (abstract_data_structure_algorithm != NULL) {
        Reyadeyat_Buffer_Block *reyadeyat_structure = (Reyadeyat_Buffer_Block*)abstract_data_structure_algorithm->structure;
        printf("node_sequence_buffer_manager[%d].structure %p node_sequence_buffer_manager[%d].next %p\n", count, abstract_data_structure_algorithm->structure, count, abstract_data_structure_algorithm->next);
        printf("reyadeyat_structure[%d].buffer_1='%.*s'\n", count, reyadeyat_structure->buffer_1->size, reyadeyat_structure->buffer_1->buffer);
        printf("reyadeyat_structure[%d].buffer_2='%.*s'\n", count, reyadeyat_structure->buffer_2->size, reyadeyat_structure->buffer_2->buffer);
        printf("reyadeyat_structure[%d].buffer_3='%.*s'\n", count, reyadeyat_structure->buffer_3->size, reyadeyat_structure->buffer_3->buffer);
        abstract_data_structure_algorithm = abstract_data_structure_algorithm->next;
        count++;
    }

    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __MEMORY_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_log_list_memory_process, "Reyadeyat Memory Process Log List End");

    for (int i = 0; i < reyadeyat_log_list_memory_process->cursor; i++) {
        Reyadeyat_Log reyadeyat_log = reyadeyat_log_list_memory_process->log_list[i];
        printf("Reyadeyat Memory log cursor = %d {.file_name = %s, .function_name = %s, .line_number = %d, .log_message=%s}\n",
               reyadeyat_log_list_memory_process->cursor, reyadeyat_log.file_name, reyadeyat_log.function_name, reyadeyat_log.line_number, reyadeyat_log.log_message);
    }
}

void external_reyadeyat_memory_create_memory_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list) {
    internal_reyadeyat_memory_create_memory_page_v_0_0_0(reyadeyat_memory_data, reyadeyat_process, reyadeyat_log_list);
}

void external_reyadeyat_memory_init_memory_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list) {
    internal_reyadeyat_memory_init_memory_page_v_0_0_0(reyadeyat_memory_data, reyadeyat_process, reyadeyat_log_list);
}

void external_reyadeyat_memory_fetch_memory_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list) {
    internal_reyadeyat_memory_fetch_memory_page_v_0_0_0(reyadeyat_memory_data, reyadeyat_process, reyadeyat_log_list);
}

void external_reyadeyat_memory_claim_memory_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list) {
    internal_reyadeyat_memory_claim_memory_page_v_0_0_0(reyadeyat_memory_data, reyadeyat_process, reyadeyat_log_list);
}

void external_reyadeyat_memory_copy_memory_page_to_memory_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list) {
    internal_reyadeyat_memory_copy_memory_page_to_memory_page_v_0_0_0(reyadeyat_memory_data, reyadeyat_process, reyadeyat_log_list);
}

void external_reyadeyat_memory_copy_memory_page_to_file_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list) {
    internal_reyadeyat_memory_copy_memory_page_to_file_page_v_0_0_0(reyadeyat_memory_data, reyadeyat_process, reyadeyat_log_list);
}

void external_reyadeyat_memory_copy_file_page_to_memory_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list) {
    internal_reyadeyat_memory_copy_file_page_to_memory_page_v_0_0_0(reyadeyat_memory_data, reyadeyat_process, reyadeyat_log_list);
}

void external_reyadeyat_memory_copy_file_page_to_file_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process, Reyadeyat_Log_List *reyadeyat_log_list) {
    internal_reyadeyat_memory_copy_file_page_to_file_page_v_0_0_0(reyadeyat_memory_data, reyadeyat_process, reyadeyat_log_list);
}

