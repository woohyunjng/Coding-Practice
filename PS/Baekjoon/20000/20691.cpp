#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300001;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<int> QR[MAX];
int S, C[MAX], tree[2][MAX];

int query(int t, int idx) {
    int res = 0;
    while (idx > 0)
        res += tree[t][idx], idx -= (idx & -idx);
    return res;
}

void update(int t, int idx, int val) {
    while (idx < MAX)
        tree[t][idx] += val, idx += (idx & -idx);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, V = 0, ans;
    vector<int> comp, A, B;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> C[i], comp.push_back(C[i]);

    for (int i = 1; i <= M; i++) {
        cin >> S;
        while (S--)
            cin >> X, QR[i].push_back(X), comp.push_back(X);
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();

    for (int i = 1; i <= N; i++)
        C[i] = lower_bound(comp.begin(), comp.end(), C[i]) - comp.begin() + 1;
    for (int i = 1; i <= M; i++)
        for (int &j : QR[i])
            j = lower_bound(comp.begin(), comp.end(), j) - comp.begin() + 1;

    for (int i = 1; i <= N; i++)
        update(0, C[i], 1), V += i - query(0, C[i]);

    for (int i = 1; i <= M; i++) {
        A.clear(), B.clear(), Y = 0, ans = INF;
        for (int j : QR[i])
            A.push_back(query(0, j - 1)), B.push_back(N - query(0, j)), Y += B.back();
        ans = min(ans, Y);

        reverse(A.begin(), A.end()), reverse(B.begin(), B.end());

        for (int j : QR[i])
            Y -= B.back(), B.pop_back(), Y += A.back(), A.pop_back(), ans = min(ans, Y);

        ans += V;

        for (int j = 0; j < QR[i].size(); j++)
            update(1, QR[i][j], 1), ans += j + 1 - query(1, QR[i][j]);
        for (int j : QR[i])
            update(1, j, -1);

        cout << ans << '\n';
    }

    return 0;
}