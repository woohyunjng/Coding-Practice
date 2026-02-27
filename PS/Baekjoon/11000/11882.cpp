#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, D = 0, ans = 0;
    string S, ans_S;

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr K;

    cin >> N >> S, ans_S = S;
    for (int i = 0; i < N; i++) {
        if (S[i] == '(')
            D++;
        else if (S[i] == ')')
            D--;
        else {
            cin >> X >> Y, D--, ans_S[i] = ')';
            ans += Y, pq.push({X - Y, i});
        }

        while (D < 0) {
            D += 2, K = pq.top(), pq.pop();
            ans += K[0], ans_S[K[1]] = '(';
        }
    }

    cout << ans << '\n'
         << ans_S << '\n';

    return 0;
}