#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], sm[MAX];
map<int, bool> chk;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S;
    bool res = false;
    cin >> N >> S;

    chk[0] = true;
    for (int i = 1; i <= N; i++)
        cin >> A[i], sm[i] = sm[i - 1] + A[i], chk[sm[i]] = true;
    res = chk[S];

    for (int i = 0; i <= N; i++)
        res |= chk[(S - (sm[N] - sm[i])) % sm[N]];

    cout << (res ? "Yes" : "No") << '\n';

    return 0;
}