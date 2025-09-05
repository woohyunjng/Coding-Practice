#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;
const int MAX = 100001;

int D[MAX], W[MAX], C[MAX], T[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X, ans = 0;
    vector<int> res;

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> D[i] >> W[i];

    set<int> st;

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr V;

    for (int i = 1; i <= min(N, K); i++)
        C[i] = i, pq.push({W[i], -i});

    for (int i = K + 1; i <= N; i++) {
        if (st.empty()) {
            X = pq.top()[0];
            while (!pq.empty() && pq.top()[0] == X) {
                V = pq.top(), pq.pop(), res.push_back(D[C[-V[1]]]);
                st.insert(-V[1]), T[-V[1]] = V[0];
            }
        }
        X = *st.begin(), st.erase(st.begin());
        C[X] = i, pq.push({T[X] + W[i], -X});
    }

    while (!pq.empty())
        V = pq.top(), pq.pop(), res.push_back(D[C[-V[1]]]);

    for (int i = 1; i <= N; i++)
        ans += i * res[i - 1];
    cout << ans << '\n';

    return 0;
}