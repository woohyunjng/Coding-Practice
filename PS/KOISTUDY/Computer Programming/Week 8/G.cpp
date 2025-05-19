#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int L[MAX], R[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0, X;
    vector<int> arr, V;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> L[i] >> R[i], arr.push_back(i);

    sort(arr.begin(), arr.end(), [&](int a, int b) { return L[a] < L[b]; });

    for (int i : arr) {
        if (V.empty() || V.back() < R[i])
            V.push_back(R[i]), ans++;
        else
            X = lower_bound(V.begin(), V.end(), R[i]) - V.begin(), V[X] = R[i];
    }

    ans = N - ans;
    cout << ans << '\n';

    return 0;
}