#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 4> tp;

const int MAX = 200001;
const int BUCKET = 450;

int A[MAX], L[MAX], R[MAX], ans[MAX], V[MAX][2],
    S[BUCKET][BUCKET], C[BUCKET][BUCKET], SB[BUCKET], CB[BUCKET];
vector<tp> val[MAX];

void update(int x) {
    int K = x / BUCKET;
    for (int i = K; i < BUCKET; i++)
        SB[i] += x, CB[i]++;
    for (int i = x; i <= (K + 1) * BUCKET - 1; i++)
        S[K][i - K * BUCKET] += x, C[K][i - K * BUCKET]++;
}

int query(int x) {
    int ans = 0, K = x / BUCKET;
    ans += x * (CB[K - 1] + C[K][x - K * BUCKET]);
    ans -= SB[K - 1] + S[K][x - K * BUCKET];
    ans -= x * (CB[BUCKET - 1] - CB[K] + C[K][BUCKET - 1] - C[K][x - K * BUCKET]);
    ans += SB[BUCKET - 1] - SB[K] + S[K][BUCKET - 1] - S[K][x - K * BUCKET];
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, PL, PR, D = 0;
    vector<int> arr;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= Q; i++)
        cin >> L[i] >> R[i], arr.push_back(i);
    sort(arr.begin(), arr.end(), [&](int x, int y) {
        if (L[x] / BUCKET != L[y] / BUCKET)
            return L[x] < L[y];
        return R[x] < R[y];
    });

    PL = 1, PR = 1;
    for (int i : arr) {
        if (PR < R[i])
            val[PL - 1].push_back({-1, PR + 1, R[i], i}), PR = R[i];
        if (PL > L[i])
            val[PR].push_back({1, L[i], PL - 1, i}), PL = L[i];
        if (PR > R[i])
            val[PL - 1].push_back({1, R[i] + 1, PR, i}), PR = R[i];
        if (PL < L[i])
            val[PR].push_back({-1, PL, L[i] - 1, i}), PL = L[i];
    }

    for (int i = 1; i <= N; i++) {
        update(A[i]);
        for (tp j : val[i])
            for (int k = j[1]; k <= j[2]; k++)
                ans[j[3]] += query(A[k]) * j[0];
        V[i][0] = query(A[i]), V[i][1] = query(A[i + 1]);
    }

    PL = 1, PR = 1;
    for (int i : arr) {
        ans[i] += D;
        while (PR < R[i])
            ans[i] += V[PR++][1];
        while (PL > L[i])
            ans[i] -= V[--PL][0];
        while (PR > R[i])
            ans[i] -= V[--PR][1];
        while (PL < L[i])
            ans[i] += V[PL++][0];
        D = ans[i];
    }

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';

    return 0;
}