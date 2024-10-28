#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 4> tp;

int A[MAX], res[MAX], two[MAX * 30];

void solve() {
    int N, X = 0, Y = 0, Z = 0, last = 0;
    tp P, Q;
    cin >> N;

    stack<tp> st;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++) {
        X = 0;
        while ((A[i] & 1) == 0)
            A[i] >>= 1, X++;
        st.push({A[i], X, A[i], A[i] * two[X] % MOD});
        res[i] = (res[i - 1] + st.top()[3]) % MOD;

        while (st.size() > 1) {
            P = st.top(), st.pop();
            Q = st.top(), st.pop();

            res[i] = (res[i] - P[3] - Q[3] + MOD * 2) % MOD;

            double Z = Q[0];
            for (int j = 0; j < P[1]; j++)
                Z /= 2;

            if (Z <= P[0]) {
                P[1] += Q[1];
                P[2] = (P[2] + Q[2]) % MOD;
                P[3] = (P[2] - P[0] + two[P[1]] * P[0] + MOD) % MOD;
                st.push(P);

                res[i] = (res[i] + P[3] + MOD) % MOD;
            } else {
                st.push(Q);
                st.push(P);

                res[i] = (res[i] + P[3] + Q[3]) % MOD;
                break;
            }
        }
    }

    for (int i = 1; i <= N; i++)
        cout << res[i] << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;
    cin >> T;

    two[0] = 1;
    for (int i = 1; i < 30 * MAX; i++)
        two[i] = (two[i - 1] * 2) % MOD;

    while (T--)
        solve();

    return 0;
}