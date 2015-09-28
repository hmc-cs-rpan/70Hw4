/**
 * \file sprite.hpp
 * \author Daniel Zhang, Ricky Pan, CS 70 Provided Code
   =========
   interface definition for the Sprite class. Defines the behavior
   of a single asciimation 'character'
 */

#ifndef SPRITE_HPP_INCLUDED
#define SPRITE_HPP_INCLUDED 1;

#include <iostream>
#include <fstream>

/**
 * \class Sprite
 * \brief Holds the contents of a single ASCIImation sprite
 *
 * \details
 * Stores an array of characters that will be displayed to the screen, along
 * with the sprite's current location.
 *
 * \remarks
 *    The implemented code only works for a fixed size sprite.
 *
 */
class Sprite {
public:
    // Size of the sprite, in characters
    static const size_t WIDTH = 40;
    static const size_t HEIGHT = 10;

    /**
     * \brief Constructor for the Sprite class
     * \pre
     * \post Creates a Sprite with all the private variables instantiated
     */
    Sprite(std::string fname, size_t x, size_t y, bool scroll);

    /**
     * \brief Modifies the location of the sprite by adding 1 to xvalue_
     * if shouldScroll_ is true
     * 
     * \post The sprite may have moved right.
     */
    void update();

    /**
     * \brief Reads a text file containing the characters for a sprite.
     * \post populates the sprite's character array.
     */
    void loadImage(const std::string& fname);

    /**
     * \brief Accessor function to the sprite's x location.
     * \returns Returns a size_t containing the sprite's x location.
     */
    size_t getXLocation();

    /**
     * \brief Accessor function to the sprite's y location.
     * \return Returns a size_t containing the sprite's y location.
     */
    size_t getYLocation();

    /**
     * \brief Accessor function to the sprite's character array.
     * \return Returns the character at a specified row and column.
     */
    char getCharAt(size_t row, size_t col);



private:
    // Current location of the sprite on the screen in (x, y) form.
    size_t xvalue_;
    size_t yvalue_;

    // Characters to display on the screen for this sprite
    char spriteArray_[WIDTH*HEIGHT];

    // Boolean that tells whether the sprite is moving.
    bool shouldScroll_;
    
    /**
     * \brief Modifer function to change the sprite's location.
     * \post Sprite's location changes to user-specified location.
     * \return none
     */
    void setLocation(size_t x, size_t y);

    /**
     * \brief Modifer function to change sprite scrolling status
     * \post Changes sprite's scrolling status to specified input
     * \return none
     */
     void setScrolling(bool flag);
};

#endif // ifndef SPRITE_HPP_INCLUDED
