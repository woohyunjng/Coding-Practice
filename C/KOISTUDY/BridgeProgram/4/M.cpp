#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int A, int B)
{
    if (A < B)
        swap(A, B);

    while (A % B)
    {
        int rest = A % B;
        A = B, B = rest;
    }

    return B;
}

int main()
{
    int N, res = 0, k, A;
    cin >> N;

    char counter[(int)(N / 2) + 1] = {0};

    for (int i = 3; i * (i + 1) <= N; i += 2)
    {
        for (int j = i - 2; j > 0; j -= 2)
        {
            if (gcd(i, j) != 1)
                continue;

            for (int k = 1; i * (i + j) * k <= N; k++)
            {
                A = i * (i + j) * k / 2;
                counter[A]++;
                if (counter[A] == 1)
                    res++;
                else if (counter[A] == 2)
                    res--;
            }
        }
    }

    cout << res;
}
