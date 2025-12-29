![Cody](Images/Logo.png)

Cody is a robot for the next season of WRO Robomission Senior. WRO is a global robotics competition, and in the Robomission challenge, you have to design, build and program a robot to complete a set of missions on a board in under 2 minutes. Cody is our attempt at making our best robot so far, which will be faster, more precise and more reliable than all of our previous. WRO hasn't released the next season yet, so I've designed Cody to be modular and allow us to add the attachments we need to complete the missions for next year.

![Render](Images/Render.png)

## How it works

- **Electronics:** I'm using an ESP32 as the microcontroller. I'm using an MPU9250 IMU for orientation, TCS34725 color sensors for detecting lines and items, an ADS1115 ADC for measuring the voltage of the battery and TB6612FNG motor drivers.
- **Actuators:** I'm using JGB37-3530 motors for the wheels and for 2 attachments. I'm also using 2 Corona DS919MG servos for attachments.
- **Power:** I'm using a 3S 2200mAh LiPo battery for powering the robot. I'm also using a voltage regulator for powering the servos and the ESP32.
- **Structure:** I'm using 3D printed structural parts that have attachments for the components. I will be printing them out of PETG.
- **Software:** I'm using odometry and PID algorithms for control.

## Why I made this

My team has been using Lego Spike since we started competing, but it's starting to show its limitations. This year, we went to the international final for the first time. Robomission had opened up to all hardwares for the first time this year, which means other teams could make faster, more precise and more reliable robots than what we could possibly do with Lego. I'm designing this robot to be faster, more precise and more reliable than our previous robots with the power of open hardware.

## PCB

![PCB 3D model](Images/PCB3D.png)

![PCB Layout](Images/PCBLayout.png)

![PCB Schematic](Images/PCBSchematic.png)

## Wiring diagram

![Wiring diagram](Images/WiringDiagram.png)

## BOM

|Item                            |Amount|Owned|Needed|Unit Price|Total Price      |Link                                                                                                    |Config                             |
|--------------------------------|------|-----|------|----------|-----------------|--------------------------------------------------------------------------------------------------------|-----------------------------------|
|Motors and wheels               |2     |0    |2     |16,35 €   |32,70 €          |https://es.aliexpress.com/item/4001339371886.html                                                       |12V530                             |
|Buzzer                          |1     |1    |0     |-         |0,00 €           |-                                                                                                       |-                                  |
|RGB LED                         |1     |1    |0     |-         |0,00 €           |-                                                                                                       |-                                  |
|BMS Resistors                   |6     |6    |0     |-         |0,00 €           |-                                                                                                       |-                                  |
|TB6612FNG Motor drivers         |2     |0    |2     |2,02 €    |4,04 €           |https://es.aliexpress.com/item/1005006983040834.html                                                    |TB6612FNG Weld                     |
|ESP32 DevKitC                   |1     |0    |1     |5,34 €    |5,34 €           |https://es.aliexpress.com/item/1005008256121637.html                                                    |32D-Type-C-1PCS                    |
|PCF8575 GPIO Expander           |1     |0    |1     |1,64 €    |1,64 €           |https://es.aliexpress.com/item/1005002073772322.html                                                    |1PCS                               |
|ADS1115 ADC                     |1     |0    |1     |1,48 €    |1,48 €           |https://es.aliexpress.com/item/32311656694.html                                                         |ADS1115 Blue                       |
|MPU9250 IMU                     |1     |0    |1     |6,89 €    |6,89 €           |https://es.aliexpress.com/item/1005009033822037.html                                                    |GY-9250 original                   |
|TCS34725 Color sensor           |2     |0    |2     |2,85 €    |5,70 €           |https://es.aliexpress.com/item/1005009651619906.html                                                    |1pcs                               |
|XT60 Connectors                 |2     |0    |2     |3,94 €    |7,88 €           |https://es.aliexpress.com/item/1005004628891959.html                                                    |2 pairs male female                |
|JST-XH Connector kit            |1     |0    |1     |7,93 €    |7,93 €           |https://es.aliexpress.com/item/1005008638438956.html                                                    |-                                  |
|12V to 6V converter             |1     |0    |1     |2,90 €    |2,90 €           |https://es.aliexpress.com/item/1005007763337343.html                                                    |6V                                 |
|Servo attachments               |2     |0    |2     |10,03 €   |20,06 €          |https://es.aliexpress.com/item/1005002272302617.html                                                    |With 25mm arm x1                   |
|Motor attachments               |2     |0    |2     |16,35 €   |32,70 €          |https://es.aliexpress.com/item/4001339371886.html                                                       |Decide when next season is released|
|Velcro for battery and converter|1     |0    |1     |1,30 €    |1,30 €           |https://es.aliexpress.com/item/1005008938790125.html                                                    |Black 1M                           |
|Battery                         |2     |0    |2     |14,00 €   |27,99 €          |https://www.amazon.es/Zeee-Bater%C3%ADa-Veh%C3%ADculos-Cuadric%C3%B3ptero-Helic%C3%B3ptero/dp/B0BYNSH6Q7|-                                  |
|Cable for sensors and motors    |1     |0    |1     |1,69 €    |1,69 €           |https://es.aliexpress.com/item/1005006566120439.html                                                    |2m 22 AWG                          |
|PCB                             |1     |0    |1     |9,09 €    |9,09 €           |https://jlcpcb.com                                                                                      |                                   |
|TOTAL                           |      |     |      |          |169,33€ ($199.38)|                                                                                                        |                                   |
