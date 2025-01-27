#include <bits/stdc++.h>
#define int long long

#define MAX 1010
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

    int N, res = 0, A, cnt = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        res ^= arr[i];
    }

    if (res != 0) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= arr[i]; j++) {
                if ((res ^ arr[i] ^ (arr[i] - j)) == 0)
                    cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}