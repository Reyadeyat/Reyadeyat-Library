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

#include "algorithms.0.0.0.h"

void swap(uint64_t *a, uint64_t *b, Reyadeyat_Algorithm_Metric *algorithm_metric, Reyadeyat_Process *reyadeyat_process) {
    int temp = *a;
    *a = *b;
    *b = temp;
    algorithm_metric->instruction_count += 0/*methods*/ + 0/*loop*/ + 3/*instructions*/ + 0/*condition*/;
}

void bubble_sort_v_0_0_0(uint64_t *dataset_buffer, Reyadeyat_Algorithm_Metric *algorithm_metric,
                         Reyadeyat_Process *reyadeyat_process) {
    BOOLEAN swapped;
    for (UINT64 i = 0; i < algorithm_metric->dataset_size - 1; i++) {
        swapped = false;
        for (UINT64 j = 0; j < algorithm_metric->dataset_size - i - 1; j++) {
            if (dataset_buffer[j] > dataset_buffer[j + 1]) {
                swap(&dataset_buffer[j], &dataset_buffer[j + 1], algorithm_metric, reyadeyat_process);
                swapped = true;
                algorithm_metric->instruction_count += 1/*methods*/ + 0/*loop*/ + 3/*instructions*/ + 0/*condition*/;
            }
            algorithm_metric->instruction_count += 0/*methods*/ + 1/*loop*/ + 0/*instructions*/ + 1/*condition*/;
        }
        if (swapped == false) {
            algorithm_metric->instruction_count += 1/*if instructions*/;
            algorithm_metric->instruction_count += 0/*methods*/ + 0/*loop*/ + 1/*instructions*/ + 0/*condition*/;
            break;
        }
        algorithm_metric->instruction_count += 0/*methods*/ + 1/*loop*/ + 1/*instructions*/ + 2/*condition*/;
    }
}

void merge(uint64_t *dataset_buffer, int left_index, int median_index, int right_index, Reyadeyat_Algorithm_Metric *algorithm_metric, Reyadeyat_Process *reyadeyat_process) {
    int i, j, k;
    int n1 = median_index - left_index + 1;
    int n2 = right_index - median_index;
    algorithm_metric->instruction_count += 0/*methods*/ + 0/*loop*/ + 5/*instructions*/ + 0/*condition*/;
    // Create temp arrays
    uint64_t L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++) {
        L[i] = dataset_buffer[left_index + i];
        algorithm_metric->instruction_count += 0/*methods*/ + 1/*loop*/ + 3/*instructions*/ + 1/*condition*/;
    }

    for (j = 0; j < n2; j++) {
        R[j] = dataset_buffer[median_index + 1 + j];
        algorithm_metric->instruction_count += 0/*methods*/ + 1/*loop*/ + 4/*instructions*/ + 1/*condition*/;
    }

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = left_index;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            dataset_buffer[k] = L[i];
            i++;
        } else {
            dataset_buffer[k] = R[j];
            j++;
        }
        k++;
        algorithm_metric->instruction_count += 0/*methods*/ + 1/*loop*/ + 3/*instructions*/ + 3/*condition*/;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        dataset_buffer[k] = L[i];
        i++;
        k++;
        algorithm_metric->instruction_count += 0/*methods*/ + 1/*loop*/ + 3/*instructions*/ + 1/*condition*/;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        dataset_buffer[k] = R[j];
        j++;
        k++;
        algorithm_metric->instruction_count += 0/*methods*/ + 1/*loop*/ + 3/*instructions*/ + 1/*condition*/;
    }
}

void merge_sort_v_0_0_0(uint64_t *dataset_buffer, int64_t left_index, int64_t right_index, Reyadeyat_Algorithm_Metric *algorithm_metric,
                        Reyadeyat_Process *reyadeyat_process) {
    if (left_index < right_index) {
        int median_index = left_index + (right_index - left_index) / 2;

        // Sort first and second halves
        merge_sort_v_0_0_0(dataset_buffer, left_index, median_index, algorithm_metric, reyadeyat_process);
        merge_sort_v_0_0_0(dataset_buffer, median_index + 1, right_index, algorithm_metric, reyadeyat_process);

        merge(dataset_buffer, left_index, median_index, right_index, algorithm_metric, reyadeyat_process);

        algorithm_metric->instruction_count += 3/*methods*/ + 0/*loop*/ + 3/*instructions*/ + 1/*condition*/;
    }
}

// function to find the partition position
int64_t partition(uint64_t *dataset_buffer, int64_t low_index, int64_t high_index, Reyadeyat_Algorithm_Metric *algorithm_metric, Reyadeyat_Process *reyadeyat_process) {

    // select the rightmost element as pivot
    uint64_t pivot = dataset_buffer[high_index];

    // pointer for greater element
    uint64_t i = (low_index - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (uint64_t j = low_index; j < high_index; j++) {
        if (dataset_buffer[j] <= pivot) {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&dataset_buffer[i], &dataset_buffer[j], algorithm_metric, reyadeyat_process);

            algorithm_metric->instruction_count += 1/*methods*/ + 0/*loop*/ + 1/*instructions*/ + 0/*condition*/;
        }
        algorithm_metric->instruction_count += 0/*methods*/ + 0/*loop*/ + 0/*instructions*/ + 1/*condition*/;
    }

    // swap the pivot element with the greater element at i
    swap(&dataset_buffer[i + 1], &dataset_buffer[high_index], algorithm_metric, reyadeyat_process);

    algorithm_metric->instruction_count += 0/*methods*/ + 0/*loop*/ + 4/*instructions*/ + 0/*condition*/;
    // return the partition point
    return (i + 1);
}

void quick_sort_v_0_0_0(uint64_t *dataset_buffer, int64_t low_index, int64_t high_index, Reyadeyat_Algorithm_Metric *algorithm_metric, Reyadeyat_Process *reyadeyat_process) {
    if (low_index < high_index) {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        uint64_t pivot = partition(dataset_buffer, low_index, high_index, algorithm_metric, reyadeyat_process);

        // recursive call on the left of pivot
        quick_sort_v_0_0_0(dataset_buffer, low_index, pivot - 1, algorithm_metric, reyadeyat_process);

        // recursive call on the right of pivot
        quick_sort_v_0_0_0(dataset_buffer, pivot + 1, high_index, algorithm_metric, reyadeyat_process);

        algorithm_metric->instruction_count += 3/*methods*/ + 0/*loop*/ + 3/*instructions*/ + 0/*condition*/;
    }
    algorithm_metric->instruction_count += 0/*methods*/ + 0/*loop*/ + 0/*instructions*/ + 1/*condition*/;
}
