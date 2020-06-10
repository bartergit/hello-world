import random
from math import atan, pi
from operator import attrgetter

import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

from lab1_1 import Point
from lab1_1 import define_orientation
from lab3_collision import distance


def animate(i):
    stack.append(points.pop(0))
    data_x = []
    data_y = []
    for point in stack:
        data_x.append(point.x)
        data_y.append(point.y)

    if len(points) == 0:  # for last point
        data_x.append(min_point.x)
        data_y.append(min_point.y)
        lines.set_data(data_x, data_y)
        anim.event_source.stop()
        return lines,
    lines.set_data(data_x, data_y)
    while define_orientation(stack[-2], stack[-1], points[0]) == "right":
        stack.pop()
    return lines,


def sorter(p1):
    value1 = pi / 2 if p1.x == min_point.x \
        else atan((p1.y - min_point.y) / abs(min_point.x - p1.x))
    if p1.x < min_point.x:
        value1 = pi - value1
    return value1, distance(p1, min_point)


if __name__ == "__main__":
    random.seed(322)
    # arr = [[9, 7], [1, -2], [-9, 9], [-5, -10], [7, 10], [8, 0], [2, -8], [9, 8], [2, 3], [2, -3], [2, -6], [-3, -7], [3, -7],
    #  [8, 4], [0, 1], [-1, -2], [1, -2], [-10, 9], [-8, 2], [-2, -2]]
    points = [Point(random.uniform(-3, 3), random.uniform(-3, 3)) for i in range(15)]
    points = [i for n, i in enumerate(points) if i not in points[:n]]
    min_point = min(points, key=attrgetter('y'))
    stack = [min_point]
    points.remove(min_point)
    points.sort(key=lambda point: sorter(point))
    points.append(min_point)

    fig = plt.figure()
    ax = plt.axes(xlim=(-11, 11), ylim=(-11, 11))
    lines, = plt.plot([], [])
    anim = FuncAnimation(fig, animate, frames=7, interval=500, blit=True)
    plt.plot(min_point.x, min_point.y, 'ro', color=(0.5, 0.5, 0))
    for ind, point in enumerate(points):
        plt.plot(point.x, point.y, 'ro', markersize=2)
    plt.show()
