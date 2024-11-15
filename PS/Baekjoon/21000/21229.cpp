#include <bits/stdc++.h>
#define int long long

#define MAX 2001000
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], cnt[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X = 0, res = 0, Y;
    vector<int> arr;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        cnt[A[i]]++, X = max(X, A[i]);
    }

    for (int i = 1; i <= X * 2; i++)
        cnt[i] += cnt[i - 1];

    for (int i = 1; i <= X; i++) {
        arr.clear();
        for (int j = 1; j <= X / i; j++) {
            Y = cnt[(j + 1) * i - 1] - cnt[j * i - 1];
            if (Y & 1)
                arr.push_back(j);
        }

        if (arr.size() == 1 && arr[0] == 1)
            res += cnt[(arr[0] + 1) * i - 1] - cnt[arr[0] * i - 1];
        else if (arr.size() == 2 && arr[1] == arr[0] + 1)
            res += cnt[(arr[1] + 1) * i - 1] - cnt[arr[1] * i - 1];
    }

    cout << res << '\n';

    return 0;
}