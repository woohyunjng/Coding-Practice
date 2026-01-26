#include "meeting.h"
#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 3> tp;

const int MAX = 5001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int S[MAX], E[MAX], W[MAX], dp[MAX], SM[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, V, X, Y;
    cin >> N >> K;
    vector<tp> arr;
    vector<int> comp, val;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= N; i++) {
        cin >> S[i] >> E[i] >> W[i];
        comp.push_back(S[i]), comp.push_back(E[i]);
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), V = comp.size();
    for (int i = 1; i <= N; i++) {
        S[i] = lower_bound(comp.begin(), comp.end(), S[i]) - comp.begin() + 1;
        E[i] = lower_bound(comp.begin(), comp.end(), E[i]) - comp.begin() + 1;
        arr.push_back({S[i], E[i], W[i]});
    }

    sort(arr.begin(), arr.end(), [&](tp x, tp y) { return x[0] == y[0] ? x[1] < y[1] : x[0] < y[0]; });
    for (int i = 1; i <= N; i++) {
        S[i] = arr[i - 1][0], E[i] = arr[i - 1][1], W[i] = arr[i - 1][2];
        SM[i] = SM[i - 1] + W[i];
    };

    for (int i = 1; i <= V; i++) {
        val.clear(), dp[i] = dp[i - 1];
        for (int j = 1; j <= N; j++)
            if (E[j] <= i)
                val.push_back(j);
        X = (int)val.size() - 1, Y = 0;

        for (int j = i; j >= 1; j--) {
            while (X >= 0 && S[val[X]] >= j)
                pq.push(W[val[X]]), Y += W[val[X--]];
            while (pq.size() > K)
                Y -= pq.top(), pq.pop();
            dp[i] = max(dp[i], dp[j - 1] + Y);
        }

        while (!pq.empty())
            pq.pop();
    }

    cout << SM[N] - dp[V] << '\n';
}
