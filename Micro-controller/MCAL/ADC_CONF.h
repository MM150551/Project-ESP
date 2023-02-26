//MODES:
#define ADC_VoltageRefMode                        ADC_VoltageRef2_56v
#define ADC_PrescalerMode                         ADC_Prescaler128Mask
#define ADC_ModeSelect                            ADC_SingleConversion
#define ADC_AutoTrigerMode                        ADC_AutoTrigSRCFreeRunningMask
/************************ Selecting ADC's Volage ************************/ 
#define ADC_VoltageRefMask                       ~0b00111111
#define ADC_VoltageRefAVCC                        0b01000000
#define ADC_VoltageRefAREF                        0b00000000
#define ADC_VoltageRef2_56v                       0b11000000
/************************ prescaller *******************************/
#define ADC_PrescalerMask                        ~0b11111000
#define ADC_Prescaler2Mask                        1
#define ADC_Prescaler4Mask                        2
#define ADC_Prescaler8Mask                        3
#define ADC_Prescaler16Mask                       4
#define ADC_Prescaler32Mask                       5
#define ADC_Prescaler64Mask                       6
#define ADC_Prescaler128Mask                      7
/************************ ADC mode select ************************/
#define ADC_AutoTrigger                           1
#define ADC_SingleConversion                      0
/************************ ADC Adujust select ************************/
#define ADC_RightAdjust                           0
#define ADC_LeftAdjust                            1
/************************Auto trigger selection********************/
#define ADC_AutoTrigSRCMask                      ~0b00011111
#define ADC_AutoTrigSRCFreeRunningMask            0
#define ADC_AutoTrigSRCAnalogCompMask             0b00100000
#define ADC_AutoTrigSRCEXTI0Mask                  0b01000000
#define ADC_AutoTrigSRCTimer0CompMask             0b01100000
#define ADC_AutoTrigSRCTimer0OvfMask              0b10000000
#define ADC_AutoTrigSRCTimer1CompMask             0b10100000
#define ADC_AutoTrigSRCTimer1OvfMask              0b11000000
#define ADC_AutoTrigSRCTimer1CaptMask             0b11100000