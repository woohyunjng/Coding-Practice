#include <bits/stdc++.h>
using namespace std;

int N, K, ans = 1;

void get(int X) {
    if (X > K)
        return;
    ans = ans * (N - K + X) / X;
    get(X + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> K, N--, K--;

    get(1);

    cout << ans << '\n';

    return 0;
}