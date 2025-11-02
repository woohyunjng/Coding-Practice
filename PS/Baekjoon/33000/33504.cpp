#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500001;

int A[MAX], B[MAX];
vector<int> arr[MAX], val[MAX];

int comb(int X) { return (X * (X + 1)) / 2; }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, ans = 0;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], arr[A[i]].push_back(i);
    for (int i = 1; i <= N; i++)
        cin >> B[i], val[B[i]].push_back(i);

    for (int i = 1; i <= N; i++)
        if (A[i] == B[i])
            ans += comb(i - 1) + comb(N - i);

    for (int i = 1; i <= N; i++) {
        for (int j : arr[i]) {
            X = N - j + 1;
            if (X <= j)
                ans += X * (lower_bound(val[i].begin(), val[i].end(), j + 1) - lower_bound(val[i].begin(), val[i].end(), X));
            else
                ans += j * (lower_bound(val[i].begin(), val[i].end(), X + 1) - lower_bound(val[i].begin(), val[i].end(), j));

            ans -= lower_bound(val[i].begin(), val[i].end(), X) != val[i].end() && *lower_bound(val[i].begin(), val[i].end(), X) == X ? min(j, X) : 0;
            if (X != j)
                ans -= lower_bound(val[i].begin(), val[i].end(), j) != val[i].end() && *lower_bound(val[i].begin(), val[i].end(), j) == j ? min(j, X) : 0;
        }

        for (int j : val[i]) {
            X = N - j + 1;
            if (X <= j)
                ans += X * (lower_bound(arr[i].begin(), arr[i].end(), j + 1) - lower_bound(arr[i].begin(), arr[i].end(), X));
            else
                ans += j * (lower_bound(arr[i].begin(), arr[i].end(), X + 1) - lower_bound(arr[i].begin(), arr[i].end(), j));
        }
    }

    cout << ans << '\n';

    return 0;
}