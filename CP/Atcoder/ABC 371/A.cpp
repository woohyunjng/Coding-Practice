#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

bool arr[3][3];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    char Sab, Sac, Sbc;
    cin >> Sab >> Sac >> Sbc;

    vector<int> num = {0, 1, 2};

    if (Sab == '>')
        arr[0][1] = true, arr[1][0] = false;
    else
        arr[0][1] = false, arr[1][0] = true;

    if (Sac == '>')
        arr[0][2] = true, arr[2][0] = false;
    else
        arr[0][2] = false, arr[2][0] = true;

    if (Sbc == '>')
        arr[1][2] = true, arr[2][1] = false;
    else
        arr[1][2] = false, arr[2][1] = true;

    sort(num.begin(), num.end(), [&](int a, int b) {
        return arr[a][b];
    });

    cout << (char)('A' + num[1]);

    return 0;
}