import random
from operator import attrgetter

import matplotlib.pyplot as plt

from lab1_1 import Point
from lab1_1 import define_orientation
from lab1_3 import draw_figure
from copy import deepcopy

def find_max_right(core_point, points):
    # points.remove(core_point)
    max = points[0]
    if (max == core_point):
        # print(1)
        max = points[-1]
        for point in points[:-1]:
            if define_orientation(core_point, max, point) == "right" and point != core_point:
                max = point
    else:
        for point in points[1:]:
            if define_orientation(core_point, max, point) == "right" and point != core_point:
                max = point
    return max


def jarvis(original_points):
    points = deepcopy(original_points)
    points = [i for n, i in enumerate(points) if i not in points[:n]]
    core_point = min(points, key=attrgetter('y'))
    carcass = [core_point]
    while True:
        p1 = find_max_right(core_point, points)
        core_point = p1
        points.remove(core_point)
        if p1 == carcass[0]:
            break
        carcass.append(p1)
    return carcass


if __name__ == "__main__":
    random.seed(32)  # 100
    points = [Point(random.uniform(-10, 10), random.uniform(-10, 10)) for i in range(30)]
    carcass = jarvis(points)
    print(len(carcass))
    draw_figure(carcass)
    for point in points:
        plt.plot(point.x, point.y, 'ro')
    for point in carcass:
        plt.plot(point.x, point.y, 'ro', color=(0, 0, 0))
    plt.plot(carcass[0].x, carcass[0].y, 'ro', color=(1, 0, 0))
    plt.show()
