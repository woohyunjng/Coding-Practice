#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;

int X[MAX], Y[MAX];
bool chk[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0;
    vector<int> arr;

    cin >> N;
    for (int i = 1; i <= N * 2; i++) {
        cin >> X[i] >> Y[i], arr.push_back(i);
        if (X[i] > Y[i])
            swap(X[i], Y[i]);
    }
    sort(arr.begin(), arr.end(), [&](int x, int y) { return X[x] + Y[x] < X[y] + Y[y]; });

    for (int i = 0; i < N; i++)
        ans -= X[arr[i]], ans += Y[arr[i + N]];

    cout << ans << '\n';

    return 0;
}