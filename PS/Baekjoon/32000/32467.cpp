#include <bits/stdc++.h>
#define int long long

#define MAX 100100
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

    int N, K, X, st, en, md, res, C;
    vector<int> arr;
    cin >> N >> K >> X;

    for (int i = 1; i <= N; i++)
        cin >> A[i] >> B[i];

    st = 0, en = 100000000;
    while (st <= en) {
        md = st + en >> 1;
        arr.clear();

        for (int i = 1; i <= N; i++)
            arr.push_back(max(A[i] - md, 0ll) * B[i]);
        sort(arr.begin(), arr.end());

        C = 0;
        for (int i = 0; i <= N - X; i++)
            C += arr[i];

        if (C < K) {
            en = md - 1;
            res = md;
        } else
            st = md + 1;
    }

    cout << res;

    return 0;
}