P, K = map(int, input().split())
res = 0

for i in range(2, K):
    if P % i == 0:
        res = i
        break

print("GOOD" if res == 0 else "BAD " + str(res))
