.global __mulsi3
.global _start
.global usleep

_start:
        li sp, 0x1fc
        jal main
1:
        j 1b

__mulsi3:
        mv      a2,a0
        li      a0,0
1:
        and     a3,a1,1
        beqz    a3,2f
        add     a0,a0,a2
2:
        srl     a1,a1,0x1
        sll     a2,a2,0x1
        bnez    a1,1b
        ret

usleep:
        li t0, 1024
1:
        addi t0, t0, -1
        bnez t0, 1b
        ret
