#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 3000;

int N, K, W[MAX], H[MAX], ans = 0x3f3f3f3f3f3f3f3f;

int gcd(int X, int Y) { return Y == 0 ? X : gcd(Y, X % Y); }

pr pick(int X, int Y) {
    vector<int> arr;
    int SW = 0, SH = 0;
    for (int i = 0; i < N; i++)
        arr.push_back(i);

    sort(arr.begin(), arr.end(), [&](int x, int y) { return X * W[x] + Y * H[x] < X * W[y] + Y * H[y]; });
    for (int i = 0; i < K; i++)
        SW += W[arr[i]], SH += H[arr[i]];
    ans = min(ans, SW * SH);
    return {SW, SH};
}

void dnc(pr X, pr Y) {
    if (X == Y)
        return;

    int A = abs(X[1] - Y[1]), B = abs(X[0] - Y[0]), G = gcd(A, B);
    A /= G, B /= G;
    pr K = pick(A, B);

    if (K == X || K == Y)
        return;

    dnc(X, K), dnc(K, Y);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> W[i] >> H[i];

    dnc(pick(1, 0), pick(0, 1)), cout << ans << '\n';

    return 0;
}