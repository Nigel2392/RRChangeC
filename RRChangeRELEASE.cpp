#include <windows.h>

int main()
{
    int i;
    do{
    Sleep(100);
    int w,h,rr,key=0;
    SYSTEM_POWER_STATUS test;
    GetSystemPowerStatus(&test);
    int p=test.ACLineStatus;
    if(p!=i){
    if (rr!=144 && test.BatteryFlag & 8 || rr!=144 && test.ACLineStatus == 1){
                            rr=144;
                            i=p;
    }else if (rr!=60 && test.ACLineStatus!=1){
                            rr=60;
                            i=p;
    }
                            DEVMODE sDevMode;
                            ZeroMemory(&sDevMode, sizeof(DEVMODE));
                            sDevMode.dmSize = sizeof(DEVMODE);
                            sDevMode.dmDisplayFrequency = rr;
                            sDevMode.dmFields |= DM_DISPLAYFREQUENCY;
                                LONG rVal = ChangeDisplaySettings(&sDevMode, CDS_UPDATEREGISTRY);
                                    switch (rVal)
                                    {
                                        case DISP_CHANGE_SUCCESSFUL:  //The settings change was successful.
                                        break;
                                    }
    }
    }while(1);
}