#include "image.h"

image::image(std::string nom, SDL_Renderer *renderer)
{
    // On charge notre image
    SDL_Surface* tmp = SDL_LoadBMP(nom.c_str());
    if (tmp==NULL) std::cout <<"Image non chargée " <<SDL_GetError() <<std::endl;
    // On initialise nos arguments
    m_texture = SDL_CreateTextureFromSurface(renderer, tmp);
    if (m_texture==NULL) std::cout <<"Texture non chargée " <<SDL_GetError() <<std::endl;


    height=tmp->h;
    width=tmp->w;


    m_positionImage = {0, 0, width, height};


    std::cout <<"w=" <<tmp->w <<" h=" <<tmp->h;


    // On a plus besoin de la surface donc on libère la mémoire
    SDL_FreeSurface(tmp);
}

image::~image()
{
    SDL_DestroyTexture(m_texture);
    m_texture = NULL;
}

void image::afficher(SDL_Renderer *renderer, int x, int y)
{
    if (m_texture != NULL)
    {
        SDL_Rect r= {.x=x,.y=y,.w=m_positionImage.w,.h=m_positionImage.h};
        SDL_RenderCopy(renderer, m_texture, &m_positionImage, &r);
    }
}
