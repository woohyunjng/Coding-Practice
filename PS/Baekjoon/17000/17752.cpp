#include <bits/stdc++.h>
#define int long long
using namespace std;

int SA[2], SB[2], X, TA, TB, ans;

void InitA(signed T, signed _X) { X = _X | (1ll << 31); }
void InitB(signed T) { ans = TB = 0; }

signed GameA(signed I, signed J) {
    if (I == 4)
        return -1;
    else if (I != 2)
        return J > 1 ? -3 : -4;
    else
        return X & (1 << TA++) ? -2 : -1;
}

signed GameB(signed I, signed J) {
    if (I == 4)
        return -1;
    else if (I == 2)
        return J > 1 ? -3 : -4;
    else if (I == 1) {
        TB++;
        return -2;
    } else {
        if (TB == 32)
            return ans >> 1;
        else if (TB == 31)
            return ans;
        ans |= (1ll << TB++);
        return -1;
    }
}
