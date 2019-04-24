from time import time

from pypozyx import RawSensorData, SingleRegister, POZYX_SUCCESS, get_first_pozyx_serial_port, PozyxSerial, get_serial_ports
from pypozyx.definitions.bitmasks import POZYX_INT_MASK_IMU

class PozyxContainer(object):
     def __init__(self):
        remote_id = None
        serial_port = get_first_pozyx_serial_port()
        if serial_port is None:
            print("No Pozyx connected. Check your USB cable or your driver!")
            raise IOError("failed to open Pozyx port")

        pozyx = PozyxSerial(serial_port)

        self.pozyx = pozyx
        self.remote_id = remote_id

def init():
    return PozyxContainer()

def setup(self):
        """There is no specific setup functionality"""
        self.pozyx.printDeviceInfo(self.remote_id)

        self.current_time = time()

def run_once(self):
        """Gets new IMU sensor data"""
        sensor_data = RawSensorData()
        calibration_status = SingleRegister()
        if self.remote_id is not None or self.pozyx.checkForFlag(POZYX_INT_MASK_IMU, 0.01) == POZYX_SUCCESS:
            status = self.pozyx.getAllSensorData(sensor_data, self.remote_id)
            status &= self.pozyx.getCalibrationStatus(calibration_status, self.remote_id)
            # print(calibration_status)
            if status == POZYX_SUCCESS:
                return sensor_data

def is_none(val):
    return val is None