#ifndef CONFG_H_
#define CONFG_H_

/*
INTx_ModeSelect
Range:
EINT_LowLevel               0
EINT_LogicalChange          1
EINT_FalleEdge              2
EINT_RisingEdge             3
*/

#define INT0_ModeSelect                 EINT_RisingEdge
#define INT1_ModeSelect                 EINT_LogicalChange
#define INT2_ModeSelect                 EINT_LogicalChange


/*
EXTI_PINx
Range:
ACTIVE                      1
DEACTIVE                    0
*/

#define EXTI_PIN0                        ACTIVE
#define EXTI_PIN1                        DEACTIVE
#define EXTI_PIN2                        DEACTIVE

#endif