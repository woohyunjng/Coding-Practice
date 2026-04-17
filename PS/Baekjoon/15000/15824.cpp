#include <algorithm>
#include <iostream>
#define int long long
#define MOD 1000000007
using namespace std;

int arr[400000], two[400000];

signed main() {
    int N, res = 0;
    cin >> N;

    two[0] = 1;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        two[i] = (two[i - 1] << 1) % MOD;
    }
    sort(arr + 1, arr + N + 1);

    for (int i = 1; i <= N; i++) {
        res = (res + (two[i - 1] - two[N - i] + MOD) * arr[i] % MOD) % MOD;
    }

    cout << res;
    return 0;
}