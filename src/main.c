#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "aoc_util/file_util.h"
#include "days.h"

static void print_time(clock_t diff) {
    clock_t secs = diff / CLOCKS_PER_SEC, rem = diff % CLOCKS_PER_SEC;
    double ms = ((double)(rem * 1000)) / ((double)CLOCKS_PER_SEC);
    printf("Took %ld s, %f ms\n", secs, ms);
}

void get_inp_path(char *dest, size_t day, char *inpname) {
    char *aoc_input = getenv("AOC_INPUT");

    size_t len = sprintf(dest, "%s/2023/day%zu/", aoc_input, day);

    if (inpname == NULL) {
        sprintf(dest + len, "input");
    } else {
        sprintf(dest + len, "%s", inpname);
    }
}

int main(int argc, char **argv) {
    char pathbuf[256];

    if (argc < 2) {
        printf("Enter day and part as command line arguments,\n");
        printf("Or run all by passing \"all\" as parameter.\n");
    } else if (*argv[1] == 'a') {
        printf("Running all days:\n");
        printf("===========================\n");
        clock_t timer = clock();
        for (size_t i = 0; i < AMT_DAYS; i++) {
            get_inp_path(pathbuf, i + 1, NULL);
            char *input = file_read_full(pathbuf);

            clock_t subtimer = clock();
            printf("---------------------------\n");
            printf("Running Day %zu\n", i + 1);
            printf("Part 1:\n");
            days[2 * i](input);
            print_time(clock() - subtimer);
            printf("\n");

            free(input);
            input = file_read_full(pathbuf);

            subtimer = clock();
            printf("Part 2:\n");
            days[2 * i + 1](input);
            print_time(clock() - subtimer);

            free(input);
        }
        printf("===========================\n");
        print_time(clock() - timer);
    } else {
        char *inpname = NULL;
        if (argc >= 4) {
            inpname = argv[3];
        }

        int day = atoi(argv[1]) - 1;
        int part = atoi(argv[2]) - 1;

        get_inp_path(pathbuf, day + 1, inpname);
        char *input = file_read_full(pathbuf);

        if (day < 0 || day >= AMT_DAYS) {
            printf("Must give day between 1 and %d!\n", AMT_DAYS);
            return 0;
        }

        if (part < 0 || part > 1) {
            printf("Part must be either 1 or 2\n");
            return 0;
        }

        int index = 2 * day + part;

        clock_t start = clock();
        days[index](input);
        print_time(clock() - start);
    }
}
