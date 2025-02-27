X = int(input())
ans = -1

for i in range(X + 1, 10000):
    S = str(i)
    A, B = int(S[:2]), int(S[2:])
    if (A + B) ** 2 == i:
        ans = i
        break

print(ans)
