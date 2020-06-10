import random
from operator import attrgetter

import matplotlib.pyplot as plt

from lab1_1 import Point
from lab1_3 import draw_figure
from lab1_1 import define_orientation
from lab5_diameter import S


def quick_hull(points):
    A = min(points, key=attrgetter('x'))
    B = max(points, key=attrgetter('x'))
    convex_hull = [A, B]
    segment_1, segment_2 = [], []  # segment_1 is to the left of AB
    [segment_1.append(point) if define_orientation(A, B, point) == "left" else segment_2.append(point) for point in points]
    find_hull(segment_2, A, B, convex_hull)
    find_hull(segment_1, B, A, convex_hull)
    return convex_hull

def find_hull(segment, P, Q, convex_hull):
    if len(segment) == 0:
        return
    max = 0
    for point in segment:
        if S(P,Q,point) > max:
            max = S(P,Q,point)
            max_point = point
    C = max_point
    convex_hull.insert(convex_hull.index(P),C)
    segment_1, segment_2 = [], []  # segment_1 is to the right side of PC, segment_2 is to the right side of the CQ
    for point in segment:
        if define_orientation(P, C, point) == "right":
            segment_1.append(point)
        if define_orientation(C, Q, point) == "right":
            segment_2.append(point)
    find_hull(segment_1, P, C, convex_hull)
    find_hull(segment_2, C, Q, convex_hull)


if __name__ == "__main__":
    random.seed(10)
    points = [Point(random.uniform(-10, 10), random.uniform(-10, 10)) for i in range(30)]
    plt.plot([i.x for i in points], [i.y for i in points], 'ro', color=(0.5, 0.5, 0))
    hull = quick_hull(points)
    plt.plot([i.x for i in hull], [i.y for i in hull], 'ro', color=(0.5, 0.5, 1))
    draw_figure(hull)
    plt.show()