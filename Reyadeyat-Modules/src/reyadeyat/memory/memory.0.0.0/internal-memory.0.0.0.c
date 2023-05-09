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

#include "internal-memory.0.0.0.h"

void internal_reyadeyat_memory_module_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, void **abstract_data_structure_algorithm_mem_block, int abstract_data_structure_algorithm_mem_block_struct_length, void **abstract_data_structure_block, int abstract_data_structure_block_length, int size, Reyadeyat_Process *reyadeyat_process) {
    //Abstract Data Structure Algorithm Memory Block
    //Reyadeyat_Node_Sequence *abstract_data_structure_algorithm_mem_block = malloc((sizeof *abstract_data_structure_algorithm_mem_block) * 100);
    *abstract_data_structure_algorithm_mem_block = malloc(abstract_data_structure_algorithm_mem_block_struct_length * size);
    //Abstract Data Structure Buffer
    //Reyadeyat_Buffer_Block *abstract_data_structure_block = malloc((sizeof *abstract_data_structure_block) * 100);
    *abstract_data_structure_block = malloc(abstract_data_structure_block_length * size);
    //Data Structure Instance Buffer
    printf("Reyadeyat_Buffer size=%lu\n", sizeof(Reyadeyat_Buffer));
    long data_buffer_size_1 = (sizeof(Reyadeyat_Buffer)+(sizeof(char)*1024*1024))*100;
    long data_buffer_size_2 = (sizeof(Reyadeyat_Buffer)+(sizeof(char)*1024*1024*4))*100;
    long data_buffer_size_3 = (sizeof(Reyadeyat_Buffer)+(sizeof(char)*1024*1024*16))*100;

    struct timespec t1, t2;
    clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
    void *data_buffer_1 = malloc(data_buffer_size_1);
    void *data_buffer_2 = malloc(data_buffer_size_2);
    void *data_buffer_3 = malloc(data_buffer_size_3);

    struct timespec deadline;
    clock_gettime(CLOCK_MONOTONIC, &deadline);
    //deadline.tv_sec += 5;
    //validate if is correct
    //    pagesof 4k memory
    /*deadline.tv_nsec += 4000000;//1 millisecond = 1000000 nanoseconds
    if(deadline.tv_nsec >= 1000000000) {
        deadline.tv_nsec -= 1000000000;
        deadline.tv_sec++;
    }*/
    clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &deadline, NULL);
    clock_gettime(CLOCK_MONOTONIC_RAW, &t2);
    uint64_t differens_nano = (t2.tv_sec - t1.tv_sec) * 1000000 + (t2.tv_nsec - t1.tv_nsec) / 1000;
    //uint64_t differens_milli = differens_nano / 1000;
    uint64_t differens_milli = (t2.tv_sec - t1.tv_sec) * 1000 + (t2.tv_nsec - t1.tv_nsec) / 1000000;
    printf("Malloc time %lu nano seconds\n", differens_nano);
    printf("Malloc time %lu milli seconds\n", differens_milli);
    printf("data_buffer_1 size=%lu\n", data_buffer_size_1);
    printf("data_buffer_2 size=%lu\n", data_buffer_size_2);
    printf("data_buffer_3 size=%lu\n", data_buffer_size_3);
    unsigned long pointer_address_1;
    unsigned long pointer_address_2;
    unsigned long pointer_address_3;
    for (int i = 0; i < 100; i++) {
        Reyadeyat_Node_Sequence *abstract_data_structure_algorithm = *abstract_data_structure_algorithm_mem_block+(abstract_data_structure_algorithm_mem_block_struct_length*i);
        abstract_data_structure_algorithm->structure = *abstract_data_structure_block+(abstract_data_structure_block_length*i);
        abstract_data_structure_algorithm->next = i + 1 == 100 ? NULL : *abstract_data_structure_algorithm_mem_block+(abstract_data_structure_algorithm_mem_block_struct_length*(i+1));
        printf("node_sequence_buffer_manager[%d].structure %p node_sequence_buffer_manager[%d].next %p\n", i, abstract_data_structure_algorithm->structure, i, abstract_data_structure_algorithm->next);

        Reyadeyat_Buffer_Block *reyadeyat_structure_pointer = abstract_data_structure_algorithm->structure;

        char output_buffer[128];
        int number = 0;

        pointer_address_1 = (i*(sizeof(Reyadeyat_Buffer)+(sizeof(char)*10)));
        reyadeyat_structure_pointer->buffer_1 = (Reyadeyat_Buffer*)(data_buffer_1+pointer_address_1);
        reyadeyat_structure_pointer->buffer_1->size = 10;
        reyadeyat_structure_pointer->buffer_1->buffer = (char*)(data_buffer_1+pointer_address_1+sizeof(Reyadeyat_Buffer));
        number = i*10;
        reyadeyat_process->kernel->utilities_module->number_to_char("integer", &number, output_buffer, &reyadeyat_structure_pointer->buffer_1->size, reyadeyat_process);
        memcpy(reyadeyat_structure_pointer->buffer_1->buffer, output_buffer, reyadeyat_structure_pointer->buffer_1->size);
        printf("data_buffer_1[%d] size=%lu - reyadeyat_structure[%d].buffer_1='%.*s'\n", i, pointer_address_1, i, reyadeyat_structure_pointer->buffer_1->size, reyadeyat_structure_pointer->buffer_1->buffer);

        pointer_address_2 = (i*(sizeof(Reyadeyat_Buffer)+(sizeof(char)*100)));
        reyadeyat_structure_pointer->buffer_2 = (Reyadeyat_Buffer*)(data_buffer_2+pointer_address_2);
        reyadeyat_structure_pointer->buffer_2->size = 100;
        reyadeyat_structure_pointer->buffer_2->buffer = (char*)(data_buffer_2+pointer_address_2+sizeof(Reyadeyat_Buffer));
        number = i*100;
        reyadeyat_process->kernel->utilities_module->number_to_char("integer", &number, output_buffer, &reyadeyat_structure_pointer->buffer_2->size, reyadeyat_process);
        memcpy(reyadeyat_structure_pointer->buffer_2->buffer, output_buffer, reyadeyat_structure_pointer->buffer_2->size);
        printf("data_buffer_2[%d] size=%lu - reyadeyat_structure[%d].buffer_2='%.*s'\n", i, pointer_address_2, i, reyadeyat_structure_pointer->buffer_2->size, reyadeyat_structure_pointer->buffer_2->buffer);

        pointer_address_3 = (i*(sizeof(Reyadeyat_Buffer)+(sizeof(char)*1000)));
        reyadeyat_structure_pointer->buffer_3 = (Reyadeyat_Buffer*)(data_buffer_3+pointer_address_3);
        reyadeyat_structure_pointer->buffer_3->size = 1000;
        reyadeyat_structure_pointer->buffer_3->buffer = (char*)(data_buffer_3+pointer_address_3+sizeof(Reyadeyat_Buffer));
        number = i*1000;
        reyadeyat_process->kernel->utilities_module->number_to_char("integer", &number, output_buffer, &reyadeyat_structure_pointer->buffer_3->size, reyadeyat_process);
        memcpy(reyadeyat_structure_pointer->buffer_3->buffer, output_buffer, reyadeyat_structure_pointer->buffer_3->size);
        printf("data_buffer_3[%d] size=%lu - reyadeyat_structure[%d].buffer_3='%.*s'\n", i, pointer_address_3, i, reyadeyat_structure_pointer->buffer_3->size, reyadeyat_structure_pointer->buffer_3->buffer);
    }

    printf("data_buffer_1 size=%lu consumed=%lu\n", data_buffer_size_1, pointer_address_1 + (sizeof(Reyadeyat_Buffer)+(sizeof(char)*10)));
    printf("data_buffer_2 size=%lu consumed=%lu\n", data_buffer_size_2, pointer_address_2 + (sizeof(Reyadeyat_Buffer)+(sizeof(char)*100)));
    printf("data_buffer_3 size=%lu consumed=%lu\n", data_buffer_size_3, pointer_address_3 + (sizeof(Reyadeyat_Buffer)+(sizeof(char)*1000)));

    Reyadeyat_Node_Sequence *abstract_data_structure_algorithm = *abstract_data_structure_algorithm_mem_block;
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

    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __FILE_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process->log_list,
                                  "Reyadeyat Memory Process internal process version %s name %s buffer_size %u",
                                  reyadeyat_memory_data->version, reyadeyat_memory_data->name, reyadeyat_memory_data->buffer_size);

    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __MEMORY_MODULE__, __FILE_NAME__, __func__, __LINE__,reyadeyat_process->log_list, "Reyadeyat Memory Process Finished Initial Test");
}


