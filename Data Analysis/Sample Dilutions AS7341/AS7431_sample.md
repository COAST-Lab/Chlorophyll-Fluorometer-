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

## Step 4
## Dilution Preparation
Prepare an 80% (5.2mg/L), 60% (3.9mg/L), 40% (2.6mg/L), and 20% (1.3mg/L) dilution solutions of the chlorophyll water sample. 

## Step 5
Insert fill an empty cuvette with the 6.5 mg/L solutuion. Insert the cuvette into the sensor. Cover the sensor with the cardboard box and run the code with the LED light on for one minute. 

## Step 6 
Stop the reading and take out the corvette. Repeat this process with the 80%, 60%, 40%, and 20% dilution solutions. 

## Step 7
After all of the dilution solutions have been tested, stop testing and take the SD card out of the fluorometer and plug it into the computer to begin analysis of the data collected.

## Step 8
This test will be performed first with an LED intensity of 255 and an AS73411 gain of 512x and an ATIME of 59 and ASTEP of 599 and then repeated with a gain of 64x. The data is recorded onto the SD card in the microcontroller. 

# Data Analysis

## Graphing
When taking measurements the AS7341 light sensor collects light measurements of multiple wavelengths. The wavelength of 680nm (denoted as F8) will be analyzed.

## Graph characteristics
Each graph shows the categories of '6.5 mg/L', '5.2 mg/L', '3.9 mg/L', '2.6 mg/L', and '1.3 mg/L' on the x-axis to denote each test. And the numerical value of the F8 light measurement on the y-axis. The mean of each category will be plotted with an error bar with extends from the lowest value of the data set to the largest.

## 512x Gain Graph

![Dillutions_gain_512](https://github.com/jessiewynne/Chlorophyll-Fluorometer-/assets/106984291/c09a2a3d-d664-4e92-b7f5-607d3c19e98d)

## 64x Gain Graph

![Dillutions_gain_64](https://github.com/jessiewynne/Chlorophyll-Fluorometer-/assets/106984291/84f892dc-a129-4098-b200-fd9b9366fe56)



```python

```
