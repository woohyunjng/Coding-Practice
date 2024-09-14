#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX];
vector<int> arr[MAX];

int calc(int K) { return K * (K + 1) / 2; }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0, val = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        arr[A[i]].push_back(i);
    }

    for (int i = 1; i <= N; i++) {
        if (arr[i].empty())
            continue;
        val = calc(arr[i][0] - 1) + calc(N - arr[i].back());
        for (int j = 1; j < arr[i].size(); j++)
            val += calc(arr[i][j] - arr[i][j - 1] - 1);
        res += calc(N) - val;
    }

    cout << res;

    return 0;
}