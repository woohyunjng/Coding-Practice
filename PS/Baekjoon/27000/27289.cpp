#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500001;

int X[MAX], L[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0, V = 0;
    vector<int> arr;
    priority_queue<int> pq;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> X[i], arr.push_back(i);
    for (int i = 1; i <= N; i++)
        cin >> L[i];

    sort(arr.begin(), arr.end(), [&](int x, int y) { return X[x] + L[x] == X[y] + L[y] ? X[x] < X[y] : X[x] + L[x] < X[y] + L[y]; });
    for (int i : arr) {
        ans++, V += X[i], pq.push(X[i]);
        while (V > X[i] + L[i])
            ans--, V -= pq.top(), pq.pop();
    }

    cout << ans << '\n';

    return 0;
}