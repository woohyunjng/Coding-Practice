#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, Q, A, X;
    vector<int> arr;
    vector<int>::iterator it;
    cin >> T;

    while (T--) {
        cin >> N >> M >> Q;
        arr.clear();
        for (int i = 1; i <= M; i++) {
            cin >> A;
            arr.push_back(A);
        }
        sort(arr.begin(), arr.end());

        while (Q--) {
            cin >> A;
            it = lower_bound(arr.begin(), arr.end(), A);
            if (it == arr.end()) {
                cout << N - *prev(it) << '\n';
            } else if (it == arr.begin()) {
                cout << *it - 1 << '\n';
            } else {
                X = *it - *prev(it) - 1;
                cout << (X + 1) / 2 << '\n';
            }
        }
    }

    return 0;
}