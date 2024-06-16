#include <bits/stdc++.h>
#define MAX 10001
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

int arr[MAX], D[MAX];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K, S, sz, Q, A, B, C, B_group, C_group, res;
    cin >> N >> M >> K;

    S = sqrt(N);

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        D[i / S] += arr[i];
    }

    Q = M + K;
    while (Q--)
    {
        cin >> A >> B >> C;
        if (A == 1)
        {
            D[B / S] += C - arr[B];
            arr[B] = C;
        }
        else
        {
            res = 0;
            for (; B % S && B <= C; B++)
                res += arr[B];
            for (; (C + 1) % S && B <= C; C--)
                res += arr[C];
            for (; B <= C; B += S)
                res += D[B / S];
            cout << res << '\n';
        }
    }
}
