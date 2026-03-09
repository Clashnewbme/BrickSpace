#include "Workspace.h"

Workspace::Workspace()
{
    parts.push_back(Part(0,0,0,20,1,20));
}

void Workspace::draw()
{
    for(auto &p : parts)
        p.draw();

    player.draw();
}

bool Workspace::checkCollision(float x, float z)
{
    for(auto &p : parts)
    {
        if(x > p.x - p.w/2 && x < p.x + p.w/2 &&
           z > p.z - p.d/2 && z < p.z + p.d/2)
        {
            return true;
        }
    }

    return false;
}