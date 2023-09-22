#include <stdio.h>
#include <SDL.h>
#include <SDL_mixer.h>


#define N_DISCS 6
#define Height 600

#if N_DISCS > 5
#define Width 1500

#elif N_DISCS <=5
#define Width 1000

#endif


void move(int pin1, int pin2, int tower[3][N_DISCS], int tower_sizes[3], SDL_Renderer *render) 
{
    int disc = tower[pin1][tower_sizes[pin1] - 1];
    int a = tower_sizes[pin1];

    tower[pin1][tower_sizes[pin1] - 1] = 0;
    tower_sizes[pin1]--;
    
    tower[pin2][tower_sizes[pin2]] = disc;
    tower_sizes[pin2]++;

    // Efface le rendu précédent
    SDL_SetRenderDrawColor(render, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(render);

    // Dessine les disques sur les tours
    for (int i = 0; i < 3; i++)
    {
        int y = Height - 20;
        for (int j = 0; j < tower_sizes[i]; j++)
        {
            int disc = tower[i][j];
            int size = disc * 25 + 20; 
            SDL_Rect rect;
            rect.x = (i+1) * Width / 4 - size/2;
            rect.y = y;
            rect.w = size;
            rect.h = 18;

            SDL_SetRenderDrawColor(render, 120, 120, 120, SDL_ALPHA_OPAQUE);
            SDL_RenderFillRect(render, &rect);

            y -= 20 ;
        }
    }

    SDL_RenderPresent(render);
    if (N_DISCS < 4)
        SDL_Delay(1000);
    else
        SDL_Delay(500);
}


void Algo_Hanoi(int n, int pin1, int pin2, int pin3, int tower[3][N_DISCS], int tower_sizes[3], SDL_Renderer *render)
{
    if ( n == 0 )
        return ;

    Algo_Hanoi(n-1, pin1, pin3, pin2, tower, tower_sizes, render);
    move(pin1, pin2, tower, tower_sizes, render);
    Algo_Hanoi(n-1, pin3, pin2, pin1, tower, tower_sizes, render);
}




int main(int argc, char const *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    int tower[3][N_DISCS] = {0};
    int tower_sizes[3] = {N_DISCS, 0, 0};

    for (int i = 0; i < N_DISCS; i++)
    {        
        tower[0][i] = 2*N_DISCS - 2*i;
    }


    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    window = SDL_CreateWindow("Tour de HanoÏ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    Mix_Init(MIX_INIT_MP3);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Music *background_music = Mix_LoadMUS("Title.mp3");
    Mix_PlayMusic(background_music, -1) ;


    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    Algo_Hanoi(N_DISCS, 0, 2, 1, tower, tower_sizes, renderer);

    

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


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    Mix_FreeMusic(background_music);
    Mix_CloseAudio();
    Mix_Quit();


    return 0;
}
