N = int(input())
if not N % 400:
    print("Leap")
elif not N % 4 and N % 100:
    print("Leap")
else:
    print("Normal")
