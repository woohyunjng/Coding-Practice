#include <bits/stdc++.h>
#define int long long

#define MAX 200000
using namespace std;

typedef array<int, 4> tp;

int H[MAX], L[MAX], R[MAX], qr[MAX][3], ans[MAX];
tp tree[MAX * 4];
vector<int> arr[MAX], lst[MAX];

tp merge(tp A, tp B) {
    tp res;
    res[0] = max({A[0], B[0], A[2] + B[1]}), res[3] = A[3] + B[3];
    res[1] = A[1], res[2] = B[2];

    if (A[0] == A[3])
        res[1] = A[3] + B[1];
    if (B[0] == B[3])
        res[2] = A[2] + B[3];

    return res;
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = {0, 0, 0, 1};
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void update(int n, int s, int e, int x) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] = {1, 1, 1, 1};
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x), update(n << 1 | 1, m + 1, e, x);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

tp query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return {0, 0, 0, 0};
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return merge(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q;
    bool flag;
    vector<int> Hcomp;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> H[i], Hcomp.push_back(H[i]);
    sort(Hcomp.begin(), Hcomp.end()), Hcomp.erase(unique(Hcomp.begin(), Hcomp.end()), Hcomp.end());

    for (int i = 1; i <= N; i++) {
        H[i] = lower_bound(Hcomp.begin(), Hcomp.end(), H[i]) - Hcomp.begin();
        lst[H[i]].push_back(i);
    }

    cin >> Q;

    for (int i = 1; i <= Q; i++)
        cin >> qr[i][0] >> qr[i][1] >> qr[i][2], L[i] = 0, R[i] = Hcomp.size() - 1;

    while (true) {
        init(1, 1, N), flag = false;
        for (int i = 1; i <= Q; i++)
            if (L[i] <= R[i])
                flag = true, arr[L[i] + R[i] >> 1].push_back(i);
        if (!flag)
            break;

        for (int i = Hcomp.size() - 1; i >= 0; i--) {
            for (int j : lst[i])
                update(1, 1, N, j);
            for (int j : arr[i]) {
                if (query(1, 1, N, qr[j][0], qr[j][1])[0] >= qr[j][2])
                    L[j] = i + 1, ans[j] = i;
                else
                    R[j] = i - 1;
            }
            arr[i].clear();
        }
    }

    for (int i = 1; i <= Q; i++)
        cout << Hcomp[ans[i]] << '\n';

    return 0;
}