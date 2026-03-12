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

2. A mill picks up and releases two colors of cement at a time

![Mill](Images/Mill.png)

## How it works

- **Electronics:** I'm using an ESP32 as the microcontroller, an MPU9250 IMU for orientation and a TCS34725 color sensor for detecting lines. I'm also using an ADS1115 ADC for measuring the voltage of the battery and a PCF8575 GPIO expander.
- **Camera:** I'm using an ESP32-CAM to detect the color pattern of the mosaic.
- **Actuators:** I'm using JGB37-3530 motors for the wheels and a JGA25-371 motor for the mill. I'm using TB6612FNG drivers to control them.
- **Power:** I'm using a 3S 2200mAh LiPo battery for powering the robot. I'm also using a voltage regulator for powering the ESP32.
- **Structure:** I'm using 3D printed structural parts that have attachments for the components. I will be printing them out of PETG. I'm also using standard hardware such as bearings, timing belts and pulleys and castor wheels.
- **Software:** I'm using odometry and a Pure Pursuit algorithm for control.

## Why I made this

My team has been using Lego Spike since we started competing, but it's starting to show its limitations. This year, we went to the international final for the first time. Robomission had opened up to all hardwares for the first time this year, which means other teams could make faster, more precise and more reliable robots than what we could possibly do with Lego. I'm designing this robot to be faster, more precise and more reliable than our previous robots with the power of open hardware.

## PCB

![PCB 3D model](Images/PCB3D.png)

![PCB Layout](Images/PCBLayout.png)

![PCB Schematic](Images/PCBSchematic.png)

## Wiring diagram

![Wiring diagram](Images/WiringDiagram.png)

## Onshape Document

https://cad.onshape.com/documents/260b0a88adbc970035266293/w/ce63ac66f2f848d4fa4400ea/e/e148cc90b3821c2fc497715b?renderMode=1&uiState=69b1ed001121df76ba1aad64

## BOM

> Note that the amount to buy might be higher than the amount to be used because the item is sold in bulk

