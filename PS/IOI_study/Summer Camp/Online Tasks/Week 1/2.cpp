#include <bits/stdc++.h>
#define int long long

using namespace std;

int empt(vector<int> &arr, int K) {
    for (int i = 0; i <= K; i++) {
        if (arr[i] != 0)
            return i;
    }
    return -1;
}

int distribute(vector<int> &arr, int K) {
    int X = arr[K];
    arr[K] = 0;
    while (X) {
        K = (K + 1) % arr.size();
        arr[K]++, X--;
    }
    return K;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N;

    vector<int> A(N), B(N);
    vector<int> X, Y;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];

    for (int i = 0; i < N - 1; i++) {
        while (true) {
            K = empt(A, i);
            if (K == -1)
                break;
            distribute(A, K);
            X.push_back(K);
        }
    }

    for (int i = 0; i < N - 1; i++) {
        while (true) {
            K = empt(B, i);
            if (K == -1)
                break;
            Y.push_back(distribute(B, K));
        }
    }

    cout << X.size() + Y.size() << '\n';
    for (int i : X)
        cout << "D " << i + 1 << '\n';
    reverse(Y.begin(), Y.end());
    for (int i : Y)
        cout << "C " << i + 1 << '\n';

    return 0;
}