#include <bits/stdc++.h>
#define int long long
#define MAX 100100
#define SQRT_MAX 1000

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX];
vector<int> arr[SQRT_MAX];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, S, size, t, B, C, D, res;
    cin >> N;

    S = sqrt(N);
    size = N / S;
    if (N % S)
        size++;

    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        arr[i / S].push_back(A[i]);
    }

    for (int i = 0; i <= size; i++)
        sort(arr[i].begin(), arr[i].end());

    cin >> M;
    while (M--)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> B >> C >> D;

            res = 0;
            for (; B % S && B <= C; B++)
            {
                if (A[B] > D)
                    res++;
            }
            for (; (C + 1) % S && B <= C; C--)
            {
                if (A[C] > D)
                    res++;
            }
            for (; B <= C; B += S)
                res += arr[B / S].end() - upper_bound(arr[B / S].begin(), arr[B / S].end(), D);

            cout << res << '\n';
        }
        else
        {
            cin >> B >> C;
            for (int i = 0; i < arr[B / S].size(); i++)
            {
                if (arr[B / S][i] == A[B])
                    arr[B / S][i] = C;
            }
            A[B] = C;
            sort(arr[B / S].begin(), arr[B / S].end());
        }
    }

    return 0;
}