from collections import deque

N = int(input())
tree = list(map(int, input().split()))

child = [[] for i in range(N)]
child_num = [0 for i in range(N)]

for i in range(N):
    if tree[i] == -1:
        continue
    child[tree[i]].append(i)
    child_num[tree[i]] += 1

M = int(input())
dq = deque([M])
left = [True for i in range(N)]

while len(dq):
    p = dq.pop()
    left[p] = False
    child_num[tree[p]] -= 1

    for i in child[p]:
        dq.append(i)

res = 0
for i in range(N):
    if not child_num[i] and left[i]:
        res += 1

print(res)
