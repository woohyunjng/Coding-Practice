#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, V = 0;
    bool ans = true;

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    if (K % M)
        ans = false;
    K /= M;

    vector<int> arr, upper, lower, res;
    for (int i = 1; i <= N; i++)
        arr.push_back(i);
    sort(arr.begin(), arr.end(), [&](int x, int y) { return A[x] < A[y]; });

    for (int i = N - 1; i >= N - K; i--)
        upper.push_back(arr[i]);
    for (int i = 0; i < N - K; i++)
        lower.push_back(arr[i]);

    for (int i = 1; i <= N; i++) {
        if (!upper.empty() && V * M <= A[upper.back()] * (i - 1))
            res.push_back(upper.back()), V++, upper.pop_back();
        else if (!lower.empty() && V * M > A[lower.back()] * (i - 1))
            res.push_back(lower.back()), lower.pop_back();
        else
            ans = false;
    }

    if (ans) {
        for (int i : res)
            cout << i << ' ';
        cout << '\n';
    } else
        cout << "impossible" << '\n';

    return 0;
}