#include "SDLT.hpp"

SDL_Surface *screen;
int SCREEN_WIDTH;
int SCREEN_HEIGHT;
char input = 0;
bool LMB = false;
bool RMB = false;
int mouseX = 0;
int mouseY = 0;
key a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,one,two,three,four,five,six,seven,eight,nine,zero;
bool writing = false;

void clearScreen()
{
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
}
void drawText(char* text, int size, int x, int y, int fR, int fG, int fB, int bR, int bG, int bB)
{
	TTF_Font* font = TTF_OpenFont("ARIAL.TTF", size);
	SDL_Color foregroundColor = { fR, fG, fB };
	SDL_Color backgroundColor = { bR, bG, bB };
	SDL_Surface* textSurface = TTF_RenderText_Shaded(font, text, foregroundColor, backgroundColor);
	SDL_Rect textLocation = { x, y, 0, 0 };
	SDL_BlitSurface(textSurface, NULL, screen, &textLocation);
	SDL_FreeSurface(textSurface);
	TTF_CloseFont(font);
}
void drawText(char* text)
{
	TTF_Font* font = TTF_OpenFont("ARIAL.TTF", 12);
	SDL_Color foregroundColor = { 0, 0, 0 };
	SDL_Color backgroundColor = { 255, 255, 255 };
	SDL_Surface* textSurface = TTF_RenderText_Shaded(font, text, foregroundColor, backgroundColor);
	SDL_Rect textLocation = { SCREEN_WIDTH/2, 50, 0, 0 };
	SDL_BlitSurface(textSurface, NULL, screen, &textLocation);
	SDL_FreeSurface(textSurface);
	TTF_CloseFont(font);
}

void init(int screenWidth, int screenHeight, bool fullScreen)
{
	a.ch = "a";
	b.ch = "b";
	c.ch = "c";
	d.ch = "d";
	e.ch = "e";
	f.ch = "f";
	g.ch = "g";
	h.ch = "h";
	i.ch = "i";
	j.ch = "j";
	k.ch = "k";
	l.ch = "l";
	m.ch = "m";
	n.ch = "n";
	o.ch = "o";
	p.ch = "p";
	q.ch = "q";
	r.ch = "r";
	s.ch = "s";
	t.ch = "t";
	u.ch = "u";
	v.ch = "v";
	w.ch = "w";
	x.ch = "x";
	y.ch = "y";
	z.ch = "z";
	one.ch = "1";
	two.ch = "2";
	three.ch = "3";
	four.ch = "4";
	five.ch = "5";
	six.ch = "6";
	seven.ch = "7";
	eight.ch = "8";
	nine.ch = "9";
	zero.ch = "0";

	TTF_Init();
	SCREEN_WIDTH = screenWidth;
	SCREEN_HEIGHT = screenHeight;
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, (fullScreen ? SDL_FULLSCREEN : 0));
	SDL_CreateThread(pollInput, (void *)NULL);
}
void flip()
{
	SDL_Flip(screen);
}
void draw(imageInfo randomPicture)
{
	SDL_BlitSurface(randomPicture.image, &randomPicture.Src, screen, &randomPicture.Dest);
}

imageInfo::imageInfo(char *path)
{
	loadImage(path);
	SDL_Surface *surf = SDL_LoadBMP(path);
	Src.w = surf->w;
	Src.h = surf->h;  
	SDL_FreeSurface(surf);
	Src.x = 0;
	Src.y = 0;
	Dest.x = 0;
	Dest.y = 0;
}
imageInfo::imageInfo(char *path, int sx, int sy, int sw, int sh, int dx, int dy)
{
	loadImage(path);
	Src.x = sx;
	Src.y = sy;
	Src.w = sw;
	Src.h = sh;
	Dest.x = dx;
	Dest.y = dy;
}
void imageInfo::loadImage(char *path)
{
	temp = SDL_LoadBMP(path);
	image = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
}


