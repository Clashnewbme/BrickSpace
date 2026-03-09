#pragma once

#include "../scene/Workspace.h"
#include "Camera.h"

class Engine
{
public:

    static Engine* instance;

    Workspace workspace;
    Camera camera;

    bool keys[256] = {false};

    void start(int argc, char** argv);

    void update();
    void render();

};