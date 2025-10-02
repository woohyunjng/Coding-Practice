#include <bits/stdc++.h>
using namespace std;

const int MAX = 10;

string A[MAX], B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, V, ans = 0;
    vector<int> arr;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i], arr.push_back(i);
    for (int i = 0; i < N; i++)
        cin >> B[i];

    do {
        V = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < 4; j++)
                V += A[arr[i]][j] != B[i][j];
        ans = max(ans, V);
    } while (next_permutation(arr.begin(), arr.end()));

    cout << ans << '\n';

    return 0;
}