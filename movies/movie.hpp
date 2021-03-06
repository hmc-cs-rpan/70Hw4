/**
 * \file movie.hpp
 * \author Daniel Zhang, Ricky Pan, CS 70 Provided Code
 * \help from Prof Medero, Brian Cheng, and grutors Eric and Lisa
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
 * Stores an array of pointers to Sprites that will be displayed to the screen,
 * the number of sprites, the size of the array, and the character array.
 *
 */
class Movie {
public:

    // Size of the screen, in characters
    static const size_t WIDTH = 80;
    static const size_t HEIGHT = 40;
    

    /**
     * \brief constructor of the Movie class
     * \pre maxSprites is a positive integer
     * \post creates a movie with a sprite array of
     * size maxSprites.  Sets numSprites_ to 0.
     */
    Movie(size_t maxSprites);

    Movie() = delete;

    ~Movie();

    Movie(Movie& copy) = delete;

    Movie& operator= (const Movie&);

    /**
     * \brief Creates the current display showing the sprites
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
     * \pre filename is a string with an image of a sprite.
     * requires the same fields as the sprite constructor.
     * \post adds the sprite's pointer to the array mySprites_
     * \return none
     */
    void addSprite(std::string filename, size_t x, size_t y, bool scroll);

private:

    // A pointer to an array of pointers to Sprites
    Sprite * * mySprites_;

    // Maximum sprites a movie can hold
    size_t maxSprites_;

    // Current number of sprites in the movie
    size_t numSprites_;
    
    // The characters to display on the screen.
    char movieArray_[WIDTH*HEIGHT];
    

};

#endif // ifndef MOVIE_HPP_INCLUDED
