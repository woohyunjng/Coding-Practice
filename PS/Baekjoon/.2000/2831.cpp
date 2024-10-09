#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> arr[4];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, res = 0, A = 0, B = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> X;
        if (X < 0)
            arr[0].push_back(-X);
        else
            arr[1].push_back(X);
    }

    for (int i = 1; i <= N; i++) {
        cin >> X;
        if (X < 0)
            arr[2].push_back(-X);
        else
            arr[3].push_back(X);
    }

    for (int i = 0; i < 4; i++)
        sort(arr[i].begin(), arr[i].end());

    for (A = 0; A < arr[0].size() && B < arr[3].size(); A++)
        if (arr[0][A] > arr[3][B])
            res++, B++;

    for (A = 0, B = 0; A < arr[2].size() && B < arr[1].size(); A++)
        if (arr[2][A] > arr[1][B])
            res++, B++;

    cout << res;

    return 0;
}