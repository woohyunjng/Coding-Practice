#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], inc[MAX], decr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    for (int i = N; i >= 1; i--) {
        if (arr[i] < arr[i + 2]) {
            inc[i] = inc[i + 2] + 1;
            decr[i] = 1;
        } else {
            inc[i] = 1;
            decr[i] = decr[i + 2] + 1;
        }
    }

    for (int i = 1; i <= N; i++)
        res = max(res, min(inc[i] * 2, 1 + decr[i + 1] * 2));
    cout << res;

    return 0;
}