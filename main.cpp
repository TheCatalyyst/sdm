#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>

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
                                                                  640,
                                                                  480,
                                                                  SDL_WINDOW_SHOWN);

        if( pWindow )
        {
            bool esc=false;
            bool down=false;
            bool up=false;
            bool left=false;
            bool right=false;
            SDL_Event event;
            while(1){

                while(SDL_PollEvent(&event))
                {
                    switch (event.type)
                    {
                    case SDL_MOUSEMOTION:
                        std::cout << "x= " << event.motion.x << std::endl;
                        break;
                    case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                        {
                        case SDLK_ESCAPE:
                            esc=true;
                            return 0;
                            break;
                        case SDLK_UP:
                            std::cout << "up down\n";
                            up=true;
                            break;
                        case SDLK_DOWN:
                            std::cout << "down down\n";
                            down=true;
                            break;
                        case SDLK_LEFT:
                            std::cout << "left down\n";
                            left=true;
                            break;
                        case SDLK_RIGHT:
                            std::cout << "right down\n";
                            right=true;
                            break;
                        default:
                            std::cout << "Touche inconnue down \n";
                            break;
                        }
                        break;
                         case SDL_KEYUP:
                        switch(event.key.keysym.sym)
                        {
                        case SDLK_UP:
                            up=false;
                            std::cout << "up up\n";
                            break;
                        case SDLK_DOWN:
                            std::cout << "down up\n";
                            down=false;
                            break;
                        case SDLK_LEFT:
                            std::cout << "left up\n";
                            left=false;
                            break;
                        case SDLK_RIGHT:
                            std::cout << "right up\n";
                            right=false;
                            break;
                        default:
                            std::cout << "Touche inconnue up \n";
                            break;
                        }
                    default:
                        std::cout << "Evenement inconnu\n";
                        break;

                    }
                    std::cout << "done\n";
                }

                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






















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
