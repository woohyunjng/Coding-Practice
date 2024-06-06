A, B, C = input().split(".")
print(A[2:4] + B.rjust(2, "0") + C.rjust(2, "0") + "-XXXXXXX")
