/**
 * \file movie.cpp
 * \author Daniel Zhang, Ricky Pan, CS 70 Provided Code
   =========
 *
 * \brief Implements the Movie class
 */

#include <iostream>
#include <ncurses.h>
#include <unistd.h>

#include "movie.hpp"
#include "sprite.hpp"

using namespace std;

Movie::Movie(size_t maxSprites): maxSprites_(maxSprites)
{
    numSprites_ = 0;
    // mySprites_ is a pointer to an array of pointers.
    mySprites_ = new Sprite* [maxSprites_];
    cerr << "Movie() constructor called" << endl;
}

void Movie::updateContents() 
{
    // Clears the character array by writing a space to each element
    for(size_t i = 0; i < Movie::WIDTH * Movie::HEIGHT; ++i)
    {
        movieArray_[i] = ' ';
    }

    for(size_t i = 0; i < numSprites_; ++i)
    {

        Sprite& currSprite = *mySprites_[i];
        //Updates currSprite's location if shouldScroll_ is true
        currSprite.update();

        // Loops through all of the characters in the sprite and copies them to 
        // the right spot in the movie's character array.

        size_t currSpriteX = currSprite.getXLocation();
        size_t currSpriteY = currSprite.getYLocation();

        for(size_t row = 0; row < currSprite.getHeight(); ++row)
        {
            for(size_t col = 0; col < currSprite.getWidth(); ++col)
            {
                char ch = currSprite.getCharAt(row, col);
                
                // movieRow * Movie::WIDTH returns the starting index of a given row
                // in movieArray_. We find the correct index by adding movieCol.
                // mod Movie::WIDTH accounts for xvalues greater than the screen
                // width and allows the sprite to wrap around.
                // If it's a space, don't copy the character.
                if(ch != ' ')
                {
                     size_t movieRow = currSpriteY + row;
                     size_t movieCol = (currSpriteX + col) % Movie::WIDTH;

                     size_t movieIndex =  movieRow * Movie::WIDTH + movieCol;

                    // cerr << "movie index is " << movieIndex << endl;
                    // cerr << ch << endl;

                    movieArray_[movieIndex] = ch;
                }
            }
        }
    }
}

/**
 * Initializes the screen for ncurses, then repeatedly updates the screen until
 * the user exits by pressing 'q'.
 */
void Movie::play() 
{

    const int PAUSE_TIME_IN_MICROSECONDS = 40000;

    // Initialize the screen
    initscr();

    // Don't echo characters entered by the user
    noecho();

    // Make the cursor invisible
    curs_set(0);

    // Tell ncurses not to block waiting for user input on getch() calls.
    nodelay(stdscr, TRUE);

    // We're not using the cursor, so tell ncurses to leave it wherever our
    // updates happen to put it.
    leaveok(stdscr, TRUE);

    // Leave the cursor on the bottom line of the screen instead of scrolling
    // if one of our updates would put it off-screen.
    scrollok(stdscr, FALSE);


    // Play the movie by refreshing the screen with new data, every so often
    int ch;
    bool finished = false;

    while (not(finished)) {
        // Copy contents to the screen
        updateContents(); // Get updated character values from the sprite object
        display();        // Copy the movie's characters to the screen's buffer
        refresh();        // Refresh the screen

        // Sleep between updates
        usleep(PAUSE_TIME_IN_MICROSECONDS);

        // Check to see if the user has entered 'q' to quit yet
        ch = getch();
        if (ch == 'q') {
            finished = true;
        }
    }

    // Put the cursor back to beginning of the last row of the terminal, where
    // we expect it to be when the program exits.
    mvcur(0, COLS - 1, LINES - 1, 0);

    // Restore the saved shell terminal before exiting.
    endwin();
}

void Movie::display() 
{
    // Loops through all of the characters in the movie's character array and
    // copies them to the right place on the screen, using the ncurses function
    // mvaddch: mvaddch(r, c, char) puts the character char at row r, column c
    // of the screen.

    for(size_t row = 0; row < Movie::HEIGHT; ++row)
    {
        for(size_t col = 0; col < Movie::WIDTH; ++col)
        {
            char ch = movieArray_[row * Movie::WIDTH + col];
            mvaddch(row, col, ch);
        }
    }

}

void Movie::addSprite(string filename, size_t x, size_t y, bool scroll)
{
    // Creates a new sprite in the heap
    Sprite * toAdd = new Sprite(filename, x, y, scroll);

    cerr << "addSprite" << numSprites_ << endl;

    if(numSprites_ < maxSprites_)
    {
        mySprites_[numSprites_] = toAdd;
    }

    // If the array isn't big enough, doubles the size of mySprites_
    else
    {   
        Sprite ** bigArray = new Sprite*[2*maxSprites_];

        // Copy the elements of mySprites_ into the bigger array
        for(size_t i = 0; i < maxSprites_; ++i)
        {
            bigArray[i] = mySprites_[i];
        }

        // Adds the last sprite into bigArray
        bigArray[maxSprites_] = toAdd;
        

        for(size_t i = 0; i < maxSprites_; ++i)
        {
            delete mySprites_[i];
        }
        maxSprites_ *= 2;

        mySprites_ = bigArray;
    }

    numSprites_ += 1;
}

Movie::~Movie()
{
    for(size_t i = 0; i < maxSprites_; ++i)
    {
        delete mySprites_[i];
    }
    delete [] mySprites_;
}


