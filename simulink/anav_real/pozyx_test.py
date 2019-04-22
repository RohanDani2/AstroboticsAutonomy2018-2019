from pypozyx import PozyxSerial
def test():
    port = '/dev/ttyACMX' # on UNIX systems this will be '/dev/ttyACMX'
    p = PozyxSerial(port)
    return p