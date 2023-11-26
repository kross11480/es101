import machine
import time
import pyb

def toggle_led(timer):
    global led, state
    if state == 'off':
        led.on()
        state = 'on'
    else:
        led.off()
        state = 'off'

state = 'off'
led = machine.Pin('PC7', machine.Pin.OUT)
timer = pyb.Timer(3, freq=4)
timer.callback(toggle_led)
