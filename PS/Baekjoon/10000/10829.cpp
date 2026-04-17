#include <iostream>
using namespace std;

int main() {
    long long num;
    int arr[48], i = -1;
    cin >> num;

    while (num > 0) {
        arr[++i] = num % 2;
        num = (long long)(num / 2);
    }

    for (int j = i; j >= 0; j--) {
        cout << arr[j];
    }
}
