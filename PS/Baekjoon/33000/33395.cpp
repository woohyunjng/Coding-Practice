#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1'000'001;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0;
    priority_queue<int> pq;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], pq.push(0);
    sort(A + 1, A + N + 1);

    for (int i = 1; i <= N; i++) {
        A[i] = i - A[i];
        if (pq.empty() || pq.top() <= A[i])
            pq.push(A[i]);
        else {
            ans += pq.top() - A[i], pq.pop();
            pq.push(A[i]), pq.push(A[i]);
        }
    }

    cout << ans << '\n';

    return 0;
}