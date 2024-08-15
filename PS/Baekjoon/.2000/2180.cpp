#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 40000
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<long double, 3> tp;

tp arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i][1] >> arr[i][2];
        if (arr[i][1] == 0)
            arr[i][0] = INF;
        else
            arr[i][0] = arr[i][2] / arr[i][1];
    }

    sort(arr, arr + N);

    for (int i = 0; i < N; i++)
        res += (res * (int)arr[i][1] % MOD + (int)arr[i][2]) % MOD;
    cout << (res + MOD) % MOD;

    return 0;
}