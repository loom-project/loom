/*
Unit testing code for loom. This is a generic novaprova testrunner.
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

Derived from NovaProva testrunner.c sample <http://www.novaprova.org>
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <getopt.h>
#include <np.h>

int usage(char *prog) {
    printf("Usage: %s [-j concurrency] [-f text|junit]\n", prog);
    return -1;
}

int main(int argc, char **argv) {
    int result, c;

    np_runner_t *runner = np_init();

    while ((c = getopt(argc, argv, "j:f:")) != -1) {
        switch (c) {
            case 'j':
                np_set_concurrency(runner, atoi(optarg));
                break;
            case 'f':
                np_set_output_format(runner, optarg);
                break;
            default:
                np_done(runner);
                return usage(argv[0]);
        }
    }

    result = np_run_tests(runner, NULL);

    np_done(runner);

    return result;
}

