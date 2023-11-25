//
// Created by mnm on 5/5/23.
//

#ifndef REYADEYAT_REYADEYAT_CORE_H
#define REYADEYAT_REYADEYAT_CORE_H

#define __REYADEYAT_MAIN_MODULE__ "REYADEYAT_MAIN_MODULE"
#define __ALGORITHMS_MODULE__ "ALGORITHMS_MODULE"
#define __DATA_STRUCTURES_MODULE__ "DATA_STRUCTURES_MODULE"
#define __UTILITIES_MODULE__ "UTILITIES_MODULE"
#define __FILE_MODULE__ "FILE_MODULE"
#define __MEMORY_MODULE__ "MEMORY_MODULE"
#define __COMPUTER_MODULE__ "COMPUTER_MODULE"

#define Reyadeyat_KB 1024
#define Reyadeyat_MB 1048576
#define Reyadeyat_GB 1073741824
#define Reyadeyat_TB 1099511627776

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define REYADEYAT_ENUM_TYPE(ENUM_TYPE) typedef enum ENUM_TYPE ENUM_TYPE; enum ENUM_TYPE
#define REYADEYAT_DATA_TYPE(DATA_TYPE) typedef struct DATA_TYPE DATA_TYPE; struct DATA_TYPE

#define REYADEYAT_PACKED_DATA_TYPE(DATA_TYPE) typedef struct __attribute__((__packed__)) DATA_TYPE DATA_TYPE; struct DATA_TYPE

#define BOOLEAN bool
#define UINT64 uint64_t

#endif //REYADEYAT_REYADEYAT_CORE_H
