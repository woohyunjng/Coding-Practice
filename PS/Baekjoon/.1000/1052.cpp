#include <iostream>
using namespace std;

int main()
{
    int N, K, cnt, M, res = 0;
    cin >> N >> K;

    while (true)
    {
        cnt = 0;
        M = N;
        while (M)
        {
            cnt += M & 1;
            M >>= 1;
        }

        if (cnt > K)
        {
            N++;
            res++;
        }
        else
            break;
    }

    cout << res;
}