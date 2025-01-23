#include <bits/stdc++.h>
#define int long long

#define MAX 400000

using namespace std;

vector<int> lst[MAX], arr[MAX];
int M, P[MAX], L[MAX], R[MAX], ans[MAX], QR[MAX][3], tree[MAX];

int query(int x) {
    int res = 0;
    while (x) {
        res += tree[x];
        x -= x & (-x);
    }
    return res;
}

void update(int x, int v) {
    while (x <= M) {
        tree[x] += v;
        x += x & (-x);
    }
}

void update(int l, int r, int v) { update(l, v), update(r + 1, -v); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, val;
    bool flag;
    cin >> N >> M;

    for (int i = 1; i <= M; i++)
        cin >> X, lst[X].push_back(i);

    for (int i = 1; i <= N; i++)
        cin >> P[i];

    cin >> Q;
    for (int i = 1; i <= Q; i++)
        cin >> QR[i][0] >> QR[i][1] >> QR[i][2];

    for (int i = 1; i <= N; i++)
        L[i] = 1, R[i] = Q;

    while (true) {
        for (int i = 1; i <= M; i++)
            tree[i] = 0;
        flag = false;

        for (int i = 1; i <= N; i++) {
            if (L[i] <= R[i])
                flag = true, arr[L[i] + R[i] >> 1].push_back(i);
        }
        if (!flag)
            break;

        for (int i = 1; i <= Q; i++) {
            if (QR[i][0] <= QR[i][1])
                update(QR[i][0], QR[i][1], QR[i][2]);
            else {
                update(QR[i][0], M, QR[i][2]);
                update(1, QR[i][1], QR[i][2]);
            }

            for (int j : arr[i]) {
                val = 0, flag = false;
                for (int k : lst[j])
                    val += query(k), flag |= val >= P[j];
                if (flag)
                    ans[j] = i, R[j] = i - 1;
                else
                    L[j] = i + 1;
            }

            arr[i].clear();
        }
    }

    for (int i = 1; i <= N; i++) {
        if (ans[i] == 0)
            cout << "NIE\n";
        else
            cout << ans[i] << '\n';
    }

    return 0;
}