| Item                             | Amount | Amount to buy | Unit price | Total price        | Unit Min Weight (g) | Unit Max Weight (g) | Link                                                                                                     | Config                              |
|----------------------------------|--------|---------------|------------|--------------------|---------------------|---------------------|----------------------------------------------------------------------------------------------------------|-------------------------------------|
| PETG                             | 1      | 0             | 0,00 €     | 0,00 €             | 360,00              | 400,00              | -                                                                                                        | -                                   |
| PCB                              | 1      | 1             | 16,00 €    | 16,00 €            | 40,00               | 60,00               | https://jlcpcb.com                                                                                       | -                                   |
| Battery                          | 2      | 2             | 17,50 €    | 34,99 €            | 130,00              | 160,00              | https://www.amazon.es/Zeee-Bater%C3%ADa-Veh%C3%ADculos-Cuadric%C3%B3ptero-Helic%C3%B3ptero/dp/B0BYNSH6Q7 | -                                   |
| X Axis linear rail               | 1      | 1             | 10,99 €    | 10,99 €            | 160,00              | 180,00              | https://es.aliexpress.com/item/4000762343261.html                                                        | MGN12C 200mm                        |
| Z Axis linear rail               | 1      | 1             | 7,09 €     | 7,09 €             | 50,00               | 60,00               | https://es.aliexpress.com/item/4000762343261.html                                                        | MGN9C 100mm                         |
| Motors                           | 5      | 5             | 20,86 €    | 104,28 €           | 175,00              | 200,00              | https://es.aliexpress.com/item/1005008730235398.html                                                     | 533rpm 12V Single motor             |
| JGA25-371 Motor                  | 1      | 1             | 7,79 €     | 7,79 €             | 100,00              | 110,00              | https://es.aliexpress.com/item/1005007546764319.html                                                     | 60rpm 12V                           |
| Front wheels                     | 2      | 2             | 1,59 €     | 3,18 €             | 27,00               | 30,00               | https://es.aliexpress.com/item/1005010058308140.html                                                     | 49295 1pcs                          |
| Back wheels                      | 2      | 2             | 1,79 €     | 3,58 €             | 5,00                | 10,00               | https://es.aliexpress.com/item/1005005334424631.html                                                     | 7.5mm 1Pcs MJ310                    |
| 5x10x4 Bearing                   | 12     | 20            | 0,35 €     | 6,98 €             | 2,00                | 3,00                | https://es.aliexpress.com/item/1005007668446060.html                                                     | 5x10x4mm                            |
| 17x26x5 Bearing                  | 2      | 2             | 2,90 €     | 5,79 €             | 7,00                | 9,00                | https://es.aliexpress.com/item/1005008226294126.html                                                     | 6803-2RS (17X26X5)                  |
| Timing pulleys                   | 2      | 2             | 1,79 €     | 3,58 €             | 15,00               | 30,00               | https://es.aliexpress.com/item/1005008678109995.html                                                     | 8mm 10mm 36T                        |
| Timing belt                      | 1      | 1             | 3,29 €     | 3,29 €             | 6,00                | 12,00               | https://es.aliexpress.com/item/1005006459125914.html                                                     | Belt Width 9mm 300mm-2GT(150 Teeth) |
| Buzzer                           | 1      | 0             | 0,00 €     | 0,00 €             | 2,00                | 4,00                | -                                                                                                        | -                                   |
| RGB LED                          | 1      | 0             | 0,00 €     | 0,00 €             | 2,00                | 4,00                | -                                                                                                        | -                                   |
| BMS Resistors                    | 6      | 0             | 0,00 €     | 0,00 €             | 0,25                | 0,50                | -                                                                                                        | -                                   |
| Limit switches                   | 2      | 10            | 0,24 €     | 2,36 €             | 2,00                | 2,00                | https://es.aliexpress.com/item/1005008823539259.html                                                     | 16mm Lever                          |
| TB6612FNG Motor drivers          | 3      | 3             | 2,10 €     | 6,30 €             | 1,00                | 2,00                | https://es.aliexpress.com/item/1005006983040834.html                                                     | TB6612FNG Weld                      |
| ESP32 DevKitC                    | 1      | 1             | 5,39 €     | 5,39 €             | 250,00              | 260,00              | https://es.aliexpress.com/item/1005008256121637.html                                                     | 32D-Type-C-1PCS                     |
| PCF8575 GPIO Expander            | 1      | 1             | 0,99 €     | 0,99 €             | 1,00                | 2,00                | https://es.aliexpress.com/item/1005002073772322.html                                                     | 1PCS                                |
| ADS1115 ADC                      | 1      | 1             | 1,59 €     | 1,59 €             | 1,00                | 2,00                | https://es.aliexpress.com/item/32311656694.html                                                          | ADS1115 Blue                        |
| MPU9250 IMU                      | 1      | 1             | 7,49 €     | 7,49 €             | 2,00                | 3,00                | https://es.aliexpress.com/item/1005009033822037.html                                                     | GY-9250 original                    |
| TCS34725 Color sensor            | 1      | 1             | 2,99 €     | 2,99 €             | 2,00                | 3,00                | https://es.aliexpress.com/item/1005009651619906.html                                                     | 1pcs                                |
| XT60 Connectors                  | 2      | 2             | 0,75 €     | 1,50 €             | 7,00                | 8,00                | https://es.aliexpress.com/item/1005004628891959.html                                                     | 2 pairs male female                 |
| JST-XH Connectors                | 9      | 9             | 0,59 €     | 5,29 €             | 1,00                | 2,00                | https://es.aliexpress.com/item/1005008638438956.html                                                     | -                                   |
| 12V to 6V converter              | 1      | 1             | 2,82 €     | 2,82 €             | 20,00               | 40,00               | https://es.aliexpress.com/item/1005007763337343.html                                                     | 6V                                  |
| ESP32-CAM                        | 1      | 1             | 13,29 €    | 13,29 €            | 10,00               | 15,00               | https://www.amazon.es/diymore-desarrollo-ESP32-CAM-MB-Bluetooth-inal%C3%A1mbrica/dp/B08X3GRK22           | -                                   |
| Velcro for battery and converter | 1      | 1             | 1,84 €     | 1,84 €             | 5,00                | 15,00               | https://es.aliexpress.com/item/1005008938790125.html                                                     | Black 1M 30mm                       |
| Cable for sensors and motors     | 1      | 1             | 1,99 €     | 1,99 €             | 18,00               | 24,00               | https://es.aliexpress.com/item/1005006566120439.html                                                     | 3m 22 AWG                           |
| TOTAL                            |        |               |            | 261,38 € ($301.19) | 2327,5              | 2755                |                                                                                                          |                                     |

---

Made with ❤️ for Blueprint thanks to Hack Club