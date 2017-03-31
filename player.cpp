#include <iostream>
#include "player.h"

unsigned int player::m_dernier_No = 0;
player::player(std::string imgname ,SDL_Renderer *renderer): image(imgname, renderer)
{
    m_dernier_No ++;
    m_No=m_dernier_No;
    std::cout << "Joueur " <<get_player_no() <<" cree\n";

}

unsigned int player::get_player_no()
{
    return m_No;
}
