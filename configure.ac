#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_INIT([loom], [0.1], [byron.platt@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_RANLIB

# Checks for libraries.
AC_CHECK_LIB([talloc], [talloc_init], [], [AC_MSG_ERROR(talloc required)])
PKG_CHECK_MODULES(NP, novaprova, [], [AC_MSG_ERROR(novaprova required)])

# Checks for header files.
AC_CHECK_HEADERS([stdint.h stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_INT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T

# Checks for library functions.

AC_CONFIG_FILES([
 Makefile
])
AC_OUTPUT
