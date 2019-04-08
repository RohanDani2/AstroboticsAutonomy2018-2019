# Xbox button mapping
#   Left joystick  --> Left drive
#   Right joystick --> Right drive
#   Left trigger   --> Bucket reverse
#   Right trigger  --> Bucket dig
#   Left bumper    --> Bucket lift
#   Right bumper   --> Bucket lower
#   Y button       --> Dump lift
#   A button       --> Dump lower

from __future__ import print_function

from tkinter import *
# from xbox import *


def xbox_connected():
    return 1


def wifi_connected():
    return 1


def check_connections():
    global j_status, w_status
    if xbox_connected():
        j_status.configure(text="Controller Connected", bg="green")
    else:
        j_status.configure(text="Connecting Controller....", bg="red")
    if wifi_connected():
        w_status.configure(text="Wifi Connected", bg="green")
    else:
        w_status.configure(text="Connecting Wifi....", bg="red")
    window.update()


def disconnect():
    global j_status, w_status
    j_status.configure(text="Controller Disconnected", bg="red", fg="yellow")
    w_status.configure(text="Wifi Disconnected", bg="red", fg="yellow")
    window.update()


# GUI Stuff
window = Tk()
window.title("Command Center")
window.geometry("500x300")

Label(window, text="Connections:", relief=RIDGE, width=18, justify=LEFT).grid(row=0, sticky=W, pady=5, padx=5)
Button(text="Connect", command=check_connections, bg="orange", fg="maroon", width=15, activebackground="orange", activeforeground="green").grid(row=0, column=1)
Button(text="Disconnect", bg="maroon", fg="orange", command=disconnect, width=15, activebackground="maroon", activeforeground="yellow").grid(row=0, column=2)

Label(window, text="Mode of Operation:", relief=RIDGE, width=18).grid(row=1, sticky=W, pady=5, padx=5)
Button(text="Autonomous", width=15).grid(row=1, column=1)
Button(text="Teleop", command="check_connections", width=15).grid(row=1, column=2)

Label(window, text="Extras:", relief=RIDGE, width=18).grid(row=2, sticky=W, pady=5, padx=5)
Button(text="Quit", width=15).grid(row=2, column=1)

Label(window, text="Wifi Status:", relief=RIDGE, width=18).grid(row=3, sticky=W, pady=5, padx=5)
w_status = Label(window, text="Connecting Wifi...", bd=1, relief=SUNKEN, anchor=W, bg="red", fg="yellow", width=34)
w_status.grid(row=3, column=1, columnspan=2)

Label(window, text="Controller Status:", relief=RIDGE, width=18).grid(row=4, sticky=W, pady=5, padx=5)
j_status = Label(window, text="Connecting Controller...", bd=1, relief=SUNKEN, anchor=W, bg="red", fg="yellow", width=34)
j_status.grid(row=4, column=1, columnspan=2)

window.mainloop()
print("testing")
