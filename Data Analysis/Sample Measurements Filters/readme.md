# Description
This is the analysis of the chlorophyll fluorometer by taking measurements 
of chlorophyll standards via rhodamine dye. This analysis is to test the use
of filters with different transmissions to evaluate if higher transmissions lead 
to less overlap in measurements. 

# Fluormeter Testing

## Fluormeter Design 
This fluorometer is a benchtop model with housing which positions the LED and 
the TSL2592 at a 90-degree angle as well as will be an opaque design as to 
eliminate any ambient light from impacting the measurements. The TSL 2591
has been fitted with either a Rosculox #18 filter (56% transmission) or a Rosculox
#321 filter (39% transmission). The top of the benchtop design contains a hole 
that fits a cuvette. To begin testing, a cuvette is placed into the fluorometer with the water
sample. Design materials can be found at:
https://github.com/COAST-Lab/Chlorophyll-Fluorometer-/tree/main/Firmware. 

![Device diagram](https://github.com/jessiewynne/Chlorophyll-Fluorometer-/assets/106984291/554d99b8-492b-47fd-ae99-6a4d6a99ab5d)

## Filters
Filters fitted over the light sensor are used to commit the blue excitation light from
being measured. Red filters with wavelengths between 690-740nm are usually used
to accomplish this. The filter used in this test, Rsoculox filters #18 and #321 have 
wavelengths of approximately 620-700nm and 660-700nm respectively. 

![IMG_4911](https://github.com/jessiewynne/Chlorophyll-Fluorometer-/assets/106984291/e6dd8524-6fb8-4f67-a9e4-7e0d3e390712)
![IMG_4910](https://github.com/jessiewynne/Chlorophyll-Fluorometer-/assets/106984291/375621dd-f009-4b60-b892-446acf3e2451)

## Testing Procedure 

### Step 1
A YSI instrument was calibrated to be used to verify the chlorophyll water sample
which would be prepared. Calibration information: 
https://www.ysi.com/file%20library/documents/manuals/exo-user-manual-web.pdf

### Step 2
A water sample was prepared with a chlorophyll concentration of 6.5mg/L and 
an RFU of 15.8 RFU. This water sample was prepared with rhodamine dye and DI water

#### Chlorophyll Sample Preparation
###### Step 1
5mL of Rhodamine dye was pipetted into a 1000mL volumetric flask or beaker. Fill 
the flask or beaker up to 1000mL mark with DI water
    
###### Step 2
Pipette 5mL of the prepared solution in step 1 into a separate 1000mL volumetric
flask or beaker. Fill this flask or beaker up to 1000mL mark with DI water. This
will be your chlorophyll water sample

###### Step 3
Verify the concentration of the prepared chlorophyll water sample with the YSI

  
### Step 3
Insert an empty cuvette into the fluorometer housing. Cover the fluorometer with a 
cardboard box to ensure it is in complete darkness. Modify the code to turn the LED OFF
and run for 1 minute 

![IMG_4870](https://github.com/jessiewynne/Chlorophyll-Fluorometer-/assets/106984291/18f3646b-04e4-481c-b781-406d663bb5e0)

### Step 4
Repeat step 3 with the LED ON 

### Step 5
Stop readings and take the empty cuvette out of the fluorometer. Insert a cuvette 
filled with DI water into the fluorometer. Recover with the box and run the code 
with the LED ON for one minute

### Step 6
Stop readings and take the cuvette filled with DI water out of the fluorometer. 
Insert a cuvette filled with chlorophyll water solution into the fluorometer. 
Recover with the box and run the code with the LED ON for one minute

### Step 7
Stop testing and take the SD card out of the fluorometer and plug it into the 
computer to begin analysis of the data collected. 

### Step 8
This test will be performed first with an LED intensity of 250 and a TSL 2591
gain of HIGH and then repeated with a LED intensity of 255 and a TSL 2591
gain of MAX. 

This test was completed once with the Rosculox #18 filter and then again
with the #321 filter. 


## Data Analysis 

### Graphing 
When taking measurements the TSL 2591 light sensor collects light measurements 
of Visible, Full, IR, and Lux. Data analysis will be performed on Visible, Full
, and Lux. 

#### Graph characteristics
Each graph shows the catagories of 'cuvette dark', 'cuvette light', 'DI Water' 
and '6.5 mg/L' on the x-axis to denote each test. And the numerical value of 
the light measurement on the y-axis. The mean of each category will be plotted
with an error bar with extends from the lowest value of the data set to 
the largest. 

## Lux Graph #18 Filter

![chl_sample_filter_18_lux](https://github.com/jessiewynne/Chlorophyll-Fluorometer-/assets/106984291/fdeaa569-6012-46e6-b5d6-61c43986480f)

## Lux Graph #321 Filter

![chl_sample_filter_321](https://github.com/jessiewynne/Chlorophyll-Fluorometer-/assets/106984291/fab4484a-5f64-4384-b8a0-261faf894dd3)

## Visible Graph #18 Filter
![chl_sample_filter_18_visible](https://github.com/jessiewynne/Chlorophyll-Fluorometer-/assets/106984291/dda8abfe-e1cf-458e-bc43-a431d0d8213e)

## Visible Graph #321 Filter
![chl_sample_filter_321_visible](https://github.com/jessiewynne/Chlorophyll-Fluorometer-/assets/106984291/6a673d27-7fbe-468c-aae3-a249fd96f800)

## Full Graph #18 Filter
![chl_sample_filter_18_full](https://github.com/jessiewynne/Chlorophyll-Fluorometer-/assets/106984291/cfe74d3c-d1f1-450f-9665-91ffa5e3c4b3)

## Full Graph #321 Filter 
![chl_sample_filter_321_full](https://github.com/jessiewynne/Chlorophyll-Fluorometer-/assets/106984291/05c0c925-9923-477b-93a6-8bb5b9a86dfc)

# Conclusion
It seems that the greater the transmission of the filter, the higher the light measurements
are. This could be beneficial as the LED is able to penetrate through these filters more
and possibly lead to higher sensitivity when measuring chlorophyll fluorescence. 


```python

```
