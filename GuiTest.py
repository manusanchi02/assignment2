import serial.tools.list_ports
import PySimpleGUI as sg

errore = True
currentTemp = 0
totalWash = 0
currentState = 'Sleeping'
errors = 'No Errors'
comPort= 'COM3'
restartButton = sg.Button('Restart')

sg.theme('LightBlue')  # Add a touch of color
# All the stuff inside your window.
defaultLayout = [  [sg.Text('Current Temperature:') ,sg.Text(currentTemp)],
            [sg.Text('Total Car Washed:') ,sg.Text(totalWash)],
            [sg.Text('Current State:') ,sg.Text(currentState)],
            [sg.Text('Error:') ,sg.Text(errors)]]
if errore == True:
    defaultLayout.append([restartButton])

loginLayout = [  [sg.Text('Please enter COM port')],
            [sg.Text('COM Port', size=(15, 1)), sg.InputText()],
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
        window.close()
        window = sg.Window('Arduino Controller '+comPort, defaultLayout)
    if event == 'Restart':
        print('Restarting')

window.close()