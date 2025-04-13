#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 1000001;

int gcd(int X, int Y) { return Y ? gcd(Y, X % Y) : X; }

int H[MAX], S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, ans = 0;
    pr X;
    vector<pr> arr, tmp;

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> H[i], S[i] = S[i - 1] + H[i];

    for (int i = 1; i <= N; i++) {
        if (arr.empty())
            arr.push_back({H[i], i});
        else {
            arr.push_back({H[i], i});
            for (pr j : arr) {
                X = {gcd(j[0], H[i]), j[1]};
                if (tmp.empty() || tmp.back()[0] < X[0])
                    tmp.push_back(X);
            }
            arr = tmp, tmp.clear();
        }

        for (pr j : arr)
            if (i - j[1] + 1 >= K)
                ans = max(ans, j[0] * (S[i] - S[j[1] - 1]));
    }

    cout << ans << '\n';

    return 0;
}