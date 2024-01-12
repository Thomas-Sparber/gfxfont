#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library
#include "font.h"
#include "Fonts/FreeMono24pt7b.H"

LCDWIKI_KBV mylcd(ILI9486,A3,A2,A1,A0,A4); //model,cs,cd,wr,rd,reset

void drawPixel(uint16_t x, uint16_t y, uint16_t color)
{
  mylcd.Set_Draw_color(color);
  mylcd.Draw_Pixel(x, y);
}

void drawRect(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t color)
{
  mylcd.Set_Draw_color(color);
  mylcd.Fill_Rectangle(x, y, width, height);
}

void setup() 
{
  mylcd.Init_LCD();
  
  Font f(&drawPixel, &drawRect);
  f.setFont(&FreeMono24pt7b);
  f.setCursor(0,100);
  f.print("Test");

  uint16_t w;
  f.getTextWidth("Test", &w);
  f.setCursor(mylcd.Get_Display_Width() - w, 200);
  f.print("Test");
}

void loop() 
{
  
}
