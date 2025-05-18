#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 200001;
const int MAX_C = 27;

int A[MAX], D[MAX], tree[MAX];
vector<int> P[MAX_C];

int query(int x) {
    int res = 0;
    for (; x; x -= x & -x)
        res += tree[x];
    return res;
}

void update(int x, int v) {
    for (; x < MAX; x += x & -x)
        tree[x] += v;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0, X = 0;
    string S;

    cin >> N >> S;
    for (int i = 1; i <= N * 2; i++) {
        A[i] = S[i - 1] - 'a' + 1;
        D[i] = P[A[i]].size(), P[A[i]].push_back(i);
    }

    for (int i = 1; i <= N * 2; i++) {
        if (D[i] + 1 <= P[A[i]].size() / 2)
            ans += X;
        else
            X++;
    }

    vector<pr> arr;
    for (int i = 1; i <= 26; i++)
        for (int j = 0; j < P[i].size() / 2; j++)
            arr.push_back({P[i][j], P[i][j + P[i].size() / 2]});

    sort(arr.begin(), arr.end(), [&](pr x, pr y) { return x[0] < y[0]; });

    for (pr i : arr)
        ans += query(N * 2) - query(i[1]), update(i[1], 1);

    cout << ans << '\n';

    return 0;
}