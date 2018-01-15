# Uses python3
# Implement an algorithm for the fractional knapsack problem: finding
# the most valuable combination of items out of a larger pool 
# that can fit into a smaller bag.

# Input: The total number of items n, the capacity W of a knapsack,
#   and then for the next n lines, the value and weight of items.
#
# Output: The maximal value of fractions of items that fit

import random

def get_optimal_value(capacity, weights, values):
    value = 0.
    index = 0
    worth = {}
    #1. Find the value of each item
    #2. Sort items by value
    for i in range(len(weights)):
        worth[i] = float(values[i])/weights[i]
    sort_keys = sorted(worth, key=worth.__getitem__, reverse=True)
    #3. Add items by value until weight limit reached
    while capacity > 0.:
        amt = min(capacity, weights[sort_keys[index]])
        value += worth[index]*amt
        capacity -= amt
        index += 1
    
    return value


data = list(map(int, input().split()))
# n, capacity = data[0:2]
# values = data[2:(2 * n + 2):2]
# weights = data[3:(2 * n + 2):2]
n = 1000; capacity = 2*10**6
values = random.sample(range(2*10**6),1000)
weights = random.sample(range(2*10**6),1000)
opt_value = get_optimal_value(capacity, weights, values)
print("{:.10f}".format(opt_value))
