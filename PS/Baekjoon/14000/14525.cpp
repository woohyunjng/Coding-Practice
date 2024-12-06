#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        K >>= 1;
        N = N * N % MOD;
    }
    return res;
}

class Hash {
  public:
    int base, mod1, mod2, N;
    string S;

    vector<int> H[2], P[2];

    Hash() {}

    Hash(string S, int base = 31, int mod1 = 1234567891, int mod2 = 1000000007) : S(S), base(base), mod1(mod1), mod2(mod2) {
        N = S.size();

        for (int i = 0; i < 2; i++) {
            H[i].resize(N + 1), P[i].resize(N + 1);
            P[i][0] = 1;
        }

        for (int i = 1; i <= N; i++) {
            P[0][i] = P[0][i - 1] * base % mod1;
            P[1][i] = P[1][i - 1] * base % mod2;
        }

        for (int i = 1; i <= N; i++) {
            H[0][i] = (H[0][i - 1] * base + S[i - 1] - 'a' + 1) % mod1;
            H[1][i] = (H[1][i - 1] * base + S[i - 1] - 'a' + 1) % mod2;
        }
    }

    int get(int l, int r) {
        int val_1, val_2;
        val_1 = (H[0][r] - H[0][l - 1] * P[0][r - l + 1] % mod1 + mod1) % mod1;
        val_2 = (H[1][r] - H[1][l - 1] * P[1][r - l + 1] % mod2 + mod2) % mod2;

        return val_1 * mod2 + val_2;
    }
};

string S[MAX];
map<int, bool> cnt;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, res = INF, st, en, mid, val;
    bool flag;
    cin >> N >> M;

    vector<Hash> H(N * 2 + 1);

    for (int i = 1; i <= N * 2; i++)
        cin >> S[i], H[i] = Hash(S[i]);

    for (int i = 1; i <= M; i++) {
        cnt.clear();
        st = i, en = M, val = INF;
        while (st <= en) {
            mid = st + en >> 1;
            cnt.clear(), flag = true;

            for (int j = 1; j <= N; j++)
                cnt[H[j].get(i, mid)] = true;
            for (int j = N + 1; j <= N * 2; j++)
                flag = flag && !cnt[H[j].get(i, mid)];

            if (flag)
                val = min(val, mid - i + 1), en = mid - 1;
            else
                st = mid + 1;
        }
        res = min(res, val);
    }

    cout << res << '\n';

    return 0;
}