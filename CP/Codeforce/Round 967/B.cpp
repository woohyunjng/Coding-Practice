#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, l, r, X;
    cin >> T;

    while (T--) {
        cin >> N;
        if (!(N & 1))
            cout << -1 << '\n';
        else {
            l = 1, r = N, X = 1;
            while (l <= r) {
                if (l == r)
                    arr[l++] = X++;
                else {
                    arr[l++] = X++;
                    arr[r--] = X++;
                }
            }

            for (int i = 1; i <= N; i++)
                cout << arr[i] << ' ';
            cout << '\n';
        }
    }

    return 0;
}