"""Setup serial communication between Lopy, Arduino.
"""
import os
import machine
import pycom

# Configure second UART bus on pins P3(TX1) and P4(RX1)
uart1 = machine.UART(1, baudrate=9600)

machine.main('main.py')
