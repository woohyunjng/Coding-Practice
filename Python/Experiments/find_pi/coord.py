import time

import math

start_time = time.time()

test_case = 10**4
success = 0

for i in range(test_case):
    for j in range(test_case):
        x, y = i / test_case, j / test_case
        if x**2 + y**2 <= 1:
            success += 1

end_time = time.time()

pi = 4 * (success / test_case**2)

print(f"PI value : {pi} (error percentage {abs(math.pi - pi) / math.pi * 100}%)")
print(f"Executed {test_case ** 2} test cases in {end_time - start_time}s")
