#include <bits/stdc++.h>
using namespace std;

void add(int X, int Y, int Z) {
    cout << "+ " << X << ' ' << Y << ' ' << Z << '\n', cout.flush();
}

void subtract(int X, int Y, int Z) {
    cout << "- " << X << ' ' << Y << ' ' << Z << '\n', cout.flush();
}

int compare(int X, int Y) {
    int res;
    cout << "< " << X << ' ' << Y << '\n', cout.flush();
    cin >> res;
    return res;
}

int IDX[101];

int get_int(int A) {
    int X = 0, Y = 4, Z, res = 0;
    bool flag;

    for (; Y <= 34; Y++) {
        Z = Y == 4 ? A : Y - 1;
        subtract(IDX[A - 1], IDX[A - 1], IDX[Z]), flag = compare(IDX[Z], IDX[A - 1]) > 0;
        add(IDX[A - 1], IDX[A - 1], IDX[Z]);
        if (flag)
            break;
        add(IDX[Y], IDX[Z], IDX[Z]), X++;
    }
    Y = Y == 4 ? A : Y - 1;

    while (Y >= A) {
        res |= 1 << X, subtract(IDX[A - 1], IDX[A - 1], IDX[Y]), Y = Y == 4 ? A : Y - 1, X--;
        while (compare(IDX[Y], IDX[A - 1]) > 0)
            Y = Y == 4 ? A : Y - 1, X--;
    }

    return res;
}

int compare_fraction() {
    int X, Y, Z, rev = 0, V[2];

    for (int i = 0; i <= 100; i++)
        IDX[i] = i + 1;

    X = compare(IDX[0], IDX[1]), Y = compare(IDX[2], IDX[3]);
    if (X != Y)
        return X > Y ? 1 : -1;
    if (X == -1)
        rev ^= 1, swap(IDX[0], IDX[1]), swap(IDX[2], IDX[3]);
    if (X == 0)
        return 0;

    while (true) {
        V[0] = get_int(1), V[1] = get_int(3);
        if (V[0] != V[1])
            return (rev ^ (V[0] < V[1])) ? -1 : 1;

        V[0] = compare(IDX[0], IDX[99]), V[1] = compare(IDX[2], IDX[99]);
        if (V[0] == V[1] && V[0] == 0)
            return 0;
        else if (V[0] == 0)
            return rev ? 1 : -1;
        else if (V[1] == 0)
            return rev ? -1 : 1;

        swap(IDX[0], IDX[1]), swap(IDX[2], IDX[3]), rev ^= 1;
    }
}

signed main() {
    int res = compare_fraction();
    cout << "! " << res << '\n', cout.flush();
}