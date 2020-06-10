import matplotlib.pyplot as plt

from lab1_1 import Point
from lab3_collision import distance
import random
from lab9_divide_and_conquer import divide_and_conquer
from lab9_divide_and_conquer import Distance

def test(func, i = 1000, flag = True):
    errors = 0
    for i in range(i):
        points = [Point(random.randint(-10, 10), random.randint(-10, 10)) for i in range(10)]
        points = [i for n, i in enumerate(points) if i not in points[:n]]
        min = Distance(points[0],points[1])
        for p1 in points:
            for p2 in points:
                if p1 == p2:
                    continue
                if Distance(p1,p2).dis < min.dis:
                    min = Distance(p1,p2)
        min_by_func = func(points)
        if  min_by_func.dis != min.dis:
            errors += 1
            if flag:
                for p in points:
                    plt.plot(p.x, p.y, 'ro')
                plt.plot(min.p1.x,min.p1.y, 'ro',color=(1,1,0))
                plt.plot(min.p2.x,min.p2.y, 'ro',color=(1,1,0))
                plt.plot(min_by_func.p1.x, min_by_func.p1.y, 'ro', color=(0, 1, 0))
                plt.plot(min_by_func.p2.x, min_by_func.p2.y, 'ro', color=(0, 1, 0))
                print("Expected %f but found %f"%(min.dis,min_by_func.dis))
                plt.show()


    print("The are %d errors"%errors)

if __name__ == "__main__":
    random.seed(22)
    test(divide_and_conquer,flag=True)