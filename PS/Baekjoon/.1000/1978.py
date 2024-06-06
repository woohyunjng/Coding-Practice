N, res = int(input()), 0

for i in range(N):
    A = int(input())
    for j in range(2, int(A**0.5) + 1):
        if not A % j:
            break
    else:
        res += 1

print(res)
