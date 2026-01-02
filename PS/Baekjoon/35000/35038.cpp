#include "game.h"

int mj1000j(int n, int k) { return k == 0 ? 0 : (n / (k << 1) + 2) % 2; }
int anchor(int m, int k, int c) { return k == 0 ? m : (m + ((((m + k) / (k << 1) + 2) % 2) == c ? k : -k)); }