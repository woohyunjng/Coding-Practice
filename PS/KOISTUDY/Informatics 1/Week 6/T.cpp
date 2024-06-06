#include <iostream>
using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < K; k++)
                cout << i << ' ' << j << ' ' << k << '\n';
        }
    }
    cout << N * M * K;
}