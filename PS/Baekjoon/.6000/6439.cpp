#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;

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

bool check(int A, int B, int C, int D, int E, int F, int G, int H)
{
    if (E > G)
        swap(E, G);
    if (F > H)
        swap(F, H);

    bool res = is_intersect({A, B}, {C, D}, {E, H}, {G, H}) || is_intersect({A, B}, {C, D}, {E, H}, {E, F}) || is_intersect({A, B}, {C, D}, {G, H}, {G, F}) || is_intersect({A, B}, {C, D}, {E, F}, {G, F});
    if (res)
        return res;
    return (E <= A && A <= G && F <= B && B <= H) || (E <= C && C <= G && F <= D && D <= H);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, A, B, C, D, E, F, G, H;
    cin >> T;

    while (T--)
    {
        cin >> A >> B >> C >> D >> E >> F >> G >> H;
        cout << (check(A, B, C, D, E, F, G, H) ? 'T' : 'F') << '\n';
    }

    return 0;
}