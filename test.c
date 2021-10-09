/*****************************************************************/
/*                                                               */
/*   CASIO fx-9860G SDK Library                                  */
/*                                                               */
/*   File name : [ProjectName].c                                 */
/*                                                               */
/*   Copyright (c) 2006 CASIO COMPUTER CO., LTD.                 */
/*                                                               */
/*****************************************************************/
#include "fxlib.h"
#include "stdio.h"
#include "stdlib.h"
#include "MonochromeLib.h"
#include "syscall.h"
#include <math.h>

//****************************************************************************
//  AddIn_main (Sample program main function)
//
//  param   :   isAppli   : 1 = This application is launched by MAIN MENU.
//                        : 0 = This application is launched by a strip in eACT application.
//
//              OptionNum : Strip number (0~3)
//                         (This parameter is only used when isAppli parameter is 0.)
//
//  retval  :   1 = No error / 0 = Error
//
//****************************************************************************
int AddIn_main(int isAppli, unsigned short OptionNum)
{
    unsigned int key;
    int active = 0;
    Bdisp_AllClr_DDVRAM();
    while (IsKeyDown(KEY_CTRL_EXIT) == 0) {
        if(IsKeyDown(KEY_CTRL_F3)) {
            active = 1;
        } else if(IsKeyDown(KEY_CTRL_F4)) {
            active = 0;
        }
        if(active) {
            // locate(1,1);
            // Print((unsigned char*)"<distance/speed|time>");
            // PrintXY(1,2,"soh,cah,toa;PIr^2", 1);
            PrintXY(1,2,"some formulas eh", 1);
        }
        ML_display_vram();
        ML_clear_vram();
        Sleep(500);
    }
    while(1){
        GetKey(&key);
    }
    return 1;
   
    // Bdisp_AllClr_DDVRAM();
    // Bdisp_DrawLineVRAM(0,0,20,0);    
    // // locate(1,1);
    // // Print((unsigned char*)"<distance/speed|time>");
    // // locate(1,2);
    // // Print((unsigned char*)"soh,cah,toa");

    

    // return 1;
}




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

