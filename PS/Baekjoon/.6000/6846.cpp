#include <bits/stdc++.h>
#define int long long

#define MAX 1001
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX][3];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B, C, res;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    cin >> M;
    while (M--) {
        cin >> A >> B >> C;
        res = INF;

        for (int i = 1; i <= N; i++) {
            if ((arr[i][0] >= A && arr[i][1] >= B && arr[i][2] >= C) || (arr[i][0] >= A && arr[i][1] >= C && arr[i][2] >= B) || (arr[i][0] >= B && arr[i][1] >= A && arr[i][2] >= C) || (arr[i][0] >= B && arr[i][1] >= C && arr[i][2] >= A) || (arr[i][0] >= C && arr[i][1] >= A && arr[i][2] >= B) || (arr[i][0] >= C && arr[i][1] >= B && arr[i][2] >= A))
                res = min(res, arr[i][0] * arr[i][1] * arr[i][2]);
        }

        if (res == INF)
            cout << "Item does not fit." << '\n';
        else
            cout << res << '\n';
    }

    return 0;
}