#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int A[3];
    bool res = false;
    cin >> A[0] >> A[1] >> A[2];

    res |= (A[0] == A[1] && A[1] == A[2]);
    res |= (A[0] + A[1] == A[2]);
    res |= (A[0] == A[1] + A[2]);
    res |= (A[1] == A[0] + A[2]);

    cout << (res ? "Yes" : "No") << '\n';

    return 0;
}