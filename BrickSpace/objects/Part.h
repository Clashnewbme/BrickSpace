#ifndef PART_H
#define PART_H

class Part
{
public:

    float x;
    float y;
    float z;

    float w;
    float h;
    float d;

    Part(float px, float py, float pz, float width, float height, float depth);

    void draw();
};

#endif