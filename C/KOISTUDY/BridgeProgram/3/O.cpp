#include <iostream>
using namespace std;

int main()
{
    int N, A = 0, B = 0;
    cin >> N;

    while (!(N % 2))
    {
        N /= 2;
        A++;
    }

    while (!(N % 5))
    {
        N /= 5;
        B++;
    }

    cout << (N > 1 | A > B ? -1 : B * 2 - A);
}