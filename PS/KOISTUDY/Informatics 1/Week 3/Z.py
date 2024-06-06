N = int(input())
res = 0

for i in [10, 5, 3, 1]:
    res += N // i
    N %= i

print(res)
