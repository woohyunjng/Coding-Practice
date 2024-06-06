#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

int arr[100100], checked[100100];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, K, F, res = 0;
    cin >> T;

    while (T--)
    {
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            cin >> arr[i];
            checked[i] = false;
        }

        res = 0;
        for (int i = 1; i <= N; i++)
        {
            if (checked[i])
                continue;

            K = i;
            while (!checked[K])
            {
                checked[K] = i;
                K = arr[K];
            }

            if (checked[K] != i)
                continue;

            F = K;
            K = arr[K];
            res++;

            while (K != F)
            {
                K = arr[K];
                res++;
            }
        }

        cout << N - res << '\n';
    }

    return 0;
}