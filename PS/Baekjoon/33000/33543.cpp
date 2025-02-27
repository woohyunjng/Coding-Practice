#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

int A[MAX], B[MAX], sm[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, K, S = 0, V = 0;
    char C;

    vector<int> arr;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
        S += A[i], arr.push_back(B[i] - A[i]);
    }

    sort(arr.begin(), arr.end());
    for (int i = 1; i <= N; i++)
        sm[i] = sm[i - 1] + arr[i - 1];

    cin >> Q;
    while (Q--) {
        cin >> C >> X;
        if (C == 'A')
            S += X * N, V -= X;
        else
            V += X;

        K = lower_bound(arr.begin(), arr.end(), -V) - arr.begin();
        cout << S + sm[N] - sm[K] + (N - K) * V << '\n';
    }

    return 0;
}