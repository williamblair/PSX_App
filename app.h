
#include <stdlib.h>
#include <libgte.h>
#include <libgpu.h>
#include <libgs.h>
#include <libetc.h>

#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

const int OT_LENGTH = 10;  // the length of the order table
const int PACKETMAX = 1000; // number of total packets possible

const int PACKET_SIZE = 64;

class PSX_App
{
    public:
        PSX_App(); // constructor

        void init(const u_int w, const u_int h); // initialize the system
        void run(void);                      // run the main loop

        void setBgColor(u_char r, u_char g, u_char b); // set bg clear color

    protected:

        void drawPixel(const int x, const int y,
                       const int r, const int g, const int b);

        void drawLine(const int x0, const int y0,
                      const int x1, const int y1,
                      const int r, const int g, const int b);

        void drawRect(const int topLeftX, const int topLeftY,
                      const int bottomRightX, const int bottomRightY,
                      const int r, const int g, const int b);
					  
		void drawTriangle(const int bottomLeftX,  const int bottomLeftY,
                          const int middleX,      const int middleY,
						  const int bottomRightX, const int bottomRightY,
                          const int r, const int g, const int b);

        //void draw();          // where you actually draw stuff to the screen
        void drawFrame(void); // process a frame

    private:
        GsOT myOT[2];  // order table - 2 for double buffer
        GsOT_TAG myOT_TAG[2][1<<OT_LENGTH];
        PACKET GPUPacketArea[2][PACKETMAX];

        u_long __ramsize;//    = 0x00200000; // force 2MB of RAM
        u_long __stacksize;//  = 0x00004000; // force 16KB of stack

        short CurrentBuffer; // keep track of the current buffer

        u_int screen_width; // screen width and height
        u_int screen_height;

        u_char bgcolor[3];   // r, g, b for background color

        //u_int prio; // used in GsSort functions

};

#endif // APP_H_INCLUDED
