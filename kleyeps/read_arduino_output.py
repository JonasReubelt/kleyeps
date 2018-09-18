import serial

ser1 = serial.Serial('/dev/ttyUSB0', 9600)
ser2 = serial.Serial('/dev/ttyUSB1', 9600)


while True:
    print(ser1.readline().decode("ascii"))
    print(ser2.readline().decode("ascii"))
    print("------------------------------")
