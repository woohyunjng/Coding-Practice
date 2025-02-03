#include <bits/stdc++.h>
#define MAX 300000

using namespace std;
typedef array<int, 3> tp;

int S[MAX];
map<tp, int> mp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0, X;
    tp C = {0, 0, 0};
    string s;

    cin >> N >> s;
    for (int i = 1; i <= N; i++) {
        if (s[i - 1] == 'J')
            S[i] = 0;
        else if (s[i - 1] == 'O')
            S[i] = 1;
        else
            S[i] = 2;
    }

    mp[{0, 0, 0}] = 0;
    for (int i = 1; i <= N; i++) {
        C[S[i]]++, X = min({C[0], C[1], C[2]});
        C[0] -= X, C[1] -= X, C[2] -= X;

        if (mp.find(C) != mp.end())
            res = max(res, i - mp[C]);
        else
            mp[C] = i;
    }

    cout << res << '\n';

    return 0;
}