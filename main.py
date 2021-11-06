"""Sends the string from the Arduino to the LoPy.
"""
import time
import _thread

print('Main start')
Count = 1
Fel = 0
Pass = 0
Temp = [0, 0, 0, 0, 0]
Hum = [0, 0, 0, 0, 0]

Text = ""

while True:
  Text = uart1.readline()
  if Text == None:
    print(Count)
    Count += 1
  else:
    Text = Text.decode("utf-8")
    print(Text[0:12])
    print("Fel = " + str(Fel))
    if Text[0:1] == 'H':
        print('H')
    else:
        print(Text[0:1])
        Fel += 1
        uart1.deinit()
        time.sleep(1)
        uart1 = machine.UART(1, baudrate=9600)

    Temp[Pass] = float(Text[3:7])
    Hum[Pass] = float(Text[8:12])
    print(Temp)
    print(Hum)
    print(Pass)
    Pass += 1
    if Pass == 5:
        TempMed = round((Temp[0] + Temp[1] + Temp[2] + Temp[3] + Temp[4]) / 5, 1)
        HumMed =  round((Hum[0] + Hum[1] + Hum[2] + Hum[3] + Hum[4]) / 5, 1)
        print(TempMed)
        print(HumMed)
        h = (38.214 + TempMed * 1.698 + (TempMed**2 * 0.1871)) / 10
        h = round(h * (HumMed/100), 1)
        pybytes.send_signal(1, TempMed)
        pybytes.send_signal(2, HumMed)
        pybytes.send_signal(3, h)
        Pass = 0
        Temp = [0, 0, 0, 0, 0]
        Hum = [0, 0, 0, 0, 0]

    Count = 1

  time.sleep(1)
