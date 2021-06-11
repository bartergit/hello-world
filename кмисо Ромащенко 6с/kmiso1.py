from tabulate import tabulate


number_of_enterprises: int = 4
sum_of_money: int = 90
step: int = 15


sum_of_money += 2

# filling in input table
# input_table = dict()
# for enterprise in range(1, number_of_enterprises + 1):
#     enterprise_profit_vector: dict = dict()
#
#     for i in range(0, sum_of_money, step):
#         value: int = int(input(f"f_{enterprise}: {i}: "))
#         enterprise_profit_vector[i] = value
#     input_table[f"f_{enterprise}"] = enterprise_profit_vector
input_table = {
    'f_1': {
        0: 0,
        15: 7,
        30: 10,
        45: 11,
        60: 19,
        75: 25,
        90: 30
    },
    'f_2': {
        0: 0,
        15: 5,
        30: 10,
        45: 17,
        60: 26,
        75: 28,
        90: 34
    },
    'f_3': {
        0: 0,
        15: 4,
        30: 12,
        45: 19,
        60: 24,
        75: 30,
        90: 32
    },
    'f_4': {
        0: 0,
        15: 4,
        30: 13,
        45: 17,
        60: 21,
        75: 29,
        90: 34
    },
}

# filling result table
result = dict()
for enterprise in range(1, number_of_enterprises + 1):
    k_enterprise_profit_vector = dict()

    if enterprise == 1:
        for i in range(0, sum_of_money, step):
            k_enterprise_profit_vector[i] = input_table[f"f_{enterprise}"][i]
        result[f"w_{enterprise}"] = k_enterprise_profit_vector
    else:
        for current_sum in range(0, sum_of_money, step):
            if current_sum == 0:
                w = (0, 0)
            else:
                values_for_w = []
                print("************")
                print(f"w_{enterprise}, y={current_sum}\n")
                for z in range(0, current_sum + 2, step):
                    if enterprise == 2:
                        print(f'f{enterprise}(z={z})={input_table[f"f_{enterprise}"][z]} + w{enterprise-1}(y-z={current_sum - z})={result[f"w_{enterprise - 1}"][current_sum - z]} == {input_table[f"f_{enterprise}"][z] + result[f"w_{enterprise - 1}"][current_sum - z]}')
                        values_for_w.append(
                            (input_table[f"f_{enterprise}"][z] + result[f"w_{enterprise - 1}"][current_sum - z],
                            z)
                        )
                        values_for_w.sort(key=lambda w_z_pair: w_z_pair[0], reverse=True)
                        if len(values_for_w) > 1 and values_for_w[0][0] == values_for_w[1][0]:
                            w = (
                                values_for_w[0][0],
                                values_for_w[0][1],
                                values_for_w[1][1],
                            )
                        else:
                            w = values_for_w[0]
                    else:
                        print(f'f{enterprise}(z={z})={input_table[f"f_{enterprise}"][z]} + w{enterprise-1}(y-z={current_sum - z})={result[f"w_{enterprise - 1}"][current_sum - z][0]} == {input_table[f"f_{enterprise}"][z] + result[f"w_{enterprise - 1}"][current_sum - z][0]}')

                        values_for_w.append(
                            (input_table[f"f_{enterprise}"][z] + result[f"w_{enterprise - 1}"][current_sum - z][0],
                            z)
                        )
                        values_for_w.sort(key=lambda w_z_pair: w_z_pair[0], reverse=True)
                        if len(values_for_w) > 1 and values_for_w[0][0] == values_for_w[1][0]:
                            w = (
                                values_for_w[0][0],
                                values_for_w[0][1],
                                values_for_w[1][1],
                            )
                        else:
                            w = values_for_w[0]
                print(f"MAX: {w[0]}, z={w[1:]}")

            k_enterprise_profit_vector[current_sum] = w
            result[f"w_{enterprise}"] = k_enterprise_profit_vector

# printing result
res = []
header_info = [f"{i}" for i in range(0, sum_of_money, step)]
res.append(header_info)
res.append(["====="] * len(header_info))
for index, enterprise in enumerate(result):
    if index == 0:
        row = [f"{result[enterprise][i]}" for i in range(0, sum_of_money, step)]
    else:
        row = [f"{result[enterprise][i]}" for i in range(0, sum_of_money, step)]
    res.append(row)

print(tabulate(res))
