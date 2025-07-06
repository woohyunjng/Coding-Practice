#include <bits/stdc++.h>
using namespace std;

const int MAX = 300000;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = -1, M = 1, X;
    vector<int> arr = {0};
    string S;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    cin >> S;

    for (int i = 0; i < N; i++) {
        if (arr.back() < A[i] * M) {
            if ((M == 1 && S[++ans] == 'D') || (M == -1 && S[++ans] == 'U'))
                arr.clear(), M = -M;
            arr.push_back(A[i] * M);
        } else
            arr[lower_bound(arr.begin(), arr.end(), A[i] * M) - arr.begin()] = A[i] * M;
    }

    cout << ans << '\n';

    return 0;
}