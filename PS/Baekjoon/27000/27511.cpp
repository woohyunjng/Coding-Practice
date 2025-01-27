#include "workshop.h"
#include <bits/stdc++.h>

using namespace std;

vector<int> arr[3];
int sz[3] = {20, 6, 4};

void init() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < (1 << sz[i]); j++) {
            if (__builtin_popcount(j) * 2 == sz[i])
                arr[i].push_back(j);
        }
    }
}

int val(int x, int y, int t) {
    int a = arr[t][x], b = arr[t][y];
    for (int i = 0; i < sz[t]; i++) {
        if ((a & (1 << i)) && !(b & (1 << i)))
            return i;
    }
}

int morning(int my_num, int right_num) { return val(my_num, right_num, 0); }

int afternoon(int left_num, int my_num, int right_num) { return val(val(left_num, my_num, 1), val(my_num, right_num, 1), 2); }

int evening(int left_num, int my_num, int right_num) {
    if (my_num <= 2)
        return my_num;
    for (int i = 0; i <= 2; i++)
        if (left_num != i && right_num != i)
            return i;
}
