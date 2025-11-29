#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

int A[MAX], B[MAX], ans[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, S;
    vector<int> arr;

    cin >> N >> M >> S;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i], arr.push_back(i);

    sort(arr.begin(), arr.end(), [&](int x, int y) { return B[x] * A[y] > B[y] * A[x]; });
    for (int i : arr)
        ans[i] = min({S, M, A[i]}), S -= ans[i];

    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}