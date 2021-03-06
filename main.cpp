/*
  Josh Hartshorn
  Tic Tac Toe Clone
  11/13/2012
  -Need to clean up repetitive code, and add a timer to limit fps.
  -use a surface for loading all of the textures, and
   then copy it to a texture and render it.

    need to scale x's and o's

*/

//Linux
/*
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include <iostream>
#include <sstream>
*/
using namespace std;

//android
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <iostream>
#include <sstream>
//
int height = 640; //completely ignored on android
int width = 480; // also completely ignored on android
const int bpp = 32;
const int FPS = 15;

int GridBox[9] = {};
int player = 1;
int winner = 0;
SDL_Event event;
int messageheight = 0;
stringstream s;

SDL_Surface Draw(SDL_Surface *img, SDL_Surface *screen, int x, int y)
{;
    SDL_Rect location;
    location.x = x;
    location.y = y;

    SDL_BlitSurface(img, NULL, screen, &location);
}
class Square
{
private:
    SDL_Rect box;
public:
    Square( int x, int y, int w, int h);
    void handle_events(int numberSquare);
};
//The timer
class Timer
{
    private:
    //The clock time when the timer started
    int startTicks;

    //The ticks stored when the timer was paused
    int pausedTicks;

    //The timer status
    bool paused;
    bool started;

    public:
    //Initializes variables
    Timer();

    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();

    //Gets the timer's time
    int get_ticks();

    //Checks the status of the timer
    bool is_started();
    bool is_paused();
};
Timer::Timer()
{
    //Initialize the variables
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
}
void Timer::start()
{
    //Start the timer
    started = true;

    //Unpause the timer
    paused = false;

    //Get the current clock time
    startTicks = SDL_GetTicks();
}

void Timer::stop()
{
    //Stop the timer
    started = false;

    //Unpause the timer
    paused = false;
}

