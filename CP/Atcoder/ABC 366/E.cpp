#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MAX_VAL 1000000
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int sumX[MAX], sumY[MAX], absX[MAX_VAL * 4], absY[MAX_VAL * 4], absXsm[MAX_VAL * 4], absYsm[MAX_VAL * 4];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, D, A, B, K, res = 0, val;
    cin >> N >> D;

    vector<int> X, Y;

    for (int i = 1; i <= N; i++) {
        cin >> A >> B;
        X.push_back(A);
        Y.push_back(B);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    for (int i = 1; i <= N; i++) {
        sumX[i] = sumX[i - 1] + X[i - 1];
        sumY[i] = sumY[i - 1] + Y[i - 1];
    }

    for (int i = -MAX_VAL * 3; i <= MAX_VAL * 3; i++) {
        K = lower_bound(X.begin(), X.end(), i) - X.begin();
        if (K == N)
            val = i * N - sumX[N];
        else if (K == 0)
            val = sumX[N] - i * N;
        else
            val = i * K - sumX[K] + sumX[N] - sumX[K] - i * (N - K);

        if (0 <= val && val <= D)
            absX[val]++;
    }

    for (int i = -MAX_VAL * 3; i <= MAX_VAL * 3; i++) {
        K = lower_bound(Y.begin(), Y.end(), i) - Y.begin();
        if (K == N)
            val = i * N - sumY[N];
        else if (K == 0)
            val = sumY[N] - i * N;
        else
            val = i * K - sumY[K] + sumY[N] - sumY[K] - i * (N - K);

        if (0 <= val && val <= D)
            absY[val]++;
    }

    absXsm[0] = absX[0];
    absYsm[0] = absY[0];

    for (int i = 1; i <= D; i++) {
        absXsm[i] = absXsm[i - 1] + absX[i];
        absYsm[i] = absYsm[i - 1] + absY[i];
    }

    for (int i = 0; i <= D; i++)
        res += absX[i] * absYsm[D - i];

    cout << res;

    return 0;
}