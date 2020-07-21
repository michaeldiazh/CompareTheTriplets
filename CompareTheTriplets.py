#!/usr/bin/python

import math
import os
import random
import re
import sys

def compareTriplets(a, b):
    tot_a = 0
    tot_b = 0
    for i in range(3):
        tot_a += 1 if a[i] > b[i] else 0
        tot_b += 1 if a[i] < b[i] else 0
    return (tot_a,tot_b)

if __name__ == '__main__':
    # Getting files informaiton
    input_file = open("/Users/seppuku_kum/Desktop/Coding_Challenges/CompareTheTriplets/input00.txt",'r')
    if input_file.mode == 'r':
        data = input_file.read().replace("\n"," ")
        alice_pts, bob_pts = (data.split(" ")[0:3],data.split(" ")[3:])

    print(compareTriplets(alice_pts,bob_pts))
