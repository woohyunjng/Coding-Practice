#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 100001;

int X[MAX], Y[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int K, N, S, T, ans = 0, V;
    char P, Q;
    vector<pr> arr;

    cin >> K >> N;
    for (int i = 1; i <= N; i++) {
        cin >> P >> S >> Q >> T;
        if (P == Q) {
            ans += abs(S - T);
            continue;
        }
        arr.push_back({S, T});
    }

    sort(arr.begin(), arr.end(), [&](pr a, pr b) { return a[0] + a[1] < b[0] + b[1]; });
    N = arr.size(), ans += N;

    priority_queue<int> pq[2];

    function<void(int, int)> push = [&](int x, int y) {
        if (x > y)
            swap(x, y);
        int tx, ty;
        pq[0].push(x), pq[1].push(-y), V += y - x;
        if (pq[0].top() > -pq[1].top()) {
            tx = pq[0].top(), pq[0].pop();
            ty = -pq[1].top(), pq[1].pop();
            pq[0].push(ty), pq[1].push(-tx), V += (tx - ty) * 2;
        }
    };

    while (!pq[0].empty())
        pq[0].pop();
    while (!pq[1].empty())
        pq[1].pop();
    V = 0;
    for (int i = 0; i < N; i++)
        push(arr[i][0], arr[i][1]), X[i] = V;

    while (!pq[0].empty())
        pq[0].pop();
    while (!pq[1].empty())
        pq[1].pop();
    V = 0;
    for (int i = N - 1; i >= 0; i--)
        push(arr[i][0], arr[i][1]), Y[i] = V;

    if (K == 1 && N > 0)
        ans += X[N - 1];
    else if (K == 2 && N > 0) {
        S = min(X[N - 1], Y[0]);
        for (int i = 1; i < N; i++)
            S = min(S, X[i - 1] + Y[i]);
        ans += S;
    }

    cout << ans << '\n';

    return 0;
}