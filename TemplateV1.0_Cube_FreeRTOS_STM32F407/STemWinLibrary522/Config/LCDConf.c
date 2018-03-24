#include "GUI.h"
#include "GUIDRV_FlexColor.h"
/*********************************************************************
*
*       Layer configuration (to be modified)
*
**********************************************************************
*/
//
// Physical display size
//
#define XSIZE_PHYS  480 // To be adapted to x-screen size
#define YSIZE_PHYS  272 // To be adapted to y-screen size
/*********************************************************************
*
*       Configuration checking
*
**********************************************************************
*/
#ifndef   VXSIZE_PHYS
  #define VXSIZE_PHYS XSIZE_PHYS
#endif
#ifndef   VYSIZE_PHYS
  #define VYSIZE_PHYS YSIZE_PHYS
#endif
#ifndef   XSIZE_PHYS
  #error Physical X size of display is not defined!
#endif
#ifndef   YSIZE_PHYS
  #error Physical Y size of display is not defined!
#endif
#ifndef   GUICC_565
  #error Color conversion not defined!
#endif
#ifndef   GUIDRV_FLEXCOLOR
  #error No display driver defined!
#endif
/*********************************************************************
*
*       LCD_X_Config
*
* Function description:
*   Called during the initialization process in order to set up the
*   display driver configuration.
*
*/
void LCD_X_Config(void) 
{
    
    GUI_DEVICE_CreateAndLink(&GUIDRV_Template_API, GUICC_M565, 0, 0);
    LCD_SetSizeEx (0, XSIZE_PHYS , YSIZE_PHYS);
    LCD_SetVSizeEx(0, VXSIZE_PHYS, VYSIZE_PHYS);

}

/*********************************************************************
*
*       LCD_X_DisplayDriver
*
* Function description:
*   This function is called by the display driver for several purposes.
*   To support the according task the routine needs to be adapted to
*   the display controller. Please note that the commands marked with
*   'optional' are not cogently required and should only be adapted if
*   the display controller supports these features.
*
* Parameter:
*   LayerIndex - Index of layer to be configured
*   Cmd        - Please refer to the details in the switch statement below
*   pData      - Pointer to a LCD_X_DATA structure
*
* Return Value:
*   < -1 - Error
*     -1 - Command not handled
*      0 - Ok
*/
int LCD_X_DisplayDriver(unsigned LayerIndex, unsigned Cmd, void * pData) 
{
    int r;
    (void) LayerIndex;
    (void) pData;

    switch (Cmd) 
    {
        case LCD_X_INITCONTROLLER: 
        {
            return 0;
        }
        default:
        r = -1;
    }
    return r;
}
