/**
 * @Copyright (c) 2015 Stephen M Buben <smbuben@gmail.com>
 * See project LICENSE for details.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>

#include <staticlib.h>


/**
 * @ group Local Constants
 * @{{{
 */
#define PROGRAM_VERSION "0.0.0"
/** @}}} */


/**
 * @group Local Helper Functions
 * @{{{
 */
static const char *
progname(
    const char * const argv0);

static void
print_help(
    const char * const argv0,
    int status)
    __attribute__ ((noreturn));

static void
print_version(
    const char * const argv0)
    __attribute__ ((noreturn));
/** @}}} */


/**
 * Parse arguments and start it up.
 */
int
main(
    int argc,
    char ** argv)
{
    int result;

    while (1)
    {
        int loption_index = 0;
        static struct option loptions[] =
        {
            {"help",    no_argument,    0,  0 },
            {"version", no_argument,    0,  0 },
            {0,         0,              0,  0 }
        };

        result =
            getopt_long(
                argc,
                argv,
                "hv",
                loptions,
                &loption_index);

        if (result == -1)
        {
            break;
        }

        switch(result)
        {
            /* Long options... */
            case 0:
                switch (loption_index)
                {
                    case 0:
                        print_help(argv[0], EXIT_SUCCESS);
                        break;
                    case 1:
                        print_version(argv[0]);
                        break;
                    default:
                        print_help(argv[0], EXIT_FAILURE);
                }

            /* Short options... */
            case 'h':
                print_help(argv[0], EXIT_SUCCESS);
                break;
            case 'v':
                print_version(argv[0]);
                break;
            default:
                print_help(argv[0], EXIT_FAILURE);
        }
    }

    /* Non-option arguments... */
    if (optind < argc)
    {
        fprintf(stderr,
            "%s: invalid extra agruments\n",
            argv[0]);
        print_help(argv[0], EXIT_FAILURE);
    }

    /* Go! */
    fprintf(stdout, "%s\n", Hello());

    return EXIT_SUCCESS;
}


/**
 * Extract the executable name from an argv[0] string.
 *
 * @param argv0         Program argv[0].
 *
 * @return              Pointer to the final path element of the input.
 */
static const char *
progname(
    const char * const argv0)
{
    const char * exe;
    exe = strrchr(argv0, '/');
    exe = (NULL == exe) ? argv0 : exe + 1;
    return exe;
}


/**
 * Print help/usage message.
 *
 * @param argv0         Program argv[0] for identification.
 * @param status        Exit code to return after help output.
 *
 * @return              Does not return.
 */
static void
print_help(
    const char * const argv0,
    int status)
{
    fprintf(stdout,
        "Usage: %s [ OPTIONS ]\n"
        "\n"
        "Available options:\n"
        "   -h | --help         Print this message.\n"
        "   -v | --version      Print program version and exit.\n",
        progname(argv0));
    exit(status);
}

/**
 * Print program version.
 *
 * @param argv0         Program argv[0] for identification.
 *
 * @return              Does not return.
 */
static void
print_version(
    const char * const argv0)
{
    fprintf(stdout,
        "%s v%s (build %s)\n",
        progname(argv0),
        PROGRAM_VERSION,
        __TIMESTAMP__);
    exit(EXIT_SUCCESS);
}

