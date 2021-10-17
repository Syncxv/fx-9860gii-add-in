#include "fxlib.h"
#include "stdio.h"
#include "stdlib.h"
#include "MonochromeLib.h"
#include "syscall.h"
#include <math.h>
#include "menu.h"
int AddIn_main(int isAppli, unsigned short OptionNum)
{
    unsigned int key;
    int active = 0;
    int page = 1;
    Bdisp_AllClr_DDVRAM();
    MenuClear();
    MenuSetNode(MENUBARMAIN,0,"FILE",-1          ,MENUBARFILE,0,NULL);
    MenuSetNode(MENUBARFILE,0,"SAVE",NODEFILESAVE,-1         ,0,NULL);
    MenuSetNode(MENUBARFILE,1,"S.AS",NODEFILESVAS,-1         ,0,NULL);
    MenuSetNode(MENUBARFILE,2,"AUTO",NODEFILEAUTO,-1         ,0,NULL);
    while (IsKeyDown(KEY_CTRL_EXIT) == 0) {
        if(IsKeyDown(KEY_CTRL_F3)) {
            active = 1;
        } 
        else if(IsKeyDown(KEY_CTRL_F4)) {
            active = 0;
        } 
        else if (IsKeyDown(KEY_CTRL_F1)) {
            if(page == 1) goto main;
            page = page - 1;
        }
        else if (IsKeyDown(KEY_CTRL_F6)) {
            if(page >= 3) goto main;
            page++;
        } else if(IsKeyDown(KEY_CTRL_F5)) {
            if(page == 727) {
                page = 1;
                goto main;
            }
            page = 727;
        }
        main:
        if(active) {
            switch (page)
            {
            case 1:
                locate(1,1);
                Print((unsigned char*)"<distance/speed|time>");
                locate(1,2);
                Print((unsigned char*)"a^2+b^2=c^2 pythagoras");
                locate(1,3);
                Print((unsigned char*)"soh,cah,toa");
                locate(1,4);
                Print((unsigned char*)"QUADRATIC:");
                locate(1, 5); Print((unsigned char*)"ax^2+bx+c=0");
                locate(1,6); Print((unsigned char*)"x=-b+-sqr(b^2-4ac)/2a");
                break;
            case 2:
                locate(1,1); Print((unsigned char*)"Vol Cylinder: PIr^2h");
                locate(1,2); Print((unsigned char*)"A Parelelorgram: b*h");
                locate(1,3); Print((unsigned char*)"A Triangle:1/2*b*h");
                locate(1,4); Print((unsigned char*)"A Trapezuium: ");
                locate(1,5); Print((unsigned char*)"1/2*(a+b)*h");
                locate(1,6); Print((unsigned char*)"A Ciricle: PIr^2");
                locate(1,7); Print((unsigned char*)"Radius: 1/2*d");
                locate(1,7); Print((unsigned char*)"CC: PI*2r | PI*d");
                break;
            case 3:
                locate(1,1); Print((unsigned char*)"mean median mode:");
                locate(1,2); Print((unsigned char*)"-Average");
                locate(1,3); Print((unsigned char*)"-Middle");
                locate(1,4); Print((unsigned char*)"-Most n in list");
                break;
            case 727:
                locate(1,1); Print((unsigned char*)"KEY");
                locate(1,2); Print((unsigned char*)"b: base");
                locate(1,3); Print((unsigned char*)"h: height");
                locate(1,4); Print((unsigned char*)"+-: + or =");
                locate(1,4); Print((unsigned char*)"sqr:sqaure root"); 
                locate(1,5); Print((unsigned char*)"PI: pie hehe"); 
                locate(1,6); Print((unsigned char*)"A Shape: Area Shape"); 
                locate(1,7); Print((unsigned char*)"d: diameter"); 
                locate(1,8); Print((unsigned char*)"CC: Curcumference of ciricle"); //fuck 
                break;
            default:
                break;
            }
            
            
            // PrintXY(1,2,"soh,cah,toa;PIr^2", 1);
        }
        ML_display_vram();
        ML_clear_vram();
        Sleep(500);
    }
    while(1){
        GetKey(&key);
    }
    return 1;
}

// int getFactors(int num) {
//     int arr[10];
//     int index = 0;
//     for (int i = 1; i <= num; ++i) {
//         if (num % i == 0) {
//             arr[index] = i;
//             index++;
//         }
//     }
//     return arr;
// }
//****************************************************************************
//**************                                              ****************
//**************                 Notice!                      ****************
//**************                                              ****************
//**************  Please do not change the following source.  ****************
//**************                                              ****************
//****************************************************************************


#pragma section _BR_Size
unsigned long BR_Size;
#pragma section


#pragma section _TOP

//****************************************************************************
//  InitializeSystem
//
//  param   :   isAppli   : 1 = Application / 0 = eActivity
//              OptionNum : Option Number (only eActivity)
//
//  retval  :   1 = No error / 0 = Error
//
//****************************************************************************
int InitializeSystem(int isAppli, unsigned short OptionNum)
{
    return INIT_ADDIN_APPLICATION(isAppli, OptionNum);
}

#pragma section

