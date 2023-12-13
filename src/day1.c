#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void d1p1(char *input) {
    uint64_t ans = 0;

    while (*input) {
        uint8_t d1 = 255, d2;

        while (*input != '\n') {
            if (isdigit(*input)) {
                d2 = *input - '0';
                if (d1 == 255) d1 = d2;
            }

            input++;
        }

        input++;

        ans += 10 * d1 + d2;
    }

    printf("%lu\n", ans);
}

void d1p2(char *input) {
    char *words[] = {"one", "two",   "three", "four", "five",
                     "six", "seven", "eight", "nine"};

    size_t word_lengths[] = {3, 3, 5, 4, 4, 3, 5, 5, 4};

    uint64_t ans = 0;

    while (*input) {
        uint8_t d1 = 255, d2;

        while (*input != '\n') {
            if (isdigit(*input)) {
                d2 = *input - '0';
                if (d1 == 255) d1 = d2;
            } else {
                for (size_t i = 0; i < 9; i++) {
                    if (memcmp(input, words[i], word_lengths[i]) == 0) {
                        d2 = i + 1;
                        if (d1 == 255) d1 = d2;
                        break;
                    }
                }
            }

            input++;
        }

        input++;

        ans += 10 * d1 + d2;
    }

    printf("%lu\n", ans);
}
