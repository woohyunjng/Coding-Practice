#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

vector<int> arr[26], val = {1, 4, 18, 18, 8, 4};
int S[MAX], V[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, ans = 0;
    string _S;

    cin >> _S, N = _S.size();
    for (int i = 0; i < N; i++)
        S[i] = _S[i] - 'a', arr[S[i]].push_back(i);

    for (int i = N - 1; i >= 0; i--) {
        X = i - 1;
        for (int j : val) {
            X = lower_bound(arr[j].begin(), arr[j].end(), X + 1) - arr[j].begin();
            if (X == arr[j].size()) {
                X = -1;
                break;
            }
            X = arr[j][X];
        }
        if (X != -1)
            V[i] = (N - X) + V[X + 1];
        else
            V[i] = V[i + 1];
        ans += V[i];
    }

    cout << ans << '\n';

    return 0;
}