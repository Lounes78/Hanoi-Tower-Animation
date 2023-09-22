#include <stdio.h>
#include <SDL.h>
#define Largeur 680
#define Hauteur 720



int main(int argc, char const *argv[])
{
	SDL_Window *window = NULL ;
	SDL_Renderer *render = NULL;


	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	window = SDL_CreateWindow("fenetre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

	SDL_SetRenderDrawColor(render, 255, 0, 0, SDL_ALPHA_OPAQUE);


	SDL_RenderDrawPoint(render, 100, 450);

	SDL_RenderDrawLine(render, 50, 50, 500, 500); // x et y du premier point, puis ceux du deuxieme
                                                    
	SDL_Rect rectangle ;
	rectangle.x = 300;
	rectangle.y = 300;
	rectangle.w = 200;
	rectangle.h = 120;

	SDL_RenderFillRect(render, &rectangle);

	SDL_RenderPresent(render);



	SDL_bool program_launched = SDL_TRUE ;


	while (program_launched)
	{
		SDL_Event event;

		while(SDL_PollEvent(&event))    // le while se fait sur le retour de la fct
		{
			switch(event.type)
			{
				case SDL_QUIT :
					program_launched = SDL_FALSE;
					break;

				default :
					break;

			}
		}
	}

	SDL_DestroyRenderer ;
	SDL_DestroyWindow(window) ; 
	SDL_Quit();

	return 0;

}



