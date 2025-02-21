#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200000;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, V;

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= K; i++)
        pq.push(A[i]);

    for (int i = K + 1; i <= N; i++) {
        pq.push(A[i]);
        V = pq.top(), pq.pop();
        cout << V << ' ';
    }

    for (int i = 1; i <= K; i++) {
        V = pq.top(), pq.pop();
        cout << V << ' ';
    }
    cout << '\n';

    return 0;
}