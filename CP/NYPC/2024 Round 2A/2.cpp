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

    int N, M, Q, Rs, Cs, Re, Ce;
    bool res;
    cin >> N >> M >> Q;

    vector<int> L1, L2, L3, L4; // L1 -> x축평행 L2 -> y축평행 L3 -> y=x 대각선 L4 -> y=-x 대각선
    vector<int>::iterator it1, it2;

    while (M--) {
        cin >> Rs >> Cs >> Re >> Ce;
        if (Rs == Re)
            L1.push_back(Rs);
        else if (Cs == Ce)
            L2.push_back(Cs);
        else if (Rs - Cs == Re - Ce)
            L3.push_back(Rs - Cs);
        else if (Rs + Cs == Re + Ce)
            L4.push_back(Rs + Cs);
    }

    sort(L1.begin(), L1.end());
    sort(L2.begin(), L2.end());
    sort(L3.begin(), L3.end());
    sort(L4.begin(), L4.end());

    while (Q--) {
        cin >> Rs >> Cs >> Re >> Ce;

        res = true;

        it1 = lower_bound(L1.begin(), L1.end(), Rs), it2 = lower_bound(L1.begin(), L1.end(), Re);
        res = res && ((it1 == L1.end() || *it1 != Rs) && (it2 == L1.end() || *it2 != Re) && it1 == it2);

        it1 = lower_bound(L2.begin(), L2.end(), Cs), it2 = lower_bound(L2.begin(), L2.end(), Ce);
        res = res && ((it1 == L2.end() || *it1 != Cs) && (it2 == L2.end() || *it2 != Ce) && it1 == it2);

        it1 = lower_bound(L3.begin(), L3.end(), Rs - Cs), it2 = lower_bound(L3.begin(), L3.end(), Re - Ce);
        res = res && ((it1 == L3.end() || *it1 != Rs - Cs) && (it2 == L3.end() || *it2 != Re - Ce) && it1 == it2);

        it1 = lower_bound(L4.begin(), L4.end(), Rs + Cs), it2 = lower_bound(L4.begin(), L4.end(), Re + Ce);
        res = res && ((it1 == L4.end() || *it1 != Rs + Cs) && (it2 == L4.end() || *it2 != Re + Ce) && it1 == it2);

        cout << (res ? 1 : 0) << '\n';
    }

    return 0;
}