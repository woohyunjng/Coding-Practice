N = int(input())
res = 1

while res * (res + 1) < N * 2:
    res += 1

print(res * (res + 1) // 2)
