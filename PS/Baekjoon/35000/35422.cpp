#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1000001;

int H[MAX], A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S = 0, ans = 0;

    cin >> N;
    if (N & 1) {
        cout << -1 << '\n';
        return 0;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i <= N; i++)
        cin >> H[i];
    for (int i = 1; i <= N; i++) {
        A[i] = H[i] - H[i - 1], S--;
        if (A[i] < -1)
            ans += -1 - A[i], A[i] = -1;
        else if (A[i] > 1)
            ans += A[i] - 1, A[i] = 1;
        ans += A[i] + 1, pq.push({-A[i] * 2});
        while (S < 0)
            S += 2, ans += pq.top(), pq.pop();
    }

    cout << (ans >> 1) << '\n';

    return 0;
}