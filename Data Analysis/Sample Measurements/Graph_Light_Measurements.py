# /*
#  * Project graph_chla_results
#  * Description: graph chla sample readings from a .csv file, change the file name as needed as well as the title of the graph
# and which light measurement you wish to analyze. 
#  * Author: Jessie Wynne
#  * Date: 07/28/2023
#  */

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Replace with the actual file path
file_path = "/Users/jessiewynne/chla_fluorometer/chlorphyll sample tests 7.28.23/chl_test_5_gain_high_250_light_7.28.23.csv"

# Skip the rows with duplicate headers while reading the CSV file
df = pd.read_csv(file_path, encoding='utf-8', skiprows=[1])

# Access the 'seconds' column
seconds_values = df['Seconds'][1:]

# Access different light measurements
# visible_values = df['Visible'][1:]  # Exclude the header row
# lux_values = df['Lux'][1:]          # Exclude the header row
full_values = df['Full'][1:]        # Exclude the header row

# Convert to numeric
# visible_values = pd.to_numeric(visible_values, errors='coerce').dropna()
# lux_values = pd.to_numeric(lux_values, errors='coerce').dropna()
full_values = pd.to_numeric(full_values, errors='coerce').dropna()
x_axis = pd.to_numeric(seconds_values, errors='coerce').dropna()

# Get unique test categories from the 'Test' column
categories = df['Test'].unique()
categories = [category for category in categories if category.lower() != 'test']  # Remove 'test' from the categories

# Create dictionaries to store the light values for each category
# category_visible_dict = {}
# category_lux_dict = {}
category_full_dict = {}

for category in categories:
    # category_visible_dict[category] = visible_values[df['Test'] == category]
    # category_lux_dict[category] = lux_values[df['Test'] == category]
    category_full_dict[category] = full_values[df['Test'] == category]

# Calculate the mean, minimum, and maximum for each category for each light measurement
# category_visible_means = np.array([np.mean(visible_vals) for visible_vals in category_visible_dict.values()])
# category_visible_mins = np.array([np.min(visible_vals) for visible_vals in category_visible_dict.values()])
# category_visible_maxs = np.array([np.max(visible_vals) for visible_vals in category_visible_dict.values()])

# category_lux_means = np.array([np.mean(lux_vals) for lux_vals in category_lux_dict.values()])
# category_lux_mins = np.array([np.min(lux_vals) for lux_vals in category_lux_dict.values()])
# category_lux_maxs = np.array([np.max(lux_vals) for lux_vals in category_lux_dict.values()])

category_full_means = np.array([np.mean(full_vals) for full_vals in category_full_dict.values()])
category_full_mins = np.array([np.min(full_vals) for full_vals in category_full_dict.values()])
category_full_maxs = np.array([np.max(full_vals) for full_vals in category_full_dict.values()])

# Calculate the positive and negative errors (distance from mean to maximum and minimum) for each light measurement
# yerr_pos_visible = np.abs(category_visible_maxs - category_visible_means)
# yerr_neg_visible = np.abs(category_visible_means - category_visible_mins)

# yerr_pos_lux = np.abs(category_lux_maxs - category_lux_means)
# yerr_neg_lux = np.abs(category_lux_means - category_lux_mins)

yerr_pos_full = np.abs(category_full_maxs - category_full_means)
yerr_neg_full = np.abs(category_full_means - category_full_mins)

# Prepare data for scatter plot
x_data = np.arange(len(categories))

# Scatter plot for all visible values
# plt.scatter(x_data, category_visible_means, label='Visible Measurements')
# plt.errorbar(x_data, category_visible_means, yerr=[yerr_neg_visible, yerr_pos_visible], fmt='o', capsize=3, ecolor='black')

# # Scatter plot for all lux values
# plt.scatter(x_data, category_lux_means, label='Lux Measurements')
# plt.errorbar(x_data, category_lux_means, yerr=[yerr_neg_lux, yerr_pos_lux], fmt='o', capsize=3, ecolor='black')

# # Scatter plot for all full values
plt.scatter(x_data, category_full_means, label='Full Measurements')
plt.errorbar(x_data, category_full_means, yerr=[yerr_neg_full, yerr_pos_full], fmt='o', capsize=3, ecolor='black')

plt.ylabel('Measurement Values')
plt.title("Chlorophyll Sensor Sample Tests LED 250, Gain HIGH")

plt.xticks(x_data, labels=categories, rotation=45)

plt.legend()
plt.tight_layout()
plt.show()
