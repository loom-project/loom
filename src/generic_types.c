/*
Generic types.
Copyright (C) 2013 Commonwealth of Australia

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "generic_types.h"

#include <talloc.h>
#include <stdint.h>
#include <string.h>


generic_t *talloc_generic(void *ctx, const char *name, generic_id_t id, uint32_t size) {
    generic_t *g = (generic_t *)talloc_named_const(ctx, size, name);
    if (g)
        g->id = id;
    return g;
}

#define generic_type(c, n)   \
    (n##_t *)talloc_generic(c, n##_name, n##_id, sizeof(n##_t))


/* generic u8 */
const char generic_u8_name[] = "u8";

generic_t *generic_u8(void *ctx, uint8_t value) {
    generic_u8_t *g = generic_type(ctx, generic_u8);
    if (g) {
        g->value = value;
    }
    return (generic_t *)g;
}


/* generic u16*/
const char generic_u16_name[] = "u16";

generic_t *generic_u16(void *ctx, uint16_t value) {
    generic_u16_t *g = generic_type(ctx, generic_u16);
    if (g) {
        g->value = value;
    }
    return (generic_t *)g;
}


/* generic u32*/
const char generic_u32_name[] = "u32";

generic_t *generic_u32(void *ctx, uint32_t value) {
    generic_u32_t *g = generic_type(ctx, generic_u32);
    if (g) {
        g->value = value;
    }
    return (generic_t *)g;
}


/* generic u64*/
const char generic_u64_name[] = "u64";

generic_t *generic_u64(void *ctx, uint64_t value) {
    generic_u64_t *g = generic_type(ctx, generic_u64);
    if (g) {
        g->value = value;
    }
    return (generic_t *)g;
}


/* generic s8 */
const char generic_s8_name[] = "s8";

generic_t *generic_s8(void *ctx, int8_t value) {
    generic_s8_t *g = generic_type(ctx, generic_s8);
    if (g) {
        g->value = value;
    }
    return (generic_t *)g;
}


/* generic s16*/
const char generic_s16_name[] = "s16";

generic_t *generic_s16(void *ctx, int16_t value) {
    generic_s16_t *g = generic_type(ctx, generic_s16);
    if (g) {
        g->value = value;
    }
    return (generic_t *)g;
}


/* generic s32*/
const char generic_s32_name[] = "s32";

generic_t *generic_s32(void *ctx, int32_t value) {
    generic_s32_t *g = generic_type(ctx, generic_s32);
    if (g) {
        g->value = value;
    }
    return (generic_t *)g;
}


/* generic s64*/
const char generic_s64_name[] = "s64";

generic_t *generic_s64(void *ctx, int64_t value) {
    generic_s64_t *g = generic_type(ctx, generic_s64);
    if (g) {
        g->value = value;
    }
    return (generic_t *)g;
}


/* generic string */
const char generic_string_name[] = "string";

generic_t *generic_string(void *ctx, char *value) {
    generic_string_t *g = generic_type(ctx, generic_string);
    if (g) {
        g->value = value;
    }
    return (generic_t *)g;
}

generic_t *generic_string_dup(void *ctx, char *value) {
    generic_string_t *g = generic_type(ctx, generic_string);
    if (g) {
        g->value = talloc_strdup(g, value);
    }
    return (generic_t *)g;
}

/* generic buffer */
const char generic_buffer_name[] = "buffer";

generic_t *generic_buffer(void *ctx, uint8_t *value, uint32_t len) {
    generic_buffer_t *g = generic_type(ctx, generic_buffer);
    if (g) {
        g->len = len;
        g->value = value;
    }
    return (generic_t *)g;
}

generic_t *generic_buffer_dup(void *ctx, uint8_t *value, uint32_t len) {
    generic_buffer_t *g = generic_type(ctx, generic_buffer);
    if (g) {
        g->len = len;
        g->value = talloc_size(g, g->len);
        if (g->value) {
            memcpy(g->value, value, g->len);
        }
    }
    return (generic_t *)g;
}

static char hex(char b) {
    return (b < 10) ? b+'0' : b-10+'a';
}

static char *generic_buffer_tostring(void *ctx, generic_buffer_t *g) {
    uint32_t i, j;
    uint32_t len;
    char *string;

    /* keeps things simple */
    len = g->len;
    if (len > (UINT32_MAX >> 2) - 1)
        return NULL;

    string = talloc_array(ctx, char, (len << 2) + 1);
    if (!string)
        return NULL;

    /* create string */
    for (i=0, j=0; i<len; i++) {
        uint8_t b = g->value[i];

        /* escape backslash */
        if (b == '\\') {
            string[j++] = '\\';
            string[j++] = '\\';
        }

        /* escape non printable */ 
        else if (b < ' ' || b > '~') {
            string[j++] = '\\';
            string[j++] = 'x';
            string[j++] = hex(b >> 4);
            string[j++] = hex(b & 0x0f);
        }

        else {
            string[j++] = b;
        }
    }
    string[j] = 0;

    return talloc_realloc(ctx, string, char, j);
}

/* generics */
char *generic_tostring(void *ctx, generic_t *g) {
    switch (g->id) {
        case generic_u8_id:
            return talloc_asprintf(ctx, "%u", ((generic_u8_t *)g)->value);
        case generic_u16_id:
            return talloc_asprintf(ctx, "%u", ((generic_u16_t *)g)->value);
        case generic_u32_id:
            return talloc_asprintf(ctx, "%u", ((generic_u32_t *)g)->value);
        case generic_u64_id:
            return talloc_asprintf(ctx, "%lu", ((generic_u64_t *)g)->value);
        case generic_s8_id:
            return talloc_asprintf(ctx, "%d", ((generic_s8_t *)g)->value);
        case generic_s16_id:
            return talloc_asprintf(ctx, "%d", ((generic_s16_t *)g)->value);
        case generic_s32_id:
            return talloc_asprintf(ctx, "%d", ((generic_s32_t *)g)->value);
        case generic_s64_id:
            return talloc_asprintf(ctx, "%ld", ((generic_s64_t *)g)->value);
        case generic_string_id:
            return talloc_strdup(ctx, ((generic_string_t *)g)->value);
        case generic_buffer_id:
            return generic_buffer_tostring(ctx, (generic_buffer_t *)g);
        default:
            return talloc_strdup(ctx, talloc_get_name(g));
    }
}

#ifdef __UNITTEST__
#include <stdio.h>
int generic_unittest(void) {
    char str[] = "0123456789abcdef";
    uint8_t buf[] = {0x01, 0x23, 0x45, 0x67, 0x79, 0xab, 0xcd, 0xef};
    void *pool = talloc_pool(NULL, 4096);
    generic_t **g, *generics[] = {
        generic_u8(pool, 0xf0),
        generic_u16(pool, 0xf000),
        generic_u32(pool, 0xf0000000),
        generic_u64(pool, 0xf000000000000000),
        generic_s8(pool, 0xf0),
        generic_s16(pool, 0xf000),
        generic_s32(pool, 0xf0000000),
        generic_s64(pool, 0xf000000000000000),
        generic_string(pool, str),
        generic_string_dup(pool, str),
        generic_buffer(pool, buf, sizeof(buf)),
        generic_buffer_dup(pool, buf, sizeof(buf)),
        NULL,
    };
    for (g=generics; *g; g++) {
        char *string = generic_tostring(*g, *g);
        if (string)
            printf("%s\n", string);
    }
    talloc_free(pool);
    return 0;
}
#endif
