#include <cstdio>

int main()
{
    int N;
    scanf("%x", &N);

    for (int i = 1; i < 16; i++)
        printf("%X*%X=%X\n", N, i, N * i);
}