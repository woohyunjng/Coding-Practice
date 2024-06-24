#include <bits/stdc++.h>
#define int long long
#define MAX 100100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, X, A, B, res = -1;
    cin >> N >> X;

    while (N--) {
        cin >> A >> B;
        if (A + B <= X)
            res = max(res, A);
    }

    cout << res;

    return 0;
}