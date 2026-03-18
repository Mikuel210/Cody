![Cody](Images/Logo.png)

**Cody is a robot for the next season of WRO Robomission Senior.** 

The World Robot Olympiad (WRO) is a global robotics competition. For the Robomission challenge, you have to design, build and program a robot to complete a set of challenges on a board in under 2 minutes. Cody is our attempt at making our best robot so far, and I'm designing it to be faster, more precise and more reliable than all of our previous.

![Render](Images/Render.png)

## This year's challenges

1. There is a mosaic with a randomized pattern of colors at the center of the board. You have to place a block of the right color in each square of the grid to score.

![Mosaic](Images/Mosaic1.png)

![Blocks](Images/Mosaic2.png)

2. There are blocks of "cement" of different colors on the board. You have to carry the blocks of each color to their corresponding area.

![Cement](Images/Cement.png)

## Our solution

1. A toolhead grabs and drops blocks for the mosaic by using wheels

![Toolhead](Images/Toolhead.png)

2. A mill picks up, carries and releases two colors of cement at a time

![Mill](Images/Mill.png)

## How it works

- **Electronics:** I'm using an ESP32 as the microcontroller, an MPU9250 IMU for orientation and a TCS34725 color sensor for detecting the lines on the board. I'm also using an ADS1115 ADC for measuring the voltage of the battery and a PCF8575 GPIO expander.
- **Camera:** I'm using an ESP32-CAM to detect the color pattern of the mosaic.
- **Actuators:** I'm using JGB37-3530 motors for the wheels and N20 motors for the toolhead and for the mill. I'm using TB6612FNG drivers to control them.
- **Power:** I'm using a 3S 2200mAh LiPo battery for powering the robot. I'm also using a voltage regulator for powering the ESP32.
- **Structure:** I'm using 3D printed structural parts that have attachments for the components. I will be printing them out of PETG. I'm also using standard hardware such as bearings, carbon fiber rods and castor wheels.
- **Software:** I'm using odometry and a Pure Pursuit algorithm for control.

## Why I made this

My team has been using Lego Spike since we started competing, but it's starting to show its limitations. Last year, we went to the international final for the first time. Robomission had opened up to all hardwares for the first time this year, which means other teams could make faster, more precise and more reliable robots than what we could possibly do with Lego. I'm designing this robot to be faster, more precise and more reliable than our previous robots with the power of open hardware.

## PCB

![PCB 3D model](Images/PCB3D.png)

![PCB Layout](Images/PCBLayout.png)

![PCB Schematic](Images/PCBSchematic.png)

## Wiring diagram

![Wiring diagram](Images/WiringDiagram.png)

## Onshape Document

https://cad.onshape.com/documents/a1e1109ed4daddff079aebb8/w/75daa850bdae83d3a805f11b/e/0ab81b698f3d6ebcf8c57589?renderMode=1&uiState=69baba64dff3c3ac052b00d2

## Cart screenshots

![Cart screenshot](Cart/PCB1.png)
![Cart screenshot](Cart/PCB2.png)
![Cart screenshot](Cart/Amazon1.png)
![Cart screenshot](Cart/Amazon2.png)
![Cart screenshot](Cart/AliExpress1.png)
![Cart screenshot](Cart/AliExpress2.png)
![Cart screenshot](Cart/AliExpress3.png)
![Cart screenshot](Cart/Shipping1.png)
![Cart screenshot](Cart/Shipping2.png)
![Cart screenshot](Cart/Shipping3.png)
![Cart screenshot](Cart/Shipping4.png)
![Cart screenshot](Cart/Shipping5.png)

## BOM

> Note that the amount to buy might be higher than the amount to be used because the item is sold in bulk

