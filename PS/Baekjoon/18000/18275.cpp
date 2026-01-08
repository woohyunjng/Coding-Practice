#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

vector<pr> solve(int N, int M) {
    if (N == 0)
        return {};
    else if (N == 1)
        return {{0, M}};

    int V[2][2] = {{1'000'000'000, 0}, {1'000'000'000, 0}};
    vector<pr> res, arr;

    for (int i = M; i < M + N; i++)
        V[i & 1][0] = min(V[i & 1][0], i), V[i & 1][1] = max(V[i & 1][1], i);

    if ((V[1][1] >> 1) - (V[1][0] >> 1) + 1 == N >> 1) {
        arr = solve(N >> 1, V[1][0] >> 1);
        for (pr i : arr)
            res.push_back({i[0] << 1 | 1, i[1] << 1 | 1});
        arr = solve(N - (N >> 1), V[0][0] >> 1);
        for (pr i : arr)
            res.push_back({i[0] << 1, i[1] << 1});
    } else {
        arr = solve(N >> 1, (V[1][0] >> 1) + 1);
        for (pr i : arr)
            res.push_back({i[0] << 1 | 1, i[1] << 1 | 1});
        arr = solve(N - (N >> 1), V[1][0] >> 1);
        for (pr i : arr) {
            if (i[1] == (V[1][0] >> 1))
                res.push_back({i[0] << 1, i[1] << 1 | 1});
            else
                res.push_back({i[0] << 1, i[1] << 1});
        }
    }

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    vector<pr> ans;

    cin >> N >> M;
    ans = solve(N, M);
    for (pr i : ans)
        cout << i[0] << ' ' << i[1] << '\n';

    return 0;
}