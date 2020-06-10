# 1.sort by x (then y)
# 2.recursive n/2 division, return d1,d2, h = min(d1,d2)
# 3.search two points in different half
# 3.1 if (p.x - points[n/2]) < h for p in points B.append(p)
# 3.2 for p_core in B
#       for p in B:
#           if (p_core.y - h < p.y <= p_core.y)
#                C.append(p)
import random
from math import sqrt

import matplotlib.pyplot as plt

from lab1_1 import Point

MAX_DISTANCE = 100000

class Distance():
    def __init__(self, p1, p2):
        self.p1 = p1
        self.p2 = p2

    @property
    def dis(self):
        return sqrt((self.p1.x - self.p2.x) ** 2 + (self.p1.y - self.p2.y) ** 2)

    def __str__(self):
        return str(self.dis)


def foo(points: [Point, ...], points_sorted_by_y):
    if len(points) == 2:
        return Distance(points[0], points[1])
    if len(points) == 1:
        return Distance(Point(MAX_DISTANCE, 0), Point(0, 0))
    A = points[:int(len(points) / 2)]
    B = points[int(len(points) / 2):]
    A_sorted_by_y = [point for point in points_sorted_by_y if point in A]
    B_sorted_by_y = [point for point in points_sorted_by_y if point in B]
    disA = foo(A, A_sorted_by_y)
    disB = foo(B, B_sorted_by_y)
    min_distance = disA if disA.dis < disB.dis else disB
    middle_point = B[0]
    ind = 0
    while ind < len(points_sorted_by_y):
        p1 = points_sorted_by_y[ind]
        if abs(p1.x - middle_point.x) > min_distance.dis:
            ind += 1
            continue
        for j in range(ind + 1, ind + 7):
            try:
                p2 = points_sorted_by_y[j]
            except:
                break
            new_distance = Distance(p1, p2)
            if new_distance.dis < min_distance.dis:
                min_distance = new_distance
        ind +=1
    return min_distance


def divide_and_conquer(points: [Point, ...]):
    points.sort(key=lambda point: (point.x, point.y))
    points_sorted_by_y = points.copy()
    points_sorted_by_y.sort(key=lambda point: (point.y, point.x))
    return foo(points, points_sorted_by_y)


if __name__ == "__main__":
    points = [Point(1, 3), Point(3, 4), Point(4, 3), Point(2, 6), Point(4, 5), Point(4.5, 4.5), Point(1, 8),
              Point(1.2, 4.1)]
    # points = [Point(random.uniform(-100, 100), random.uniform(-100, 100)) for i in range(1000)]
    points = [i for n, i in enumerate(points) if i not in points[:n]]
    for p in points:
        plt.plot(p.x, p.y, 'ro')

    print(divide_and_conquer(points))
    plt.show()
