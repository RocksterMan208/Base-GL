#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

#include"shaders.h"

class Camera
{
public:
    glm::vec3 position;
    glm::vec3 direction = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 upDir = glm::vec3(0.0f, 1.0f, 0.0f);

    int width;
    int height;

    float cameraSpeed = 0.1f;
    float cameraSens = 0.1f;

    float yaw;

    Camera(int width, int height, glm::vec3 position);

    void Matrix(float FOVyDeg, float nearPlane, float farPlane, Shader& shader, const char* uniform, glm::mat4 model);
    void ProcessInputs(GLFWwindow* window);

    private:
    bool  firstMouse = true;
    double lastX = 0.0;
    double lastY = 0.0;
    float lastFrameTime = 0.0f;

    bool mouseEnabled = true;
};

#endif