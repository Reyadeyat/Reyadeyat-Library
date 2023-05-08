//
// Created by mnm on 5/5/23.
//

#ifndef REYADEYAT_C_REYADEYAT_CORE_H
#define REYADEYAT_C_REYADEYAT_CORE_H

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define REYADEYAT_ENUM_TYPE(ENUM_TYPE) typedef enum ENUM_TYPE ENUM_TYPE; enum ENUM_TYPE
#define REYADEYAT_DATA_TYPE(DATA_TYPE) typedef struct DATA_TYPE DATA_TYPE; struct DATA_TYPE

#define __REYADEYAT_MAIN_MODULE__ "REYADEYAT_MAIN_MODULE"
#define __UTILITIES_MODULE__ "UTILITIES_MODULE"
#define __FILE_MODULE__ "FILE_MODULE"
#define __MEMORY_MODULE__ "MEMORY_MODULE"

#endif //REYADEYAT_C_REYADEYAT_CORE_H
