#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define isadigit(x) (x >= '0' && x <= '9')
#define issymbol(x) (x != '.' && !isadigit(x))

void d3p1(char *input) {
    size_t len = strlen(input);
    size_t w = 1;

    for (char *c = input; *c != '\n'; c++) w++;

    size_t h = len / w;

    char *prevline = input - w, *thisline = input, *nextline = input + w;

    uint32_t ans = 0;

    for (size_t y = 0; y < h; y++) {
        bool isparsing = false;
        bool prevsymbol = false;
        bool foundsymbol = false;
        uint32_t num = 0;

        for (; *thisline != '\n'; prevline++, thisline++, nextline++) {
            char pc, tc = *thisline, nc;

            if (y == 0) {
                pc = '.';
            } else {
                pc = *prevline;
            }

            if (y == h - 1) {
                nc = '.';
            } else {
                nc = *nextline;
            }

            bool symbolhere = issymbol(pc) || issymbol(tc) || issymbol(nc);
            bool dgt = isadigit(tc);

            if (!isparsing && dgt) {
                isparsing = true;
                foundsymbol = prevsymbol || symbolhere;
                num = tc - '0';
            } else if (isparsing && dgt) {
                foundsymbol |= symbolhere;
                num = 10 * num + (tc - '0');
            } else if (isparsing) {
                foundsymbol |= symbolhere;
                if (foundsymbol) {
                    ans += num;
                }
                isparsing = false;
            }

            prevsymbol = symbolhere;
        }

        if (isparsing && foundsymbol) {
            ans += num;
        }

        prevline++, thisline++, nextline++;
    }

    printf("%u\n", ans);
}

void d3p2(char *input) {
    size_t len = strlen(input);
    size_t w = 1;

    for (char *c = input; *c != '\n'; c++) w++;

    size_t h = len / w;

    char *cursym = input;

    uint32_t ans = 0;

    for (size_t y = 0; y < h; y++) {
        for (; *cursym != '\n'; cursym++) {
            if (*cursym == '*') {
                size_t n_nums = 0;
                char *num_ptrs[2];

                for (int dy = -1; dy <= 1; dy++) {
                    size_t ny = y + dy;
                    char *line = cursym + dy * w;
                    if (ny < h) {
                        for (int dx = -1; dx <= 1; dx++) {
                            char *ptr = line + dx;
                            if (isadigit(*ptr)) {
                                dx += 1;
                                while (isadigit(*ptr)) ptr--;

                                if (n_nums < 2 &&
                                    num_ptrs[n_nums] != (ptr + 1)) {
                                    num_ptrs[n_nums++] = ptr + 1;
                                }
                            }
                        }
                    }
                }

                if (n_nums == 2) {
                    uint32_t prod = 1;
                    for (size_t i = 0; i < 2; i++) {
                        uint32_t num = 0;
                        while (isadigit(*num_ptrs[i])) {
                            num = 10 * num + (*num_ptrs[i] - '0');
                            num_ptrs[i]++;
                        }
                        prod *= num;
                    }
                    ans += prod;
                }
            }
        }

        cursym++;
    }

    printf("%u\n", ans);
}
