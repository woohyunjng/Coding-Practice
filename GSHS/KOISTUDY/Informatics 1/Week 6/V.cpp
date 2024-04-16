#include <cstdio>

int main()
{
    int w, h, b;
    scanf("%d %d %d", &w, &h, &b);
    float res = (float)w * h * b / 8 / 1024 / 1024;
    printf("%.2f MB", res);
}