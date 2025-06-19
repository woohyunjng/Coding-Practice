#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int A[MAX], ans[MAX];
vector<int> arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], arr[A[i]].push_back(i);
    X = N;

    for (int i = 1; i <= N; i++) {
        for (int j : arr[i])
            ans[j] = X--;
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}