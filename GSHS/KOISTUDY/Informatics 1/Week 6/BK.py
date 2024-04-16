N = int(input())
res = 0
for i in range(N // 3, (N + 1) // 2):
    res += i - ((N - i) - (N - i) // 2) + 1
print(res)
