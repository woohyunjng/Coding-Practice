from collections import deque

N = int(input())
arr = list(map(int, input().split()))

stack = deque([])

for i in range(N):
    while len(stack):
        if stack[-1][0] <= arr[i]:
            stack.pop()
        else:
            break

    if len(stack):
        print(stack[-1][1], end=" ")
    else:
        print(0, end=" ")
    stack.append((arr[i], i + 1))
