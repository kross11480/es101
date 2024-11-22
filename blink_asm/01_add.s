.syntax unified
.cpu cortex-m3
.thumb

.word 0x20004000
.word 0x080000ed
.space 0xe4

MOV R1, #5       @ Lade den Wert 5 in Register R1
MOV R2, #10      @ Lade den Wert 10 in Register R2
ADD R0, R1, R2   @ Addiere R1 und R2, speichere das Ergebnis in R0
ADD R3, R1, #3   @ Addiere den Wert 3 auf R1, speichere das Ergebnis in R3

B .              @ Never ending loop