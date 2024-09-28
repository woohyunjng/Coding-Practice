#include <bits/stdc++.h>
#define int long long

#define MAX 3100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], fr_ind[MAX][MAX], bk_ind[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0, val;
    vector<int> bck, frt;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    for (int i = 1; i <= N; i++) {
        bck.clear(), frt.clear();
        for (int j = 1; j <= i; j++)
            bck.push_back(arr[j]);
        for (int j = i; j <= N; j++)
            frt.push_back(arr[j]);

        sort(bck.begin(), bck.end());
        sort(frt.begin(), frt.end());

        for (int j = 1; j <= i; j++)
            bk_ind[i][bck[j - 1]] = j;
        for (int j = i; j <= N; j++)
            fr_ind[i][frt[j - i]] = j;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            val = max({abs(bk_ind[N][arr[j]] - bk_ind[N][arr[i]]),
                       j - bk_ind[i][arr[i]],
                       fr_ind[j][arr[j]] - i});
            res += val;
        }
    }

    cout << res;

    return 0;
}