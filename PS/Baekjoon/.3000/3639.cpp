#include <bits/stdc++.h>
#define int long long
#define double long double

using namespace std;

const int MAX = 300000;

double V[MAX], W[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    vector<int> arr;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> V[i] >> W[i];
        arr.push_back(i);
    }

    double st = 0, en = 10000000000, mid, val, res;

    while (en - st >= 0.0000001) {
        mid = (st + en) / 2, val = 0;
        sort(arr.begin(), arr.end(), [&](int x, int y) { return V[x] - mid * W[x] > V[y] - mid * W[y]; });
        for (int i = 0; i < K; i++)
            val += V[arr[i]] - mid * W[arr[i]];

        if (val >= 0)
            res = mid, st = mid;
        else
            en = mid;
    }

    sort(arr.begin(), arr.end(), [&](int x, int y) { return V[x] - res * W[x] > V[y] - res * W[y]; });
    for (int i = 0; i < K; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    return 0;
}