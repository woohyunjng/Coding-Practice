#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    vector<int> A, B;

    cin >> N;

    while (N >= 3)
        A.push_back(N--), B.push_back(N--), B.push_back(N--);

    if (N == 2)
        A.push_back(1), B.push_back(2);

    cout << A.size() << '\n';
    for (int i : A)
        cout << i << ' ';
    cout << '\n';

    cout << B.size() << '\n';
    for (int i : B)
        cout << i << ' ';
    cout << '\n';

    return 0;
}