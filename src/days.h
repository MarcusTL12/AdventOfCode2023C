
void d1p1();
void d1p2();
void d2p1();
void d2p2();
void d3p1();
void d3p2();

#define AMT_DAYS 3

void (*days[])(char *) = {d1p1, d1p2, d2p1, d2p2, d3p1, d3p2};
