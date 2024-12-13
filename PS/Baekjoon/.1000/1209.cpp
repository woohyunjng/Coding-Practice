#include <bits/stdc++.h>
#define int long long

#define MAX 2100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N, A[MAX];

int get() {
    priority_queue<int> pq;
    int res = 0;

    for (int i = 1; i <= N; i++) {
        if (!pq.empty())
            pq.pop();
        pq.push(A[i]);
        pq.push(A[i]);

        res += abs(pq.top() - A[i]);
    }

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int res = INF;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    res = get();
    reverse(A + 1, A + N + 1);
    res = min(res, get());

    cout << res << '\n';

    return 0;
}