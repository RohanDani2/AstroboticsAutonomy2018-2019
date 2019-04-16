"""
VT Astrobotics
Command Center
2019

Author: Colin Grundey

Description:
    Command center to communicate with robot (Arduino) through network UDP/TCP.
    Xbox controller input and GUI for feedback and control.
    robot_state_thread implements each state.
    PyQt thread modifies state in response to input.

"""

"""  
TODO:
- Keep alive message
- Static IP

"""

from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QGridLayout, QLabel, QGroupBox, QVBoxLayout
from PyQt5 import QtGui, QtCore
import socket
import _thread
from xinput import *

""" Main System State """
ROBOT_STATE = "TELE"

UDP_IP = "10.0.0.122"
UDP_PORT = 4210

# Maps joystick input to PPM output
def mymap(x, in_min, in_max, out_min, out_max):
    if x > -0.2 and x < 0.2:
        return 1500
    return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)


def try_disconnect(wifi_conn=None):
    # TODO: disconnect Arduino Wifi
    wifi_conn.setStyleSheet("QLabel {background-color: red; color: yellow}")
    wifi_conn.setText("Wifi Disconnected")


def try_connect(wifi_conn=None):
    MESSAGE = "Hello, World!"
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.sendto(MESSAGE.encode(), (UDP_IP, UDP_PORT))
    sock.close()
    wifi_conn.setStyleSheet("QLabel {background-color: green; color: black}")
    wifi_conn.setText("Wifi Connected")


def send_to_arduino(message):
    MESSAGE = message
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.sendto(MESSAGE.encode(), (UDP_IP, UDP_PORT))
    sock.close()


def robotState( void ):
    global ROBOT_STATE

    joysticks = XInputJoystick.enumerate_devices()
    device_numbers = list(map(attrgetter('device_number'), joysticks))
    if not joysticks:
        print('No Joystick Found\n')
        sys.exit(0)
    j = joysticks[0]

    @j.event
    def on_button(button, pressed):
        print('button', button, pressed)
        if button == 16:
            if pressed:
                send_to_arduino("EXTEND")
                print("EXTEND")
            else:
                send_to_arduino("STOP_DUMP")
                print("STOP DUMP")
        elif button == 13:
            if pressed:
                send_to_arduino("RETRACT")
                print("RETRACT")
            else:
                send_to_arduino("STOP_DUMP")
                print("STOP DUMP")
        elif button == 10:
            if pressed:
                send_to_arduino("DIG_EN")
                print("DIG_ENABLE")
            else:
                send_to_arduino("DIG_DIS")
                print("DIG_DISABLE")
        elif button == 9:
            if pressed:
                send_to_arduino("LOCO_EN")
                print("LOCO_EN")
            else:
                send_to_arduino("LOCO_DIS")
                print("LOCO_DIS")
        elif button == 7:
            if pressed:
                send_to_arduino("ZERO_LEFT")
                print("ZERO_LEFT")
        elif button == 8:
            if pressed:
                send_to_arduino("ZERO_RIGHT")
                print("ZERO_RIGHT")
    @j.event
    def on_axis(axis, value):
        if axis == 'l_thumb_y':
            value = 'l' + str(int(mymap(value, -0.5, 0.5, 1000, 2000)))
            send_to_arduino(value)
            print(value)
        elif axis == 'r_thumb_y':
            value = 'r' + str(int(mymap(value, -0.5, 0.5, 1000, 2000)))
            send_to_arduino(value)
            print(value)

    while 1:
        if ROBOT_STATE == "TELE":
            j.dispatch_events()
            time.sleep(.05)
        elif ROBOT_STATE == "AUTO":
            y = 2
            # TODO: talk to nuc
        elif ROBOT_STATE == "FAILURE":
            x = 2


def autonomous(teleBtn, autoBtn):
    global ROBOT_STATE
    ROBOT_STATE = "AUTO"
    autoBtn.setEnabled(False)
    teleBtn.setEnabled(True)
    send_to_arduino("AUTONOMOUS")


def teleop(teleBtn, autoBtn):
    global ROBOT_STATE
    ROBOT_STATE = "TELE"
    teleBtn.setEnabled(False)
    autoBtn.setEnabled(True)
    send_to_arduino("TELEOP")


class Window(QWidget):
    def __init__(self):
        super(Window, self).__init__()
        self.setGeometry(800, 500, 500, 300)
        self.setWindowTitle("Command Center")
        self.setWindowIcon(QtGui.QIcon('images/logos/astro-logo.png'))  # astro-logo.jpg

        layout = QVBoxLayout()

        connections = QGroupBox("Connections")
        modes = QGroupBox("Modes")
        sensors = QGroupBox("Sensor Data")
        statuses = QGroupBox("Status")

        logo_img = QLabel()
        logo_img.setPixmap(QtGui.QPixmap("images/logos/Astro-banner.png"))

        wifi_conn = QLabel("Wifi Disconnected")
        wifi_conn.setStyleSheet("QLabel {background-color: red; color: yellow}")
        xbox_conn = QLabel("Controller Connected")
        xbox_conn.setStyleSheet("QLabel {background-color: green;}")

        conn_btn = QPushButton("Connect", self)
        conn_btn.setStyleSheet("QPushButton {background-color: orange; color: maroon;}")
        conn_btn.clicked.connect(lambda: try_connect(wifi_conn))
        disconn_btn = QPushButton("Disconnect", self)
        disconn_btn.setStyleSheet("QPushButton {background-color: maroon; color: orange}")
        disconn_btn.clicked.connect(lambda: try_disconnect(wifi_conn))

        teleBtn = QPushButton("Teleop", self)
        teleBtn.setEnabled(False)
        autoBtn = QPushButton("Autonomous", self)
        teleBtn.clicked.connect(lambda: teleop(teleBtn, autoBtn))
        autoBtn.clicked.connect(lambda: autonomous(teleBtn, autoBtn))

        battV = QLabel("Battery Voltage: 12V")
        speed = QLabel("Speed: 0 m/s")

        qbtn = QPushButton("Quit", self)
        qbtn.clicked.connect(QtCore.QCoreApplication.instance().quit)

        conns_grid = QGridLayout()
        conns_grid.addWidget(conn_btn, 1, 0)
        conns_grid.addWidget(disconn_btn, 1, 1)

        mode_grid = QGridLayout()
        mode_grid.addWidget(teleBtn, 2, 0)
        mode_grid.addWidget(autoBtn, 2, 1)

        sensor_grid = QGridLayout()
        sensor_grid.addWidget(battV, 0, 0)
        sensor_grid.addWidget(speed, 0, 1)

        status_grid = QGridLayout()
        status_grid.addWidget(wifi_conn, 0, 0)
        status_grid.addWidget(xbox_conn, 0, 1)
        status_grid.addWidget(qbtn, 1, 0, 1, 2)

        connections.setLayout(conns_grid)
        modes.setLayout(mode_grid)
        statuses.setLayout(status_grid)
        sensors.setLayout(sensor_grid)

        layout.addWidget(logo_img)
        layout.addWidget(connections)
        layout.addWidget(modes)
        layout.addWidget(sensors)
        layout.addWidget(statuses)

        self.setLayout(layout)
        self.show()

    def keyPressEvent(self, e):
        if e.key() == QtCore.Qt.Key_Escape:
            send_to_arduino("STOP")
            self.close()
        elif e.key() == 16777344: # Play/Pause button
            print("STOP")
            send_to_arduino("STOP")


def app():
    robo_state_thread = _thread.start_new_thread(robotState, ("",))
    the_app = QApplication(sys.argv)
    window = Window()
    sys.exit(the_app.exec_())


app()
