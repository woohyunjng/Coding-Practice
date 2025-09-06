#include <bits/stdc++.h>
using namespace std;

const int MAX = 26;

vector<int> arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string S, T;
    int N, M, ans = 1, X = 0, V, K;
    bool flag = true;

    cin >> S >> T;
    N = S.size(), M = T.size();

    for (int i = 0; i < M; i++)
        arr[T[i] - 'a'].push_back(i);

    for (int i = 0; i < N; i++) {
        V = S[i] - 'a';
        if (arr[V].empty()) {
            flag = false;
            break;
        }
        K = lower_bound(arr[V].begin(), arr[V].end(), X) - arr[V].begin();
        if (K == arr[V].size())
            ans++, K = 0;
        X = arr[V][K] + 1;
    }

    if (!flag)
        ans = -1;
    cout << ans << '\n';

    return 0;
}