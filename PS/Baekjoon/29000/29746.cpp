#include "longesttrip.h"

#include <bits/stdc++.h>
using namespace std;

int search(vector<int> arr, vector<int> target) {
    if (arr.size() == 1)
        return arr.back();

    int m = arr.size() >> 1;
    vector<int> l, r;

    l.insert(l.end(), arr.begin(), arr.begin() + m);
    r.insert(r.end(), arr.begin() + m, arr.end());
    return search(are_connected(l, target) ? l : r, target);
}

vector<int> longest_trip(int N, int D) {
    vector<int> ans, arr[2];

    arr[0].push_back(0);
    for (int i = 1; i < N; i += 2) {
        if (i + 1 == N) {
            if (!are_connected({arr[0].back()}, {i}))
                arr[1].push_back(i);
            else {
                arr[0].push_back(i);
                if (!arr[1].empty() && are_connected({arr[1].back()}, {i}))
                    arr[0].insert(arr[0].end(), arr[1].rbegin(), arr[1].rend()), arr[1].clear();
            }
        } else {
            if (are_connected({i}, {i + 1})) {
                if (are_connected({arr[0].back()}, {i})) {
                    arr[0].push_back(i), arr[0].push_back(i + 1);
                    if (!arr[1].empty() && are_connected({arr[1].back()}, {i + 1}))
                        arr[0].insert(arr[0].end(), arr[1].rbegin(), arr[1].rend()), arr[1].clear();
                } else {
                    arr[1].push_back(i), arr[1].push_back(i + 1);
                    if (are_connected({arr[0].back()}, {i + 1}))
                        arr[0].insert(arr[0].end(), arr[1].rbegin(), arr[1].rend()), arr[1].clear();
                }
            } else if (are_connected({arr[0].back()}, {i})) {
                if (arr[1].empty() || are_connected({arr[1].back()}, {i + 1}))
                    arr[0].push_back(i), arr[1].push_back(i + 1);
                else
                    arr[0].push_back(i + 1), arr[1].push_back(i);
            } else
                arr[0].push_back(i + 1), arr[1].push_back(i);
        }
    }

    if (arr[0].size() < arr[1].size())
        swap(arr[0], arr[1]);
    if (arr[1].empty() || !are_connected(arr[0], arr[1]))
        return arr[0];

    int X, Y, XD, YD;

    if (are_connected({arr[0].front()}, {arr[0].back()})) {
        if (arr[1].size() == 1 || !are_connected({arr[1].front()}, {arr[1].back()})) {
            if (!are_connected(arr[0], {arr[1].back()}))
                reverse(arr[1].begin(), arr[1].end());
            X = search(arr[0], {arr[1].back()}), ans = arr[1];
            for (int i = 0; i < arr[0].size(); i++)
                if (arr[0][i] == X)
                    XD = i;
            ans.insert(ans.end(), arr[0].begin() + XD, arr[0].end());
            ans.insert(ans.end(), arr[0].begin(), arr[0].begin() + XD);
        } else {
            X = search(arr[0], arr[1]), Y = search(arr[1], {X});
            XD = find(arr[0].begin(), arr[0].end(), X) - arr[0].begin();
            YD = find(arr[1].begin(), arr[1].end(), Y) - arr[1].begin();

            ans.insert(ans.end(), arr[0].begin() + XD + 1, arr[0].end());
            ans.insert(ans.end(), arr[0].begin(), arr[0].begin() + XD + 1);
            ans.insert(ans.end(), arr[1].begin() + YD, arr[1].end());
            ans.insert(ans.end(), arr[1].begin(), arr[1].begin() + YD);
        }
    } else if (are_connected({arr[1].back()}, {arr[0].front()}))
        ans = arr[1], ans.insert(ans.end(), arr[0].begin(), arr[0].end());
    else
        ans = arr[1], ans.insert(ans.end(), arr[0].rbegin(), arr[0].rend());

    return ans;
}