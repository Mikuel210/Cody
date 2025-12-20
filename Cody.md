- [Motors](https://es.aliexpress.com/item/4001339371886.html?spm=a2g0o.productlist.main.11.6120643bS9L8lg&algo_pvid=523d82bb-8db3-444d-9a44-c1a60baf2d96&algo_exp_id=523d82bb-8db3-444d-9a44-c1a60baf2d96-10&pdp_ext_f=%7B%22order%22%3A%2256%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21EUR%2117.04%217.65%21%21%2119.37%218.70%21%40211b6a7a17647740090365059e3f6f%2112000050646686588%21sea%21ES%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3A479a2421%3Bm03_new_user%3A-29895%3BpisId%3A5000000187634193&curPageLogUid=HiqphllHypdY&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A4001339371886%7C_p_origin_prod%3A#nav-specification)
- [Odometry](https://www.youtube.com/watch?v=TSXt7_oMIDk&list=PLiJv_3SD9kXBv5ecDxioEtX-Iu5HPcyhS&index=19)
- Color sensors

## Journal

Today I've chosen the components I'm going to use for the robot:

- **Microcontroller:** I've chosen to use the ESP32 DevKitC, as it's fast, dual core, has integrated Bluetooth and has dedicated pulse counters for the encoders. I'm also already familiar with it and it's compatible with the Arduino platform.
- **Battery:** I will be using a 3S LiPo battery, as LiPos offer a very consistent voltage curve.
- **Motor drivers:** I'll be using TB6612FNG drivers, as they're efficient, they can handle the voltage and amperage of the motors and they have a small footprint. I'm using two of them, as I'm designing the robot to be expansible with two extra motors for attachments and two extra servos.
- **State indication:** I will be using an LED and a buzzer for state indication.
- **Battery Management System (BMS):** I've chosen not to use a BMS for discharge. Instead, I will use a dedicated LiPo charger which I already own, and for discharge I will monitor cell voltage and ensure shorts or overcurrent can't happen. For monitoring cell voltage, I will use a divider circuit using resistors. I'm aware the ESP32's ADCs (Analog to Digital Converters) are pretty trashy so I might consider using external ones.
- I will also add a button to start the round.

14 55 to 18 45