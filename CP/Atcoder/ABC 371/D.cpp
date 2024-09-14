#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int X[MAX], P[MAX], sm[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, L, R;
    vector<pr> arr;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> X[i];
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        arr.push_back({X[i], P[i]});
    }
    arr.push_back({-INF, 0});

    sort(arr.begin(), arr.end());
    sm[0] = 0;
    for (int i = 1; i <= N; i++) {
        sm[i] = sm[i - 1] + arr[i].second;
    }

    cin >> Q;
    while (Q--) {
        cin >> L >> R;
        L = lower_bound(arr.begin(), arr.end(), pr(L, -INF)) - arr.begin();
        R = lower_bound(arr.begin(), arr.end(), pr(R, INF)) - arr.begin();

        cout << sm[R - 1] - sm[L - 1] << '\n';
    }

    return 0;
}