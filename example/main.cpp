/* 
 * example PSX_App project 
 * the actual coding is done in app.cpp
 */

#include "app.h"

int main(void)
{
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
	
	/* runs the main loop */
	app.run();
	
	return 0;
}