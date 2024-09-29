#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> arr[MAX];
int res[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, k, A;
    bool check = true;
    cin >> N >> k;

    for (int i = 0; i < N; i++) {
        cin >> A;
        arr[i % k].push_back(A);
    }

    for (int i = 0; i < k; i++) {
        sort(arr[i].begin(), arr[i].end());
        for (int j = 0; j < arr[i].size(); j++)
            res[j * k + i] = arr[i][j];
    }

    for (int i = 0; i < N - 1; i++)
        check = check && res[i] < res[i + 1];

    cout << (check ? "Yes" : "No");

    return 0;
}