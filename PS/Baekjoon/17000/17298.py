from collections import deque

N = int(input())
arr = list(reversed(list(map(int, input().split()))))

stack = deque([])
res = []

for i in range(N):
    while len(stack):
        if stack[-1] <= arr[i]:
            stack.pop()
        else:
            break

    if len(stack):
        res.append(stack[-1])
    else:
        res.append(-1)
    stack.append(arr[i])

print(" ".join(reversed(list(map(str, res)))))
