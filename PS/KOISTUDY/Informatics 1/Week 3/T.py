A = list(sorted(map(int, input().split())))
if A[0] + A[1] <= A[2]:
    print("Not")
elif len(set(A)) == 1:
    print("Regular")
elif len(set(A)) == 2:
    print("Isosceles")
elif A[0] ** 2 + A[1] ** 2 == A[2] ** 2:
    print("Right")
else:
    print("Normal")
