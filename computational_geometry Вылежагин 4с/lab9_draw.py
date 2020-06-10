import matplotlib.pyplot as plt
import random

from matplotlib.animation import FuncAnimation
from lab1_1 import Point
from lab9_divide_and_conquer import divide_and_conquer

def animate_points(i):
    dis = divide_and_conquer(points)
    if dis.dis < 3.3:
        dis.p1.set_speed((-dis.p1.speed[0],-dis.p1.speed[1]))
        dis.p2.set_speed((-dis.p1.speed[0], -dis.p1.speed[1]))
    for p in points:
        if not (-50 <= p.x + p.speed[0] <= 50 and -50 <= p.y + p.speed[1]<= 50):
            p.set_speed((-p.speed[0], -p.speed[1]))
        p.move()
    mat.set_data([point.x for point in points], [point.y for point in points])
    return mat,


if __name__ == "__main__":
    random.seed(2)
    points = [Point(random.uniform(-50, 50), random.uniform(-50, 50)) for i in range(20)]
    points = [i for n, i in enumerate(points) if i not in points[:n]]
    for p in points:
        p.set_random_speed(0.3)
    fig = plt.figure()
    ax = plt.axes(xlim=(-50, 50), ylim=(-50, 50))
    mat, = ax.plot([], [],'o',color=(0,0,1),markersize=10)
    anim = FuncAnimation(fig, animate_points, frames=100, interval=5,
                         blit=True)  # blit=True means only re-draw the parts that have changed.
    plt.show()
