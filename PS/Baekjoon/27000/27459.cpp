#include <bits/stdc++.h>
#define int long long

#define MAX 300000
using namespace std;

int A[MAX], tree[MAX * 4], cnt[2][MAX], cur[MAX];
vector<int> arr[MAX];

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = cnt[0][s];
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return max(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] += v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, res, val;
    cin >> T;

    while (T--) {
        cin >> N, res = N * 2;
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
            arr[i].clear(), cnt[0][i] = cnt[1][i] = 0;
        }

        for (int i = 1; i <= N; i++) {
            cnt[i & 1][A[i]]++;
            if (!(i & 1))
                arr[A[i]].push_back(i);
        }
        init(1, 1, N);

        for (int i = 1; i <= N; i++) {
            val = cnt[1][i];
            for (int j = 0; j < arr[i].size(); j++) {
                if (cur[A[arr[i][j] - 1]] == 0)
                    cur[A[arr[i][j] - 1]] = 1;
                if (arr[i][j] > 1 && arr[i][j] < N && A[arr[i][j] - 1] == A[arr[i][j] + 1])
                    cur[A[arr[i][j] - 1]] += 2;
                else {
                    update(1, 1, N, A[arr[i][j] - 1], -(cur[A[arr[i][j] - 1]] + 1) / 2), cur[A[arr[i][j] - 1]] = 0;
                    if (arr[i][j] < N)
                        cur[A[arr[i][j] + 1]] = 2;
                }
                if (arr[i][j] < N && (j + 1 == arr[i].size() || arr[i][j + 1] - arr[i][j] > 2))
                    update(1, 1, N, A[arr[i][j] + 1], -cur[A[arr[i][j] + 1]] / 2), cur[A[arr[i][j] + 1]] = 0;
            }
            val += max(query(1, 1, N, 1, i - 1), query(1, 1, N, i + 1, N)), res = min(res, N - val);
            for (int j = 0; j < arr[i].size(); j++) {
                if (cur[A[arr[i][j] - 1]] == 0)
                    cur[A[arr[i][j] - 1]] = 1;
                if (arr[i][j] > 1 && arr[i][j] < N && A[arr[i][j] - 1] == A[arr[i][j] + 1])
                    cur[A[arr[i][j] - 1]] += 2;
                else {
                    update(1, 1, N, A[arr[i][j] - 1], (cur[A[arr[i][j] - 1]] + 1) / 2), cur[A[arr[i][j] - 1]] = 0;
                    if (arr[i][j] < N)
                        cur[A[arr[i][j] + 1]] = 2;
                }
                if (arr[i][j] < N && (j + 1 == arr[i].size() || arr[i][j + 1] - arr[i][j] > 2))
                    update(1, 1, N, A[arr[i][j] + 1], cur[A[arr[i][j] + 1]] / 2), cur[A[arr[i][j] + 1]] = 0;
            }
        }

        cout << res << '\n';
    }

    return 0;
}