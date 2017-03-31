
#include <SDL.h>

class player
{
public:

    player(int No, SDL_renderer *renderer, std::string imgname);
    virtual ~image();

    int height;
    int width;


private:
    SDL_Texture* m_texture;
    SDL_Rect m_pos;
};
