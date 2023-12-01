import serial.tools.list_ports
import serial
import PySimpleGUI as sg

errore = True
currentTemp = 0
totalWash = 0
currentState = 'Sleeping'
errors = 'No Errors'
comPort= 'COM3'
restartButton = sg.Button('Restart')

#Read COM port
ports = serial.tools.list_ports.comports()
serialInst = serial.Serial()

portsList = []

for onePort in ports:
    portsList.append(str(onePort))

sg.theme('LightBlue')  # Add a touch of color
# All the stuff inside your window.
defaultLayout = [  [sg.Text('Current Temperature:') ,sg.Text(currentTemp)],
            [sg.Text('Total Car Washed:') ,sg.Text(totalWash)],
            [sg.Text('Current State:') ,sg.Text(currentState)],
            [sg.Text('Error:') ,sg.Text(errors)]]

loginLayout = [  [sg.Text('Please enter COM port')],
            [sg.Text('COM Port Available:'),sg.Text(*portsList)],
            [sg.Text('Enter the name:', size=(15, 1)), sg.InputText()],
            [sg.Button('Ok')]]


# Create the Window
window = sg.Window('Arduino Controller', loginLayout)
# Event Loop to process "events" and get the "values" of the inputs
while True:
    event, values = window.read()
    if event == sg.WIN_CLOSED or event == 'Cancel': # if user closes window or clicks cancel
        break
    if event == 'Ok':
        comPort = values[0]
        serialInst.baudrate = 9600
        serialInst.port = comPort
        serialInst.open()
        window.close()
        break

while True:
    # read valued from arduino serial port and update GUI
    window = sg.Window('Arduino Controller', defaultLayout)
    event, values = window.read(timeout=100)
    if event == sg.WIN_CLOSED or event == 'Cancel': # if user closes window or clicks cancel
        break
    ser = serial.Serial(comPort, 9600)
    b = ser.readline()         # read a byte string
    string_n = b.decode()  # decode byte string into Unicode
    string = string_n.rstrip() # remove \n and \r
    print(string)
    