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
    Movie myMovie(3);

    myMovie.addSprite("img/mystery1.txt", 20, 10, true);
    myMovie.addSprite("img/mystery1.txt", 20, 30, true);

    myMovie.play();

}


int main()
{
    makeOurMovie();
    return 0;
}
