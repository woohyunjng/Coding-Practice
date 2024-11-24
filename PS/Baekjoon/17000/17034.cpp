#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX];
vector<int> st[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, K = 0, P = 0, res = 0;
    bool flag;
    vector<int> arr;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++) {
        if (A[i] < P)
            break;
        X = lower_bound(arr.begin() + K, arr.end(), A[i]) - arr.begin();
        if (X == arr.size())
            arr.push_back(A[i]);
        else {
            flag = false;
            while (!st[X].empty() && st[X].back() < A[i])
                P = st[X].back(), st[X].pop_back(), flag = true;
            st[X].push_back(A[i]);

            if (flag)
                K = X;
        }
        res = i;
    }

    cout << res << '\n';

    return 0;
}