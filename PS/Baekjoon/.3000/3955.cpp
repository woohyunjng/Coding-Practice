#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

tp extended_gcd(int A, int B) {
    if (B == 0)
        return {A, 1, 0};
    tp res = extended_gcd(B, A % B);
    return {res[0], res[2], res[1] - A / B * res[2]};
}

int modular_inverse(int K, int X) {
    tp res = extended_gcd(K, X);
    if (res[0] != 1)
        return -1;
    return (res[1] % X + X) % X;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, K, C, res;
    cin >> T;

    while (T--) {
        cin >> K >> C;
        res = modular_inverse(C, K);

        if (K == 1)
            res = C - 1;
        if (C == 1)
            res = K + 1;

        if (res == -1 || res > 1e9)
            cout << "IMPOSSIBLE" << '\n';
        else
            cout << res << '\n';
    }

    return 0;
}