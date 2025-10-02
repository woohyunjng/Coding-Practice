#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 3> tp;

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

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

    int N, A;

    cin >> N >> A;
    cout << N - A << ' ' << modular_inverse(A, N) << '\n';

    return 0;
}