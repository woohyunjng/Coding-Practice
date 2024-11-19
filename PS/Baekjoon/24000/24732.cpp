#include "kewry.h"

#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007ll

using namespace std;

typedef array<int, 3> tp;

vector<int> calc(const vector<int> &v, signed N) {
    vector<int> ans(N), sm(N);
    vector<tp> st;
    int K;
    tp X;

    ans[0] = 1, sm[0] = ans[0];
    st.push_back({v[0], 0, 0});

    for (int i = 1; i < N; i++) {
        ans[i] = ans[i - 1] * ((i > 1) ? (v[i - 1] + 1) : v[i - 1]) % MOD;
        K = i;
        while (!st.empty() && st.back()[0] >= v[i]) {
            X = st.back(), st.pop_back();
            K = X[1];
            ans[i] = (ans[i] - (X[0] - v[i]) * (sm[X[2]] - (X[1] ? sm[X[1] - 1] : 0)) + MOD * MOD) % MOD;
        }
        st.push_back({v[i], K, i});
        sm[i] = (sm[i - 1] + ans[i]) % MOD;
    }

    return ans;
}