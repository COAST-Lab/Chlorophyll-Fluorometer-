/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/jessiewynne/graph_chla_results/src/graph_chla_results.ino"
/*
 * Project graph_chla_results
 * Description: graph chla sesnor readings from a .csv file
 * Author: Jessie Wynne
 * Date: 07/06/2023
 */

#line 8 "/Users/jessiewynne/graph_chla_results/src/graph_chla_results.ino"
import pandas as pd
import matplotlib.pyplot as plt
import csv

file = "C:/Users/jessiewynne/chla_fluorometer/led_2_minute_test_7_6_2023.csv"

df = pd.read_csv(file, encoding='utf-8')
print(df)

row = 1

x_axis = file[lux]
y_axis = file['seconds']
plt.figure(figsize=(10,10))
plt.scatter(x_axis, y_axis, marker="*", s=100, edgecolors="black", c="gray")
plt.xlabel("Time")
plt.ylabel("lux values")
plt.title("LED Test")
plt.show()