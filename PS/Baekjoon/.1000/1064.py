xA, yA, xB, yB, xC, yC = map(int, input().split())
A, B, C = (
    ((xB - xC) ** 2 + (yB - yC) ** 2) ** 0.5,
    ((xC - xA) ** 2 + (yC - yA) ** 2) ** 0.5,
    ((xA - xB) ** 2 + (yA - yB) ** 2) ** 0.5,
)

if xA == xB == xC or yA == yB == yC:
    print(-1.0)
elif len(set([xA, xB, xC])) == 3 and (yA - yB) / (xA - xB) == (yB - yC) / (xB - xC) == (
    yC - yA
) / (xC - xA):
    print(-1.0)
else:
    arr = [A, B, C]
    print(max(arr) * 2 - min(arr) * 2)
