#pragma once

#include <vector>

class Part;

class Character
{
public:

    float x = 0;
    float y = 3;
    float z = 0;

    float width = 1;
    float height = 3;
    float depth = 1;

    float velocityY = 0;

    bool onGround = false;

    void update(std::vector<Part>& parts);
    void render();

};