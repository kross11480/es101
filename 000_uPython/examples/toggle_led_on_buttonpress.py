# toggle led and stop app on alternate button press
import machine
import time
 
#toggle led 
def toggle(led):
    led.on()
    time.sleep(0.5)
    led.off()
    time.sleep(0.5)

#button pressed is True if button press stable after 20ms     
def button_pressed_debounce(pin):
    global button_pressed
    pressed = pin.value()
    time.sleep(.02)
    if pin.value() == pressed:
        button_pressed = True
    else:
        button_pressed = False

#setup led, button
button = machine.Pin('PB0', machine.Pin.IN, machine.Pin.PULL_UP)   
button.irq(trigger = machine.Pin.IRQ_FALLING, handler = button_pressed_debounce)
led = machine.Pin('PC7' ,machine.Pin.OUT)
led.high()

#initialize state and event
app_state = False
button_pressed = False

#run state machine
while True:
    #Update State
    if button_pressed:
        if app_state == False:
            app_state = True
        elif app_state == True:
            app_state = False
        button_pressed = False 
    #State Action
    if app_state:
      toggle(led) 
    else:
      led.high()
    