#include "wiring.h"
#include <bits/stdc++.h>

#define int long long
using namespace std;

typedef array<int, 2> pr;

const int INF = 1e16;
const int MAX = 200001;

int min_total_length(vector<signed> r, vector<signed> b) {
    vector<int> dp(1, 0), DS(1, 0);
    vector<pr> arr;
    map<int, int> mp;

    int S = 0, X = 1, D, P;

    for (int i : r)
        arr.push_back({i, 0});
    for (int i : b)
        arr.push_back({i, 1});
    sort(arr.begin(), arr.end()), mp[0] = 0;

    for (pr i : arr) {
        S += i[1] ? 1 : -1, DS.push_back(DS.back() + (i[1] ? i[0] : -i[0]));
        D = INF;
        if (i[1] == 1) {
            P = lower_bound(r.begin(), r.end(), i[0]) - r.begin();
            if (P < r.size())
                D = min(r[P] - i[0], D);
            if (P > 0)
                D = min(i[0] - r[P - 1], D);
        } else {
            P = lower_bound(b.begin(), b.end(), i[0]) - b.begin();
            if (P < b.size())
                D = min(b[P] - i[0], D);
            if (P > 0)
                D = min(i[0] - b[P - 1], D);
        }
        dp.push_back(dp.back() + D);
        if (mp.find(S) != mp.end())
            D = mp[S], dp[X] = min(dp[X], dp[D] + abs(DS[X] - DS[D]));
        mp[S] = X++;
    }

    return dp.back();
}