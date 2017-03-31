#include <iostream>
#include "player.h"

player::player(int No, SDL_renderer *renderer,std::string imgname)
{
    SDL_surface* tmp_surface = SDL_LoadBMP(imgname.c_str());
    if (tmp_surface==null) std::cout <<"Image non chargée " <<SDL_GetError() << std::endl;

    m_texture=SDL_CreateTexture(renderer, tmp_surface);
    if (m_surface==null) std::cout <<"Texture non chargée " <<SDL_GetError() << std::endl;





}
