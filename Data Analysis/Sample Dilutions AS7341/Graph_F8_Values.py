# /*
#  * Project graph_chla_results
#  * Description: graph chla sample readings from a .csv file, change the file name as needed as well as the title of the graph
# and which light measurement you wish to analyze. 
#  * Author: Jessie Wynne
#  * Date: 08/09/2023
#  */

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Replace with the actual file path
file_path = "/Users/jessiewynne/chl_dillutions_AS7341_512Gain.csv"

# df = pd.read_csv(file_path, encoding='utf-8', skiprows=[1])
# print(df.columns.tolist())

# Skip the rows with duplicate headers while reading the CSV file
df = pd.read_csv(file_path, encoding='utf-8', skiprows=[1])

# # Access the 'seconds' column
Seconds_values = df['Seconds'][1:]
df['Seconds'] = pd.to_numeric(df['Seconds'], errors='coerce')
# Access the 'F8 (Raw)' column
df = df.groupby('Test').apply(lambda group: group.iloc[1:]).reset_index(drop=True)
f8_raw_values = df['F8 (Raw)'][1:]

# Convert to numeric
f8_raw_values = pd.to_numeric(f8_raw_values, errors='coerce').dropna()
x_axis = df['Seconds']

# Get unique test categories from the 'Test' column
categories = df['Test'].unique()
categories = [category for category in categories if category.lower() != 'test']  # Remove 'test' from the categories

# Create a dictionary to store the 'F8 (Raw)' values for each category
category_f8_raw_dict = {}

for category in categories:
    category_f8_raw_dict[category] = f8_raw_values[df['Test'] == category]

# Calculate the mean, minimum, and maximum for each category for 'F8 (Raw)' data
category_f8_raw_means = np.array([np.mean(f8_raw_vals) for f8_raw_vals in category_f8_raw_dict.values()])
category_f8_raw_mins = np.array([np.min(f8_raw_vals) for f8_raw_vals in category_f8_raw_dict.values()])
category_f8_raw_maxs = np.array([np.max(f8_raw_vals) for f8_raw_vals in category_f8_raw_dict.values()])

# Calculate the positive and negative errors for 'F8 (Raw)' data
yerr_pos_f8_raw = np.abs(category_f8_raw_maxs - category_f8_raw_means)
yerr_neg_f8_raw = np.abs(category_f8_raw_means - category_f8_raw_mins)

# Prepare data for scatter plot
x_data = np.arange(len(categories))

# Scatter plot for 'F8 (Raw)' values
plt.scatter(x_data, category_f8_raw_means, label='F8 (Raw) Measurements')
plt.errorbar(x_data, category_f8_raw_means, yerr=[yerr_neg_f8_raw, yerr_pos_f8_raw], fmt='o', capsize=3, ecolor='black')

plt.ylabel('F8 (Raw) Measurement Values')
plt.title("Chlorophyll Sensor Sample Tests LED 255, Gain 64, Filter 19, ATIME 59, ASTEP 599")

plt.xticks(x_data, labels=categories, rotation=45)

plt.legend()
plt.tight_layout()
plt.show()
