#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B, T;
    cin >> N >> M;
    cin >> T;

    while (M--) {
        cin >> A >> B;
        if (!T)
            arr[A].push_back(B);
        else {
            arr[A].push_back(B);
            arr[B].push_back(A);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i].size() << ' ';
        sort(arr[i].begin(), arr[i].end());
        for (int j : arr[i])
            cout << j << ' ';
        cout << '\n';
    }

    return 0;
}