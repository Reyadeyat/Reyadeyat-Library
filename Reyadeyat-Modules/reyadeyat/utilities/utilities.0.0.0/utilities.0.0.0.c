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

#include "utilities.0.0.0.h"

/** test if processor a little-endian - least-significant byte first*/
void is_little_endian_v_0_0_0(int *is_little_endin) {
    unsigned int little = 0x0204080A;
    *is_little_endin = *((char *) &little) == 0x0A;
}

/** test if processor a big-endian - most-significant byte first*/
void is_big_endian_v_0_0_0(int *is_big_endin) {
    unsigned int big = 0x0204080A;
    *is_big_endin = *((char *) &big) == 0x02;
}

void reyadeyat_utilities_number_to_char_v_0_0_0(char *input_number_type, const void *input_number,
                                                         char *output_buffer, int *output_length,
                                                         Reyadeyat_Process *reyadeyat_process) {
    reyadeyat_log_add_log_to_list(REYADEYAT_DEBUG, __UTILITIES_MODULE__, __FILE_NAME__, __func__, __LINE__,
                                  reyadeyat_process->log_list, "function '%s' not implemented yet\n", __func__);
    int count = 1;
    int digit = 0;
    int number = *((int *) input_number);
    if (number == 0) {
        output_buffer[0] = '0';
        //output_buffer[1] = '\0';
        *output_length = 1;
        return;
    }
    do {
        digit = number % 10;
        output_buffer[count - 1] = '0' + digit;
        count++;
        number = number / 10;
    } while (number > 0);
    output_buffer[--count] = '\0';
    int cursor = 0;
    while ((count / 2) - cursor > 0) {
        number = output_buffer[(count - 1) - cursor];
        output_buffer[(count - 1) - cursor] = output_buffer[cursor];
        output_buffer[cursor] = number;
        cursor++;
    }
    //output_buffer[count] = '\0';
    //*output_length = count+1;
    *output_length = count;
}

