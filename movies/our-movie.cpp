/**
 * \file our-movie.hpp
 * \author Daniel Zhang, Ricky Pan, CS 70 Provided Code
   =========
 * \brief Provides the main() function for running one of the movies
 * defined in movieScripts.cpp.
 */

#include <iostream>
#include "movie.hpp"
#include "sprite.hpp"

using namespace std;

// Creates and loads a sprite from our pacman file.
// Creates a movie and adds the sprite.  Then plays the movie.
// Sprite should move across the screen until the user presses "q"
void makeOurMovie() 
{
    Sprite mySprite;

    mySprite.setScrolling(true);

    mySprite.loadImage("img/pacman.txt");
    mySprite.setLocation(30,10);

    Movie myMovie;
    myMovie.addSprite(mySprite);

    myMovie.play();

}


int main()
{
    makeOurMovie();
    return 0;
}
