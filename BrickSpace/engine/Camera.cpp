#include "Camera.h"
#include <GLUT/glut.h>
#include <cmath>

void Camera::apply()
{
    float radYaw = yaw * 3.14159f / 180.0f;
    float radPitch = pitch * 3.14159f / 180.0f;

    float camX = targetX + distance * cos(radPitch) * sin(radYaw);
    float camY = targetY + distance * sin(radPitch);
    float camZ = targetZ + distance * cos(radPitch) * cos(radYaw);

    gluLookAt(
        camX, camY, camZ,
        targetX, targetY, targetZ,
        0,1,0
    );
}