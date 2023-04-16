.syntax unified
.cpu cortex-m3
.thumb

.word 0x20004000
.word 0x080000ed
.space 0xe4

#nop
#ldr r0, =123456789
#mov r1, r0

#Initialize Clock for GPIOC, GPIOB, GPIOA
    ldr r0, =0x00000007
    ldr r1, =0x4002104C
    str r0, [r1]

#Initialize LED0
#- LEDs: GPIOC->MODER = (GPIOC->MODER & 0xFFFF3FFF) | 0x00004000;
    ldr r1, =0x48000800
    ldr r0, [r1]
    and r0, #0xFFFF3FFF
    orr r0, 0x00004000
    str r0, [r1]

#- switch LED OFF/ON: GPIOC -> ODR |= (1<<7); GPIOC->ODR &= ~( 1 << i );
    ldr r1, =0x48000814
    ldr r0, [r1]
    and r0, #0xFFFFFF7F
    str r0, [r1]

b . @ Never ending loop
