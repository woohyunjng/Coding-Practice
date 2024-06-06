#include <cstdio>

int main()
{
    int h, b, c, s;
    scanf("%d %d %d %d", &h, &b, &c, &s);
    float res = (float)h / 8;
    res *= (float)b * c * s / 1024 / 1024;
    printf("%.1f MB", res);
}