void Timer::pause()
{
    //If the timer is running and isn't already paused
    if( ( started == true ) && ( paused == false ) )
    {
        //Pause the timer
        paused = true;

        //Calculate the paused ticks
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}
void Timer::unpause()
{
    //If the timer is paused
    if( paused == true )
    {
        //Unpause the timer
        paused = false;

        //Reset the starting ticks
        startTicks = SDL_GetTicks() - pausedTicks;

        //Reset the paused ticks
        pausedTicks = 0;
    }
}

int Timer::get_ticks()
{
    //If the timer is running
    if( started == true )
    {
        //If the timer is paused
        if( paused == true )
        {
            //Return the number of ticks when the timer was paused
            return pausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            return SDL_GetTicks() - startTicks;
        }
    }

    //If the timer isn't running
    return 0;
}

bool Timer::is_started()
{
    return started;
}

bool Timer::is_paused()
{
    return paused;
}
Square::Square ( int x, int y, int w, int h)
{
    box.x = x;
    box.y = y;
    box.w = w;//square width
    box.h = h;//square height
}
void Square::handle_events(int numberSquare)
{
    //mouse offsets
    int x = 0, y = 0;
    //if mouse is clicked
    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        //get the mouse offsets
        //x = event.motion.x;
        //y = event.motion.y;

        SDL_GetMouseState(&x, &y);

        cout << "x: " << x << "y: " << y << endl;

        //If a square is clicked
        if((x > box.x) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ))
        {
            switch (numberSquare)
            {
            case 1:
                //square one
                if((player % 2) == 1)
                {
                    if(GridBox[0]== 0)
                    {
                        GridBox[0] = 1;
                        player++;
                    }
                }
                if((player % 2) == 0)
                {
                    if(GridBox[0]== 0)
                    {
                        GridBox[0] = 2;
                        player++;
                    }
                }
                break;

            case 2:
                //square two
                if((player % 2) == 1)
                {
                    if(GridBox[1]== 0)
                    {
                        GridBox[1] = 1;
                        player++;
                    }
                }
                if((player % 2) == 0)
                {
                    if(GridBox[1]== 0)
                    {
                        GridBox[1] = 2;
                        player++;
                    }
                }
                break;
            case 3:
                //square two
                if((player % 2) == 1)
                {
                    if(GridBox[2]== 0)
                    {
                        GridBox[2] = 1;
                        player++;
                    }
                }
                if((player % 2) == 0)
                {
                    if(GridBox[2]== 0)
                    {
                        GridBox[2] = 2;
                        player++;
                    }
                }
                break;
            case 4:
                //square two
                if((player % 2) == 1)
                {
                    if(GridBox[3]== 0)
                    {
                        GridBox[3] = 1;
                        player++;
                    }
                }
                if((player % 2) == 0)
                {
                    if(GridBox[3]== 0)
                    {
                        GridBox[3] = 2;
                        player++;
                    }
                }
                break;
            case 5:
                //row two
                if((player % 2) == 1)
                {
                    if(GridBox[4]== 0)
                    {
                        GridBox[4] = 1;
                        player++;
                    }
                }
                if((player % 2) == 0)
                {
                    if(GridBox[4]== 0)
                    {
                        GridBox[4] = 2;
                        player++;
                    }
                }
                break;
            case 6:
                //square two
                if((player % 2) == 1)
                {
                    if(GridBox[5]== 0)
                    {
                        GridBox[5] = 1;
                        player++;
                    }
                }
                if((player % 2) == 0)
                {
                    if(GridBox[5]== 0)
                    {
                        GridBox[5] = 2;
                        player++;
                    }
                }
                break;
            case 7:
                //square two
                if((player % 2) == 1)
                {
                    if(GridBox[6]== 0)
                    {
                        GridBox[6] = 1;
                        player++;
                    }
                }
                if((player % 2) == 0)
                {
                    if(GridBox[6]== 0)
                    {
                        GridBox[6] = 2;
                        player++;
                    }
                }
                break;
            case 8:
                //square two
                if((player % 2) == 1)
                {
                    if(GridBox[7]== 0)
                    {
                        GridBox[7] = 1;
                        player++;
                    }
                }
                if((player % 2) == 0)
                {
                    if(GridBox[7]== 0)
                    {
                        GridBox[7] = 2;
                        player++;
                    }
                }
                break;
            case 9:
                //square two
                if((player % 2) == 1)
                {
                    if(GridBox[8]== 0)
                    {
                        GridBox[8] = 1;
                        player++;
                    }
                }
                if((player % 2) == 0)
                {
                    if(GridBox[8]== 0)
                    {
                        GridBox[8] = 2;
                        player++;
                    }
                }
                break;
            }
        }
    }
}
//this can be cleaned up. perhaps with a for loop!
void DrawImage(int*GridBox, SDL_Surface *imgX, SDL_Surface *imgO, SDL_Surface *screen)
{
    //row 1 // column one image starts 4% of total assuming image size of 120 pixels
            // column two image starts at 38% of total
            // column three image starts at 71%
    if (GridBox[0] == 1)
    {
        Draw(imgX,screen, (width * .04),((height-messageheight)/12));
    }
    else if (GridBox[0] == 2)
    {
        Draw(imgO, screen, (width * .04), ((height- messageheight)/12));
    }
    if (GridBox[1] == 1)
    {
        Draw(imgX,screen, width * .38,((height-messageheight)/12));
    }
    else if (GridBox[1] == 2)
    {
        Draw(imgO, screen, width * .38,((height-messageheight)/12));
    }
    if (GridBox[2] == 1)
    {
        Draw(imgX,screen, (width * .71),((height-messageheight)/12));
    }
    else if (GridBox[2] == 2)
    {
        Draw(imgO, screen, (width * .71),((height-messageheight)/12));
    }
    //row 2
    if (GridBox[3] == 1)
    {
        Draw(imgX,screen, width * .04,((height-messageheight)/2)-imgO->h/2);
    }
    else if (GridBox[3] == 2)
    {
        Draw(imgO, screen, width * .04, ((height-messageheight)/2)-imgO->h/2);
    }
    if (GridBox[4] == 1)
    {
        Draw(imgX,screen, width * .38,((height-messageheight)/2)-imgO->h/2);
    }
    else if (GridBox[4] == 2)
    {
        Draw(imgO, screen, width * .38, ((height-messageheight)/2)-imgO->h/2);
    }
    if (GridBox[5] == 1)
    {
        Draw(imgX,screen, width * .71,((height-messageheight)/2)-imgO->h/2);
    }
    else if (GridBox[5] == 2)
    {
        Draw(imgO, screen, width * .71, ((height-messageheight)/2)-imgO->h/2);
    }
    // row 3
    if (GridBox[6] == 1)
    {
        Draw(imgX,screen, width * .04,(height-messageheight) * .75);
    }
    else if (GridBox[6] == 2)
    {
        Draw(imgO, screen, width * .04, (height-messageheight) * .75);
    }
    if (GridBox[7] == 1)
    {
        Draw(imgX,screen, width * .38,(height-messageheight) * .75);
    }
    else if (GridBox[7] == 2)
    {
        Draw(imgO, screen, width * .38, (height-messageheight) * .75);
    }
    if (GridBox[8] == 1)
    {
        Draw(imgX,screen, width * .71,(height-messageheight) * .75);
    }
    else if (GridBox[8] == 2)
    {
        Draw(imgO, screen, width * .71, (height-messageheight)* .75);
    }
}
void SDL_PutPixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16 *)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = pixel;
        break;
    }
}
void SDL_DrawLine(SDL_Surface* pDestination, int pX1, int pY1, int pX2, int pY2, Uint32 pColour )
{
    int lenX = pX2 - pX1;
    int lenY = pY2 - pY1;

    float vectorLen = sqrtf(lenX * lenX + lenY * lenY);
    if(vectorLen == 0)
        return;

    float inclineX = lenX / vectorLen;
    float inclineY = lenY / vectorLen;

    float x = (int)pX1;
    float y = (int)pY1;

    bool locked = SDL_MUSTLOCK(pDestination);
    if(locked)
        SDL_LockSurface(pDestination);

    for(int i = 0; i < (int)vectorLen; ++i)
    {
        SDL_PutPixel(pDestination, (int)x, (int)y, pColour);
        x += inclineX;
        y += inclineY;
    }

    if(locked)
        SDL_UnlockSurface(pDestination);
}
void message_panel(SDL_Surface* screen){
SDL_Rect rect = {0, height-60, width, 60};

SDL_FillRect(screen,&rect,100);
}
int main ( int argc, char** argv )
{
    //Keep track of the current frame
    int frame = 0;

    //Whether or not to cap the frame rate
    bool cap = true;

    //The frame rate regulator
    Timer fps;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window;
    SDL_Renderer* renderer;
    SDL_Texture *textureImage = NULL;

    printf("sdl window created\n");
    window = SDL_CreateWindow("TicTacToe-SDL2",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN);
    if (!window){
        printf("Failed to create window\n");
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if ( !renderer )
    {
        printf("Unable to set video: %s\n", SDL_GetError());
        return 1;
    }
    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }

    //testing to make sure screen size changed for later code
    cout << "height: " << height << endl;
    cout << "width: " << width << endl;
    SDL_GetWindowSize(window, &width, &height);
    SDL_Surface* screen = SDL_CreateRGBSurface( 0, width, height, 32, 0, 0, 0, 0 ); 
    cout << "height: " << height << endl;
    cout << "width: " << width << endl;
    
    //I need to find a way to get the true dimensions of the game board so I can properly size the grid squares
    messageheight = 60;
    int screenheight = screen -> h;
    int boardheight = screenheight - messageheight; 
    //make grid squares
    //row 1
//x, y , width, height
    Square gridOne( 0, 0, width/3,(boardheight/3));
    Square gridTwo( width/3, 0,width/3,(boardheight/3));
    Square gridThree( width/3 * 2, 0,width/3,(boardheight/3));
    // row 2
    Square gridFour( 0, boardheight/3,width/3,(boardheight/3));
    Square gridFive( width/3, boardheight/3,width/3,(boardheight/3));
    Square gridSix( width/3 * 2, boardheight/3,width/3,(boardheight/3));
    // row 3
    Square gridSeven( 0, (boardheight/3) * 2,width/3,(boardheight/3));
    Square gridEight( width/3, (boardheight/3) * 2,width/3,(boardheight/3));
    Square gridNine( width/3 * 2, (boardheight/3) * 2,width/3,(boardheight/3));
    SDL_Surface *imgX = IMG_Load("x.png");
    if (!imgX)
    {
        printf("Unable to load PNG: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Surface *imgO = IMG_Load("o.png");
    if (!imgX)
    {
        printf("Unable to load PNG: %s\n", SDL_GetError());
        return 1;
    }

    TTF_Font *font = NULL;

    SDL_Color textColor = {0,255,0 };
    SDL_Surface *message = NULL;
 
    SDL_Surface *end_message = NULL;
    SDL_Surface *replay_message = NULL;

    font = TTF_OpenFont( "argos.ttf", 25 );
    if( !font )
    {
        return false;
    }


    printf("Game Loop Starting\n");
    bool EndGame = false;
    bool done = false;
    // program main loop
    while (!done)
    {
        //win conditions
        //rows
        if (GridBox[0] == 1 && GridBox[1] == 1 && GridBox [2] == 1)
        {
            winner = 1;
            EndGame = true;
        }
        if (GridBox[3] == 1 && GridBox[4] == 1 && GridBox [5] == 1)
        {
            winner = 1;
            EndGame = true;
        }
        if (GridBox[6] == 1 && GridBox[7] == 1 && GridBox [8] == 1)
        {
            winner = 1;
            EndGame = true;
        }
        //columns
        if (GridBox[0] == 1 && GridBox[3] == 1 && GridBox [6] == 1)
        {
            winner = 1;
            EndGame = true;
        }
        if (GridBox[1] == 1 && GridBox[4] == 1 && GridBox [7] == 1)
        {
            winner = 1;
            EndGame = true;
        }
        if (GridBox[2] == 1 && GridBox[5] == 1 && GridBox [8] == 1)
        {
            winner = 1;
            EndGame = true;
        }
        //diagonal
        if (GridBox[2] == 1 && GridBox[4] == 1 && GridBox [6] == 1)
        {
            winner = 1;
            EndGame = true;
        }
        if (GridBox[0] == 1 && GridBox[4] == 1 && GridBox [8] == 1)
        {
            winner = 1;
            EndGame = true;
        }
        //rows player 2
        if (GridBox[0] == 2 && GridBox[1] == 2 && GridBox [2] == 2)
        {
            winner = 2;
            EndGame = true;
        }
        if (GridBox[3] == 2 && GridBox[4] == 2 && GridBox [5] == 2)
        {
            winner = 2;
            EndGame = true;
        }
        if (GridBox[6] == 2 && GridBox[7] == 2 && GridBox [8] == 2)
        {
            winner = 2;
            EndGame = true;
        }
        //columns player 2
        if (GridBox[0] == 2 && GridBox[3] == 2 && GridBox [6] == 2)
        {
            winner = 2;
            EndGame = true;
        }
        if (GridBox[1] == 2 && GridBox[4] == 2 && GridBox [7] == 2)
        {
            winner = 2;
            EndGame = true;
        }
        if (GridBox[2] == 2 && GridBox[5] == 2 && GridBox [8] == 2)
        {
            winner = 2;
            EndGame = true;
        }
        //diagonal player 2
        if (GridBox[2] == 2 && GridBox[4] == 2 && GridBox [6] == 2)
        {
            winner = 2;
            EndGame = true;
        }
        if (GridBox[0] == 2 && GridBox[4] == 2 && GridBox [8] == 2)
        {
            winner = 2;
            EndGame = true;
        }

        //tie
        if (player == 10)
        {
            EndGame = true;
        }
        // message processing loop
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = true;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
            {
                // exit if ESCAPE is pressed
                if (event.key.keysym.sym == SDLK_ESCAPE)
                done = true;
                break;
            }
            case SDL_MOUSEBUTTONDOWN:
            {
                if (!EndGame){
                //handle grid square events
                gridOne.handle_events(1);
                gridTwo.handle_events(2);
                gridThree.handle_events(3);
                gridFour.handle_events(4);
                gridFive.handle_events(5);
                gridSix.handle_events(6);
                gridSeven.handle_events(7);
                gridEight.handle_events(8);
                gridNine.handle_events(9);
                for (int i = 9 - 1; i >= 0; i--) 
                    cout <<GridBox[i];
                }
                cout << endl;
            }
                
            } // end switch
        } // end of message processing
        frame++;

        // DRAWING STARTS HERE
        SDL_FillRect(screen,NULL,SDL_MapRGB ( screen->format, 0, 0, 0 )); 
        message_panel(screen);
        SDL_DrawLine(screen,0, (height/3)-messageheight/2, width, (height/3)-messageheight/2,255);
        SDL_DrawLine(screen,0, (height/3 + height/3)-messageheight/2, width, (height/3 + height/3)-messageheight/2,255);
        SDL_DrawLine(screen,width/3, 0, width/3, height-messageheight,255);
        SDL_DrawLine(screen,width/3+width/3, 0, width/3+width/3, height-messageheight,255);
        // player turn (1 or 2)
        if((player %2) == 1)
        {
            message = TTF_RenderText_Solid( font, "Player 1 Go!", textColor );
            Draw( message, screen, 0 ,height-50 );
        }
        else if((player %2) == 0)
        {
            message = TTF_RenderText_Solid( font, "Player 2 Go!", textColor );
            Draw( message, screen, 0, height-50);
        }

        DrawImage(GridBox, imgX, imgO, screen);
        // DRAWING ENDS HERE
        //Limit frame rate
        if( ( cap == true ) && ( fps.get_ticks() < 1000 / FPS ) )
        {
            //Sleep the remaining frame time
            SDL_Delay( ( 1000 / FPS ) - fps.get_ticks() );
        }
        
        if(EndGame)
        {
            SDL_PollEvent(&event);
            bool replay = false;

            if (winner == 1)
            {
                message = TTF_RenderText_Solid( font, "Player 1 has won!", textColor );
                for(int i = 3; i > 0; i--){
                    s << "Game Starting In: " << i;
                    replay_message = TTF_RenderText_Solid(font, s.str().c_str(), textColor);
                    message_panel(screen);
                    Draw( message, screen, 0, height-50);
                    Draw(replay_message,screen,width/2,height-50);
                    textureImage = SDL_CreateTextureFromSurface(renderer,screen);

                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, textureImage, NULL, NULL);
                    SDL_RenderPresent(renderer);
                    SDL_DestroyTexture(textureImage);
                    cout << "\nGame starting in: " << i << endl;
                    SDL_Delay(1000);
                    s.str(std::string());
                }
                replay = true;
                printf("\nGame Restarting\n");
            }
            else if (winner == 2)
            {
                message = TTF_RenderText_Solid( font, "Player 2 has won!", textColor );
                for(int i = 3; i > 0; i--){
                    s << "Game Starting In: " << i;
                    replay_message = TTF_RenderText_Solid(font, s.str().c_str(), textColor);
                    message_panel(screen);
                    Draw( message, screen, 0, height-50);
                    Draw(replay_message,screen,width/2,height-50);
                    textureImage = SDL_CreateTextureFromSurface(renderer,screen);

                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, textureImage, NULL, NULL);
                    SDL_RenderPresent(renderer);
                    SDL_DestroyTexture(textureImage);
                    cout << "\nGame starting in: " << i << endl;
                    SDL_Delay(1000);
                    s.str(std::string());
                }
                replay = true;
                printf("\nGame Restarting\n");
            }
            else
            {
                message = TTF_RenderText_Solid( font, "This is a tie!", textColor );
                Draw( message, screen, width/3,0);
                for(int i = 3; i > 0; i--){
                    s << "Game Starting In: " << i;
                    replay_message = TTF_RenderText_Solid(font, s.str().c_str(), textColor);
                    message_panel(screen);
                    Draw( message, screen, 0, height-50);
                    Draw(replay_message,screen,width/2,height-50);
                    textureImage = SDL_CreateTextureFromSurface(renderer,screen);

                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, textureImage, NULL, NULL);
                    SDL_RenderPresent(renderer);
                    SDL_DestroyTexture(textureImage);
                    cout << "\nGame starting in: " << i << endl;
                    SDL_Delay(1000);
                    s.str(std::string());
                }
                replay = true;
                printf("\nGame Restarting\n");
            }

            if (replay)
            {
                for(int i = 0; i < 9; i++)
                {
                    GridBox[i] = 0;
                }
                done = false;
                winner = 0;
                replay = false;
                EndGame = false;
                player = 1;
            }

        }

        // finally, update the screen :)
        textureImage = SDL_CreateTextureFromSurface(renderer,screen);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, textureImage, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(textureImage);
    } // end main loop
// free loaded bitmap
    SDL_FreeSurface(imgX);
    SDL_FreeSurface(imgO);
    SDL_FreeSurface(message);
    SDL_FreeSurface(replay_message);
    SDL_FreeSurface(end_message);
    SDL_FreeSurface(screen);
    SDL_DestroyTexture(textureImage);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();


// all is well ;)
    printf("Exited cleanly\n");
    return 0;
}



