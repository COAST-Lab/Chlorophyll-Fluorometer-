## Description
This is the analysis of the chlorophyll fluorometer by taking measurements 
of chlorophyll standards via rhodamine dye. These tests serve as an analysis
of the fluorometer's functionality for future testing. 

# Fluormeter Testing

## Fluormeter Design 
This fluorometer is a benchtop model with housing which positions the LED and 
the TSL2592 at a 90-degree angle as well as will be an opaque design as to 
eliminate any ambient light from impacting the measurements. The TSL 2591
is fitted with a red filter. The top of the benchtop design contains a hole 
that fits a cuvette. A cuvette is placed into the fluorometer with the water
sample to begin testing. Design materials can be found at:
https://github.com/COAST-Lab/Chlorophyll-Fluorometer-/tree/main/Firmware. 

![Device diagram](https://github.com/jessiewynne/Chlorophyll-Fluorometer-/assets/106984291/e1dbfbcf-1282-4f4f-b6a5-64d1a4bbdccc)

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

![IMG_4870](https://github.com/jessiewynne/Chlorophyll-Fluorometer-/assets/106984291/631908a3-fcbd-4e5a-ba5a-82cc02da3a98)



### Step 4
Repeat step 3 with the LED ON 

### Step 5
Stop readings and take the empty cuvette out of the fluorometer. Insert a cuvette 
filled with DI water into the fluorometer. Recover with the box and run the code 
with the LED ON for one minute

### Step 6
Stop readings and take the cuvette filled with DI water out of the flurometer. 
Insert a cuvette filled with chlorophyll water solution into the fluorometer. 
Recover with the box and run the code with the LED ON for one minute

### Step 7
Stop testing and take the SD card out of the fluorometer and plug it into the 
computer to begin analysis of the data collected. 

### Step 8
This test will be performed first with an LED intensity of 250 and a TSL 2591
gain of HIGH and then repeated with a LED intensity of 255 and a TSL 2591
gain of MAX. 


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

## Lux Graphs 

![Chlorophyll_Sample_Tests_LED_250_Gain_High_Lux](https://github.com/jessiewynne/Chlorophyll-Fluorometer-/assets/106984291/4a7cc37a-fedc-479b-a4ac-9ac780fac6bd)

![Chlorophyll_Sample_Tests_LED_255_Gain_Max_Lux](https://github.com/jessiewynne/Chlorophyll-Fluorometer-/assets/106984291/84f70004-b088-42a7-a517-b019b4ec19a3)


## Visible Graphs 

![Chlorophyll_Sample_Tests_LED_250_Gain_High_Visible ](https://github.com/jessiewynne/Chlorophyll-Fluorometer-/assets/106984291/d7686e21-c524-4046-9984-067f10f2fa0b)

![Chlorophyll_Sample_Tests_LED_255_Gain_Max_Visible ](https://github.com/jessiewynne/Chlorophyll-Fluorometer-/assets/106984291/2606f4a9-b12d-4285-80c7-236bbcc46252)

## Full Graphs 
![Chlorophyll_Sample_Tests_LED_250_Gain_High_Full](https://github.com/jessiewynne/Chlorophyll-Fluorometer-/assets/106984291/e72b1fba-54ed-4a39-bd89-b31b2d3f94a9)


![Chlorophyll_Sample_Tests_LED_255_Gain_Max_Full](https://github.com/jessiewynne/Chlorophyll-Fluorometer-/assets/106984291/1c4d4c50-cade-47bd-aa56-0de902508da5)
