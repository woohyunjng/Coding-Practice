A = input()
B = input()
C = input()

print(str(int(B[0])) + "-" + str(int(B[1])) + " NO." + str(int(B[2:])))
print(C + "(" + ("M" if A[7] in ["1", "3"] else "F") + ")")
print("BirthDay " + str(int(A[2:4])) + "/" + str(int(A[4:6])))