|Item                            |Amount|Amount to buy|Unit price|Total price       |Link                                                                                                    |Config                         |
|--------------------------------|------|-------------|----------|------------------|--------------------------------------------------------------------------------------------------------|-------------------------------|
|PETG                            |1     |0            |0,00 €    |0,00 €            |-                                                                                                       |-                              |
|PCB                             |1     |1            |16,00 €   |16,00 €           |https://jlcpcb.com                                                                                      |-                              |
|Battery                         |2     |2            |17,50 €   |34,99 €           |https://www.amazon.es/Zeee-Bater%C3%ADa-Veh%C3%ADculos-Cuadric%C3%B3ptero-Helic%C3%B3ptero/dp/B0BYNSH6Q7|-                              |
|X Axis rods                     |2     |8            |2,17 €    |17,39 €           |https://es.aliexpress.com/item/1005006793821681.html                                                    |12x100mm 1pcs                  |
|Z Axis rods                     |2     |2            |3,29 €    |6,58 €            |https://es.aliexpress.com/item/4001063505625.html                                                       |8mm 200mm                      |
|Wheel motors                    |2     |2            |17,76 €   |35,52 €           |https://es.aliexpress.com/item/1005008730235398.html                                                    |533rpm 12V Single motor        |
|N20 motors                      |4     |4            |10,47 €   |41,88 €           |https://es.aliexpress.com/item/1005009284080839.html                                                    |136x2, 272x2 without fixed seat|
|Front wheels                    |2     |2            |3,44 €    |6,87 €            |https://es.aliexpress.com/item/1005010058308140.html                                                    |49295 1pcs                     |
|Back wheels                     |2     |2            |1,69 €    |3,38 €            |https://es.aliexpress.com/item/1005005334424631.html                                                    |7.5mm 1Pcs MJ310               |
|5x10x4 Bearing                  |11    |20           |0,35 €    |6,98 €            |https://es.aliexpress.com/item/1005007668446060.html                                                    |5x10x4mm                       |
|Buzzer                          |1     |0            |0,00 €    |0,00 €            |-                                                                                                       |-                              |
|RGB LED                         |1     |0            |0,00 €    |0,00 €            |-                                                                                                       |-                              |
|Resistors                       |7     |0            |0,00 €    |0,00 €            |-                                                                                                       |-                              |
|Mechanical switch               |1     |0            |0,00 €    |0,00 €            |-                                                                                                       |-                              |
|Limit switches                  |2     |10           |0,20 €    |1,99 €            |https://es.aliexpress.com/item/1005008823539259.html                                                    |16mm Lever                     |
|TB6612FNG Motor drivers         |3     |3            |2,11 €    |6,33 €            |https://es.aliexpress.com/item/1005006983040834.html                                                    |TB6612FNG Weld                 |
|ESP32 DevKitC                   |1     |1            |5,29 €    |5,29 €            |https://es.aliexpress.com/item/1005008256121637.html                                                    |32D-Type-C-1PCS                |
|PCF8575 GPIO Expander           |1     |1            |1,63 €    |1,63 €            |https://es.aliexpress.com/item/1005002073772322.html                                                    |1PCS                           |
|ADS1115 ADC                     |1     |1            |1,59 €    |1,59 €            |https://es.aliexpress.com/item/32311656694.html                                                         |ADS1115 Blue                   |
|MPU9250 IMU                     |1     |1            |9,48 €    |9,48 €            |https://es.aliexpress.com/item/1005009033822037.html                                                    |GY-9250 original               |
|TCS34725 Color sensor           |1     |1            |3,59 €    |3,59 €            |https://es.aliexpress.com/item/1005006292597348.html                                                    |Rectangular                    |
|XT60 Connectors                 |2     |2            |0,87 €    |1,73 €            |https://es.aliexpress.com/item/1005004628891959.html                                                    |2 pairs male female            |
|JST-XH Connectors               |9     |9            |0,54 €    |4,89 €            |https://es.aliexpress.com/item/1005008638438956.html                                                    |-                              |
|12V to 6V converter             |1     |1            |2,64 €    |2,64 €            |https://es.aliexpress.com/item/1005007763337343.html                                                    |6V                             |
|ESP32-CAM                       |1     |1            |13,29 €   |13,29 €           |https://www.amazon.es/diymore-desarrollo-ESP32-CAM-MB-Bluetooth-inal%C3%A1mbrica/dp/B08X3GRK22          |-                              |
|Velcro for battery and converter|1     |1            |1,75 €    |1,75 €            |https://es.aliexpress.com/item/1005008938790125.html                                                    |Black 1M 30mm                  |
|Cable for sensors and motors    |1     |1            |2,27 €    |2,27 €            |https://es.aliexpress.com/item/1005006566120439.html                                                    |5m 22 AWG                      |
|Cable for battery               |1     |0            |0,00 €    |0,00 €            |-                                                                                                       |-                              |
|TOTAL                           |      |             |          |226,06 € ($260.19)|                                                                                                        |                               |


---

Made with ❤️ for Blueprint thanks to Hack Club