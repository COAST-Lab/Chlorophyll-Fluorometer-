# Description
This is the analysis of the chlorophyll fluorometer by taking measurements of chlorophyll standards via rhodamine dye. These tests serve as an analysis of the fluorometer's functionality for future testing.

# Fluormeter Testing

## Fluormeter Design
This fluorometer is a benchtop model with housing which positions the LED and the AS7341 at a 90-degree angle as well as will be an opaque design as to eliminate any ambient light from impacting the measurements. The AS7341 is fitted with a red filter Rocsculux filter #19. This filter had a 20% transmission. The top of the benchtop design contains a hole that fits a cuvette. A cuvette is placed into the fluorometer with the water sample to begin testing. Design materials can be found at: https://github.com/COAST-Lab/Chlorophyll-Fluorometer-/tree/main/Firmware.


# Testing Procedure

## Step 1
A YSI instrument was calibrated to be used to verify the chlorophyll water sample which would be prepared. Calibration information: https://www.ysi.com/file%20library/documents/manuals/exo-user-manual-web.pdf

## Step 2
A water sample was prepared with a chlorophyll concentration of 6.5mg/L and an RFU of 15.8 RFU. This water sample was prepared with rhodamine dye and DI water

## Chlorophyll Sample Preparation
### Step 1
5mL of Rhodamine dye was pipetted into a 1000mL volumetric flask or beaker. Fill the flask or beaker up to 1000mL mark with DI water

### Step 2
Pipette 5mL of the prepared solution in step 1 into a separate 1000mL volumetric flask or beaker. Fill this flask or beaker up to 1000mL mark with DI water. This will be your chlorophyll water sample

### Step 3
Verify the concentration of the prepared chlorophyll water sample with the YSI

## Step 3
Insert an empty cuvette into the fluorometer housing. Cover the fluorometer with a cardboard box to ensure it is in complete darkness. Modify the code to turn the LED OFF and run for 1 minute


## Step 4
Repeat step 3 with the LED ON

## Step 5
Stop readings and take the empty cuvette out of the fluorometer. Insert a cuvette filled with DI water into the fluorometer. Recover with the box and run the code with the LED ON for one minute

## Step 6
Stop readings and take the cuvette filled with DI water out of the flurometer. Insert a cuvette filled with chlorophyll water solution into the fluorometer. Recover with the box and run the code with the LED ON for one minute

## Step 7
Stop testing and take the SD card out of the fluorometer and plug it into the computer to begin analysis of the data collected.

## Step 8
This test will be performed first with an LED intensity of 255 and a AS73411 gain of 512x and an ATIME of 59 and ASTEP of 599 and then repeated with a gain of 64x and then 4x. The data is recorded onto the SD card in the microcontroller. 

# Data Analysis

## Graphing
When taking measurements the AS7341 light sensor collects light measurements of multiple wavelengths. The wavelength of 680nm (denoted as F8) will be analyzed.

## Graph characteristics
Each graph shows the catagories of 'cuvette dark', 'cuvette light', 'DI Water Dark', 'DI Water Light' and '6.5 mg/L' on the x-axis to denote each test. And the numerical value of the F8 light measurement on the y-axis. The mean of each category will be plotted with an error bar with extends from the lowest value of the data set to the largest.

## 512x Gain Graph

## 64x Gain Graph

## 4x Gain Graph


```python

```
