#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

int play_game(int N, signed Q, int K, vector<int> L, vector<int> R) {
    vector<int> comp;
    vector<pr> arr, st;
    vector<tp> val, cur, tmp;

    set<pr> dp;
    set<pr>::iterator it;

    dp.insert({0, 0});

    int X = 0, Y = 0, S, VR = 0, ans = 0, C = 0, V, PR;

    for (int i = 0; i < Q; i++) {
        arr.push_back({L[i], 1});
        if (R[i] + 1 < N)
            arr.push_back({R[i] + 1, -1});
        comp.push_back(R[i] % K);
    }

    comp.push_back(0), comp.push_back(K - 1);
    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();

    sort(arr.begin(), arr.end());
    for (pr i : arr) {
        if (!st.empty() && st.back()[0] == i[0])
            st.back()[1] += i[1];
        else
            st.push_back({i[0], i[1]});
    }

    for (pr i : st) {
        if (i[0] > X)
            val.push_back({X, i[0] - 1, Y});
        Y += i[1], X = i[0];
    }
    if (X < N)
        val.push_back({X, N - 1, Y});

    for (int i = 0; i < val.size(); i++) {
        if (val[i][1] + 1 > K * C) {
            ans += ((val[i][1] + 1) / K - C) * val[i][2], C = (val[i][1] + 1) / K;
            if ((val[i][1] + 1) % K == 0)
                continue;
            val[i][0] = K * C;
        }

        cur.clear(), cur.push_back({0, val[i][1] % K, val[i][2]});
        while (i + 1 < val.size() && val[i + 1][1] < K * (C + 1))
            i++, cur.push_back({val[i][0] % K, val[i][1] % K, val[i][2]});
        if (i + 1 < val.size() && val[i + 1][0] < K * (C + 1))
            cur.push_back({val[i + 1][0] % K, K - 1, val[i + 1][2]}), val[i + 1][0] = K * (C + 1);
        if (cur.back()[1] != K - 1)
            cur.push_back({cur.back()[1] + 1, K - 1, 0});

        for (int j = 0; j < cur.size(); j++) {
            cur[j][0] = lower_bound(comp.begin(), comp.end(), cur[j][0]) - comp.begin();
            cur[j][1] = lower_bound(comp.begin(), comp.end(), cur[j][1] + 1) - comp.begin() - 1;
            if (cur[j][0] <= cur[j][1])
                tmp.push_back(cur[j]);
        }
        cur = tmp, tmp.clear(), reverse(cur.begin(), cur.end()), PR = VR;

        for (tp j : cur) {
            it = dp.lower_bound({j[0], -1});
            if (it != dp.end() && (*it)[0] == j[0])
                X = (*it)[1], dp.erase(it), dp.insert({j[0], X + j[2]});
            else
                dp.insert({j[0], j[2]});

            X = 0;
            while (true) {
                it = prev(dp.lower_bound({j[1] + 1, -1}));
                if (next(it) == dp.end()) {
                    VR += j[2] - X;
                    break;
                } else if (X + (*next(it))[1] <= j[2])
                    X += (*next(it))[1], dp.erase(next(it));
                else {
                    X = X + (*next(it))[1] - j[2], Y = (*next(it))[0];
                    dp.erase(next(it)), dp.insert({Y, X});
                    break;
                }
            }
        }

        X = 0;
        while (true) {
            it = dp.begin();
            if (it == dp.end())
                break;
            else if (X + (*it)[1] <= PR)
                X += (*it)[1], dp.erase(it);
            else {
                X = X + (*it)[1] - PR, Y = (*it)[0];
                dp.erase(it), dp.insert({Y, X});
                break;
            }
        }
        if (dp.empty() || (*dp.begin())[0] != 0)
            dp.insert({0, PR});
        else {
            it = dp.begin(), X = (*it)[1] + PR;
            dp.erase(it), dp.insert({0, X});
        }
        C++;
    }

    ans += VR;
    return ans;
}
