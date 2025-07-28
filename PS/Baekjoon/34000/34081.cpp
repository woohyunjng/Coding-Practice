#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500001;

int X[MAX], Y[MAX], C[MAX], V[MAX];

int sqrt(int X) {
    int st = 0, en = 2e9, md, res;
    while (st <= en) {
        md = st + en >> 1;
        if (md * md >= X)
            res = md, en = md - 1;
        else
            st = md + 1;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, L, ans = 0, K;
    vector<int> arr;
    priority_queue<int> pq;

    cin >> N >> L;
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i] >> C[i];
        if (X[i] * X[i] + Y[i] * Y[i] > L * L)
            continue;
        V[i] = L - sqrt(X[i] * X[i] + Y[i] * Y[i]);
        arr.push_back(i);
    }

    sort(arr.begin(), arr.end(), [](int x, int y) { return V[x] > V[y]; }), K = 0;
    while (K < arr.size()) {
        if (K > 0)
            for (int i = 0; i < V[arr[K - 1]] - V[arr[K]] && !pq.empty(); i++)
                ans += pq.top(), pq.pop();

        L = V[arr[K]];
        while (K < arr.size() && V[arr[K]] == L)
            pq.push(C[arr[K]]), K++;
    }

    if (!arr.empty())
        for (int i = 0; i <= V[arr.back()] && !pq.empty(); i++)
            ans += pq.top(), pq.pop();

    cout << ans << '\n';

    return 0;
}