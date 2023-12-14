#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aoc_util/vector.h"

void d4p1(char *input) {
    uint8_t numbuf[10];

    uint32_t ans = 0;

    while (*input) {
        while (*input != ':') input++;
        while (!isdigit(*input)) input++;

        size_t n = 0;
        while (*input != '|') {
            int x = atoi(input);
            numbuf[n++] = x;
            while (isdigit(*input)) input++;
            while (*input == ' ') input++;
        }

        while (!isdigit(*input)) input++;

        size_t count = 0;
        while (*input != '\n') {
            int x = atoi(input);

            for (size_t i = 0; i < n; i++) {
                if (x == numbuf[i]) {
                    count++;
                    break;
                }
            }

            while (isdigit(*input)) input++;
            while (*input == ' ') input++;
        }

        if (count > 0) {
            ans += 1 << (count - 1);
        }

        input++;
    }

    printf("%u\n", ans);
}

void d4p2(char *input) {
    uint8_t numbuf[10];

    vec_t n_cards = vec_create(sizeof(uint32_t));

    size_t i = 0;

    while (*input) {
        while (*input != ':') input++;
        while (!isdigit(*input)) input++;

        size_t n = 0;
        while (*input != '|') {
            int x = atoi(input);
            numbuf[n++] = x;
            while (isdigit(*input)) input++;
            while (*input == ' ') input++;
        }

        while (!isdigit(*input)) input++;

        size_t count = 0;
        while (*input != '\n') {
            int x = atoi(input);

            for (size_t i = 0; i < n; i++) {
                if (x == numbuf[i]) {
                    count++;
                    break;
                }
            }

            while (isdigit(*input)) input++;
            while (*input == ' ') input++;
        }

        size_t endind = i + count + 1;
        while (endind > n_cards.len) {
            vec_push(&n_cards, &(uint32_t){1});
        }

        uint32_t *ptr = vec_get(&n_cards, i);

        uint32_t n_cards_pos = *ptr;

        uint32_t *end_ptr = ptr + count + 1;

        while (++ptr < end_ptr) *ptr += n_cards_pos;

        input++;
        i++;
    }

    uint32_t ans = 0, *ptr = n_cards.data;

    for (size_t i = 0; i < n_cards.len; i++, ptr++) ans += *ptr;

    printf("%u\n", ans);
}
