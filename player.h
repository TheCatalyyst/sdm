#ifndef PLAYER_H
#define PLAYER_H

#include "image.h"
#include <SDL2/SDL.h>
class player : public image
{
public:


    player( std::string imgname, SDL_Renderer * renderer);


    unsigned int get_player_no();

private:

    unsigned int m_No;
    static unsigned int m_dernier_No;

};

#endif