int pollInput(void *ptr)
{
	SDL_Event event;
	while(1)
	{	
		if (SDL_PollEvent(&event)) 
		{
			switch (event.type)
			{
			case SDL_QUIT: //window closed
				SDL_Quit();
				break;
			case SDL_KEYDOWN:
				input = event.key.keysym.sym;
				switch(event.key.keysym.sym)
				{
					case 'a':
						a.down = true;
						break;
					case 'b':
						b.down = true;
						break;
					case 'c':
						c.down = true;
						break;
					case 'd':
						d.down = true;
						break;
					case 'e':
						e.down = true;
						break;
					case 'f':
						f.down = true;
						break;
					case 'g':
						g.down = true;
						break;
					case 'h':
						h.down = true;
						break;
					case 'i':	
						i.down = true;
						break;
					case 'j':
						j.down = true;
						break;
					case 'k':
						k.down = true;
						break;
					case 'l':
						l.down = true;
						break;
					case 'm':
						m.down = true;
						break;
					case 'n':
						n.down = true;
						break;
					case 'o':
						o.down = true;
						break;
					case 'p':
						p.down = true;
						break;
					case 'q':
						q.down = true;
						break;
					case 'r':	
						r.down = true;
						break;
					case 's':
						s.down = true;
						break;
					case 't':	
						t.down = true;
						break;
					case 'u':
						u.down = true;
						break;
					case 'v':
						v.down = true;
						break;
					case 'w':
						w.down = true;
						break;
					case 'x':
						x.down = true;
						break;
					case 'y':
						y.down = true;
						break;
					case 'z':
						z.down = true;
						break;
					case '1':
						one.down = true;
						break;
					case '2':
						two.down = true;
						break;
					case '3':
						three.down = true;
						break;
					case '4':
						four.down = true;
						break;
					case '5':	
						five.down = true;
						break;
					case '6':
						six.down = true;
						break;
					case '7':
						seven.down = true;
						break;
					case '8':
						eight.down = true;
						break;
					case '9':
						nine.down = true;
						break;
					case '0':
						zero.down = true;
						break;
				}
				break;
			case SDL_KEYUP:
				input = 0;
				switch(event.key.keysym.sym)
				{
					case 'a':
						a.down = false;
						break;
					case 'b':
						b.down = false;
						break;
					case 'c':
						c.down = false;
						break;
					case 'd':
						d.down = false;
						break;
					case 'e':
						e.down = false;
						break;
					case 'f':
						f.down = false;
						break;
					case 'g':
						g.down = false;
						break;
					case 'h':
						h.down = false;
						break;
					case 'i':	
						i.down = false;
						break;
					case 'j':
						j.down = false;
						break;
					case 'k':
						k.down = false;
						break;
					case 'l':
						l.down = false;
						break;
					case 'm':
						m.down = false;
						break;
					case 'n':
						n.down = false;
						break;
					case 'o':
						o.down = false;
						break;
					case 'p':
						p.down = false;
						break;
					case 'q':
						q.down = false;
						break;
					case 'r':	
						r.down = false;
						break;
					case 's':
						s.down = false;
						break;
					case 't':	
						t.down = false;
						break;
					case 'u':
						u.down = false;
						break;
					case 'v':
						v.down = false;
						break;
					case 'w':
						w.down = false;
						break;
					case 'x':
						x.down = false;
						break;
					case 'y':
						y.down = false;
						break;
					case 'z':
						z.down = false;
						break;
					case '1':
						one.down = false;
						break;
					case '2':
						two.down = false;
						break;
					case '3':
						three.down = false;
						break;
					case '4':
						four.down = false;
						break;
					case '5':	
						five.down = false;
						break;
					case '6':
						six.down = false;
						break;
					case '7':
						seven.down = false;
						break;
					case '8':
						eight.down = false;
						break;
					case '9':
						nine.down = false;
						break;
					case '0':
						zero.down = false;
						break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch(event.button.button)
				{
				case SDL_BUTTON_RIGHT:	
					RMB = (event.button.state == SDL_PRESSED);	
					break;	
				case SDL_BUTTON_LEFT:
					LMB = (event.button.state == SDL_PRESSED);
					break;	
				}
				break;
			case SDL_MOUSEBUTTONUP:
				switch(event.button.button)
				{
				case SDL_BUTTON_RIGHT:	
					RMB = (event.button.state == SDL_PRESSED);	
					break;	
				case SDL_BUTTON_LEFT:
					LMB = (event.button.state == SDL_PRESSED);
					break;	
				}
				break;
			}
			switch(event.type)
			{
			case SDL_MOUSEMOTION:
				mouseX = event.motion.x;
				mouseY = event.motion.y;
				break;
			}
		}
	}
}

