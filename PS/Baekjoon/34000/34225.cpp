#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0, S = 0, V = 0x3f3f3f3f3f3f3f3f, VD, L, R;
    vector<int> arr;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], arr.push_back(i);

    sort(arr.begin(), arr.end(), [&](int x, int y) { return A[x] < A[y]; });

    for (int i = 0; i < N; i++) {
        if (-A[arr[i]] + S < V)
            V = -A[arr[i]] + S, VD = i;
        S += A[arr[i]];
        if (S - V + A[arr[i]] > ans)
            ans = S - V + A[arr[i]], L = VD, R = i;
    }

    cout << R - L + 1 << '\n';
    for (int i = L; i <= R; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    return 0;
}