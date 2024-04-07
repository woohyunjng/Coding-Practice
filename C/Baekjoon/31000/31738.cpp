#include <iostream>
using namespace std;

int main()
{
    long long int N, M, res = 1;
    cin >> N >> M;

    if (N >= M)
        cout << 0;
    else
    {
        for (int i = 2; i <= N; i++)
            res = res * i % M;
        cout << res;
    }
}