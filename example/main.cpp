/* 
 * example PSX_App project 
 */

#include "app.h"
#include "pad.h"

int main(void)
{
	int rectX = 400; // test controller to move rect
	int rectY = 200;
	int rectWidth = 200;
	int rectHeight = 200;

	/* create an instance of the app */
	PSX_App app;
	
	/* initialize with a screen size of (640,480)
	 * other screen sizes include:
	 * 
	 * width:  256, 320, 360, 512, 640
	 * height: 240 (interlace off), 480 (interlace on)
	 * the lib handles whether interlacing should be on or not
	 * the most common other resolution is (320,240)
	 * */
	app.init(640, 480);
	
	/* set the background color */
	app.setBgColor(0, 75, 75); // 255 max for each r,g,b

	/* create an instance of a pad
	 * PSX_App::init should be called because
	 * it calls the PSYQ's controller init function */
	PSX_Pad pad1(0); // controller port 0

	/* main game loop */
	while(1)
	{
		/* use the bios font to print to the screen */
		FntPrint("Hello World!\n");

		/* read pad data */
		pad1.read();

		/* test and move rect accordingly 
		 * buttons are defined in pad.h */
		if( pad1.checkHeld( PadLeft )){
			rectX--;
		}
		if( pad1.checkHeld( PadRight )){
			rectX++;
		}
		if( pad1.checkHeld( PadUp )){
			rectY--;
		}
		if( pad1.checkHeld( PadDown )){
			rectY++;
		}

		if( pad1.checkPressed( PadCross )){
			FntPrint("Clicked X!");
			printf("Clicked X!\n");
		}

		
		/* args - x0, y0, x1, y1, r,g,b */
		app.drawLine(100, 400, 200, 200,
		         255, 0, 0);
		
		/* draw 10 random color pixels 
		 * drawPixel args - x,y, r,g,b */
		for(int i=300; i<=400; i+=10){
			for(int j=10; j<=110; j+= 10){
				app.drawPixel(i, j, rand()%255, rand()%255, rand()%255);
			}
		}
		
		/* draw a blue rectangle 
		 * args - top left x, top left y, bottom right x, bottom right y,
		 *        r,g,b  */
		app.drawRect(rectX, rectY, rectX + rectWidth, rectY + rectHeight,
		         0, 0, 255);

		/* draw a green triangle
		 * args - bottom left x, bottom left y, middle x, middle y, bottom right x, bottom right y,
		 *        r, g, b
		 * */
		app.drawTriangle(250, 350, 300, 300, 350, 350, 
		             0, 255, 0);

        app.drawFrame(); // draw the frame
	}
	
	return 0;
}
