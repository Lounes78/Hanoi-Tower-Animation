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




/*
#include <iostream>
#include <sdlpp/sdlpp.hpp>
static const auto Width = 1280; static const auto Height = 720;
class Hanoi
{
private:
auto move(int pinl, int pin2)
std::cout << "move" << pin1 <<<">"<<< pin2 << std::endl;
const auto disc tower [pin1].back();
tower [pin1].pop_back(); tower [pin2].push_back(disc);
r.setDrawColor(0x00, 0x00, 0x00, 0xff);
r.clear(); for (auto i = 0; i < 3; ++i)
{
auto y Height - 20; for (auto disc: tower[i])
{
std::cout << disc; r.setDrawColor (exff, exff, exff, exff);
const auto rect = SDL_Rect{(i + 1) Width 4, y, 10, 18:
y = 20;
}
r.fillRect(&rect);
std::cout << std::endl;
}
std::cout << std::endl;

}

sdl::Renderer &r;
public:
Hanoi (sdl::Renderer &r, int n) : r(r)
for (auto i = 0; i < n; ++i) tower[0].push_back(n - i - 1);
solve(n, 0, 1, 2);
} std::array<std::vector<int>, 3> tower;
auto main()> int
{ auto init sdl::Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
const auto Width = 1280;
const auto Height = 720;
auto wsdl::Window{"Tower of Hanoi", 63, 126, Width, Height, SDL WINDOW_BORDERLESS};
autor sdl::Renderer {w.get(), -1, 0);
r.setDrawColor(0x00, 0x00, 0x00, 0xff); r.clear(); r.setDrawColor (0xff, exff, 0xff, exff); const auto rect = SDL_Rect(0, 0, 10, 100); r.fillRect(&rect);
auto hanoi Hanoi{r, 3};
r.present(); SDL_Delay(1000);
}

*/


/* #include <stdio.h>
#include <SDL.h>
#define Width 800
#define Height 600




void move(int pin1, int pin2, int tower[3][N_DISCS], int tower_sizes[3]) 
{
    SDL_Window *window = NULL ;
    SDL_Renderer *render = NULL;

    int disc = tower[pin1][tower_sizes[pin1] - 1];
    
    tower[pin1][tower_sizes[pin1] - 1] = 0;
    tower_sizes[pin1]--;
    
    tower[pin2][tower_sizes[pin2]] = disc;
    tower_sizes[pin2]++;

    SDL_SetRenderDrawColor(render, 120, 120, 120, SDL_ALPHA_OPAQUE);

    for (int i = 0; i < 3; i++)
    {
        int y = Height - 20;

        for (int j = 0; j < tower[i].size(); j++)
        {
            int disc = tower[i][j];
            SDL_SetRenderDrawColor(render, 120, 120, 120, SDL_ALPHA_OPAQUE);

            SDL_Rect rect;
            rect.x = (i+1) * Width / 4;
            rect.y = y;
            rect.w = 10;
            rect.h = 18;

         SDL_RenderFillRect(render, &rect);

         y -= 20 ;

        }

    }


    SDL_RenderPresent(render);
    SDL_Delay(1000);

}


void Algo_Hanoi(int n, int pin1, int pin2, int pin3)
{
    if ( n == 0 )
        return ;

    Algo_Hanoi(n-1, pin1, pin3, pin2);
    move(pin1, pin2, );
    Algo_Hanoi(n-1, pin3, pin2, pin1);
}



int main(int argc, char const *argv[])
{
    SDL_Window *window = NULL ;
    SDL_Renderer *render = NULL;


    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Tour de HanoÏ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_BORDERLESS);
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    SDL_SetRenderDrawColor(render, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(render);



    return 0;
}*/