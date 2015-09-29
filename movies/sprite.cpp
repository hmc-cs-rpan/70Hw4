/**
 * \file sprite.cpp
 * \author Daniel Zhang, Ricky Pan, CS 70 Provided Code
 *
 * \brief Implements the Sprite class
 */

#include <cstddef>
#include <iostream>

#include "sprite.hpp"

using namespace std;

Sprite::Sprite(string fname, size_t x, size_t y, bool scroll): 
               xvalue_(x), yvalue_(y), shouldScroll_(scroll)
             {
                ifstream inputFile{fname};
    
                // Reads in characters from the text file, 
                // copies them into the character array.
                char ch;
                for (size_t i = 0; i < Sprite::WIDTH * Sprite::HEIGHT; ++i)
                {
                    ch = inputFile.get();
                    if (inputFile.good())
                    {
                        spriteArray_[i] = ch;        // Populates spriteArray_
                    }
                }
                inputFile.close();
                cerr <<  "Parameterized sprite constructor called" << endl;
             }

Sprite::Sprite()
{
    // Nothing to do here
}

void Sprite::loadImage(const string& fname) 
{
    ifstream inputFile{fname};
    
    // Reads in characters from the text file, 
    // copies them into the character array.
    char ch;
    for (size_t i = 0; i < Sprite::WIDTH * Sprite::HEIGHT; ++i)
    {
        ch = inputFile.get();
        if (inputFile.good())
        {
            spriteArray_[i] = ch;        // Populates spriteArray_
        }
    }
    inputFile.close();
}


void Sprite::update() 
{   
    if(Sprite::shouldScroll_)
    {
        xvalue_ +=1;
    }
}

size_t Sprite::getXLocation() const
{
    return xvalue_;
}

size_t Sprite::getYLocation() const
{
    return yvalue_;
}

char Sprite::getCharAt(size_t row, size_t col) const
{
    size_t index = row * Sprite::WIDTH + col;
    return spriteArray_[index];
}

void Sprite::setLocation(size_t x, size_t y)
{
    xvalue_ = x;
    yvalue_ = y;
}

void Sprite::setScrolling(bool flag)
{
    shouldScroll_ = flag;
}
