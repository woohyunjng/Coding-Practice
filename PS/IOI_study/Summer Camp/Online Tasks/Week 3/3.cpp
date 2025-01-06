#include <bits/stdc++.h>
#define int long long

#define MAX 200100
using namespace std;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0, K = 0;
    priority_queue<int> pq;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    pq.push(A[1]), pq.push(0);
    res += abs(A[1] - pq.top()) + abs(pq.top());

    for (int i = 2; i <= N; i++) {
        if (A[i - 1] < A[i])
            K -= A[i] - A[i - 1];
        pq.pop();
        pq.push(A[i] + K), pq.push(K);
        res += abs(A[i] - pq.top() + K) + abs(pq.top() - K);
    }

    cout << res;

    return 0;
}