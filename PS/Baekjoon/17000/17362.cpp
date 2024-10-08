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
    cin >> N;

    if (N <= 5)
        cout << N;
    else if (N <= 9)
        cout << 10 - N;
    else {
        N -= 9;
        N %= 8;
        if (N < 4)
            cout << N + 1;
        else
            cout << 9 - N;
    }

    return 0;
}