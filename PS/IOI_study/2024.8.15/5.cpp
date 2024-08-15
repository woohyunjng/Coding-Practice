#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int cnt[6][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A;
    cin >> N;

    vector<int> arr;

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A;
            cnt[i][A] = j;
        }
    }

    for (int i = 1; i <= N; i++)
        arr.push_back(i);

    sort(arr.begin(), arr.end(), [&](int a, int b) {
        int val = 0;
        for (int i = 1; i <= 5; i++)
            val += cnt[i][a] < cnt[i][b];
        return val >= 3;
    });

    for (int i : arr)
        cout << i << ' ';

    return 0;
}