#include <bits/stdc++.h>
#define int long long

#define MOD1 1000000007
#define MOD2 1234567891
#define BASE 100003

using namespace std;
typedef pair<int, int> pr;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int L, st, en, mid, res = 0;
    string S;
    vector<int> H[2], P[2];
    bool flag;

    unordered_map<int, unordered_map<int, int>> mp;

    cin >> L >> S;

    H[0].resize(L + 1), H[1].resize(L + 1), P[0].resize(L + 1), P[1].resize(L + 1), P[0][0] = P[1][0] = 1;

    for (int i = 1; i <= L; i++) {
        P[0][i] = P[0][i - 1] * BASE % MOD1, P[1][i] = P[1][i - 1] * BASE % MOD2;
        H[0][i] = (H[0][i - 1] * BASE + S[i - 1] - 'a' + 1) % MOD1, H[1][i] = (H[1][i - 1] * BASE + S[i - 1] - 'a' + 1) % MOD2;
    }

    function<pr(int, int)> get = [&](int l, int r) {
        int X = (H[0][r] - H[0][l - 1] * P[0][r - l + 1] % MOD1 + MOD1) % MOD1,
            Y = (H[1][r] - H[1][l - 1] * P[1][r - l + 1] % MOD2 + MOD2) % MOD2;
        return (pr){X, Y};
    };

    st = 1, en = L;
    while (st <= en) {
        mid = (st + en) >> 1;
        mp.clear(), flag = false;

        for (int i = 0; i + mid <= L; i++) {
            pr val = get(i + 1, i + mid);
            if (mp[val.first].find(val.second) != mp[val.first].end()) {
                flag = true;
                break;
            }
            mp[val.first][val.second] = i;
        }

        if (flag)
            res = mid, st = mid + 1;
        else
            en = mid - 1;
    }

    cout << res;

    return 0;
}