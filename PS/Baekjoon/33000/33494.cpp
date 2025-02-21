#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 3000000;
const int BUCKET = 3000;
const int MAX_QUERY = 30000;

int A[MAX], tree[BUCKET], V[BUCKET], D[BUCKET], cnt[BUCKET][MAX_QUERY], G[BUCKET];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, Q, T, X, Y, S, SQ, TX, TY, Z, R, fixed;

    cin >> N >> K, SQ = (int)sqrt(N);
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    cin >> Q, fixed = min(K, Q);

    for (int i = 1; i <= N; i++) {
        V[i / SQ] += A[i] / K, X = (K - A[i] % K) % K;
        tree[i / SQ] += A[i];
        if (X <= fixed)
            cnt[i / SQ][X]++;
    }

    while (Q--) {
        cin >> T >> X >> Y;
        if (T == 1) {
            for (; X % SQ && X <= Y; X++) {
                A[X]++, Z = A[X] + G[X / SQ], tree[X / SQ]++;
                if (Z % K == 0)
                    V[X / SQ]++;
                TX = (K - (Z - 1) % K + D[X / SQ]) % K;
                if (TX <= fixed)
                    cnt[X / SQ][TX]--;
                TX = (TX - 1 + K) % K;
                if (TX <= fixed)
                    cnt[X / SQ][TX]++;
            }
            for (; (Y + 1) % SQ && X <= Y; Y--) {
                A[Y]++, Z = A[Y] + G[Y / SQ], tree[Y / SQ]++;
                if (Z % K == 0)
                    V[Y / SQ]++;
                TY = (K - (Z - 1) % K + D[Y / SQ]) % K;
                if (TY <= fixed)
                    cnt[Y / SQ][TY]--;
                TY = (TY - 1 + K) % K;
                if (TY <= fixed)
                    cnt[Y / SQ][TY]++;
            }
            for (; X <= Y; X += SQ)
                D[X / SQ] = (D[X / SQ] + 1) % K, V[X / SQ] += cnt[X / SQ][D[X / SQ]], G[X / SQ]++, tree[X / SQ] += SQ;
        } else {
            S = 0, R = 0, TX = X, TY = Y;
            for (; TX % SQ && TX <= TY; TX++)
                S += (A[TX] + G[TX / SQ]) / K, R += A[TX] + G[TX / SQ];
            for (; (TY + 1) % SQ && TX <= TY; TY--)
                S += (A[TY] + G[TY / SQ]) / K, R += A[TY] + G[TY / SQ];
            for (; TX <= TY; TX += SQ)
                S += V[TX / SQ], R += tree[TX / SQ];
            cout << R - S * K << '\n';
        }
    }

    return 0;
}