void internal_reyadeyat_memory_create_memory_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process) {
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __FILE_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process->log_list, "function '%s' not implemented yet", __func__);
}

void internal_reyadeyat_memory_init_memory_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process) {
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __FILE_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process->log_list, "function '%s' not implemented yet", __func__);
}

void internal_reyadeyat_memory_fetch_memory_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process) {
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __FILE_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process->log_list, "function '%s' not implemented yet", __func__);
}

void internal_reyadeyat_memory_claim_memory_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process) {
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __FILE_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process->log_list, "function '%s' not implemented yet", __func__);
}

void internal_reyadeyat_memory_copy_memory_page_to_memory_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process) {
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __FILE_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process->log_list, "function '%s' not implemented yet", __func__);
}

void internal_reyadeyat_memory_copy_memory_page_to_file_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process) {
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __FILE_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process->log_list, "function '%s' not implemented yet", __func__);
}

void internal_reyadeyat_memory_copy_file_page_to_memory_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process) {
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __FILE_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process->log_list, "function '%s' not implemented yet", __func__);
}

void internal_reyadeyat_memory_copy_file_page_to_file_page_v_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process) {
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __FILE_MODULE__, __FILE_NAME__, __func__, __LINE__, reyadeyat_process->log_list, "function '%s' not implemented yet", __func__);
}


