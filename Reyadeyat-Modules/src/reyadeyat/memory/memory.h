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

#ifndef REYADEYAT_MEMORY_H
#define REYADEYAT_MEMORY_H

REYADEYAT_DATA_TYPE(Reyadeyat_Memory_Module) {
    void (*construct)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process);
    void (*destruct)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process);
    void (*module)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process);
    void (*process)(Reyadeyat_Memory_Data *reyadeyat_memory_data, void **abstract_data_structure_algorithm_mem_block, int abstract_data_structure_algorithm_mem_block_struct_length, void **abstract_data_structure_block, int abstract_data_structure_block_length, int size, Reyadeyat_Process *reyadeyat_process);
    void (*create_memory_book)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process);
    void (*create_memory_page)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process);
    void (*init_memory_page)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process);
    void (*fetch_memory_page)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process);
    void (*claim_memory_page)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process);
    void (*copy_memory_page_to_memory_page)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process);
    void (*copy_memory_page_to_file_page)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process);
    void (*copy_file_page_to_memory_page)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process);
    void (*copy_file_page_to_file_page)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process);
    void (*flush_memory_page)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process);
    void (*flush_memory_book)(Reyadeyat_Memory_Data *reyadeyat_memory_data, Reyadeyat_Process *reyadeyat_process);
};

extern Reyadeyat_Memory_Module* load_reyadeyat_memory_module(char* library_file_path, char *version_number, Reyadeyat_Process *reyadeyat_process);

#endif //REYADEYAT_MEMORY_H
