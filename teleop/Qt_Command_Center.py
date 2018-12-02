"""
VT Astrobotics
Command Center

"""

import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QGridLayout, QLabel, QGroupBox, QVBoxLayout
from PyQt5 import QtGui, QtCore
import socket
import _thread
import threading

mythreads = []

ROBOT_STATE = "TELE"


def try_disconnect(wifi_conn=None):
    # TODO: disconnect Arduino Wifi
    wifi_conn.setStyleSheet("QLabel {background-color: red; color: yellow}")
    wifi_conn.setText("Wifi Disconnected")


def try_connect(wifi_conn=None):
    # TODO: connect to Arduino Wifi
    UDP_IP = "192.168.50.93"
    UDP_PORT = 4210
    MESSAGE = "Hello, World!"
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.sendto(MESSAGE.encode(), (UDP_IP, UDP_PORT))
    sock.close()
    wifi_conn.setStyleSheet("QLabel {background-color: green; color: black}")
    wifi_conn.setText("Wifi Connected")


def robotState():
    global ROBOT_STATE
    while 1:
        while ROBOT_STATE == "TELE":
            print("Teleop!")
        while ROBOT_STATE == "AUTO":
            print("Autonomous!")
            # TODO: talk to nuc


def autonomous(teleBtn, autoBtn):
    global ROBOT_STATE
    ROBOT_STATE = "AUTO"
    autoBtn.setEnabled(False)
    teleBtn.setEnabled(True)


def teleop(teleBtn, autoBtn):
    global ROBOT_STATE
    ROBOT_STATE = "TELE"
    teleBtn.setEnabled(False)
    autoBtn.setEnabled(True)
    _thread.start_new_thread(robotState, (,))


class Window(QWidget):
    def __init__(self):
        super(Window, self).__init__()
        self.setGeometry(800, 500, 500, 300)
        self.setWindowTitle("Command Center")
        self.setWindowIcon(QtGui.QIcon('astro-logo.png'))  # astro-logo.jpg

        layout = QVBoxLayout()

        connections = QGroupBox("Connections")
        modes = QGroupBox("Modes")
        sensors = QGroupBox("Sensor Data")
        statuses = QGroupBox("Status")

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

        layout.addWidget(connections)
        layout.addWidget(modes)
        layout.addWidget(sensors)
        layout.addWidget(statuses)

        self.setLayout(layout)
        self.show()


def app():
    the_app = QApplication(sys.argv)
    window = Window()
    sys.exit(the_app.exec_())


app()
