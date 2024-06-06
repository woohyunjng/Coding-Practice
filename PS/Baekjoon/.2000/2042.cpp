#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K, a, b;
    cin >> N >> M >> K;

    long long int arr[N + 1], L[N + 1], A[N + 1], S[N + 1], sm[N + 1] = {0}, res = 0, c, change;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        sm[i] = sm[i - 1] + arr[i];
        L[i] = i & -i;
    }

    for (int i = 1; i <= N; i++)
    {
        S[i] = sm[i] - sm[i - L[i]];
    }

    for (int i = 0; i < M + K; i++)
    {
        cin >> a >> b >> c;
        if (a == 1)
        {
            change = c - arr[b];
            arr[b] += change;
            while (b <= N)
            {
                S[b] += change;
                b += L[b];
            }
        }
        else
        {
            res = 0;
            while (c > 0)
            {
                res += S[c];
                c -= L[c];
            }
            b -= 1;
            while (b > 0)
            {
                res -= S[b];
                b -= L[b];
            }

            cout << res << '\n';
        }
    }
}
