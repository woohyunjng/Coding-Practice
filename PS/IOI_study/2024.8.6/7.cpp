#include <bits/stdc++.h>
#define int long long
#define MAX 200100
#define INF 0x7f7f7f7f7f7f7f7f
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], cur[22];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0, l = 1, r = 1, K = 0;
    bool check;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    K = arr[1];
    while (r <= N && l <= r) {
        res += r - l + 1;
        r++;

        while (K & arr[r])
            K ^= arr[l++];
        K |= arr[r];
    }

    cout << res;

    return 0;
}