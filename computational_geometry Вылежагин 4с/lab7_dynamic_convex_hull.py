import random

import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

from lab1_1 import Point
from lab1_1 import define_orientation


def point_on_line(point, p1, p2):
    p_max = Point(max(p1.x, p2.x), max(p1.y, p2.y))
    p_min = Point(min(p1.x, p2.x), min(p1.y, p2.y))
    if define_orientation(p1, p2, point) == "on" \
            and p_min.x <= point.x <= p_max.x and p_min.y <= point.y <= p_max.y:
        return True
    else:
        return False


def append_point(convex_hull, point):
    if point in convex_hull:
        return convex_hull
    if len(convex_hull) == 0 or len(convex_hull) == 1:
        print(convex_hull)
        convex_hull.append(point)
        return convex_hull
    if len(convex_hull) == 2:
        p1, p2 = convex_hull[0], convex_hull[1]
        if define_orientation(p1, p2, point) == "on":
            if (point_on_line(point, p1, p2)):
                print(point)
            elif (point_on_line(p1, point, p2)):
                print(p1)
                convex_hull = [p2, point]
            else:
                print(p2)
                convex_hull = [p1, point]
        else:
            if define_orientation(p1, p2, point) == "left":
                convex_hull = [p1, point, p2]
            else:
                convex_hull = [p1, p2, point]
        return convex_hull
    if len(convex_hull) > 2:
        right_sides = []
        for i in range(len(convex_hull)):
            if define_orientation(convex_hull[i], convex_hull[(i + 1) % len(convex_hull)], point) == "right":
                right_sides.append((convex_hull[i], convex_hull[(i + 1) % len(convex_hull)]))
            elif 0 not in right_sides:
                right_sides.append(0)
        if len(right_sides) == 1:
            return convex_hull
        convex_hull = []
        for side in right_sides:
            if side == 0:
                convex_hull.append(point)
            else:
                if side[0] not in convex_hull:
                    convex_hull.append(side[0])
                if side[1] not in convex_hull:
                    convex_hull.append(side[1])
        return convex_hull


def animate_points(i):
    points = convex_hull
    if len(convex_hull) > 2:
        points = points + [points[0]]
    lines.set_data([point.x for point in points], [point.y for point in points])
    return lines,


def onclick(event):
    global convex_hull
    convex_hull = append_point(convex_hull, Point(event.xdata,event.ydata))

if __name__ == "__main__":
    random.seed(300)
    convex_hull = []
    print(convex_hull)
    fig = plt.figure()
    ax = plt.axes(xlim=(-50, 50), ylim=(-50, 50))
    lines, = ax.plot([], [])
    anim = FuncAnimation(fig, animate_points, frames=100, interval=500,
                         blit=True)  # blit=True means only re-draw the parts that have changed.
    cid = fig.canvas.mpl_connect('button_press_event', onclick)
    plt.show()
