#include <bits/stdc++.h>
#define int long long

#define MAX 1000100
#define MOD 1000000007

using namespace std;

int F[MAX], parent[MAX], cnt[MAX];
bool mx[MAX], val[MAX];

int find(int X) { return parent[X] = parent[X] == X ? X : find(parent[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X > Y)
        swap(X, Y);
    if (X != Y)
        parent[Y] = X;
}

int modmul(int X, int Y) {
    int res = 0;
    while (Y--)
        res = (res + X) % MOD;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X;
    string S, res;
    set<int> st;

    cin >> S >> K, N = S.size();

    for (int i = 0; i < N; i++)
        parent[i] = i;

    X = 0;
    for (int i = 1; i < N; i++) {
        while (X && S[i] != S[X])
            X = F[X - 1];
        if (S[i] == S[X])
            uni(i, X), F[i] = ++X;
    }

    cnt[N] = 1, mx[N] = false;
    for (int i = N - 1; i >= 0; i--) {
        cnt[i] = cnt[i + 1], mx[i] = mx[i + 1];
        if (F[i])
            continue;
        st.clear();
        if (i) {
            for (int j = F[i - 1];; j = F[j - 1]) {
                st.insert(find(j));
                if (j == 0)
                    break;
            }
        }

        if (mx[i] || K / (26 - st.size()) < cnt[i + 1])
            cnt[i] = modmul(cnt[i + 1], (26 - st.size())), mx[i] = true;
        else
            cnt[i] = cnt[i + 1] * (26 - st.size());
    }

    cout << cnt[0] % MOD << '\n';

    if (K > cnt[0] && !mx[0]) {
        cout << "OVER\n";
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (F[i])
            res.push_back(res[find(i)]);
        else {
            for (int j = 0; j < 26; j++)
                val[j] = false;
            if (i) {
                for (int j = F[i - 1];; j = F[j - 1]) {
                    val[res[find(j)] - 'a'] = true;
                    if (j == 0)
                        break;
                }
            }

            if (!mx[i + 1])
                X = (K - 1) / cnt[i + 1], K = K - X * cnt[i + 1];
            else
                X = 0;
            for (int j = 0; j < 26; j++) {
                if (val[j])
                    continue;
                if (X == 0) {
                    res.push_back(j + 'a');
                    break;
                }
                X--;
            }
        }
    }
    assert(K == 1);
    cout << res << '\n';

    return 0;
}