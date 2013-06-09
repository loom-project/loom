#include <np.h>
#include "generic.h"

void test_u8(void) {
    generic_t *u8 = generic_u8(NULL, 129);
    NP_ASSERT_NOT_NULL(u8);
    NP_ASSERT_EQUAL(u8->id, generic_u8_id);
    NP_ASSERT_EQUAL(((generic_u8_t *)u8)->value, 129);
    NP_ASSERT_STR_EQUAL(generic_tostring(u8, u8), "129");
    NP_ASSERT_EQUAL(generic_free(u8), 0);
}

void test_u16(void) {
    generic_t *u16 = generic_u16(NULL, 32769);
    NP_ASSERT_NOT_NULL(u16);
    NP_ASSERT_EQUAL(u16->id, generic_u16_id);
    NP_ASSERT_EQUAL(((generic_u16_t *)u16)->value, 32769);
    NP_ASSERT_STR_EQUAL(generic_tostring(u16, u16), "32769");
    NP_ASSERT_EQUAL(generic_free(u16), 0);
}

void test_u32(void) {
    generic_t *u32 = generic_u32(NULL, 2147483649);
    NP_ASSERT_NOT_NULL(u32);
    NP_ASSERT_EQUAL(u32->id, generic_u32_id);
    NP_ASSERT_EQUAL(((generic_u32_t *)u32)->value, 2147483649);
    NP_ASSERT_STR_EQUAL(generic_tostring(u32, u32), "2147483649");
    NP_ASSERT_EQUAL(generic_free(u32), 0);
}

void test_u64(void) {
    generic_t *u64 = generic_u64(NULL, 9223372036854775809U);
    NP_ASSERT_NOT_NULL(u64);
    NP_ASSERT_EQUAL(u64->id, generic_u64_id);
    NP_ASSERT_EQUAL(((generic_u64_t *)u64)->value, 9223372036854775809U);
    NP_ASSERT_STR_EQUAL(generic_tostring(u64, u64), "9223372036854775809");
    NP_ASSERT_EQUAL(generic_free(u64), 0);
}

void test_s8(void) {
    generic_t *s8 = generic_s8(NULL, 129);
    NP_ASSERT_NOT_NULL(s8);
    NP_ASSERT_EQUAL(s8->id, generic_s8_id);
    NP_ASSERT_EQUAL(((generic_s8_t *)s8)->value, -127);
    NP_ASSERT_STR_EQUAL(generic_tostring(s8, s8), "-127");
    NP_ASSERT_EQUAL(generic_free(s8), 0);
}

void test_s16(void) {
    generic_t *s16 = generic_s16(NULL, 32769);
    NP_ASSERT_NOT_NULL(s16);
    NP_ASSERT_EQUAL(s16->id, generic_s16_id);
    NP_ASSERT_EQUAL(((generic_s16_t *)s16)->value, -32767);
    NP_ASSERT_STR_EQUAL(generic_tostring(s16, s16), "-32767");
    NP_ASSERT_EQUAL(generic_free(s16), 0);
}

void test_s32(void) {
    generic_t *s32 = generic_s32(NULL, 2147483649);
    NP_ASSERT_NOT_NULL(s32);
    NP_ASSERT_EQUAL(s32->id, generic_s32_id);
    NP_ASSERT_EQUAL(((generic_s32_t *)s32)->value, -2147483647);
    NP_ASSERT_STR_EQUAL(generic_tostring(s32, s32), "-2147483647");
    NP_ASSERT_EQUAL(generic_free(s32), 0);
}

void test_s64(void) {
    generic_t *s64 = generic_s64(NULL, 9223372036854775809U);
    NP_ASSERT_NOT_NULL(s64);
    NP_ASSERT_EQUAL(s64->id, generic_s64_id);
    NP_ASSERT_EQUAL(((generic_s64_t *)s64)->value, -9223372036854775807);
    NP_ASSERT_STR_EQUAL(generic_tostring(s64, s64), "-9223372036854775807");
    NP_ASSERT_EQUAL(generic_free(s64), 0);
}

void test_string(void) {
    char str[] = "0123456789abcdef";
    generic_t *string1 = generic_string(NULL, str);
    generic_t *string2 = generic_string_dup(NULL, str);
    NP_ASSERT_NOT_NULL(string1);
    NP_ASSERT_NOT_NULL(string2);
    NP_ASSERT_EQUAL(string1->id, generic_string_id);
    NP_ASSERT_EQUAL(string2->id, generic_string_id);
    NP_ASSERT_NOT_NULL(((generic_string_t *)string1)->value);
    NP_ASSERT_NOT_NULL(((generic_string_t *)string2)->value);
    NP_ASSERT_PTR_EQUAL(((generic_string_t *)string1)->value, str);
    NP_ASSERT_PTR_NOT_EQUAL(((generic_string_t *)string2)->value, str);
    NP_ASSERT_STR_EQUAL(generic_tostring(string1, string1), "0123456789abcdef");
    NP_ASSERT_STR_EQUAL(generic_tostring(string2, string2), "0123456789abcdef");
    NP_ASSERT_EQUAL(generic_free(string1), 0);
    NP_ASSERT_EQUAL(generic_free(string2), 0);
}

void test_buffer(void) {
    uint8_t buf[] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef};
    generic_t *buffer1 = generic_buffer(NULL, buf, sizeof(buf));
    generic_t *buffer2 = generic_buffer_dup(NULL, buf, sizeof(buf));
    NP_ASSERT_NOT_NULL(buffer1);
    NP_ASSERT_NOT_NULL(buffer2);
    NP_ASSERT_EQUAL(buffer1->id, generic_buffer_id);
    NP_ASSERT_EQUAL(buffer2->id, generic_buffer_id);
    NP_ASSERT_EQUAL(((generic_buffer_t *)buffer1)->len, sizeof(buf));
    NP_ASSERT_EQUAL(((generic_buffer_t *)buffer2)->len, sizeof(buf));
    NP_ASSERT_NOT_NULL(((generic_buffer_t *)buffer1)->value);
    NP_ASSERT_NOT_NULL(((generic_buffer_t *)buffer2)->value);
    NP_ASSERT_PTR_EQUAL(((generic_buffer_t *)buffer1)->value, buf);
    NP_ASSERT_PTR_NOT_EQUAL(((generic_buffer_t *)buffer2)->value, buf);
    NP_ASSERT_STR_EQUAL(generic_tostring(buffer1, buffer1), "\\x01#Eg\\x89\\xab\\xcd\\xef");
    NP_ASSERT_STR_EQUAL(generic_tostring(buffer2, buffer2), "\\x01#Eg\\x89\\xab\\xcd\\xef");
    NP_ASSERT_EQUAL(generic_free(buffer1), 0);
    NP_ASSERT_EQUAL(generic_free(buffer2), 0);
}

