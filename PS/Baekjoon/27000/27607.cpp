#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 250001;

int dp[MAX][2];

pair<int, vector<int>> complaint(int N, vector<int> L, vector<int> R) {
    int ans = 1e9, M = L.size(), X, Y;
    vector<int> ans_val, arr, st, stR, stL;

    for (int i = 0; i < M; i++)
        arr.push_back(i);

    sort(arr.begin(), arr.end(), [&](int x, int y) {
        if (L[x] == L[y])
            return R[x] > R[y];
        return L[x] < L[y];
    });

    for (int i : arr) {
        while (!st.empty() && R[st.back()] >= R[i])
            st.pop_back();
        st.push_back(i);
    }

    for (int i : st)
        stL.push_back(L[i]), stR.push_back(R[i]);

    M = st.size();
    for (int i = 1; i <= M; i++) {
        X = lower_bound(stR.begin(), stR.end(), stL[i - 1]) - stR.begin() + 1;
        dp[i][0] = dp[X - 1][0] + 1;
    }
    for (int i = M; i >= 1; i--) {
        X = lower_bound(stL.begin(), stL.end(), stR[i - 1] + 1) - stL.begin() + 1;
        dp[i][1] = dp[X][1] + 1;
    }

    for (int i = 0; i <= N; i++) {
        X = lower_bound(stR.begin(), stR.end(), i) - stR.begin() + 1;
        Y = lower_bound(stL.begin(), stL.end(), i + 1) - stL.begin() + 1;
        if (dp[X - 1][0] + dp[Y][1] < ans)
            ans = dp[X - 1][0] + dp[Y][1], ans_val.clear();
        if (dp[X - 1][0] + dp[Y][1] == ans)
            ans_val.push_back(i);
    }

    return {ans + 1, ans_val};
}