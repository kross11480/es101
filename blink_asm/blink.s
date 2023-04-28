.syntax unified
.cpu cortex-m3
.thumb

.word 0x20004000
.word 0x080000ed
.space 0xe4

#Initialize Clock for GPIOC, GPIOB, GPIOA
    ldr r0, =0x00000006
    ldr r1, =0x4002104C
    str r0, [r1]

#Initialize LED 0,1,2,3
#- LEDs: GPIOC->MODER = (GPIOC->MODER & 0xFFFF00FF) | 0x00005500;
    ldr r1, =0x48000800
    ldr r0, [r1]
    and r0, 0xFFFF00FF
    orr r0, 0x00005500
    str r0, [r1]

#- switch LED: bit value 1 is LED OFF, bit value 0 is LED ON
#- OFF/ON: GPIOC -> ODR |= (1<<7); GPIOC->ODR &= ~( 1 << i );
    ldr r1, =0x48000814
    ldr r0, [r1]
    orr r0, 0x00000F0
    str r0, [r1]

b . @ Never ending loop
