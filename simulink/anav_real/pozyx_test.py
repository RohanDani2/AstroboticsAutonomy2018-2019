from pypozyx import PozyxSerial

def test():
    print('hello3')
    port = '/dev/cu.usbmodem1411' # on UNIX systems this will be '/dev/ttyACMX'
    p = PozyxSerial(port)