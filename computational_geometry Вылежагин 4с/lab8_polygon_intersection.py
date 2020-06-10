from lab1_1 import define_orientation
from lab11_triangulation import Point
import matplotlib.pyplot as plt
from lab1_2 import is_intersect

def find_intersection_point(a, b, c, d):
    dx = (a.x - b.x, c.x - d.x)
    dy = (a.y - b.y, c.y - d.y)

    d = (det(a, b), det(c, d))
    x = det(d, dx) / det(dx, dy)
    y = det(d, dy) / det(dx, dy)
    return Point(x, y)


def scalar_mult(v1, v2):
    return v1.x * v2.x + v1.y * v2.y

def det(i, j):
    return i[0] * j[1] - i[1] * j[0]

def is_aimed(a_start, a_end, b_start, b_end):
    if det(b_start - b_end, b_start - a_end) > 0 and det(b_start - b_end, a_start - a_end) < 0:
        return True
    if det(b_start - b_end, b_start - a_end) < 0 and det(b_start - b_end, a_start - a_end) > 0:
        return True
    return scalar_mult(a_end - a_start, a_end - b_end) < 0


def is_point_outer(a_start, a_end, b_end):
    return define_orientation(a_start, a_end, b_end) == 'right'


def get_lines(points_p, points_q):
    for i, point_q in enumerate(points_q):
            if is_point_outer(points_p[0], points_p[1], point_q) or \
                    is_point_outer(point_q, points_q[(i + 1) % len(points_q)], points_p[1]):
                return 0, i


def polygon_intersection(polygon1, polygon2):
    p_index, q_index = get_lines(polygon1, polygon2)
    res = []
    while True:
        pq = is_aimed(polygon1[p_index], polygon1[(p_index + 1) % len(polygon1)], polygon2[q_index],
                      polygon2[(q_index + 1) % len(polygon2)])
        qp = is_aimed(polygon2[q_index], polygon2[(q_index + 1) % len(polygon2)], polygon1[p_index],
                      polygon1[(p_index + 1) % len(polygon1)])
        # p is aimed on q and q is aimed on p
        if pq and qp:
            if is_point_outer(polygon1[p_index], polygon1[(p_index + 1) % len(polygon1)],
                              polygon2[(q_index + 1) % len(polygon2)]):
                q_index += 1 if q_index + 1 < len(polygon2) else -len(polygon2) + 1
            else:
                p_index += 1 if p_index + 1 < len(polygon1) else -len(polygon1) + 1
        # p is aimed on q not q is not aimed p
        elif pq and not qp:
            if not is_point_outer(polygon2[q_index], polygon2[(q_index + 1) % len(polygon2)],
                                  polygon1[(p_index + 1) % len(polygon1)]):
                res.append(polygon1[(p_index + 1) % len(polygon1)])
            p_index += 1 if p_index + 1 < len(polygon1) else -len(polygon1) + 1
        # p is not aimed q not q is aimed on p
        elif not pq and qp:
            if not is_point_outer(polygon1[p_index], polygon1[(p_index + 1) % len(polygon1)],
                                  polygon2[(q_index + 1) % len(polygon2)]):
                res.append(polygon2[(q_index + 1) % len(polygon2)])
            q_index += 1 if q_index + 1 < len(polygon2) else -len(polygon2) + 1
        # p is not aimed on q not q is not aimed on p
        else:
            if is_intersect(polygon1[p_index], polygon1[(p_index + 1) % len(polygon1)],
                                     polygon2[q_index], polygon2[(q_index + 1) % len(polygon2)]):
                res.append(find_intersection_point(polygon1[p_index], polygon1[(p_index + 1) % len(polygon1)],
                                                     polygon2[q_index], polygon2[(q_index + 1) % len(polygon2)]))
            if define_orientation(polygon1[p_index], polygon1[(p_index + 1) % len(polygon1)],
                                     polygon2[(q_index + 1) % len(polygon2)]) == 'right':
                q_index += 1 if q_index + 1 < len(polygon2) else -len(polygon2) + 1
            else:
                p_index += 1 if p_index + 1 < len(polygon1) else -len(polygon1) + 1
        if len(res) > 1:
            if res[0] == res[-1]:
                res.pop()
                break
    return res


def draw_figure(points:[Point], color):
    for ind, point in enumerate(points):
        plt.plot([point.x, points[(ind + 1)%len(points)].x], [point.y, points[(ind + 1)%len(points)].y], color)

if __name__ == "__main__":
    polygon1 = [Point(9, 7), Point(-6, 5), Point(-10, 2), Point(-9, -5), Point(3, -10), Point(6, -10), Point(8, -5), Point(10, 6)]
    polygon2 = [Point(1, 10), Point(-7, 9), Point(-8, 4), Point(-7, -2), Point(-6, -5), Point(1, -2), Point(3, 5.5)]
    draw_figure(polygon1, 'black')
    draw_figure(polygon2, 'black')
    polygon_intersection = polygon_intersection(polygon1, polygon2)
    print(polygon_intersection)
    draw_figure(polygon_intersection, 'green')
    plt.show()
