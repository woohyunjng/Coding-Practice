xA, yA = map(int, input().split())
xB, yB = map(int, input().split())
xC, yC = map(int, input().split())

arr = [
    (xA - xB) ** 2 + (yA - yB) ** 2,
    (xB - xC) ** 2 + (yB - yC) ** 2,
    (xC - xA) ** 2 + (yC - yA) ** 2,
]
arr = list(sorted(arr))

if arr[0] + arr[1] == arr[2]:
    print("Yes")
else:
    print("No")
