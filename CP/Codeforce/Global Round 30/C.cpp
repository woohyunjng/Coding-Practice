#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int A[MAX], B[MAX], C[MAX];

void solve() {
    int N, M, X = 0, ans = 0;
    vector<int> arr, val;

    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> X, pq.push(X);

    for (int i = 1; i <= M; i++)
        cin >> B[i];

    for (int i = 1; i <= M; i++) {
        cin >> C[i];
        if (C[i] > 0)
            arr.push_back(i);
    }

    sort(arr.begin(), arr.end(), [](int x, int y) { return B[x] > B[y]; });

    while (!pq.empty()) {
        X = pq.top(), pq.pop();
        if (arr.empty() || B[arr.back()] > X) {
            val.push_back(X);
            continue;
        }
        ans++, X = max(X, C[arr.back()]), arr.pop_back(), pq.push(X);
    }

    sort(A + 1, A + N + 1), sort(val.begin(), val.end()), arr.clear();

    for (int i = 1; i <= M; i++) {
        if (C[i] > 0)
            continue;
        arr.push_back(B[i]);
    }

    sort(arr.begin(), arr.end());
    for (int i = N; i >= 1; i--) {
        A[i] = val.back(), val.pop_back();
        while (!arr.empty() && arr.back() > A[i])
            arr.pop_back();
        if (arr.empty())
            break;
        arr.pop_back(), ans++;
    }

    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}