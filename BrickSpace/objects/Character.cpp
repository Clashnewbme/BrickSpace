#include "Character.h"
#include <GLUT/glut.h>
#include <vector>

Character::Character()
{
    x = 0;
    y = 1;
    z = 0;

    width = 1.0f;
    height = 2.0f;
    depth = 1.0f;
}

void Character::move(float dx, float dz)
{
    x += dx;
    z += dz;
}

void Character::draw()
{
    glPushMatrix();

    glTranslatef(x, y, z);

    // these are all the body part s, for example this is the torso, change the colors if you want ig idk
    glColor3f(0.2f,0.6f,1.0f);
    glPushMatrix();
    glScalef(1,1.2,0.5);
    glutSolidCube(1);
    glPopMatrix();

    // head
    glColor3f(1,0.8f,0.6f);
    glPushMatrix();
    glTranslatef(0,1,0);
    glutSolidSphere(0.35,20,20);
    glPopMatrix();

    // left arm
    glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(-0.75,0.3,0);
    glScalef(0.3,1,0.3);
    glutSolidCube(1);
    glPopMatrix();

    // right arm
    glPushMatrix();
    glTranslatef(0.75,0.3,0);
    glScalef(0.3,1,0.3);
    glutSolidCube(1);
    glPopMatrix();

    // left leg
    glColor3f(0,0,1);
    glPushMatrix();
    glTranslatef(-0.3,-1,0);
    glScalef(0.4,1,0.4);
    glutSolidCube(1);
    glPopMatrix();

    // right leg
    glPushMatrix();
    glTranslatef(0.3,-1,0);
    glScalef(0.4,1,0.4);
    glutSolidCube(1);
    glPopMatrix();

    glPopMatrix();
}
