#include <bits/stdc++.h>
#define int long long
using namespace std;

// {배열 상태, 현재 상태, 현재 위치}

// (256 * state + 16 * (state - 1) + pos)

map<int, int> vst;

int D[16][2][3]; // 덮어쓸 문자 (0/1) 다음 상태 (0~15) 이동할 방향(-1/1)

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    char C, PC, CC;
    int N, L, X, Y, Z, K, A, B;
    string S;

    cin >> C >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> PC >> X >> Y >> CC >> Z;
        D[PC - 'A'][X][0] = Y, D[PC - 'A'][X][1] = CC - 'A', D[PC - 'A'][X][2] = Z;
    }

    // X : 배열 상태 Y : 현재 상태 Z : 위치
    Y = C - 'A', Z = 0;

    cin >> S, X = 0;
    for (int i = 0; i < L; i++)
        X |= (S[i] - '0') << i;

    while (true) {
        K = X * 256 + Y * 16 + Z, vst[K] = true;
        A = (X & (1 << Z)) >> Z;
        if (D[Y][A][2] == 0)
            break;
        X &= ((1 << L) - 1) ^ (1 << Z), X ^= (D[Y][A][0] << Z), Z += D[Y][A][2], Y = D[Y][A][1];
        if (Z < 0 || Z >= L)
            break;
        K = X * 256 + Y * 16 + Z;
        if (vst[K]) {
            cout << "CONTINUE" << '\n';
            return 0;
        }
    }

    cout << "STOP" << '\n';

    return 0;
}