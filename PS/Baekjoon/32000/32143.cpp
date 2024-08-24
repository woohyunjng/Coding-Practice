#include <bits/stdc++.h>
#define int long long

#define endl '\n'
#define INF 0x7f7f7f7f7f7f7f7f
#define MAX 201001

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, N, Q, X, K, cur = 0;
    cin >> H;

    cin >> N >> Q;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= N; i++) {
        cin >> X;
        pq.push(X);
        cur += X;
    }

    while (!pq.empty()) {
        K = pq.top();
        if (cur - K >= H) {
            pq.pop();
            cur -= K;
            N--;
        } else
            break;
    }

    if (cur >= H)
        cout << N << '\n';
    else
        cout << -1 << '\n';

    while (Q--) {
        cin >> X;
        pq.push(X);

        cur += X;
        N++;

        while (!pq.empty()) {
            K = pq.top();
            if (cur - K >= H) {
                pq.pop();
                cur -= K;
                N--;
            } else
                break;
        }

        if (cur >= H)
            cout << N << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}