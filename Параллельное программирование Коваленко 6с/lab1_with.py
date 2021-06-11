import time
import multiprocessing 
import random
from cmath import sqrt

solutions = []

def solve(a, b, c):
    D = b**2 - 4*a*c
    x1 = (-b + sqrt(D))/ (2 * a)
    x2 = (-b + sqrt(D))/ (2 * a)
    solutions.append((x1,x2))

def solve_many(n):  
    for i in range(int(1000_000/8) * n, int(1000_000/8) * (n + 1)):
        solve(random.uniform(1, 100),random.uniform(1, 100), random.uniform(1, 100))
    
if __name__ == '__main__':
    random.seed(1)
    processes = []
    starttime = time.time()
    for i in range(8):
        process = multiprocessing.Process(target=solve_many, \
            args=(i,))
        processes.append(process)
        process.start()
    for process in processes:
        process.join()
    print('That took {} seconds'.format(time.time() - starttime))