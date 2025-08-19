#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500001;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, P, S = 0;
    priority_queue<int> pq;

    cin >> N >> P;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++) {
        pq.push(-A[i]), S += A[i];
        while (!pq.empty() && S + pq.top() >= P)
            S += pq.top(), pq.pop();
        cout << (S < P ? -1 : (int)pq.size()) << ' ';
    }
    cout << '\n';

    return 0;
}