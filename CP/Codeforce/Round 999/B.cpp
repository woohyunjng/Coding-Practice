#include <bits/stdc++.h>
#define int long long

#define MAX 300000
using namespace std;
typedef array<int, 2> pr;

map<int, int> cnt;

void solve() {
    int N, X, Y;
    vector<int> A, B;
    vector<pr> diff;
    cin >> N;

    cnt.clear();
    for (int i = 1; i <= N; i++)
        cin >> X, cnt[X]++, A.push_back(X);
    sort(A.begin(), A.end());

    for (int i = 3; i < A.size() - 1; i++)
        diff.push_back({A[i + 1] - A[i], i});
    sort(diff.begin(), diff.end());

    for (int i = A.size() - 2; i >= 0; i--) {
        if (A[i] != A[i + 1])
            continue;
        if (i >= 2) {
            cout << A[0] << ' ' << A[1] << ' ' << A[i] << ' ' << A[i] << '\n';
            return;
        } else if (i == 1) {
            if (A[0] + A[1] + A[2] > A[3]) {
                cout << A[0] << ' ' << A[1] << ' ' << A[2] << ' ' << A[3] << '\n';
                return;
            }
            if (diff.size() > 0 && diff[0][0] < A[1] * 2) {
                cout << A[1] << ' ' << A[2] << ' ' << A[diff[0][1]] << ' ' << A[diff[0][1] + 1] << '\n';
                return;
            }
        } else {
            diff.push_back({A[3] - A[2], 2});
            sort(diff.begin(), diff.end());

            if (diff[0][0] < A[1] * 2) {
                cout << A[1] << ' ' << A[1] << ' ' << A[diff[0][1]] << ' ' << A[diff[0][1] + 1] << '\n';
                return;
            }
        }

        break;
    }

    cout << -1 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}