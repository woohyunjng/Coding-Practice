#include <bits/stdc++.h>
#define int long long
#define MAX 300100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, res = 0;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    for (int i = 2; i <= N; i++) {
        A = arr[i - 1], B = arr[i];
        if (A > B) {
            while (A > B) {
                B *= 2;
                dp[i]++;
            }
        } else {
            while (A * 2 <= B) {
                A *= 2;
                dp[i]--;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        if (dp[i] > 0) {
            res += dp[i];
            dp[i + 1] += dp[i];
        }
    }

    cout << res;

    return 0;
}