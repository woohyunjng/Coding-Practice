import time
import random

import math

start_time = time.time()

test_case = 10**8
success = 0

for _ in range(test_case):
    x, y = random.random(), random.random()
    if x**2 + y**2 <= 1:
        success += 1

end_time = time.time()

pi = 4 * (success / test_case)

print(f"PI value : {pi} (error percentage {abs(math.pi - pi) / math.pi * 100}%)")
print(f"Executed {test_case} test cases in {end_time - start_time}s")
