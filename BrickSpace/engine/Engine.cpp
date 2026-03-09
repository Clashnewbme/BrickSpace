#include "Engine.h"
#include <GLUT/glut.h>

Engine* Engine::instance = nullptr;

int lastMouseX;
int lastMouseY;
bool rightMouseDown = false;

void displayWrapper()
{
    Engine::instance->render();
}

void updateWrapper()
{
    Engine::instance->update();
    glutPostRedisplay();
}

void keyDown(unsigned char key,int x,int y)
{
    Engine::instance->keys[key] = true;
}

void keyUp(unsigned char key,int x,int y)
{
    Engine::instance->keys[key] = false;
}

void mouseButton(int button,int state,int x,int y)
{
    if(button == GLUT_RIGHT_BUTTON)
    {
        rightMouseDown = (state == GLUT_DOWN);
        lastMouseX = x;
        lastMouseY = y;
    }
}

void mouseMove(int x,int y)
{
    if(!rightMouseDown) return;

    int dx = x - lastMouseX;
    int dy = y - lastMouseY;

    lastMouseX = x;
    lastMouseY = y;

    Engine::instance->camera.yaw += dx * 0.3f;
    Engine::instance->camera.pitch -= dy * 0.3f;

    if(Engine::instance->camera.pitch > 80)
        Engine::instance->camera.pitch = 80;

    if(Engine::instance->camera.pitch < -80)
        Engine::instance->camera.pitch = -80;
}

void Engine::start(int argc, char** argv)
{
    instance = this;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(800,600);
    glutCreateWindow("BrickSpace");

    glEnable(GL_DEPTH_TEST);

    glClearColor(0.5f,0.7f,1.0f,1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0, 800.0/600.0, 0.1, 1000.0);
    glMatrixMode(GL_MODELVIEW);

    workspace.loadExample();

    glutDisplayFunc(displayWrapper);
    glutIdleFunc(updateWrapper);

    glutKeyboardFunc(keyDown);
    glutKeyboardUpFunc(keyUp);

    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);

    glutMainLoop();
}

void Engine::update()
{
    float speed = 0.15f;

    if(keys['w'])
        workspace.player.z -= speed;

    if(keys['s'])
        workspace.player.z += speed;

    if(keys['a'])
        workspace.player.x -= speed;

    if(keys['d'])
        workspace.player.x += speed;

    if(keys[' '] && workspace.player.onGround)
    {
        workspace.player.velocityY = 0.25f;
        workspace.player.onGround = false;
    }

    workspace.update();

    camera.targetX = workspace.player.x;
    camera.targetY = workspace.player.y + 2;
    camera.targetZ = workspace.player.z;
}

void Engine::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    camera.apply();

    workspace.render();

    glutSwapBuffers();
}