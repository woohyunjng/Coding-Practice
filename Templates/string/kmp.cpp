#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> get_pi(string P) {
    int size = P.size(), j = 0;
    vector<int> pi(size, 0);

    for (int i = 1; i < size; i++) {
        while (j > 0 && P[i] != P[j])
            j = pi[j - 1];
        if (P[i] == P[j])
            pi[i] = ++j;
    }
    return pi;
}

vector<int> kmp(string S, string P) {
    vector<int> pi = get_pi(P), ans;
    int S_size = S.size(), P_size = P.size(), j = 0;

    for (int i = 0; i < S_size; i++) {
        while (j > 0 && S[i] != P[j])
            j = pi[j - 1];
        if (S[i] == P[j]) {
            if (j == P_size - 1) {
                ans.push_back(i - P_size + 2);
                j = pi[j];
            } else
                j++;
        }
    }

    return ans;
}