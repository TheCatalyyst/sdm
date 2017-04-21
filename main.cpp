#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>
#include <vector>


#include "player.h"
#include "image.h"

using namespace std;
int main(int argc, char** argv)
{
    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }

    {
        /* Création de la fenêtre */
        SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Window",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  800,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);



        SDL_Renderer * renderer;
        renderer=SDL_CreateRenderer(pWindow,0,0);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        /* Clear the entire screen to our selected color. */

        SDL_RenderClear(renderer);


// Player generation /////////////////////////////////
        unsigned int nplayer=5;
        vector<player*> playervect;
        for (unsigned int i_player=0;i_player<nplayer;i_player ++){
            player* curr_player = new player("soleil.bmp",renderer);
            playervect.push_back(curr_player);
            cout << "player " << playervect[i_player]->get_player_no() << "initialized\n";
        }
//////////////////////////////////////////////////////


        if( pWindow )
        {
            bool esc=false;
            bool down=false;
            bool up=false;
            bool left=false;
            bool right=false;
            SDL_Event event;


            /////////////////////////////BOUCLE WHILE POUR ROMAIN
            while(1){

                while(SDL_PollEvent(&event))
                {
                    switch (event.type)
                    {
                    case SDL_MOUSEMOTION:
                        cout << "x= " << event.motion.x << endl;
                        break;
                    case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                        {
                        case SDLK_ESCAPE:
                            esc=true;
                            SDL_Quit();
                            return 0;
                            break;
                        case SDLK_UP:
                            cout << "up down\n";
                            up=true;
                            break;
                        case SDLK_DOWN:
                            cout << "down down\n";
                            down=true;
                            break;
                        case SDLK_LEFT:
                            cout << "left down\n";
                            left=true;
                            break;
                        case SDLK_RIGHT:
                            cout << "right down\n";
                            right=true;
                            break;
                        default:
                            cout << "Touche inconnue down \n";
                            break;
                        }
                        break;
                         case SDL_KEYUP:
                        switch(event.key.keysym.sym)
                        {
                        case SDLK_UP:
                            up=false;
                            cout << "up up\n";
                            break;
                        case SDLK_DOWN:
                            cout << "down up\n";
                            down=false;
                            break;
                        case SDLK_LEFT:
                            cout << "left up\n";
                            left=false;
                            break;
                        case SDLK_RIGHT:
                            cout << "right up\n";
                            right=false;
                            break;
                        default:
                            cout << "Touche inconnue up \n";
                            break;
                        }
                    default:
                        cout << "Evenement inconnu\n";
                        break;

                    }
                    cout << "done\n";
                }

                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                SDL_RenderClear(renderer);

                if (up){
                  playervect[0]->afficher(renderer,0,0);
                  cout << "Player " << playervect[0]->get_player_no() << " displayed\n";
                }
                SDL_RenderPresent(renderer);








                SDL_Delay(10);
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                }

            SDL_DestroyWindow(pWindow);
        }
        else
        {
            fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
        }
    }

    SDL_Quit();

    return 0;
}
