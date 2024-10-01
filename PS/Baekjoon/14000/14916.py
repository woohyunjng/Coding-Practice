N = int(input())
res = 0

res += N // 5
N %= 5

if N & 1:
    res -= 1
    N += 5

res += N // 2

print(res)
