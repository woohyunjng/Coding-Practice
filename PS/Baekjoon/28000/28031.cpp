#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 150001;

int A[MAX], V[MAX], S[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, Y, ans, Z, W;
    vector<pr> arr;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], arr.push_back({A[i], i});

    sort(arr.begin(), arr.end());
    for (int i = 1; i <= N; i++) {
        V[arr[i - 1][1]] = i;
        S[i][0] = S[i - 1][0] + arr[i - 1][0];
        S[i][1] = S[i - 1][1] + arr[i - 1][0] * i;
    }
    S[N + 1][0] = S[N][0], S[N + 1][1] = S[N][1];

    cin >> Q;
    while (Q--) {
        cin >> X >> Y, ans = 0;
        Z = lower_bound(arr.begin(), arr.end(), pr{Y, 0}) - arr.begin() + 1;
        ans += S[min(V[X], Z) - 1][1] + S[N][1] - S[max(V[X], Z - 1)][1];
        if (V[X] < Z)
            ans += S[Z - 1][1] - S[V[X]][1] - (S[Z - 1][0] - S[V[X]][0]), Z--;
        else
            ans += (S[V[X] - 1][1] - S[Z - 1][1]) + (S[V[X] - 1][0] - S[Z - 1][0]);
        ans += Y * Z;

        cout << ans << '\n';
    }

    return 0;
}