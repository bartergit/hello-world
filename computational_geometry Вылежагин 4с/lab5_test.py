import random

import matplotlib.pyplot as plt

from lab1_1 import Point
from lab1_3 import draw_figure
from lab1_4 import is_convex
from lab2 import is_inside
from lab5_jarvis import jarvis

from lab3_collision import distance

from lab5_diameter import diameter_search
from math import factorial


def jarvis_test(n=1000):
    errors = 0
    for i in range(n):
        print(end=str(i) + " ")
        points = [Point(random.uniform(-10, 10), random.uniform(-10, 10)) for i in range(30)]
        carcass = jarvis(points)
        state = is_convex(carcass)
        for point in points:
            if is_inside(carcass, point) == "inside" or is_inside(carcass, point) == "on":
                pass
            else:
                state = False
                break
        if state:
            pass
            # print("ok")
        else:
            errors += 1
            draw_figure(carcass)
            for p in carcass:
                plt.plot(p.x, p.y, 'ro', color=(0, 0, 0))
            plt.plot(carcass[0].x, carcass[0].y, 'ro', color=(1, 0, 0))
            for p in points:
                plt.plot(p.x, p.y, 'ro')
            plt.show()
            print("error")
    print()
    return errors


def diameter_search_test(n=1000):
    errors = 0
    for i in range(n):
        print(end=str(i) + " ")
        points = [Point(random.uniform(-10, 10), random.uniform(-10, 10)) for i in range(30)]
        d_max, d1,d2 = diameter_search(points)
        n = len(points)
        c = int(factorial(n) / factorial(n - 2) / 2)
        for i in range(c * 5):
            p1 = random.choice(points)
            p2 = random.choice(points)
            dis = distance(p1,p2)
            if dis > d_max:
                print(d_max, dis)
                carcass = jarvis(points)
                draw_figure(carcass)
                draw_figure((d1,d2))
                draw_figure((p1,p2))
                plt.show()
                errors += 1
                break
    print()
    return errors


if __name__ == "__main__":
    random.seed(5)
    # print(jarvis_test(),"errors")
    print(diameter_search_test(), "errors")