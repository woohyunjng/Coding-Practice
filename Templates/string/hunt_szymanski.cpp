#include <bits/stdc++.h>
#define int long long
using namespace std;

int hunt_szymanski(string &S, string &P) {
    int N = S.size(), M = P.size();
    vector<int> idx[30];
    int S[N + 1] = {-1}, l = 1;

    for (int i = M; i--;)
        idx[P[i] - 'a'].push_back(i);

    for (int i = 0; i < N; i++) {
        for (int j : idx[S[i] - 'a']) {
            if (S[l - 1] < j)
                S[l++] = j;
            else
                S[lower_bound(S, S + l, j) - S] = j;
        }
    }

    return l - 1;
}