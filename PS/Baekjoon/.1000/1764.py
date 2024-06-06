from collections import defaultdict

N, M = map(int, input().split())
checked = defaultdict(bool)
NM = []

for i in range(N):
    checked[input()] = True

for j in range(M):
    S = input()
    if checked[S]:
        NM.append(S)

NM = sorted(NM)
print(len(NM))
for i in NM:
    print(i)
