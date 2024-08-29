#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int sm[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, X, Y, res = 0, A, B;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> N >> M >> K >> X >> Y;
    res = K * (X + Y);

    for (int i = 1; i <= N; i++) {
        cin >> A >> B;
        pq.push(A * X - B * Y);
    }

    while (M--) {
        A = pq.top(), pq.pop();
        res += A;
    }

    cout << res;

    return 0;
}