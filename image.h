#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <SDL.h>

class image
{
    public:

        image(std::string nom, SDL_Renderer *renderer);
        virtual ~image();

        void afficher(SDL_Renderer *renderer, int, int);

        int height;
        int width;

    private:

        SDL_Texture* m_texture;
        SDL_Rect m_positionImage;
};

#endif // IMAGE_H
