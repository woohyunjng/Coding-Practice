from math import gcd

N = int(input())
arr = []

for i in range(N):
    arr.append(int(input()))

G_arr = []
for i in range(1, N):
    G_arr.append(arr[i] - arr[i - 1])
G = gcd(*G_arr)

res = 0
for i in G_arr:
    res += i // G - 1
print(res)
