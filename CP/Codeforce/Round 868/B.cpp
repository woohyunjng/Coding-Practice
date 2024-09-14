#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, K, state, val_1, val_2;
    cin >> T;

    while (T--) {
        cin >> N >> K;
        for (int i = 1; i <= N; i++)
            cin >> arr[i];

        state = 0, val_1 = -1, val_2 = -1;
        for (int i = 1; i <= N; i++) {
            if (i % K == arr[i] % K)
                continue;
            else {
                if (state == 1) {
                    state = -1;
                    break;
                } else if (state == 0) {
                    state = 2;
                    val_1 = i % K, val_2 = arr[i] % K;
                } else {
                    if (val_2 != i % K || val_1 != arr[i] % K) {
                        state = -1;
                        break;
                    } else {
                        state = 1;
                    }
                }
            }
        }

        cout << state << '\n';
    }

    return 0;
}