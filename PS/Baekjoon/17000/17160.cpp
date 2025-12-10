#include <bits/stdc++.h>
#define int long long
#define double long double

using namespace std;

const int MAX = 501;
const int MAX_S = 101;
const int GGB = 2520;

int X[MAX], R[MAX], G[MAX], P[MAX], M[MAX], K[MAX], V[MAX];
double ans[MAX];
bool chk[MAX_S][MAX_S];

int gcd(int A, int B) { return B ? gcd(B, A % B) : A; }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S = 0;
    double F = 1.0, C;

    P[1] = M[1] = 1;
    for (int i = 2; i < MAX_S; i++) {
        if (P[i] != 0)
            continue;
        M[i] = i;
        while (M[i] * i < MAX_S)
            M[i] = M[i] * i;
        for (int j = i; j < MAX_S; j += i)
            P[j] = max(P[j], i);
    }

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> R[i] >> G[i];
        K[i] = P[(R[i] + G[i]) / gcd(GGB, R[i] + G[i])];
    }

    for (int i = 0; i < GGB; i++) {
        for (int j = 1; j < MAX_S; j++)
            fill(chk[j], chk[j] + MAX_S, true), V[j] = M[P[j]];
        C = 1.0;

        for (int j = 0; j < N; j++) {
            if (V[K[j]] != 0)
                C /= (double)V[K[j]];
            V[K[j]] = S = 0;
            for (int k = 0; k < M[K[j]]; k++) {
                if (chk[K[j]][k] && ((k * GGB + i) + X[j]) % (R[j] + G[j]) < R[j])
                    S++;
                chk[K[j]][k] &= ((k * GGB + i) + X[j]) % (R[j] + G[j]) >= R[j];
                V[K[j]] += chk[K[j]][k];
            }
            ans[j] += C * S, C *= (double)V[K[j]];
        }
    }

    cout << fixed << setprecision(12);
    for (int i = 0; i < N; i++)
        cout << ans[i] / GGB << '\n', F -= ans[i] / GGB;

    if (F < 1e-9)
        F = 0.0;
    cout << F << '\n';

    return 0;
}