import time
import random
from cmath import sqrt

solutions = []

def solve(a, b, c):
    D = b**2 - 4*a*c
    x1 = (-b + sqrt(D))/ (2 * a)
    x2 = (-b + sqrt(D))/ (2 * a)
    solutions.append((x1,x2))

if __name__ == '__main__':
    random.seed(1)
    starttime = time.time()
    for i in range(1000_000):
        solve(random.uniform(1, 100),random.uniform(1, 100),random.uniform(1, 100))
        
    print('That took {} seconds'.format(time.time() - starttime))
    # print(solutions)