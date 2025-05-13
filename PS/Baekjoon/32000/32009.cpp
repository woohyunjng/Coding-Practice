#include "Alice.h"
#include "Bob.h"

#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef pair<signed, signed> pr;

int gcd(int A, int B) { return B ? gcd(B, A % B) : A; }

vector<pr> Alice() {
    int X = setN(5000);
    vector<pr> ans;
    for (int i = 1; i < 5000; i++)
        ans.push_back({X % i + 1, i + 1});
    return ans;
}

int Bob(vector<pr> V) {
    int X = 0, Y = 1, A, B, G;

    for (pr i : V) {
        A = i.first - 1, B = i.second - 1;
        while (X % B != A)
            X += Y;
        G = B / gcd(B, Y);
        if (1e18 / G < Y)
            break;
        Y *= G;
    }

    return X;
}
