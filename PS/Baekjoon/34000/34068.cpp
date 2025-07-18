#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 200001;

int S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B, ans = 0;
    vector<int> arr;

    cin >> N >> M;
    while (M--)
        cin >> A >> B, S[A]++;

    for (int i = 1; i <= N; i++)
        arr.push_back(i);

    sort(arr.begin(), arr.end(), [](int a, int b) { return S[a] < S[b]; });
    for (int i = 0; i + 1 < N; i++) {
        ans += max(S[arr[i]] + 1 - S[arr[i + 1]], 0ll);
        S[arr[i + 1]] = max(S[arr[i + 1]], S[arr[i]] + 1);
    }

    cout << ans << '\n';

    return 0;
}