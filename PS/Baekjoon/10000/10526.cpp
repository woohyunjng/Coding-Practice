#include <bits/stdc++.h>
#define int long long

#define MAX 14

using namespace std;
typedef pair<int, bool> pr;

int W[MAX][MAX];
vector<int> chk[MAX][1 << MAX];

signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);

    int N, L, X, val, D;
    bool flag, res = false;
    vector<int> arr;

    cin >> N >> L;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> W[i][j];

    if (N == 2) {
        res = W[0][1] * 2 == L;
        cout << (res ? "possible" : "impossible") << '\n';
        return 0;
    }

    if (!(N & 1)) {
        X = (N >> 1) - 1;
        for (int i = 0; i < (1 << N); i++) {
            if (__builtin_popcount(i) != X || (i & 1))
                continue;
            arr.clear();
            for (int j = 0; j < N; j++)
                if (i & (1 << j))
                    arr.push_back(j);

            do {
                val = W[0][arr[0]], flag = val > 0;
                for (int i = 1; i < X; i++)
                    val += W[arr[i - 1]][arr[i]], flag &= W[arr[i - 1]][arr[i]] > 0;
                if (!flag)
                    continue;
                chk[arr[X - 1]][i].push_back(val);
            } while (next_permutation(arr.begin(), arr.end()));

            for (int j : arr)
                sort(chk[j][i].begin(), chk[j][i].end());
        }
    }

    X = N >> 1;
    for (int i = 0; i < (1 << N); i++) {
        if (__builtin_popcount(i) != X || (i & 1))
            continue;
        arr.clear();
        for (int j = 0; j < N; j++)
            if (i & (1 << j))
                arr.push_back(j);

        do {
            val = W[0][arr[0]], flag = val > 0;
            for (int i = 1; i < X; i++)
                val += W[arr[i - 1]][arr[i]], flag &= W[arr[i - 1]][arr[i]] > 0;
            if (!flag)
                continue;
            chk[arr[X - 1]][i].push_back(val);
        } while (next_permutation(arr.begin(), arr.end()));

        for (int j : arr)
            sort(chk[j][i].begin(), chk[j][i].end());
    }

    D = (1 << N) - 2;
    for (int i = 0; i < (1 << N); i++) {
        if (__builtin_popcount(i) != X || (i & 1))
            continue;
        for (int j = 1; j < N; j++) {
            if (!(i & (1 << j)))
                continue;
            for (int k = 1; k < N; k++) {
                if (i & (1 << k))
                    continue;
                for (int l : chk[j][i]) {
                    val = lower_bound(chk[k][D ^ i].begin(), chk[k][D ^ i].end(), L - (l + W[j][k])) - chk[k][D ^ i].begin();
                    if (X == chk[k][D ^ i].size() || chk[k][D ^ i][val] != L - (l + W[j][k]))
                        continue;
                    cout << "possible\n";
                    return 0;
                }
            }
        }
    }

    cout << "impossible\n";

    return 0;
}