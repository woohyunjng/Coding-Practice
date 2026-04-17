#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N;

pr go(int P_1, int P_2, int M) {
    if (P_1 < P_2 && P_2 <= M) {
        if (M == N)
            return {INF, -1};
        return {M + 1 - P_2 + M - P_1, M + 1};
    } else if (P_1 <= M && M < P_2)
        return {M - P_1, P_2};
    else if (P_2 < P_1 && P_1 <= M)
        return {M - P_1, P_2};
    else if (P_2 < M && M < P_1)
        return {P_1 - M, P_2};
    else if (M <= P_2 && P_2 < P_1) {
        if (M == 1)
            return {INF, -1};
        return {P_2 - M + 1 + P_1 - M, M - 1};
    } else if (M < P_1 && P_1 < P_2)
        return {P_1 - M, P_2};
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int P_1, P_2, M, S, res = INF, val;
    pr X;

    cin >> N >> P_1 >> P_2 >> M >> S;

    if (abs(P_1 - M) % 2 == 1 && abs(P_2 - M) % 2 == 0) {
        X = go(P_1, P_2, M);
        val = X.first;
        res = min(res, val + go(M, X.second, S).first);
    } else if (abs(P_2 - M) % 2 == 1 && abs(P_1 - M) % 2 == 0) {
        X = go(P_2, P_1, M);
        val = X.first;
        res = min(res, val + go(M, X.second, S).first);
    } else if (abs(P_1 - M) % 2 == 1 && abs(P_2 - M) % 2 == 1) {
        if (P_1 > P_2)
            swap(P_1, P_2);
        if ((S <= P_1 && P_2 <= M && S == 1) || (M <= P_1 && P_2 <= S && S == N))
            res = -1;
        if (P_2 >= M) {
            X = go(P_1, P_2, M);
            val = X.first;
            res = min(res, val + go(M, X.second, S).first);
        }

        if (P_1 <= M) {
            X = go(P_2, P_1, M);
            val = X.first;
            res = min(res, val + go(M, X.second, S).first);
        }
    }

    cout << (res == INF ? -1 : res) << '\n';

    return 0;
}
