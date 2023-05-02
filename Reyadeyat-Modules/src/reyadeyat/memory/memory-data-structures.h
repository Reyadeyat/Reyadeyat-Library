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

#ifndef REYADEYAT_C_MEMORY_MEMORY_DATA_STRUCTURES_H
#define REYADEYAT_C_MEMORY_MEMORY_DATA_STRUCTURES_H

#define REYADEYAT_DATA_TYPE(DATA_TYPE) typedef struct DATA_TYPE DATA_TYPE; struct DATA_TYPE

REYADEYAT_DATA_TYPE(Reyadeyat_Node_Sequence) {
    void *structure;
    Reyadeyat_Node_Sequence *next;
};

REYADEYAT_DATA_TYPE(Reyadeyat_Node_Chain) {
    void *structure;
    Reyadeyat_Node_Chain *next;
    Reyadeyat_Node_Chain *previous;
};

REYADEYAT_DATA_TYPE(Reyadeyat_Tree_Node_Binary_Sequence) {
    void *structure;
    Reyadeyat_Tree_Node_Binary_Sequence *left;
    Reyadeyat_Tree_Node_Binary_Sequence *right;
};

REYADEYAT_DATA_TYPE(Reyadeyat_Tree_Node_Binary_Chain) {
    void *structure;
    Reyadeyat_Tree_Node_Binary_Chain *parent;
    Reyadeyat_Tree_Node_Binary_Chain *left;
    Reyadeyat_Tree_Node_Binary_Chain *right;
};

REYADEYAT_DATA_TYPE(Reyadeyat_Tree_Node_Sequence) {
    void *structure;
    Reyadeyat_Tree_Node_Sequence *sequence_list;
};

REYADEYAT_DATA_TYPE(Reyadeyat_Tree_Node_Chain) {
    void *structure;
    void *sequence_list;
};

REYADEYAT_DATA_TYPE(Reyadeyat_String) {
    int length;
    int size;
    char *string;
};

REYADEYAT_DATA_TYPE(Reyadeyat_String_Block) {
    Reyadeyat_String *string_1;
    Reyadeyat_String *string_2;
    Reyadeyat_String *string_3;
};

REYADEYAT_DATA_TYPE(Reyadeyat_Buffer) {
    int size;
    int padded_size;
    char *buffer;
};

REYADEYAT_DATA_TYPE(Reyadeyat_Buffer_Block) {
    Reyadeyat_Buffer *buffer_1;
    Reyadeyat_Buffer *buffer_2;
    Reyadeyat_Buffer *buffer_3;
};

typedef struct _Reyadeyat_Memory_Data_ {
    /**@since 0.0.0*/
    char* version;
    /**@since 0.0.0*/
    char* name;
    /**@debrecated 0.0.1*/
    unsigned int buffer_size;
    /**@since 0.0.1*/
    unsigned long buffer_size_long;
} Reyadeyat_Memory_Data;

#endif //REYADEYAT_C_MEMORY_MEMORY_DATA_STRUCTURES_H
