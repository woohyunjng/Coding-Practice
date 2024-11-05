#include <bits/stdc++.h>
#define int long long

#define MAX 510
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X = 0, res = INF;
    vector<tp> arr;

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++) {
        X = 0;
        for (int j = i; j <= N; j++)
            arr.push_back({X += A[j], i, j});
    }
    sort(arr.begin(), arr.end());

    for (int i = 1; i <= N; i++) {
        res = INF;
        for (int j = 0; j < arr.size(); j++) {
            if (arr[j][1] <= i && i <= arr[j][2]) {
                if (j + 1 < arr.size() && !(arr[j + 1][1] <= i && i <= arr[j + 1][2]))
                    res = min(res, arr[j + 1][0] - arr[j][0]);
                if (j - 1 >= 0 && !(arr[j - 1][1] <= i && i <= arr[j - 1][2]))
                    res = min(res, arr[j][0] - arr[j - 1][0]);
            }
        }
        cout << res << ' ';
    }

    return 0;
}