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

    int A[5], val;
    char C[5] = {'A', 'B', 'C', 'D', 'E'};
    string S;

    vector<pair<int, string>> res;
    for (int i = 0; i < 5; i++)
        cin >> A[i];

    for (int i = 1; i <= 31; i++) {
        val = 0, S = "";
        for (int j = 0; j < 5; j++)
            if ((1 << j) & i)
                val += A[j], S += C[j];
        res.push_back({-val, S});
    }

    sort(res.begin(), res.end());
    for (pair<int, string> i : res)
        cout << i.second << '\n';

    return 0;
}