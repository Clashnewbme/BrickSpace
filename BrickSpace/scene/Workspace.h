#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <vector>
#include "../objects/Part.h"
#include "../objects/Character.h"

class Workspace
{
public:

    std::vector<Part> parts;
    Character player;

    Workspace();

    void draw();
    bool checkCollision(float x, float z);
};

#endif