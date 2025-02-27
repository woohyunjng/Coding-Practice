#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

int N, M, B[MAX];

int get(int K, vector<int> arr) {
    if (M == K)
        return accumulate(arr.begin(), arr.end(), 0ll);
    if (arr.empty())
        return 0ll;
    vector<int> X, Y;

    for (int i : arr) {
        if (i % B[K])
            X.push_back(i);
        else
            Y.push_back(i);
    }

    int A = get(K + 1, X), B = get(K + 1, Y);
    return K % 2 ? max(A, B) : min(A, B);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int X;
    vector<int> arr;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> X, arr.push_back(X);
    for (int i = 0; i < M; i++)
        cin >> B[i];

    if (M > 100) {
        cout << 0 << '\n';
        return 0;
    }

    cout << get(0, arr) << '\n';

    return 0;
}