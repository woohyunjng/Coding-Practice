#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

map<string, int> mp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    string S;
    vector<string> arr;

    cin >> N >> M;

    while (N--) {
        cin >> S;
        if (S.size() < M)
            continue;
        if (!mp.count(S))
            mp[S] = 0, arr.push_back(S);
        mp[S]++;
    }

    sort(arr.begin(), arr.end(), [&](string x, string y) {
        if (mp[x] != mp[y])
            return mp[x] > mp[y];
        if (x.size() != y.size())
            return x.size() > y.size();
        return x < y;
    });

    for (string i : arr)
        cout << i << '\n';

    return 0;
}