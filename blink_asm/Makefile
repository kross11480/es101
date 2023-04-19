ARMGNU ?= arm-none-eabi

AOPS = -g

all : blink.elf

clean:
	rm -f *.o
	rm -f *.elf

blink.o : blink.s
	$(ARMGNU)-as $(AOPS) blink.s -o blink.o

blink.elf :	blink.o
	$(ARMGNU)-ld -Ttext=0x8000000 blink.o -o blink.elf