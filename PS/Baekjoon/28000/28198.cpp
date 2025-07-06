#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;

int N, A[MAX], S[MAX];

int solve(int T) {
    priority_queue<int> L;
    priority_queue<int, vector<int>, greater<int>> R;

    int ans = 0, l = -(T ^ 1), r = N + 1 + T;

    while (true) {
        ans++;
        if (!T) {
            l += 2;
            for (int i = max(1, l - 1); i <= min(l, r - 1); i++)
                L.push(A[i]);
            for (int i = 1; i <= l - r + 1; i++)
                L.push(R.top()), R.pop();
            if (l >= r && L.top() == l)
                return ans;
        } else {
            r -= 2;
            for (int i = min(N, r + 1); i >= max(r, l + 1); i--)
                R.push(A[i]);
            for (int i = 1; i <= l - r + 1; i++)
                R.push(L.top()), L.pop();
            if (l >= r && R.top() == r)
                return ans;
        }

        if (l < r && (L.empty() || L.top() == l) && (R.empty() || R.top() == r) && (S[r - 1] - S[l] == r - l - 1))
            return ans;

        T ^= 1;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int ans[2] = {MAX, MAX}, X;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], S[i] = S[i - 1] + (A[i] == i);
    if (S[N] == N)
        ans[0] = 0;

    for (int i = 0; i < 2; i++)
        ans[i] = min(ans[i], solve(i));
    X = ans[0] < ans[1] ? 0 : 1;

    for (int i = 1; i <= ans[X]; i++)
        cout << ((i + X) & 1 ? 'P' : 'S');
    cout << ".\n";

    return 0;
}