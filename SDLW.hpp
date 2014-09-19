#include "SDL/SDL.h"
#include "SDL/SDL_thread.h"
#include "SDL/SDL_ttf.h"

int pollInput(void *);

void init(int screenWidth, int screenHeight, bool fullScreen);
void flip();
void drawText(char* text, int size, int x, int y, int fR, int fG, int fB, int bR, int bG, int bB);
void drawText(char* text);
void clearScreen();

extern SDL_Surface *screen;
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern char input;
extern bool LMB;
extern bool RMB;
extern int mouseX;
extern int mouseY;

struct imageInfo
{
	imageInfo(char *image, int sx, int sy, int sw, int sh, int dx, int dy);
	imageInfo(char *image);
	SDL_Surface *temp, *image;
	SDL_Rect Src, Dest;
	void loadImage(char *);	
	void draw();
};

struct key
{	
	bool down;
	char *ch;
};
extern key a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,one,two,three,four,five,six,seven,eight,nine,zero;

void draw(imageInfo image);


