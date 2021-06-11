from math import sin, factorial, pi, radians
from scipy.integrate import quad
import multiprocessing


def func(x):
    return sin(radians(x ** 2))


def calc_integral_with_series(A):
    e = 0.1**6
    res = 0
    n = 0
    while True:
        temp = res
        res += ((-1) ** n) * (A ** (4 * n + 3)) / ((4 * n + 3) * factorial(2 * n + 1))
        if abs(temp - res) < e:
            break
        n += 1
    return res


def cal_with_trapezoid(A):
    n = 30
    h = A / n
    res = 0
    for i in range(n + 1):
        xi = h * i
        if i == 0 or i == n:
            res += func(xi) / 2
        else:
            res += func(xi)
    return res * h


def solve_with_first_method():
    res = []
    for A in range(1, 11):
        res1, res2 = quad(func, 0, A)
        res.append(res1 - res2)
    return res


def solve_with_second_method():
    res = []
    for A in range(1, 11):
        res.append(calc_integral_with_series(A))
    return res


def solve_with_third_method():
    res = []
    for A in range(1, 11):
        res.append(cal_with_trapezoid(A))


def main():
    processes = [multiprocessing.Process(target=solve_with_first_method),
                 multiprocessing.Process(target=solve_with_second_method),
                 multiprocessing.Process(target=solve_with_third_method)]
    for process in processes:
        process.start()
    for process in processes:
        process.join()


if __name__ == "__main__":
    main()
