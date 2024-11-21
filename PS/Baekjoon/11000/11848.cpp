#include <bits/stdc++.h>
#define int long long

#define MAX 300100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], B[MAX], state[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, S, res = 0;
    pr X, Y, Z;
    cin >> N >> M >> S;

    priority_queue<pr> pq_A, pq_B, pq_X;

    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
        pq_A.push({A[i], i});
    }

    while (M--) {
        X = pq_A.top(), pq_A.pop();
        res += X.first, state[X.second] = 1;
    }

    for (int i = 1; i <= N; i++) {
        if (state[i] == 1)
            pq_B.push({B[i] - A[i], i});
        else
            pq_X.push({B[i], i});
    }

    while (S--) {
        while (!pq_A.empty() && state[pq_A.top().second])
            pq_A.pop();
        while (!pq_B.empty() && state[pq_B.top().second] != 1)
            pq_B.pop();
        while (!pq_X.empty() && state[pq_X.top().second])
            pq_X.pop();

        X = pq_B.top(), Y = pq_A.top();
        Z = pq_X.top();

        if (X.first + Y.first >= Z.first) {
            res += X.first + Y.first;
            pq_A.pop(), pq_B.pop(), state[X.second] = 2, state[Y.second] = 1;
            pq_A.push({A[X.second], X.second}), pq_B.push({B[Y.second] - A[Y.second], Y.second});
        } else {
            res += Z.first;
            pq_X.pop(), state[Z.second] = 2;
        }
    }

    cout << res << '\n';

    return 0;
}