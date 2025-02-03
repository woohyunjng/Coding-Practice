#include <bits/stdc++.h>
#define int long long

#define MAX 200000
using namespace std;

int A[MAX], ans[MAX][2], nxt[MAX];
vector<int> arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, B, K, X, Y, V, st, en, mid;
    cin >> N, B = (int)sqrt(N), nxt[N + 1] = N + 1;

    for (int i = 1; i <= N; i++)
        cin >> A[i], arr[A[i]].push_back(i);

    for (int i = 1; i <= N; i++) {
        if (arr[i].size() <= B) {
            for (int j = 1; j <= arr[i].size(); j++) {
                st = 1, en = N, V = 0;
                while (st <= en) {
                    mid = st + en >> 1, X = K = 0;
                    while (X < arr[i].size()) {
                        Y = X;
                        while (Y < arr[i].size() && arr[i][Y] - arr[i][X] <= mid)
                            Y++;
                        X = Y, K++;
                    }
                    if (K >= j)
                        V = mid, st = mid + 1;
                    else
                        en = mid - 1;
                }

                ans[V][0]++;
            }
        } else {
            for (int j = 1; j <= N; j++)
                nxt[j] = 0;
            for (int j : arr[i])
                nxt[j] = j;
            for (int i = N; i >= 1; i--)
                if (nxt[i] == 0)
                    nxt[i] = nxt[i + 1];

            for (int j = 1; j <= N; j++) {
                K = arr[i][0];
                while (K <= N)
                    ans[j][1]++, K = K + j + 1 > N ? N + 1 : nxt[K + j + 1];
            }
        }
    }

    for (int i = N; i >= 1; i--)
        ans[i][0] += ans[i + 1][0];
    for (int i = 1; i <= N; i++)
        cout << ans[i][0] + ans[i][1] << '\n';

    return 0;
}