#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

int CCW(pr A, pr B, pr C)
{ // A-B-C 양수 반시계 / 0 일직선 / 음수 시계
    int val = (B.first - A.first) * (C.second - A.second) - (C.first - A.first) * (B.second - A.second);
    if (val > 0)
        return 1;
    else if (val < 0)
        return -1;
    else
        return 0;
}

bool is_intersect(pr A, pr B, pr C, pr D)
{ // A-B C-D 교차판정
    int AtoC = CCW(A, B, C) * CCW(A, B, D);
    int CtoA = CCW(C, D, A) * CCW(C, D, B);

    if (AtoC == 0 && CtoA == 0)
    {
        if (A > B)
            swap(A, B);
        if (C > D)
            swap(C, D);

        return C <= B && A <= D;
    }

    return AtoC <= 0 && CtoA <= 0;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    pr A, B, C, D;
    cin >> A.first >> A.second >> B.first >> B.second;
    cin >> C.first >> C.second >> D.first >> D.second;
    cout << (int)is_intersect(A, B, C, D);

    return 0;
}