#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cout << (i == 1 ? 1 : i / 2) * (N - (i + 1) / 2) << ' ';
    cout << '\n';

    return 0;
}