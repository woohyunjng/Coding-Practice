#include <bits/stdc++.h>
#define int long long

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

const int MAX = 600000;
typedef array<int, 2> pr;

int N, A[MAX], B[MAX], tree[MAX], inv[MAX];

int query(int X) {
    int res = 0;
    while (X)
        res += tree[X], X -= X & (-X);
    return res;
}

void update(int X, int V) {
    while (X <= N)
        tree[X] += V, X += X & (-X);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int st, en, md, val, res = 0, cnt = 0;
    vector<int> arr, ans;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i];

    for (int i = 1; i <= N; i++)
        arr.push_back(i);
    sort(arr.begin(), arr.end(), [&](int x, int y) { return A[x] < A[y]; });

    for (int i = 0; i < N; i++)
        A[i] = B[arr[i]];
    arr.clear();
    for (int i = 1; i <= N; i++)
        B[i] = A[i - 1], arr.push_back(i);

    for (int i = 1; i <= N; i++) {
        inv[i] = query(N) - query(B[i]);
        cnt += inv[i], update(B[i], 1);
    }

    if (cnt & 1) {
        cout << "No" << '\n';
        return 0;
    }

    cout << "Yes" << '\n';

    st = 1, en = N;
    while (st <= en) {
        md = st + en >> 1, val = 0;
        for (int i = md + 1; i <= N; i++)
            val += max(0ll, inv[i] - md);
        if (val >= cnt / 2)
            st = md + 1, res = md;
        else
            en = md - 1;
    }

    val = 0;
    for (int i = 1; i <= N; i++)
        val += max(0ll, inv[i] - res);
    cnt = val - cnt / 2;

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr V;

    for (int i = 0; i < res; i++)
        pq.push({B[arr[i]], arr[i]});

    for (int i = res; i < N; i++) {
        pq.push({B[arr[i]], arr[i]});
        V = pq.top(), pq.pop();
        ans.push_back(V[1]);
    }

    while (res--) {
        V = pq.top(), pq.pop();
        ans.push_back(V[1]);
    }

    for (int i = 0; i + 1 < N; i++) {
        if (B[ans[i + 1]] < B[ans[i]] && cnt > 0)
            cnt--, swap(ans[i + 1], ans[i]);
    }

    for (int i : ans)
        cout << i << ' ';
    cout << '\n';

    for (int i : ans)
        cout << B[i] << ' ';
    cout << '\n';

    return 0;
}