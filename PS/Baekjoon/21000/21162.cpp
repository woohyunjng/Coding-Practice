#include <bits/stdc++.h>
using namespace std;

const int MAX = 400001;

int A[MAX], group[MAX], nxt[MAX], sa[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, D = 1;
    vector<int> arr;

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> A[N - 1 - i];
    for (int i = N; i < (N << 1); i++)
        A[i] = A[i - N];

    for (int i = 0; i < N << 1; i++)
        sa[i] = i, group[i] = A[i];
    group[N << 1] = -1;

    function<bool(int, int)> cmp = [&](int X, int Y) {
        if (group[X] == group[Y])
            return group[X + D] < group[Y + D];
        return group[X] < group[Y];
    };

    while (D <= (N << 1)) {
        sort(sa, sa + (N << 1), cmp);
        for (int i = 1; i < (N << 1); i++) {
            if (cmp(sa[i - 1], sa[i]))
                nxt[sa[i]] = nxt[sa[i - 1]] + 1;
            else
                nxt[sa[i]] = nxt[sa[i - 1]];
        }

        for (int i = 0; i < (N << 1); i++)
            group[i] = nxt[i];

        D <<= 1;
    }

    for (int i = 0; i < (N << 1); i++) {
        if (sa[i] < N && sa[i] > 0)
            arr.push_back(sa[i]);
    }

    D = arr[K - 1];
    for (int i = 0; i < N; i++)
        cout << A[(D + i) % N] << ' ';
    cout << '\n';

    return 0;
}