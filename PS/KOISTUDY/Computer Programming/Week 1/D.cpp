#include <bits/stdc++.h>
using namespace std;

const int MAX = 200;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;
    vector<int> arr;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], arr.push_back(-A[i]);

    sort(arr.begin(), arr.end());

    for (int i = 1; i <= N; i++) {
        X = lower_bound(arr.begin(), arr.end(), -A[i]) - arr.begin() + 1;
        cout << A[i] << ' ' << X << '\n';
    }

    return 0;
}