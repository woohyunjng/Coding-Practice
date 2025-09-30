#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, K, X, V;
    vector<int> arr;

    cin >> T;
    while (T--) {
        cin >> N >> K, V = 1, arr.clear();
        while (K--)
            cin >> X, V ^= 1ll << (X - 1);
        for (int i = 0; i < N; i++)
            if (V & (1ll << i))
                arr.push_back(i + 1);

        cout << N << ' ' << arr.size() << '\n';
        for (int i : arr)
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}