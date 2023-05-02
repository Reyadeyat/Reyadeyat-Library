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

#include "internal-memory.0.0.0.h"
#include "reyadeyat/utilities/utilities.0.0.0/external-utilities.0.0.0.h"

void internal_reyadeyat_memory_process_0_0_0(Reyadeyat_Memory_Data *reyadeyat_memory_data) {
    //Abstract Data Structure Algorithm Memory Block
    Reyadeyat_Node_Sequence *abstract_data_structure_algorithm_mem_block = malloc((sizeof *abstract_data_structure_algorithm_mem_block) * 100);
    //Abstract Data Structure Buffer
    Reyadeyat_Buffer_Block *abstract_data_structure_block = malloc((sizeof *abstract_data_structure_block) * 100);
    //Data Structure Instance Buffer
    printf("Reyadeyat_Buffer size=%lu\n", sizeof(Reyadeyat_Buffer));
    long data_buffer_size_1 = (sizeof(Reyadeyat_Buffer)+(sizeof(char)*10))*100;
    long data_buffer_size_2 = (sizeof(Reyadeyat_Buffer)+(sizeof(char)*100))*100;
    long data_buffer_size_3 = (sizeof(Reyadeyat_Buffer)+(sizeof(char)*1000))*100;
    void *data_buffer_1 = malloc(data_buffer_size_1);
    void *data_buffer_2 = malloc(data_buffer_size_2);
    void *data_buffer_3 = malloc(data_buffer_size_3);
    printf("data_buffer_1 size=%lu\n", data_buffer_size_1);
    printf("data_buffer_2 size=%lu\n", data_buffer_size_2);
    printf("data_buffer_3 size=%lu\n", data_buffer_size_3);
    unsigned long pointer_address_1;
    unsigned long pointer_address_2;
    unsigned long pointer_address_3;
    for (int i = 0; i < 100; i++) {
        Reyadeyat_Node_Sequence *abstract_data_structure_algorithm = abstract_data_structure_algorithm_mem_block+i;
        abstract_data_structure_algorithm->structure = abstract_data_structure_block+i;
        abstract_data_structure_algorithm->next = i + 1 == 100 ? NULL : abstract_data_structure_algorithm_mem_block+i+1;
        printf("node_sequence_buffer_manager[%d].structure %p node_sequence_buffer_manager[%d].next %p\n", i, abstract_data_structure_algorithm->structure, i, abstract_data_structure_algorithm->next);

        Reyadeyat_Buffer_Block *reyadeyat_structure_pointer = abstract_data_structure_algorithm->structure;

        char output_buffer[128];
        int number = 0;

        pointer_address_1 = (i*(sizeof(Reyadeyat_Buffer)+(sizeof(char)*10)));
        reyadeyat_structure_pointer->buffer_1 = (Reyadeyat_Buffer*)(data_buffer_1+pointer_address_1);
        reyadeyat_structure_pointer->buffer_1->size = 10;
        reyadeyat_structure_pointer->buffer_1->buffer = (char*)(data_buffer_1+pointer_address_1+sizeof(Reyadeyat_Buffer));
        number = i*10;
        external_reyadeyat_utilities_number_to_char_v_0_0_0("integer", &number, output_buffer, &reyadeyat_structure_pointer->buffer_1->size);
        memcpy(reyadeyat_structure_pointer->buffer_1->buffer, output_buffer, reyadeyat_structure_pointer->buffer_1->size);
        printf("data_buffer_1[%d] size=%lu - reyadeyat_structure[%d].buffer_1='%.*s'\n", i, pointer_address_1, i, reyadeyat_structure_pointer->buffer_1->size, reyadeyat_structure_pointer->buffer_1->buffer);

        pointer_address_2 = (i*(sizeof(Reyadeyat_Buffer)+(sizeof(char)*100)));
        reyadeyat_structure_pointer->buffer_2 = (Reyadeyat_Buffer*)(data_buffer_2+pointer_address_2);
        reyadeyat_structure_pointer->buffer_2->size = 100;
        reyadeyat_structure_pointer->buffer_2->buffer = (char*)(data_buffer_2+pointer_address_2+sizeof(Reyadeyat_Buffer));
        number = i*100;
        external_reyadeyat_utilities_number_to_char_v_0_0_0("integer", &number, output_buffer, &reyadeyat_structure_pointer->buffer_2->size);
        memcpy(reyadeyat_structure_pointer->buffer_2->buffer, output_buffer, reyadeyat_structure_pointer->buffer_2->size);
        printf("data_buffer_2[%d] size=%lu - reyadeyat_structure[%d].buffer_2='%.*s'\n", i, pointer_address_2, i, reyadeyat_structure_pointer->buffer_2->size, reyadeyat_structure_pointer->buffer_2->buffer);

        pointer_address_3 = (i*(sizeof(Reyadeyat_Buffer)+(sizeof(char)*1000)));
        reyadeyat_structure_pointer->buffer_3 = (Reyadeyat_Buffer*)(data_buffer_3+pointer_address_3);
        reyadeyat_structure_pointer->buffer_3->size = 1000;
        reyadeyat_structure_pointer->buffer_3->buffer = (char*)(data_buffer_3+pointer_address_3+sizeof(Reyadeyat_Buffer));
        number = i*1000;
        external_reyadeyat_utilities_number_to_char_v_0_0_0("integer", &number, output_buffer, &reyadeyat_structure_pointer->buffer_3->size);
        memcpy(reyadeyat_structure_pointer->buffer_3->buffer, output_buffer, reyadeyat_structure_pointer->buffer_3->size);
        printf("data_buffer_3[%d] size=%lu - reyadeyat_structure[%d].buffer_3='%.*s'\n", i, pointer_address_3, i, reyadeyat_structure_pointer->buffer_3->size, reyadeyat_structure_pointer->buffer_3->buffer);
    }

    printf("data_buffer_1 size=%lu consumed=%lu\n", data_buffer_size_1, pointer_address_1 + (sizeof(Reyadeyat_Buffer)+(sizeof(char)*10)));
    printf("data_buffer_2 size=%lu consumed=%lu\n", data_buffer_size_2, pointer_address_2 + (sizeof(Reyadeyat_Buffer)+(sizeof(char)*100)));
    printf("data_buffer_3 size=%lu consumed=%lu\n", data_buffer_size_3, pointer_address_3 + (sizeof(Reyadeyat_Buffer)+(sizeof(char)*1000)));

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

    printf("Module A internal process version %s name %s buffer_size %u\n", reyadeyat_memory_data->version,
           reyadeyat_memory_data->name, reyadeyat_memory_data->buffer_size);
}