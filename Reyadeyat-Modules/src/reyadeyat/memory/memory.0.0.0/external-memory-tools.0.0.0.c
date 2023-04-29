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

#include "external-memory-tools.0.0.0.h"

void external_reyadeyat_memory_number_to_char_v_0_0_0(char *input_number_type, const void *input_number, char* output_buffer, int *output_length) {
    int count = 1;
    int digit = 0;
    int number = *((int*)input_number);
    if (number == 0) {
        output_buffer[0] = '0';
        //output_buffer[1] = '\0';
        *output_length = 1;
        return;
    }
    while (number / (count*10) > 0) {
        //digit = *((int*)input_number) >> count;
        digit = number % (count*10);
        output_buffer[count] = '0'+digit;
        count++;
    }
    //output_buffer[count] = '\0';
    //*output_length = count+1;
    *output_length = count;
}