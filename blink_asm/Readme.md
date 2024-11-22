The following examples are written in assembler for a custom shield attached to Nucleo-L476RG Board.

blink:
A simple assembler program to make led blink on a custom shield attached to Nucleo-L476RG Board. It blinks LED3 ON Port PC7.

blink_button:
The button S0 (PB0) switches on and off the LED0..3 (on PortC4 to C7). The button press is checked in polling mode.

Use the makefile to compile the projects

-----
For compiling assembler program
```
arm-none-eabi-as toggle_led.s -o toggle_led.o 
```
For linking
```
arm-none-eabi-ld -Ttext=0x8000000 toggle_led.o -o toggle_led.elf
```
For converting ELF to binary format
```
arm-none-eabi-objcopy -O binary toggle_led.elf firmware.bin
```
Flash the application
```
st-flash --reset write firmware.bin 0x8000000 
```

Do not forget to press reset after flashing
