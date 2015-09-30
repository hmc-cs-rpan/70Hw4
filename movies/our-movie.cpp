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

// Creates a movie and adds sprites.  Then plays the movie.
// Movie should play until the user presses "q"
void makeOurMovie() 
{
    size_t MAX_SPRITES = 10;
    Movie myMovie(MAX_SPRITES);

    myMovie.addSprite("img/background.txt", 0, 0, false);
    myMovie.addSprite("img/discoball.txt", 32, 0, false);
    myMovie.addSprite("img/pacman.txt", 0, 20, true);
    myMovie.addSprite("img/ymca_y.txt", 30, 20, true);
    myMovie.addSprite("img/ymca_a.txt", 45, 20, true);
    myMovie.addSprite("img/ymca_y.txt", 60, 20, true);


    myMovie.play();

}


int main()
{
    makeOurMovie();
    return 0;
}
