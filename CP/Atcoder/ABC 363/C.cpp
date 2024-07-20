#include <bits/stdc++.h>
#define int long long
using namespace std;

bool is_palin(const string &s, int st, int K) {
    int en = st + K - 1;
    while (st < en) {
        if (s[st] != s[en])
            return false;
        st++, en--;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K, res = 0;
    string S;
    bool check;

    cin >> N >> K;
    cin >> S;

    set<string> perms;
    sort(S.begin(), S.end());
    do {
        perms.insert(S);
    } while (next_permutation(S.begin(), S.end()));

    for (auto &perm : perms) {
        check = false;
        for (int i = 0; i <= N - K; i++) {
            if (is_palin(perm, i, K)) {
                check = true;
                break;
            }
        }
        if (!check)
            res++;
    }

    cout << res;

    return 0;
}