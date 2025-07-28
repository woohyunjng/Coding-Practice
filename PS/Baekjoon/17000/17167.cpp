#include <bits/stdc++.h>
#define int long long

using namespace std;

string T[4] = {
    "A+=A",
    "A+=B",
    "B+=A",
    "B+=B"};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int A, B;
    vector<int> ans;

    cin >> A >> B;
    while (A % 2 == 0)
        A /= 2, ans.push_back(3);
    while (B % 2 == 0)
        B /= 2, ans.push_back(0);

    while (A ^ B) {
        if (A > B)
            A += B, ans.push_back(1);
        else
            B += A, ans.push_back(2);
        while (A % 2 == 0)
            A /= 2, ans.push_back(3);
        while (B % 2 == 0)
            B /= 2, ans.push_back(0);
    }

    cout << ans.size() << '\n';
    for (int i : ans)
        cout << T[i] << '\n';

    return 0;
}
