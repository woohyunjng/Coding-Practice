#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100000;

bool is_prime(int K) {
    if (K == 1)
        return false;
    for (int i = 2; i * i <= K; i++)
        if (K % i == 0)
            return false;
    return true;
}

int ans[MAX + 1];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, X, Y, Z;
    bool flag;

    for (int i = 1; i <= MAX; i++) {
        ans[i] = ans[i - 1], flag = is_prime(i + 1);
        X = i, Y = 0, Z = 1;
        while (X > 9 && flag) {
            Y = (Y + Z * (X % 10)), Z *= 10, X /= 10;
            flag &= is_prime(X * Y + 1);
        }
        ans[i] += flag;
    }

    cin >> T;
    while (T--)
        cin >> N, cout << ans[N] << '\n';
}