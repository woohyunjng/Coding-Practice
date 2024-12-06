#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X;
    cin >> N >> M;

    deque<pr> dq;
    for (int i = 1; i <= 2 * M - 1; i++) {
        cin >> X;
        while (!dq.empty() && dq.back().first < X)
            dq.pop_back();
        dq.push_back({X, i});
    }
    cout << dq.front().first << ' ';

    for (int i = 2 * M; i <= N; i++) {
        cin >> X;
        while (!dq.empty() && dq.back().first < X)
            dq.pop_back();
        while (!dq.empty() && dq.front().second <= i - 2 * M + 1)
            dq.pop_front();
        dq.push_back({X, i});
        cout << dq.front().first << ' ';
    }

    return 0;
}