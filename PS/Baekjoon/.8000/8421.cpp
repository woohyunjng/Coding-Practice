#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int N, ans = 0, X;
    cin >> N, X = sqrt(N);
    for (int i = 1; i <= X; i++)
        ans += N / i;
    for (int i = 1; i < N / X; i++)
        ans += (N / i - N / (i + 1)) * i;
    cout << ans << '\n';
    return 0;
}