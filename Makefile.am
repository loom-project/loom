# Creates Makefile for loom.
# Copyright (C) 2013 Commonwealth of Australia
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

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
