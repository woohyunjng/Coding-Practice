#include <bits/stdc++.h>
#define int long long
#define MAX_VAL 200000000

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, A, B, st, en, md, X, Y;
    vector<int> arr;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> A;
        arr.push_back(A);
    }
    sort(arr.begin(), arr.end());

    while (Q--) {
        cin >> A >> B;
        st = 0, en = 2 * MAX_VAL;

        while (st < en) {
            md = (st + en) / 2;
            X = upper_bound(arr.begin(), arr.end(), A + md) - lower_bound(arr.begin(), arr.end(), A - md);
            Y = lower_bound(arr.begin(), arr.end(), A + md) - upper_bound(arr.begin(), arr.end(), A - md);
            if (Y < B && B <= X) {
                cout << md << '\n';
                break;
            } else if (X < B) {
                st = md + 1;
            } else {
                en = md;
            }
        }
    }

    return 0;
}