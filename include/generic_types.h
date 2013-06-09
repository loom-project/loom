/*
*/

#ifndef __GENERIC_H__
#define __GENERIC_H__

#include <talloc.h>
#include <stdint.h>

typedef enum {
    generic_u8_id = 1,
    generic_u16_id,
    generic_u32_id,
    generic_u64_id,
    generic_s8_id,
    generic_s16_id,
    generic_s32_id,
    generic_s64_id,
    generic_string_id,
    generic_buffer_id,
} generic_id_t;

typedef struct generic_t {
    generic_id_t id;
} generic_t;

generic_t *talloc_generic(void *ctx, const char *name, generic_id_t id, uint32_t size);

/* u8 */
typedef struct generic_u8_t {
    generic_t base;
    uint8_t value;
} generic_u8_t;
extern const char generic_u8_name[];
generic_t *generic_u8(void *ctx, uint8_t value);

/* u16 */
typedef struct generic_u16_t {
    generic_t base;
    uint16_t value;
} generic_u16_t;
extern const char generic_u16_name[];
generic_t *generic_u16(void *ctx, uint16_t value);

/* u32 */
typedef struct generic_u32_t {
    generic_t base;
    uint32_t value;
} generic_u32_t;
extern const char generic_u32_name[];
generic_t *generic_u32(void *ctx, uint32_t value);

/* u64 */
typedef struct generic_u64_t {
    generic_t base;
    uint64_t value;
} generic_u64_t;
extern const char generic_u64_name[];
generic_t *generic_u64(void *ctx, uint64_t value);

/* s8 */
typedef struct generic_s8_t {
    generic_t base;
    int8_t value;
} generic_s8_t;
extern const char generic_s8_name[];
generic_t *generic_s8(void *ctx, int8_t value);

/* s16 */
typedef struct generic_s16_t {
    generic_t base;
    int16_t value;
} generic_s16_t;
extern const char generic_s16_name[];
generic_t *generic_s16(void *ctx, int16_t value);

/* s32 */
typedef struct generic_s32_t {
    generic_t base;
    int32_t value;
} generic_s32_t;
extern const char generic_s32_name[];
generic_t *generic_s32(void *ctx, int32_t value);

/* s64 */
typedef struct generic_s64_t {
    generic_t base;
    int64_t value;
} generic_s64_t;
extern const char generic_s64_name[];
generic_t *generic_s64(void *ctx, int64_t value);

/* string */
typedef struct generic_string_t {
    generic_t base;
    char *value;
} generic_string_t;
extern const char generic_string_name[];
generic_t *generic_string(void *ctx, char *value);
generic_t *generic_string_dup(void *ctx, char *value);

/* buffer */
typedef struct generic_buffer_t {
    generic_t base;
    uint32_t len;
    uint8_t *value;
} generic_buffer_t;
extern const char generic_buffer_name[];
generic_t *generic_buffer(void *ctx, uint8_t *value, uint32_t len);
generic_t *generic_buffer_dup(void *ctx, uint8_t *value, uint32_t len);

/* generic functions */
#define generic_free(g) talloc_free(g)
#define generic_name(g) talloc_get_name(g)
char *generic_tostring(void *ctx, generic_t *g);

#endif
