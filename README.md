Jan-Olov  -  jv222ni

# Bee-IOT, System for measurement of temperature and humidity in Bee hives
**A short background**

Simple project for measurements in bee hives with the aim of learning how to improve winter survival of bees.

During winter a lot of bees die and if the bee population gets to small, they cannot keep temperature up and the whole hive dies. Improving winter conditions in the hive can hopefully make more hives survive the winter and produce honey the next year. When you open a hive in spring it can look terrible inside. Dead bees, moisture, mold and bee poo in a mess makes you wonder how anything can live in there.

Se furhter description in the pdf-file

Desription of files:

**PDF** is a more in depth descriton of the project

**boot.py** is the boot file for the LoPy4

**main.py** is the main program for the LoPy4

**pybytes_config.json** is the configuration needed to connect to the pybytes server. I have removed some vital parts concerning my WiFi

**sketch_BME280.ino** is the program for the Arduino with measuring sensor and transmitting radio

**sketch_reveiver_PCB.ino** is the program for the receiving arduino that also sends the data to the LoPy over a serial line
