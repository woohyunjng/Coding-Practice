#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

#define MAX 200100
#define MOD 998244353

using namespace std;
typedef pair<int, int> pr;

int A[MAX], B[MAX], curA[MAX], curB[MAX];

long long inv(int N) {
    long long res = 1, K = MOD - 2;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        N = (long long)N * N % MOD, K >>= 1;
    }
    return res;
}

void m_erase(ordered_set &st, int X) {
    int index = st.order_of_key(X);
    st.erase(st.find_by_order(index));
}

void solve() {
    int N, Q, O, X, Y, K;
    long long res = 1;
    ordered_set stA, stB;

    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
        cin >> A[i], curA[i] = A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i], curB[i] = B[i];

    sort(A + 1, A + N + 1), sort(B + 1, B + N + 1);
    for (int i = 1; i <= N; i++) {
        res = res * min(A[i], B[i]) % MOD;
        stA.insert(A[i]), stB.insert(B[i]);
    }
    cout << res << ' ';

    while (Q--) {
        cin >> O >> X;
        if (O == 1) {
            curA[X]++, K = curA[X];
            X = stA.order_of_key(K);
            m_erase(stA, K - 1), stA.insert(K);

            Y = *stB.find_by_order(X - 1);
            res = res * inv(min(K - 1, Y)) % MOD;
            res = res * min(K, Y) % MOD;
        } else {
            curB[X]++, K = curB[X];
            X = stB.order_of_key(K);
            m_erase(stB, K - 1), stB.insert(K);

            Y = *stA.find_by_order(X - 1);
            res = res * inv(min(K - 1, Y)) % MOD;
            res = res * min(K, Y) % MOD;
        }

        cout << res << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}