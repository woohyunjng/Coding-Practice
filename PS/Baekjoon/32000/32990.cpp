#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res;
    vector<int> arr;

    cin >> N, res = N * N / 4;

    cout << res << '\n';
    if (res > 1000000)
        return 0;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < min(i, N - i); j++) {
            arr.clear();
            for (int k = 0; i * k + i + j + 1 <= N; k++)
                arr.push_back(i * k + j + 1);
            cout << arr.size() << ' ';
            for (int k : arr)
                cout << k << ' ' << k + i << ' ';
            cout << '\n';
        }
    }

    return 0;
}