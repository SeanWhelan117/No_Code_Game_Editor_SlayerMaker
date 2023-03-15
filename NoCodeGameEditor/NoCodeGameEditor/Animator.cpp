#include "Animator.h"

Animator::Animator()
{
   // std::cout << "Animator ready" << std::endl;
}

sf::IntRect Animator::animate(sf::Texture t_texture, int t_numOfFrames, int t_frameWidth, int t_frameHeight, int t_cols, int t_rows, int t_time)
{
    totalElapsed++;

    if (totalElapsed > t_time)
    {
        totalElapsed = 0;
        animationFrame++;
        if (animationFrame > t_numOfFrames) 
        {
            animationFrame = 0;
        }
    }
    int col = animationFrame % t_cols; 
    int row = animationFrame / t_cols; 

    rectSourceSprite.height = t_frameHeight;
    rectSourceSprite.width = t_frameWidth;
    rectSourceSprite.left = col * rectSourceSprite.width;
    rectSourceSprite.top = row * rectSourceSprite.height;

    return rectSourceSprite;
}
