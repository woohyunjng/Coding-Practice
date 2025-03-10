#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    string S, ans = "";

    cin >> N >> S;

    map<char, char> dna;
    dna['A'] = 'U', dna['T'] = 'A', dna['C'] = 'G', dna['G'] = 'C';

    for (char i : S)
        ans += dna[i];

    cout << ans << '\n';

    return 0;
}