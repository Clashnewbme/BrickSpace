#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include "Part.h"

class Character
{
public:

    float x;
    float y;
    float z;

    float width;
    float height;
    float depth;

    std::vector<Part> parts;

    Character();

    void move(float dx, float dz);
    void draw();
};

#endif