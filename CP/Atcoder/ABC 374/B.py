S = input().rstrip() + "_" * 100
T = input().rstrip() + "_" * 100

res = 0

for i in range(min(len(S), len(T))):
    if S[i] != T[i]:
        res = i + 1
        break

if res == 0:
    if len(S) != len(T):
        res = min(len(S), len(T))

print(res)
