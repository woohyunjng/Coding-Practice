#include <bits/stdc++.h>
using namespace std;

vector<int> arr[21];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> X, arr[X].push_back(i);

    for (int i = 1; i <= M; i++) {
        cout << arr[i].size() << ' ';
        for (int j : arr[i])
            cout << j << ' ';
        cout << '\n';
    }
}