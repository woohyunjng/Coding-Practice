#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

void solve() {
    int N, A, B;
    vector<pr> arr;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A >> B;
        arr.push_back({A, B});
    }

    sort(arr.begin(), arr.end(), [](pr a, pr b) {
        int aX, aY, bX, bY;
        aX = min(a.first, a.second), aY = max(a.first, a.second);
        bX = min(b.first, b.second), bY = max(b.first, b.second);

        return aX < bX || (aX == bX && aY < bY);
    });

    for (pr p : arr)
        cout << p.first << ' ' << p.second << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;
    cin >> T;

    while (T--)
        solve();

    return 0;
}