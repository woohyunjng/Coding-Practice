#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = -1;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i < N; i++)
        cin >> B[i];

    sort(A + 1, A + N + 1, greater<int>());
    sort(B + 1, B + N, greater<int>());

    for (int i = 1, j = 1; i <= N; i++) {
        if (j >= N || A[i] > B[j]) {
            if (res == -1)
                res = A[i];
            else {
                res = -1;
                break;
            }
        } else
            j++;
    }

    cout << res;

    return 0;
}