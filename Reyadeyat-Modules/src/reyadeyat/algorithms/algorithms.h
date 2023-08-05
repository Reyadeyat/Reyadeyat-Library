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

#ifndef REYADEYAT_ALGORITHMS_H
#define REYADEYAT_ALGORITHMS_H

REYADEYAT_DATA_TYPE(Reyadeyat_Algorithms_Module) {
    void (*bubble_sort)(uint64_t *dataset_buffer, Reyadeyat_Algorithm_Metric* algorithm_metric, Reyadeyat_Process *reyadeyat_process);
    void (*merge_sort)(uint64_t *dataset_buffer, int64_t left_index, int64_t right_index, Reyadeyat_Algorithm_Metric *algorithm_metric, Reyadeyat_Process *reyadeyat_process);
    void (*quick_sort)(uint64_t *dataset_buffer, int64_t low_index, int64_t high_index, Reyadeyat_Algorithm_Metric *algorithm_metric, Reyadeyat_Process *reyadeyat_process);
};

extern Reyadeyat_Algorithms_Module *load_reyadeyat_algorithms_module(char *library_file_path, char *version_number, Reyadeyat_Process *reyadeyat_process);

#endif //REYADEYAT_ALGORITHMS_H
