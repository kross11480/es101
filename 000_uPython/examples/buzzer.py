import machine
import time




# buzzer on for .5s
buzzer_pin = machine.Pin('PC12', machine.Pin.OUT)
buzzer_pin.high()
time.sleep(.3)
buzzer_pin.low()

#buzzer using PWM, this port doesn't have PWM Module

