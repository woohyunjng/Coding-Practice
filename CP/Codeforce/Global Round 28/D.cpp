#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

typedef array<int, 2> pr;

int A[MAX];
map<int, int> mp;

void solve() {
    int N, S = 0, ans = 0, X, C;
    vector<int> arr;

    cin >> N, mp.clear();
    for (int i = 1; i <= N; i++)
        cin >> A[i], S += A[i];
    sort(A + 1, A + N + 1);

    for (int i = 1; i <= N; i++) {
        X = A[i], C = 1;
        while (i + 1 <= N && A[i + 1] == X)
            i++, C++;
        ans += X / 2 * C;
        if (X & 1)
            arr.push_back(C);
    }

    sort(arr.rbegin(), arr.rend());
    for (int i = 0; i < (int)arr.size(); i += 2)
        ans += arr[i];

    cout << ans << ' ' << S - ans << '\n';
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