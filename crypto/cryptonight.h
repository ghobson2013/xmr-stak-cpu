#ifndef __CRYPTONIGHT_H_INCLUDED
#define __CRYPTONIGHT_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "../common.h"
#include <stddef.h>
#include <inttypes.h>

#define MEMORY  2097152

typedef struct {
	uint8_t hash_state[224]; // Need only 200, explicit align
	uint8_t* long_state;
	uint8_t ctx_info[24]; //Use some of the extra memory for flags
} ALIGN16 cryptonight_ctx;

typedef struct {
	const char* warning;
} alloc_msg;

size_t cryptonight_init(size_t use_fast_mem, size_t use_mlock, alloc_msg* msg);
cryptonight_ctx* cryptonight_alloc_ctx(size_t use_fast_mem, size_t use_mlock, alloc_msg* msg);
void cryptonight_free_ctx(cryptonight_ctx* ctx);

#ifdef __cplusplus
}
#endif

#endif
