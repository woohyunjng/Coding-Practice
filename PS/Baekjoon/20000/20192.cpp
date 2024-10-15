#include <bits/stdc++.h>
#define int long long

#define MAX 300100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, cnt = 0, res = 0;

    cin >> N;
    vector<int> A(N + 2, 0);

    A[0] = -INF;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    A[N + 1] = -INF;

    A.erase(unique(A.begin(), A.end()), A.end());
    N = A.size() - 2;

    cnt = 1;
    for (int i = 1; i < N; i++)
        cnt = cnt && (A[i] < A[i + 1]);
    if (cnt == 1) {
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        if (A[i] > A[i - 1] && A[i] > A[i + 1])
            cnt++;
    }

    while (cnt) {
        res++;
        if (cnt == 1)
            break;
        else if (cnt & 1)
            cnt = (cnt >> 1) + 1;
        else
            cnt >>= 1;
    }

    cout << res;

    return 0;
}