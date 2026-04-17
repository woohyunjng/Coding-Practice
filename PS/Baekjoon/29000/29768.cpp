#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;

    cin >> N >> K;
    for (int i = 1; i <= N - K + 1; i++)
        cout << 'a';
    for (int i = 2; i <= K; i++)
        cout << (char)('a' + (i - 1));
    cout << '\n';

    return 0;
}