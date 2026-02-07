#include "cards.h"
#include <bits/stdc++.h>
using namespace std;

map<vector<int>, int> mp;
map<int, vector<int>> rev;

void init_assistant(int N, int K) {
    vector<int> arr;
    int cnt = 0;

    if (K == 6) {
        for (int i = 0; i + 1 < K; i++)
            arr.push_back(i);
        do {
            rev[cnt++] = arr;
        } while (next_permutation(arr.begin(), arr.end()));
    } else if (K == 8) {
        for (int i = 0; i + 2 < K; i++)
            arr.push_back(i);
        do {
            rev[cnt++] = arr;
        } while (next_permutation(arr.begin(), arr.end()));
    }
}

void init_magician(int N, int K) {
    vector<int> arr;
    int cnt = 0;

    if (K == 6) {
        for (int i = 0; i + 1 < K; i++)
            arr.push_back(i);
        do {
            mp[arr] = cnt++;
        } while (next_permutation(arr.begin(), arr.end()));
    } else if (K == 8) {
        for (int i = 0; i + 2 < K; i++)
            arr.push_back(i);
        do {
            mp[arr] = cnt++;
        } while (next_permutation(arr.begin(), arr.end()));
    }
}

vector<int> choose_cards(vector<int> cards) {
    int K;
    vector<int> arr, res;

    if (cards.size() == 2) {
        if (cards[0] == 1 && cards[1] == 2)
            return {1};
        if (cards[0] == 1 && cards[1] == 3)
            return {3};
        if (cards[0] == 2 && cards[1] == 3)
            return {2};
    } else if (cards.size() == 3) {
        if (cards == (vector<int>){1, 2, 3})
            return {1, 2};
        if (cards == (vector<int>){1, 2, 4})
            return {1, 4};
        if (cards == (vector<int>){1, 2, 5})
            return {2, 5};
        if (cards == (vector<int>){1, 3, 4})
            return {1, 3};
        if (cards == (vector<int>){1, 3, 5})
            return {3, 5};
        if (cards == (vector<int>){1, 4, 5})
            return {1, 5};
        if (cards == (vector<int>){2, 3, 4})
            return {3, 4};
        if (cards == (vector<int>){2, 3, 5})
            return {2, 3};
        if (cards == (vector<int>){2, 4, 5})
            return {2, 4};
        if (cards == (vector<int>){3, 4, 5})
            return {4, 5};
    } else if (cards.size() == 6) {
        arr = rev[cards[0]], cards.erase(cards.begin());
        for (int i = 0; i < cards.size(); i++)
            res.push_back(cards[arr[i]]);
        return res;
    } else {
        int X, Y, D;
        for (int i = 0; i < cards.size(); i++)
            for (int j = i + 1; j < cards.size(); j++) {
                if ((cards[i] - cards[j]) % 7 == 0) {
                    X = cards[i], Y = cards[j];
                    break;
                }
            }
        if ((X - Y + 10010) % 10010 < (Y - X + 10010) % 10010)
            swap(X, Y);
        D = (Y - X + 10010) % 10010 / 7;
        cards.erase(find(cards.begin(), cards.end(), X)), cards.erase(find(cards.begin(), cards.end(), Y));
        arr = rev[D];
        for (int i = 0; i < cards.size(); i++)
            res.push_back(cards[arr[i]]);
        res.insert(res.begin(), X);
        return res;
    }
}

int find_discarded_card(vector<int> cards) {
    vector<int> arr;
    int X;

    if (cards.size() == 1) {
        if (cards[0] == 1)
            return 2;
        if (cards[0] == 3)
            return 1;
        if (cards[0] == 2)
            return 3;
    } else if (cards.size() == 2) {
        if (cards == (vector<int>){1, 2})
            return 3;
        if (cards == (vector<int>){1, 4})
            return 2;
        if (cards == (vector<int>){2, 5})
            return 1;
        if (cards == (vector<int>){1, 3})
            return 4;
        if (cards == (vector<int>){3, 5})
            return 1;
        if (cards == (vector<int>){1, 5})
            return 4;
        if (cards == (vector<int>){3, 4})
            return 2;
        if (cards == (vector<int>){2, 3})
            return 5;
        if (cards == (vector<int>){2, 4})
            return 5;
        if (cards == (vector<int>){4, 5})
            return 3;
    } else if (cards.size() == 5) {
        arr = cards, sort(arr.begin(), arr.end());
        for (int i = 0; i < cards.size(); i++)
            cards[i] = lower_bound(arr.begin(), arr.end(), cards[i]) - arr.begin();
        return mp[cards];
    } else {
        X = cards[0], cards.erase(cards.begin());
        arr = cards, sort(arr.begin(), arr.end());
        for (int i = 0; i < cards.size(); i++)
            cards[i] = lower_bound(arr.begin(), arr.end(), cards[i]) - arr.begin();
        return (X + mp[cards] * 7) % 10010;
    }
}