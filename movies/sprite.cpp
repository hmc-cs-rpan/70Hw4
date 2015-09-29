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

                // stores first two lines of image as width_ and height_ 
                width_ = readDim(inputFile);
                height_ = readDim(inputFile);

                spriteArray_ = new char[width_*height_];

                loadImage(inputFile);
                cerr <<  "Parameterized sprite constructor called" << endl;
             }

void Sprite::loadImage(ifstream& inputFile) 
{
    // Reads in characters from the ifstream
    // copies them into the character array.
    char ch;

    for (size_t i = 0; i < width_ * height_; ++i)
    {
        ch = inputFile.get();

        if (inputFile.good())
        {
            spriteArray_[i] = ch;        // Populates spriteArray_
        }
    }
    inputFile.close();
}

// atoi + c.str() implementation cited from
// stackoverflow.com/question/7663709/convert-string-to-int-c
size_t Sprite::readDim(ifstream& file)
{
    // iterates through characters of the file until a new line
    // turns the string of digits into a size_t
    string charHolder = "";
    char ch = file.get();

    while(ch != '\n')
    {
        charHolder += ch;
        ch = file.get();
    }
    return atoi(charHolder.c_str());
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

size_t Sprite::getWidth() const
{
    return width_;
}

size_t Sprite::getHeight() const
{
    return height_;
}

char Sprite::getCharAt(size_t row, size_t col) const
{
    size_t index = row * width_ + col;
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

Sprite::~Sprite()
{
    delete [] spriteArray_;
}

