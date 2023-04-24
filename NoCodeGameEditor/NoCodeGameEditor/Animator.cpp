#include "Animator.h"
/// <summary>
/// Animator Constructor
/// </summary>
Animator::Animator()
{
   // std::cout << "Animator ready" << std::endl;
}
/// <summary>
/// animate function which is called to animate a sprite sheet. 
/// Pass the already loaded texture, as well as the various paramaters to animate the specific spritesheet.
/// Returns an intrect which can be added to a sprite as one frame of the animaion
/// </summary>
/// <param name="t_texture"></param>
/// <param name="t_numOfFrames"></param>
/// <param name="t_frameWidth"></param>
/// <param name="t_frameHeight"></param>
/// <param name="t_cols"></param>
/// <param name="t_rows"></param>
/// <param name="t_time"></param>
/// <returns></returns>
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
