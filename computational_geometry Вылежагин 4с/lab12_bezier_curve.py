import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from random import random
from itertools import cycle
from matplotlib.lines import Line2D

from lab11_triangulation import Point


def get_random_color():
    return [random(), random(), random()]


# algorithm part

def get_point_on_line_from_parameter(line, t):
    point1, point2 = line
    return Point(point1.x + (point2.x - point1.x) * t, point1.y + (point2.y - point1.y) * t)


def recursive_func(core_points: [Point], t: float, intermediate_data: [Line2D], bezier_curve_points: [Point]):
    if len(core_points) < 2:
        return
    lines, = ax.plot([], [], color=next(colors))
    intermediate_data.append(lines)
    intermediate_points = []
    for ind in range(len(core_points) - 1):
        point1, point2 = core_points[ind], core_points[ind + 1]
        point = get_point_on_line_from_parameter([point1, point2], t)
        intermediate_points.append(point)
    if len(intermediate_points) >= 2:
        intermediate_data[-1].set_data([point.x for point in intermediate_points], [point.y for point in intermediate_points])
        recursive_func(intermediate_points, t, intermediate_data, bezier_curve_points)
    else:
        bezier_curve_points.append(intermediate_points[0])


# animate part

def animate_points(i):
    global bezier_curve_points    # bezier curve itself
    if i == 0:
        bezier_curve_points = []  # clear every 100 frames
    t = i / 100
    intermediate_data = []        # auxiliary lines
    recursive_func(core_points, t, intermediate_data, bezier_curve_points)
    core_points_data.set_data([point.x for point in core_points], [point.y for point in core_points])
    bezier_curve_data.set_data([point.x for point in bezier_curve_points], [point.y for point in bezier_curve_points])

    output_figures = []           # all drawn figures (points and lines) to return
    for line in intermediate_data:
        output_figures.append(line)
    output_figures.append(bezier_curve_data)
    output_figures.append(core_points_data)
    return tuple(output_figures)


def onclick(event):
    global bezier_curve_points
    global colors
    core_points.append(Point(event.xdata, event.ydata))
    bezier_curve_points = []
    colors = cycle([get_random_color() for i in range(len(core_points) - 1)])  # iterator with random colors


if __name__ == '__main__':
    colors = cycle([])
    core_points = []
    bezier_curve_points = []
    fig = plt.figure()
    ax = plt.axes(xlim=(0, 10), ylim=(0, 10))

    bezier_curve_data, = ax.plot([], [])
    print(type(bezier_curve_data))
    core_points_data, = ax.plot([], [], 'ro')

    anim = FuncAnimation(fig, animate_points, frames=100, interval=25,
                         blit=True)  # blit=True means only re-draw the parts that have changed.
    cid = fig.canvas.mpl_connect('button_press_event', onclick)
    plt.show()
