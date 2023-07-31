from collections import deque

N = int(input())
S = input()

stack = deque([])
arr = [False for i in range(N)]

for i in range(N):
    if S[i] == ")":
        if len(stack):
            arr[i] = True
            arr[stack.pop()] = True
    else:
        stack.append(i)

res = [0]
for i in arr:
    if i:
        res[-1] += 1
    else:
        res.append(0)

print(max(res))
