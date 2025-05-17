#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 500001;

int gcd(int X, int Y) { return Y == 0 ? X : gcd(Y, X % Y); }

int A[MAX], S[MAX];
vector<pr> lft[MAX], rht[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, L, R, last_ans = 0, X, Y;

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++) {
        lft[i].push_back({A[i], 1});
        for (pr j : lft[i - 1]) {
            X = gcd(j[0], A[i]), Y = j[1];
            if (lft[i].back()[0] == X)
                lft[i].back()[1] += Y;
            else
                lft[i].push_back({X, Y});
        }

        for (pr j : lft[i])
            S[i] += j[0] * j[1];
        S[i] += S[i - 1];
    }

    for (int i = N; i >= 1; i--) {
        rht[i].push_back({A[i], 1});
        for (pr j : rht[i + 1]) {
            X = gcd(j[0], A[i]), Y = j[1];
            if (rht[i].back()[0] == X)
                rht[i].back()[1] += Y;
            else
                rht[i].push_back({X, Y});
        }
    }

    cin >> Q;
    while (Q--) {
        cin >> L >> R;
        L ^= last_ans, R ^= last_ans;

        last_ans = S[R] - S[L - 1];

        for (pr i : lft[L - 1]) {
            X = L - 1;
            for (pr j : rht[L]) {
                if (X + j[1] > R) {
                    last_ans -= gcd(i[0], j[0]) * i[1] * (R - X);
                    break;
                } else
                    last_ans -= gcd(i[0], j[0]) * i[1] * j[1], X += j[1];
            }
        }

        cout << last_ans << '\n';
    }

    return 0;
}