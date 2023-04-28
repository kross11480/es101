ARMGNU ?= arm-none-eabi

AOPS = -g

all : blink_button.elf

clean:
	rm -f *.o
	rm -f *.elf

blink_button.o : blink_button.s
	$(ARMGNU)-as $(AOPS) blink_button.s -o blink_button.o

blink_button.elf :	blink_button.o
	$(ARMGNU)-ld -Ttext=0x8000000 blink_button.o -o blink_button.elf