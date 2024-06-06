N = 1000 - int(input())
res = 0

res += N // 500
N %= 500

res += N // 100
N %= 100

res += N // 50
N %= 50

res += N // 10
N %= 10

res += N // 5
N %= 5

res += N

print(res)
