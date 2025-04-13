#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int MAX_C = 30;

vector<int> arr[MAX_C];
int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, C = 0, X, Y, Z, W, L, R, ans;
    string S;

    cin >> N >> Q >> S;
    for (int i = 1; i <= N; i++) {
        A[i] = S[i - 1] - 'a', C = max(C, A[i]);
        arr[A[i]].push_back(i);
    }

    while (Q--) {
        cin >> L >> R, ans = -1, X = A[L];

        for (int i = 0; i <= C; i++) {
            if (i == X || arr[i].empty())
                continue;
            Y = upper_bound(arr[i].begin(), arr[i].end(), R) - arr[i].begin() - 1;
            if (Y >= 0) {
                Y = arr[i][Y];
                Z = lower_bound(arr[i].begin(), arr[i].end(), (L + Y) / 2) - arr[i].begin();
                if (L < Y) {
                    if (Z < arr[i].size() && L < arr[i][Z] && arr[i][Z] < Y)
                        ans = max(ans, (arr[i][Z] - L) * (Y - arr[i][Z]));
                    if (Z - 1 >= 0 && L < arr[i][Z - 1] && arr[i][Z - 1] < Y)
                        ans = max(ans, (arr[i][Z - 1] - L) * (Y - arr[i][Z - 1]));
                }
            }

            Y = lower_bound(arr[i].begin(), arr[i].end(), L) - arr[i].begin();
            if (Y >= arr[i].size())
                continue;
            Y = arr[i][Y];

            Z = *prev(upper_bound(arr[X].begin(), arr[X].end(), R));
            W = lower_bound(arr[X].begin(), arr[X].end(), (Y + Z) / 2) - arr[X].begin();
            if (Y < Z) {
                if (W < arr[X].size() && Y < arr[X][W] && arr[X][W] < Z)
                    ans = max(ans, (arr[X][W] - Y) * (Z - arr[X][W]));
                if (W - 1 >= 0 && Y < arr[X][W - 1] && arr[X][W - 1] < Z)
                    ans = max(ans, (arr[X][W - 1] - Y) * (Z - arr[X][W - 1]));
            }
        }

        cout << ans << '\n';
    }

    return 0;
}