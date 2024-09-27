#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX];
map<int, int> res;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, Q, A;
    cin >> T;

    while (T--) {
        cin >> N >> Q;

        for (int i = 1; i <= N; i++)
            cin >> arr[i];

        res.clear();

        for (int i = 1; i <= N; i++)
            res[i * (N - i + 1) - 1]++;

        for (int i = 1; i < N; i++)
            res[i * (N - i)] += arr[i + 1] - arr[i] - 1;

        while (Q--) {
            cin >> A;
            if (res.count(A))
                cout << res[A] << ' ';
            else
                cout << 0 << ' ';
        }
        cout << '\n';
    }

    return 0;
}