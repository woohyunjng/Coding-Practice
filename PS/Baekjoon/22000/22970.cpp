#include <bits/stdc++.h>
#define int long long

#define MAX 5100
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

    int N, res = 1;
    bool check;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++) {
        check = true;
        for (int j = i + 1; j <= N + 1; j++) {
            if (j == N + 1 || A[j - 1] == A[j] || (!check && A[j - 1] < A[j])) {
                res = max(res, j - i);
                break;
            }
            check = A[j - 1] < A[j];
        }
    }

    cout << res;

    return 0;
}