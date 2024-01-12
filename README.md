
# gfxfont
Simple Arduino header to use gfxfonts for every LCD screen.
Actually you cannot only use it for LCD screens but basically everywhere. You need to provide callback functions to draw pixels which makes it very flexible.

**Actually all the logic is simply copied from the [Adafruit GFX library](https://github.com/adafruit/Adafruit-GFX-Library)**
# example
Let me show you a very simple example how this can be used:

    #include <LCDWIKI_GUI.h> //Core graphics library
    #include <LCDWIKI_KBV.h> //Hardware-specific library
    #include "font.h"
    #include "Fonts/FreeMono24pt7b.h"
    
    LCDWIKI_KBV mylcd(ILI9486,A3,A2,A1,A0,A4); //model,cs,cd,wr,rd,reset
    
    //Callback function to draw a pixel
    void drawPixel(uint16_t x, uint16_t y, uint16_t color)
    {
      mylcd.Set_Draw_color(color);
      mylcd.Draw_Pixel(x, y);
    }
    
    //Callback function to draw a rectangle
    void drawRect(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t color)
    {
      mylcd.Set_Draw_color(color);
      mylcd.Fill_Rectangle(x, y, width, height);
    }
    
    void setup() 
    {
      mylcd.Init_LCD();
      
      //need to provide both callback functions in the constructor
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

As you can see in the example above I'm using an LCD from [lcdwiki.com](lcdwiki.com/3.5inch_Arduino_Display-UNO).
I just included the two header files `font.h` and the actual font file I want to use `Fonts/FreeMono24pt7b.h`. Then I set up the lcd, initialize the GFXFONT library with the callback functions to draw a pixel and a rect and that's it - then you can write text with a good looking font
# Contribute
I didn't like the default font which was available for my LCD and I saw that Adafruit created a nice font library I liked. So basically I just quickly copy and pasted all the relevant code into some header files and that's it.

**You are very welcome to contribute to this project, just open a pull request**
