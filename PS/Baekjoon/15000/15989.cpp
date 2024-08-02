#include <bits/stdc++.h>
#define int long long
#define MAX 10010

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, res = 0;
    cin >> T;

    while (T--) {
        cin >> N;
        res = 0;
        for (int i = 0; i * 3 <= N; i++)
            res += (N - i * 3) / 2 + 1;
        cout << res << '\n';
    }

    return 0;
}