#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int CCW(pr A, pr B, pr C) { // A-B-C 양수 반시계 / 0 일직선 / 음수 시계
    int val = (B.first - A.first) * (C.second - A.second) - (C.first - A.first) * (B.second - A.second);
    if (val > 0)
        return 1;
    else if (val < 0)
        return -1;
    else
        return 0;
}

bool is_intersect(pr A, pr B, pr C, pr D) { // A-B C-D 교차판정
    int AtoC = CCW(A, B, C) * CCW(A, B, D);
    int CtoA = CCW(C, D, A) * CCW(C, D, B);

    if (AtoC == 0 && CtoA == 0) {
        if (A > B)
            swap(A, B);
        if (C > D)
            swap(C, D);

        return C <= B && A <= D;
    }

    return AtoC <= 0 && CtoA <= 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    pr A, B, C, D;
    long double resX, resY;

    cin >> A.first >> A.second >> B.first >> B.second;
    cin >> C.first >> C.second >> D.first >> D.second;

    bool inter = is_intersect(A, B, C, D);
    if (!inter) {
        cout << 0;
        return 0;
    }

    cout << 1 << '\n';

    if ((A.first - B.first) * (C.second - D.second) == (A.second - B.second) * (C.first - D.first)) {
        if (A > B)
            swap(A, B);
        if (C > D)
            swap(C, D);

        if (A == D)
            cout << A.first << ' ' << A.second;
        else if (B == C)
            cout << B.first << ' ' << B.second;
        return 0;
    }

    resX = (double)((A.first * B.second - A.second * B.first) * (C.first - D.first) - (A.first - B.first) * (C.first * D.second - C.second * D.first)) / ((A.first - B.first) * (C.second - D.second) - (A.second - B.second) * (C.first - D.first));
    resY = (double)((A.first * B.second - A.second * B.first) * (C.second - D.second) - (A.second - B.second) * (C.first * D.second - C.second * D.first)) / ((A.first - B.first) * (C.second - D.second) - (A.second - B.second) * (C.first - D.first));

    cout << fixed << setprecision(20);
    cout << resX << ' ' << resY;

    return 0;
}