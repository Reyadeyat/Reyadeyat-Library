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

#ifndef REYADEYAT_FILE_H
#define REYADEYAT_FILE_H

REYADEYAT_DATA_TYPE(Reyadeyat_File_Module) {
    void (*create_memory_file)(Reyadeyat_File_Data *reyadeyat_file_data, Reyadeyat_Process *reyadeyat_process);
    void (*copy_memory_file)(Reyadeyat_File_Data *reyadeyat_file_data, Reyadeyat_Process *reyadeyat_process);
    void (*save_memory_file)(Reyadeyat_File_Data *reyadeyat_file_data, Reyadeyat_Process *reyadeyat_process);
    void (*close_memory_file)(Reyadeyat_File_Data *reyadeyat_file_data, Reyadeyat_Process *reyadeyat_process);
};

extern Reyadeyat_File_Module* load_reyadeyat_file_module(char* library_file_path, char *version_number, Reyadeyat_Process *reyadeyat_process);

#endif //REYADEYAT_FILE_H
