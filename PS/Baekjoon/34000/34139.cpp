#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

int R[MAX], C[MAX], ans[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, N;
    vector<int> arr;

    cin >> H >> N;
    for (int i = 1; i <= N; i++) {
        cin >> R[i] >> C[i];
        arr.push_back(i);
    }

    sort(arr.begin(), arr.end(), [&](int x, int y) { return C[x] < C[y]; });
    for (int i = 1; i <= N; i++)
        ans[arr[i - 1]] = i;

    cout << "YES" << '\n';
    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}