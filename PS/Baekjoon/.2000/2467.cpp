#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, K, ans = INF, ansX = -1, ansY = -1;
    vector<int> arr;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> X, arr.push_back(X);

    X = 0, Y = N - 1;
    while (X < Y) {
        K = arr[X] + arr[Y];
        if (abs(K) < ans) {
            ans = abs(K);
            ansX = arr[X], ansY = arr[Y];
        }

        if (K < 0)
            X++;
        else
            Y--;
    }

    cout << ansX << ' ' << ansY << '\n';

    return 0;
}