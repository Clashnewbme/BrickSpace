#include "Part.h"
#include <GLUT/glut.h>

Part::Part(float px, float py, float pz, float width, float height, float depth)
{
    x = px;
    y = py;
    z = pz;

    w = width;
    h = height;
    d = depth;
}

void Part::draw()
{
    glPushMatrix();

    glTranslatef(x, y, z);

    glScalef(w, h, d);

    glColor3f(0.6f,0.6f,0.6f);

    glutSolidCube(1);

    glPopMatrix();
}