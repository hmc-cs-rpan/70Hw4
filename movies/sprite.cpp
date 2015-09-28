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

size_t Sprite::getXLocation()
{
    return xvalue_;
}

size_t Sprite::getYLocation()
{
    return yvalue_;
}

char Sprite::getCharAt(size_t row, size_t col)
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
