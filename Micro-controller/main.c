#include "APPLICATION\APPLICATION.h"


void clrBuffer(unsigned char*);


int main(int argc, char **argv)
{
    APP_Init();
    unsigned char Buffer[16];
    EXTI_CallBackINT0(APP_TroubleShoot);

    while (1)
    {

        if (APP_DOOR_Checker())
        {
            APP_ReceiveData(Buffer, '#');
            APP_TAKE_DECISION(Buffer);
            clrBuffer(Buffer);
        }
        else
        {
            APP_DOOR_ERROR();
        }
    }
    return 0;
}


void clrBuffer(unsigned char* Buffer)
{
    unsigned char i = 0;
    while (Buffer[i] != '\0')
    {
        Buffer[i] = 0;
        i++;
    }
}
