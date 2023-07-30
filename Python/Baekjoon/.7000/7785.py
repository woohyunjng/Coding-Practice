N = int(input())
S = {}

for i in range(N):
    A, B = input().split()
    if B == "enter":
        S[A] = True
    else:
        S[A] = False

res = []
for i, j in S.items():
    if j:
        res.append(i)

res = sorted(res, reverse=True)
for i in res:
    print(i)
