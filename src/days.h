
void d1p1();
void d1p2();
void d2p1();
void d2p2();
void d3p1();
void d3p2();
void d4p1();
void d4p2();
void d5p1();
void d5p2();

#define AMT_DAYS 5

void (*days[])(char *) = {d1p1, d1p2, d2p1, d2p2, d3p1,
                          d3p2, d4p1, d4p2, d5p1, d5p2};
