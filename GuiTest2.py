#TEST CON 2 FINESTRE DIVERSE DELLA GUI
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
defaultLayout = [  [sg.Text('Current Temperature:') ,sg.Text(currentTemp,key='-TEMP-')],
            [sg.Text('Total Car Washed:') ,sg.Text(totalWash,key='-WASH-')],
            [sg.Text('Current State:') ,sg.Text(currentState,key='-STATE-')],
            [sg.Text('Error:') ,sg.Text(errors,key='-ERROR-')],
            [sg.Button('Restart')]]

loginLayout = [  [sg.Text('Please enter COM port')],
            [sg.Text('COM Port Available:'),sg.Text(*portsList)],
            [sg.Text('Enter the name:', size=(15, 1)), sg.InputText()],
            [sg.Button('Ok')]]


# Create the Window
windowLogin = sg.Window('Arduino Controller', loginLayout)
# Event Loop to process "events" and get the "values" of the inputs
while True:
    event, values = windowLogin.read()
    if event == sg.WIN_CLOSED or event == 'Cancel': # if user closes window or clicks cancel
        windowLogin.close()
        break
    if event == 'Ok':
        comPort = values[0]
        serialInst.baudrate = 9600
        serialInst.port = comPort
        serialInst.open()
        windowLogin.close()
        break

window = sg.Window('Arduino Controller', defaultLayout)
while True:
    
    event, values = window.read(timeout=100)
    if event == sg.WIN_CLOSED or event == 'Cancel': # if user closes window or clicks cancel
        window.close()
        break
    if event == restartButton:
        print('Restarting')
        defaultLayout.remove([sg.Button('Restart')])

    if serialInst.in_waiting:
        packet = serialInst.readline()       
        msg = packet.decode('utf').rstrip('\n')
        if(msg.split(':')[0] == 'temp'):
            currentTemp = msg.split(':')[1]
            window['-TEMP-'].update(currentTemp)
        if(msg.split(':')[0] == 'cars'):
            totalWash = msg.split(':')[1]
            window['-WASH-'].update(totalWash)
        if(msg.split(':')[0] == 'state'):
            currentState = msg.split(':')[1]
            window['-STATE-'].update(currentState)  
    if(event == 'Restart'):
        serialInst.write(b'restart')
        window['-ERROR-'].update('No Errors')
        print('Restarting')
    if(float(currentTemp) > 23):
        serialInst.write(b'tError')
        window['-ERROR-'].update('Temperature Error')
window.close()