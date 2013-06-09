AM_CFLAGS = -Wall -Werror

lib_LIBRARIES = libloom.a
libloom_a_CPPFLAGS = -I$(srcdir)/include
libloom_a_SOURCES = \
	src/generic_types.c

include_HEADERS = \
	include/generic_types.h

check_PROGRAMS = testrunner
testrunner_CPPFLAGS = -I$(srcdir)/include
testrunner_CFLAGS = -g $(NP_CFLAGS)
testrunner_LDADD = libloom.a -ltalloc $(NP_LIBS)
testrunner_SOURCES = \
	tests/testrunner.c \
	tests/tgeneric_types.c

TESTS = tests/tests.sh
EXTRA_DIST = tests/tests.sh

DISTCLEANFILES = reports/*.xml
