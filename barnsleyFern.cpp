#include <SDL.h>
#include <conio.h>
#include <iostream>
#include<chrono>
#include<thread>

using namespace std;
void draw(SDL_Renderer * renderer,float x,float y)
{
	float nextX,d,t;	
	SDL_RenderDrawPoint(renderer, x, y);
	int i = 0;
	while(i < 1000000){
	
	 d = (float)rand() / RAND_MAX;	
	
	if (d < 0.25) {
	 nextX = 0;
	 y =  0.16 * y ; 
	 
	}
	else if(d< 0.5){
	 nextX = 0.85 * x + 0.04 * y;
	 y = -0.04 * x + 0.85 * y + 1.6; 
	 x = nextX;
	 
	}
	else if(d< 0.75){	
	 nextX = 0.2 * x + -0.26 * y;
	 y = 0.23 * x + 0.22 * y + 1.6;
	 x = nextX;
	 
	}
	else {
	 nextX = -0.15 * x + 0.28 * y;
	 y = 0.26 * x + 0.24 * y + 0.44;
	 x = nextX;
	 
	 
	 }
	SDL_RenderDrawPoint(renderer, (x*60) + 500, y*-60+650);
		
			
	i++;
	 
	}
}

int main(int argc, char* argv[]) {

	float x = 640/2 ;
	float y = 480/2 ;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(1680,1050, 0, &window, &renderer);
	//SDL_RenderSetScale(renderer, 4, 4);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	draw(renderer, x, y);
	SDL_RenderPresent(renderer);
	
	SDL_Delay(10000000);


	return 0;
}