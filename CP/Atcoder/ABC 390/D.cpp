#include <bits/stdc++.h>
#define int long long

#define MAX 13
using namespace std;

int val[1 << MAX], dp[1 << MAX], A[MAX];
vector<int> st[1 << MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < (1 << N); i++)
        for (int j = 0; j < N; j++)
            if (i & (1 << j))
                val[i] += A[j];

    st[0].push_back(0);
    for (int i = 1; i < (1 << N); i++) {
        for (int k = 0; k < N; k++)
            if (i & (1 << k)) {
                X = k;
                break;
            }

        for (int j = i; j >= 0; j = (j - 1) & i) {
            if (!((i ^ j) & (1 << X)))
                continue;
            for (int k : st[j])
                st[i].push_back(k ^ val[i ^ j]);
            if (!j)
                break;
        }
        sort(st[i].begin(), st[i].end()), st[i].erase(unique(st[i].begin(), st[i].end()), st[i].end());
    }

    cout << st[(1 << N) - 1].size() << '\n';

    return 0;
}