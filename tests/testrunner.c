/* testrunner.c */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <getopt.h>
#include <np.h>

int usage(char *prog) {
    printf("Usage: %s [-j concurrency] [-f text|junit]\n", prog);
    return -1;
}

int main(int argc, char **argv)
{
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

