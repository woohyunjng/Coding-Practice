#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300001;

int X[MAX], Y[MAX], R[MAX], ans[MAX];
unordered_map<int, vector<int>> mp;

int dis(int X1, int Y1, int X2, int Y2) { return (X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K = 31, XK, CX, CY;
    vector<int> arr;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i] >> R[i];
        X[i] += 1'000'000'000, Y[i] += 1'000'000'000;
        arr.push_back(i);
    }

    sort(arr.begin(), arr.end(), [](int a, int b) { return R[a] == R[b] ? a < b : R[a] > R[b]; });
    for (int i : arr) {
        if (ans[i])
            continue;

        XK = K;
        while (K > 0 && (1ll << K) >= (R[i] << 1))
            K--;
        if (XK != K) {
            mp.clear();
            for (int j = 1; j <= N; j++) {
                if (ans[j])
                    continue;
                mp[X[j] / (1ll << K) * 10'000'000'000 + Y[j] / (1ll << K)].push_back(j);
            }
        }

        CX = X[i] / (1ll << K), CY = Y[i] / (1ll << K);
        for (int j = CX - 2; j <= CX + 2; j++) {
            for (int k = CY - 2; k <= CY + 2; k++) {
                XK = j * 10'000'000'000 + k;
                if (mp.find(XK) == mp.end())
                    continue;
                for (int l : mp[XK]) {
                    if (ans[l])
                        continue;
                    if (dis(X[i], Y[i], X[l], Y[l]) <= (R[i] + R[l]) * (R[i] + R[l]))
                        ans[l] = i;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}