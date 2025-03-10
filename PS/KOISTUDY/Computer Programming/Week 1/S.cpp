#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;

int A[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0;
    vector<int> arr;

    cin >> N;

    for (int i = 0; i < N; i++) {
        arr.push_back(i);
        for (int j = 0; j < N; j++)
            cin >> A[i][j];
    }

    do {
        if (arr[0] != 0)
            continue;
        int val = 0;
        for (int i = 1; i < N; i++)
            val += A[arr[i - 1]][arr[i]];
        val += A[arr[N - 1]][arr[0]];
        ans = max(ans, val);
    } while (next_permutation(arr.begin(), arr.end()));

    cout << ans << '\n';

    return 0;
}