from sys import setrecursionlimit

setrecursionlimit(10**6)

arr = []
while True:
    try:
        arr.append(int(input()))
    except:
        break


def tree(A, B):
    if A > B:
        return

    C = B + 1
    for i in range(A + 1, B + 1):
        if arr[A] < arr[i]:
            C = i
            break

    tree(A + 1, C - 1)
    tree(C, B)
    print(arr[A])


tree(0, len(arr) - 1)
