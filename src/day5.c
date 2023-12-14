#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "aoc_util/int_util.h"
#include "aoc_util/vector.h"

static void parse_input(char *input, vec_t *seeds, vec_t *map_data,
                        size_t *map_lengths, size_t *n_maps) {
    *seeds = vec_create(sizeof(uint64_t));

    input += 6;

    while (*input++ != '\n') {
        uint64_t x = atoll(input);
        vec_push(seeds, &x);
        while (isdigit(*input)) input++;
    }

    input++;

    *map_data = vec_create(sizeof(uint64_t));

    *n_maps = 0;

    while (*input++) {
        map_lengths[*n_maps] = 0;

        while (*input != '\n') input++;
        while (*++input && *input != '\n') {
            uint64_t x = atoll(input);
            vec_push(map_data, &x);
            map_lengths[*n_maps]++;
            while (isdigit(*input)) input++;
        }

        (*n_maps)++;
    }
}

static uint64_t map_number(uint64_t src, uint64_t *map, size_t len) {
    for (size_t i = 0; i < len; i += 3) {
        uint64_t ds = map[i], ss = map[i + 1], l = map[i + 2];

        uint64_t s_end = ss + (l - 1);

        if (ss <= src && src <= s_end) {
            return ds + src - ss;
        }
    }

    return src;
}

static uint64_t map_number_full(uint64_t src, uint64_t *maps,
                                size_t *map_lengths, size_t n_maps) {
    for (size_t i = 0; i < n_maps; i++) {
        src = map_number(src, maps, map_lengths[i]);
        maps += map_lengths[i];
    }

    return src;
}

void d5p1(char *input) {
    vec_t seeds, map_data;
    size_t map_lengths[7], n_maps;

    parse_input(input, &seeds, &map_data, map_lengths, &n_maps);

    uint64_t ans = UINT64_MAX;

    for (size_t i = 0; i < seeds.len; i++) {
        ans = min(ans, map_number_full(((uint64_t *)seeds.data)[i],
                                       map_data.data, map_lengths, n_maps));
    }

    printf("%lu\n", ans);

    vec_free(&seeds);
    vec_free(&map_data);
}

void d5p2(char *input) {
    vec_t seeds, map_data;
    size_t map_lengths[7], n_maps;

    parse_input(input, &seeds, &map_data, map_lengths, &n_maps);

    uint64_t ans = UINT64_MAX;

    for (size_t i = 0; i < seeds.len; i += 2) {
        uint64_t r_start = ((uint64_t *)seeds.data)[i];
        uint64_t r_end = r_start + ((uint64_t *)seeds.data)[i + 1];
        for (uint64_t x = r_start; x < r_end; x++) {
            ans = min(ans,
                      map_number_full(x, map_data.data, map_lengths, n_maps));
        }

        printf("%lu\n", ans);
    }

    printf("%lu\n", ans);

    vec_free(&seeds);
    vec_free(&map_data);
}
