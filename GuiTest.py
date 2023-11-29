import serial.tools.list_ports
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
    window = sg.Window('Arduino Controller', defaultLayout)
    event, values = window.read(timeout=100)
    if event == sg.WIN_CLOSED or event == 'Cancel': # if user closes window or clicks cancel
        break
    if event == restartButton:
        #serialInst.write(b'1')
        print('Restarting')
    if serialInst.in_waiting:
        packet = serialInst.readline()
        if packet.decode('utf').rstrip('error') == 'error':
            errors = 'Error'
            errore = True
            defaultLayout.append([sg.Button('Restart')])
        else:
            errors = 'No Errors'
            errore = False
            defaultLayout.remove([sg.Button('Restart')])
        if packet.decode('utf').rstrip('temp') == 'temp':
            currentTemp = packet.decode('utf').rstrip('temp')
        if packet.decode('utf').rstrip('wash') == 'wash':
            totalWash = packet.decode('utf').rstrip('wash')
        if packet.decode('utf').rstrip('state') == 'state':
            currentState = packet.decode('utf').rstrip('state')


window.close()