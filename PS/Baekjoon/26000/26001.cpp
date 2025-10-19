#include <bits/stdc++.h>
#define int long long

using namespace std;

bool query(int X, int Y) {
    string res;
    cout << "? " << X << ' ' << Y << '\n', cout.flush();
    cin >> res;
    return res == "building";
}

signed main() {
    int W, H, ansX = 1, ansY = 0;
    vector<int> arr;

    cin >> W >> H;
    for (int i = 1; i <= W; i++)
        arr.push_back(i);

    random_device rd;
    mt19937 g(rd());
    shuffle(arr.begin(), arr.end(), g);

    for (int i : arr) {
        if (ansY == H || !query(i, ansY + 1))
            continue;
        ansX = i, ansY++;
        for (int st = ansY + 1, en = H, md; st <= en;) {
            md = st + en >> 1;
            if (query(i, md))
                ansY = md, st = md + 1;
            else
                en = md - 1;
        }
    }

    cout << "! " << ansX << ' ' << ansY << '\n', cout.flush();

    return 0;
}