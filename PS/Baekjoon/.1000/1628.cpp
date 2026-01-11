#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef array<int, 2> pr;

const int INF = 1e16;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<int> dp(1, 0), DS(1, 0), R, B;
    vector<pr> arr;
    map<int, int> mp;

    int N, M, S = 0, X = 1, D, P;

    cin >> N >> M, mp[0] = 0;
    for (int i = 0; i < N; i++)
        cin >> P, R.push_back(P), arr.push_back({P, 0});
    for (int i = 0; i < M; i++)
        cin >> P, B.push_back(P), arr.push_back({P, 1});
    sort(arr.begin(), arr.end());

    for (pr i : arr) {
        S += i[1] ? 1 : -1, DS.push_back(DS.back() + (i[1] ? i[0] : -i[0]));
        D = INF;
        if (i[1] == 1) {
            P = lower_bound(R.begin(), R.end(), i[0]) - R.begin();
            if (P < R.size())
                D = min(R[P] - i[0], D);
            if (P > 0)
                D = min(i[0] - R[P - 1], D);
        } else {
            P = lower_bound(B.begin(), B.end(), i[0]) - B.begin();
            if (P < B.size())
                D = min(B[P] - i[0], D);
            if (P > 0)
                D = min(i[0] - B[P - 1], D);
        }
        dp.push_back(dp.back() + D);
        if (mp.find(S) != mp.end())
            D = mp[S], dp[X] = min(dp[X], dp[D] + abs(DS[X] - DS[D]));
        mp[S] = X++;
    }

    cout << dp.back() << '\n';

    return 0;
}