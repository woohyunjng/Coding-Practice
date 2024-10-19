#include <bits/stdc++.h>
#define int long long

#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N;

string get(int K, string X) {
    for (int i = 1; i <= K / 2; i++) {
        if (X.substr(X.size() - i) == X.substr(X.size() - 2 * i, i))
            return "";
    }
    if (N == K)
        return X;

    for (int i = 1; i <= 3; i++) {
        string res = get(K + 1, X + to_string(i));
        if (res != "")
            return res;
    }
    return "";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N;
    cout << get(0, "");

    return 0;
}