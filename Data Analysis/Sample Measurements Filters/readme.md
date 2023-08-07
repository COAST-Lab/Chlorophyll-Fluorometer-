# Decription
This is the analysis of the chlorophyll flurometer by taking measurements 
of chlorophyll standars via rhodamine dye. This analysis is to test the use
of filters with different transmissions to evaluate if higher transmissions leads 
to less overlap in measurements. 

# Fluormeter Testing

## Fluormeter Desgin 
This fluorometer is a benchtop model with housing which positions the LED and 
the TSL2592 at a 90 degree angle as well as will be an opage design as to 
eliminate any ambient light from impacting the measurements. The TSL 2591
has been fitted with either a Rosculox #18 filter (56% transmission) or a Rosculox
#321 filter (39% transmisson). The top of the benchtop design contains a hole 
which fits a cuvette. A cuvette is placed into the flurometer with the water
sample to begin testing. Design materialsc an be found at:
https://github.com/COAST-Lab/Chlorophyll-Fluorometer-/tree/main/Firmware. 

![Device%20diagram.jpg](Device%20diagram.jpg)

## Filters
Filters fitted over the light sensor are used to ommit the blue excitation light from
being measured. Red filters with the wavelemngths between 690-740nm are usually used
to acchomplish this. The filter used in this test, Rsoculox filters #18 and #321 have 
wavelengths of approixmately 620-700nm and 660-700nm respectively. 

![](IMG_4910.jpg)

![IMG_4911.jpg](IMG_4911.jpg)

## Testing Procedure 

### Step 1
A YSI instrument was calibrated to be used to verify the chlorphyll water sample
which would be prepared. Callibration information: 
https://www.ysi.com/file%20library/documents/manuals/exo-user-manual-web.pdf

### Step 2
A water sample was prepared with a chlorophyll concentration of 6.5mg/L and 
an RFU of 15.8 RFU. This water sample was prepared with rhodamine dye and DI water

#### Chlorophyll Sample Preparation
###### Step 1
5mL of Rhodamine dye was pitpetted into a 1000mL volumetric flask or beaker. Fill 
the flask or beaker up to 1000mL mark with DI water
    
###### Step 2
Pipette 5mL of the prepared solution in step 1 into a separate 1000mL volumetric
flask or beaker. Fill this flask or beaker up to 1000mL mark with DI water. This
will be your chlorphyll water sample

###### Step 3
Verify the concentration of the prepared chlorphyll water sample with the YSI

  
### Step 3
Insert an empty cuvette into the flurometer housing. Cover the flurometer with a 
cardboard box to ensure it is in complete darkness. Modify the code to turn the LED OFF
and run for 1 minute 

![IMG_4870.jpg](IMG_4870.jpg)

### Step 4
Repeat step 3 with the LED ON 

### Step 5
Stop readings and take the empty cuvette out of the flurometer. Insert a cuvette 
filled with DI water into the flurometer. Recover with the box and run the code 
with the LED ON for one minute

### Step 6
Stop readings and take the cuvette filled with DI water out of the flurometer. 
Insert a cuvette filled with chlorphyll water solution into the flurometer. 
Recover with the box and run the code with the LED ON for one minute

### Step 7
Stop testing anf take the SD card out of the flurometer and plug it into the 
computer ot begin analysis of the data collected. 

### Step 8
This test will be perfored first with an LED intensity of 250 and a TSL 2591
gain of HIGH and then repeated with a LED intensity of 255 and a TSL 2591
gain of MAX. 

This test was completed once with the Rosculox #18 filter and then again
with the #321 filter. 


## Data Analysis 

### Graphing 
When taking measurements the TSL 2591 light sensor collects light measurememts 
of Visible, Full, IR and Lux. Data analysis will be performed on Visible, Full
and Lux. 

#### Graph characteristics
Each graph shows the catagories of 'cuvette dark', 'cuvette light', 'DI Water' 
and '6.5 mg/L' on the x axis to denote each test. And the numerical value of 
the light measurement on the y axis. The mean of each catagorey will be plotted
with an error bar with extends from the lowest value of the data set to 
the largest. 

## Lux Graph #18 Filter

![chl_sample_filter_18_lux.png](chl_sample_filter_18_lux.png)

## Lux Graph #321 Filter

![chl_sample_filter_321.png](chl_sample_filter_321.png)

## Visible Graph #18 Filter

![chl_sample_filter_18_visible.png](chl_sample_filter_18_visible.png)

## Visible Graph #321 Filter

![chl_sample_filter_321_visible.png](chl_sample_filter_321_visible.png)

## Full Graph #18 Filter

![chl_sample_filter_18_full.png](chl_sample_filter_18_full.png)

## Full Graph #321 Filter 

![chl_sample_filter_321_full.png](chl_sample_filter_321_full.png)

# Conclusion
It seems that the greater the transmission of the filter, the higher the light measurements
are. This could be beneficial as the LED is able to penetrate through these filters more
and possibly lead to higher sensitivity when measuring chlorophyll fluorescence. 


```python

```
