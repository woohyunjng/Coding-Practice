#include <bits/stdc++.h>
#define int long long

#define MAX 200100
using namespace std;

int N, sm[MAX], A[MAX], tree[MAX];

int query(int idx) {
    int res = 0;
    idx++;
    if (idx <= 0)
        return 0;
    while (idx) {
        res += tree[idx];
        idx -= idx & -idx;
    }
    return res;
}

void update(int idx, int val) {
    idx++;
    while (idx <= N + 1) {
        tree[idx] += val;
        idx += idx & -idx;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int K, L, st, en, mid, res, cnt;
    cin >> N >> K >> L;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    st = 1, en = N;
    while (st <= en) {
        mid = st + en >> 1, cnt = 0;
        for (int i = 1; i <= N; i++)
            sm[i] = sm[i - 1] + (A[i] <= mid), tree[i] = 0;
        tree[N + 1] = 0;

        update(0, 1);
        for (int i = 1; i <= N; i++)
            cnt += query(sm[i] - K), update(sm[i], 1);
        if (cnt >= L)
            res = mid, en = mid - 1;
        else
            st = mid + 1;
    }

    cout << res << '\n';

    return 0;
}