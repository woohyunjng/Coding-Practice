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

    int N, D, cnt = 0;
    string S;

    cin >> N >> D >> S;

    for (char i : S)
        cnt += i == '@';

    cout << N - max(0ll, cnt - D) << '\n';

    return 0;
}