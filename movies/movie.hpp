/**
 * \file movie.hpp
 * \author Daniel Zhang, Ricky Pan, CS 70 Provided Code
   =========
   Interface definition for the Movie class, which handles the main screen
   and coordination of an ASCIImation movie.

 */
#ifndef MOVIE_HPP_INCLUDED
#define MOVIE_HPP_INCLUDED = 1;

#include "sprite.hpp"


/**
 * \class Movie
 * \brief Holds the contents of an ASCIImation movie
 *
 * \details
 * Stores an array of characters that will be displayed to the screen, and
 * a Sprite that will be added to the screen.
 *
 */
class Movie {
public:

    // Size of the screen, in characters
    static const size_t WIDTH = 80;
    static const size_t HEIGHT = 40;
    

    /**
     * \brief Default constructor of Movie class
     * \pre none
     * \post 
     */
    Movie();

    /**
     * \brief Default constructor of Movie class
     * \pre none
     * \post Doesn't allow movie to be copied
     */
    Movie(Movie& copy) = delete;

    /**
     * \brief Creates the current display showing the sprite
     * \post The current display contents are up to date and
     * ready to display to the screen.
     */
    void updateContents();

    /**
     * \brief Displays a movie on the screen until the user enters "q"
     * \post The screen is destroyed.
     */
    void play();

    /**
     * \brief Displays the current display on the screen
     * \post No change to the movie object
     */
    void display();

    /**
     * \brief Adds a sprite to our movie
     * \post Stores the sprite in the mySprite_ variable
     * \return none
     */
    void addSprite(Sprite& newSprite);

private:

    // The sprite to display in this movie.
    Sprite mySprite_ = new Sprite();
    
    // The characters to display on the screen.
    char movieArray_[WIDTH*HEIGHT];
};

#endif // ifndef MOVIE_HPP_INCLUDED
