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

    int N;
    char C1, C2;
    string S, res = "";

    cin >> N >> C1 >> C2 >> S;

    for (char i : S) {
        if (i != C1)
            res += C2;
        else
            res += C1;
    }

    cout << res << '\n';

    return 0;
}