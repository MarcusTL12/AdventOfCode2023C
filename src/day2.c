#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "aoc_util/int_util.h"

void d2p1(char *input) {
    uint64_t ans = 0;

    size_t i = 0;

    while (*input) {
        i += 1;

        uint64_t r = 0, g = 0, b = 0;

        while (*input != ':') input++;

        while (*input != '\n') {
            while (!isdigit(*input)) input++;
            uint64_t x = atoll(input);
            while (*input != ' ') input++;
            input++;

            switch (*input) {
                case 'r':
                    r = max(r, x);
                    input += 3;
                    break;
                case 'g':
                    g = max(g, x);
                    input += 5;
                    break;
                case 'b':
                    b = max(b, x);
                    input += 4;
                    break;
            }
        }

        if (r <= 12 && g <= 13 && b <= 14) ans += i;

        input++;
    }

    printf("%lu\n", ans);
}

void d2p2(char *input) {
    uint64_t ans = 0;

    size_t i = 0;

    while (*input) {
        i += 1;

        uint64_t r = 0, g = 0, b = 0;

        while (*input != ':') input++;

        while (*input != '\n') {
            while (!isdigit(*input)) input++;
            uint64_t x = atoll(input);
            while (*input != ' ') input++;
            input++;

            switch (*input) {
                case 'r':
                    r = max(r, x);
                    input += 3;
                    break;
                case 'g':
                    g = max(g, x);
                    input += 5;
                    break;
                case 'b':
                    b = max(b, x);
                    input += 4;
                    break;
            }
        }

        ans += r * g * b;

        input++;
    }

    printf("%lu\n", ans);
}
