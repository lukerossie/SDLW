#include "SDLT.hpp"	
#include <string>

int main()
{
	init(640,600,false);//screenWidth, screenHeight, bool fullscreen

	imageInfo i("example.bmp");//load the whole image, Dest at 0,0
	imageInfo s("example.bmp", 0,0, 640,400, 0,0);//specify the dimensions (image path, Src.x, Src.y, Src.w, Src.h, Dest.x, Dest.y)
	s.Src.w = 600;//or specify a dimension individually
	
	while (input != SDLK_ESCAPE)
	{		
		clearScreen(); //clears to black
		draw(i);
		drawText("This is some text.");//white on black, at SCREEN_WIDTH/2
		drawText("This text does what I want.", 12, 150,150, 255,255,255, 0,0,0);//or specify (char *text, size, x,y, fR,fG,fB, bR,bG,bB)
		drawText(std::string(std::to_string(mouseX)).c_str(), 30, 0,100, 255,255,255, 0,0,0);//display the mouse's X coordinate
		drawText(std::string(std::to_string(mouseY)).c_str(), 30, 0,150, 255,255,255, 0,0,0);//display the mouse's Y coordinate
		if(RMB) drawText("RMB", 30, 350,100, 255,255,255, 0,0,0);//show if the right mouse button is clicked
		if(LMB) drawText("LMB", 30, 350,150, 255,255,255, 0,0,0);//show if the left mouse button is clicked
		if(input!=0) drawText(&input, 30, 200,325, 255,255,255, 0,0,0);//if the latest input!=null, show it to us
		if(a.down) drawText(a.ch, 30, 400,400, 255,255,255, 0,0,0);//or check a specific key to see its state
		if(b.down) drawText(b.ch, 30, 450,400, 255,255,255, 0,0,0);
		flip();//render
	}
}

