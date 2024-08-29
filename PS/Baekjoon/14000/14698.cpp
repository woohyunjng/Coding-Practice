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

    int N, T, A, B, res = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> T;

    while (T--) {
        cin >> N;
        res = 1;

        for (int i = 1; i <= N; i++) {
            cin >> A;
            pq.push(A);
        }

        while (pq.size() >= 2) {
            A = pq.top(), pq.pop();
            B = pq.top(), pq.pop();

            res = (res * (A * B % MOD)) % MOD;
            pq.push(A * B);
        }

        while (!pq.empty())
            pq.pop();

        cout << res << '\n';
    }

    return 0;
}