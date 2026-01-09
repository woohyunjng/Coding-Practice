#include <bits/stdc++.h>
#define int long long
#define double long double

using namespace std;

const int MAX = 2000001;

typedef array<double, 3> tp;

int S[MAX], T[MAX], A[MAX], B[MAX];
double P[MAX], dp[MAX];

vector<int> in[MAX];
vector<tp> val[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, N, K, C = 0;
    vector<int> comp;
    vector<tp> upd;

    cin >> M >> N >> K;
    for (int i = 0; i < M; i++) {
        cin >> A[C] >> B[C] >> S[C] >> T[C] >> P[C];
        if (T[C] > K)
            continue;
        comp.push_back(S[C]), comp.push_back(T[C] + 1), C++;
    }
    M = C;

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), C = comp.size();
    for (int i = 0; i < M; i++) {
        S[i] = lower_bound(comp.begin(), comp.end(), S[i]) - comp.begin();
        T[i] = lower_bound(comp.begin(), comp.end(), T[i] + 1) - comp.begin();
        in[T[i]].push_back(i);
    }

    dp[1] = 1.0;
    for (int i = C - 1; i >= 0; i--) {
        for (tp j : val[i])
            upd.push_back({j[0], j[1] * j[2] + (1.0 - j[1]) * dp[(int)j[0]], 0});
        for (tp j : upd)
            dp[(int)j[0]] = max(dp[(int)j[0]], j[1]);
        for (int j : in[i])
            val[S[j]].push_back({(double)A[j], P[j], dp[B[j]]});
        upd.clear();
    }

    cout << fixed << setprecision(6) << dp[0] << '\n';

    return 0;
}