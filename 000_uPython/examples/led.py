import machine
import time

def toggle(led):
    while True:
        led.on()
        time.sleep(0.5)
        led.off()
        time.sleep(0.5)

led = machine.Pin('PC7', machine.Pin.OUT)
toggle(led)