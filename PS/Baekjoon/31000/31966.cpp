#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int S[100100], leaf[100100], leftS[100100], rightS[100100];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, A, B;
    cin >> N;

    S[0] = 1, leaf[0] = 1, leftS[0] = 1, rightS[0] = 1;
    for (int i = 1; i <= N; i++) {
        cin >> A >> B;
        leaf[i] = (leaf[A] + leaf[B]) % MOD;
        rightS[i] = (rightS[B] + rightS[A] + leaf[A] - 1) % MOD;
        leftS[i] = (leftS[A] + leftS[B] + leaf[B] - 1) % MOD;
        S[i] = (S[A] + S[B] + leftS[B] * leaf[A] % MOD + rightS[A] * leaf[B] % MOD - 1) % MOD;
    }

    for (int i = 1; i <= N; i++)
        cout << S[i] << '\n';
}