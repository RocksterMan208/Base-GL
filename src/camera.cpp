#include "camera.h"

Camera::Camera(int width, int height, glm::vec3 Position)
{
    Camera::width = width;
    Camera::height = height;
    position = Position;
}

void Camera::Matrix(float FOVyDeg, float nearPlane, float farPlane, Shader& shader, const char* uniform, glm::mat4 model)
{
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    view = glm::lookAt(position, position + direction, upDir);
    projection = glm::perspective(static_cast<float>(glm::radians(FOVyDeg)), static_cast<float>(width) / static_cast<float>(height), nearPlane, farPlane);

    glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(projection * view * model));
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
}

void Camera::ProcessInputs(GLFWwindow* window)
{
    glm::vec3 forward = glm::normalize(glm::vec3(direction.x, 0.0f, direction.z));
    glm::vec3 right   = glm::vec3(-forward.z, 0.0f, forward.x);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        position += cameraSpeed * forward;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        position += cameraSpeed * -forward;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        position += cameraSpeed * -right;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        position += cameraSpeed * right;
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
    {
        position += cameraSpeed * upDir;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
    {
        position += cameraSpeed * -upDir;
    }

    if (mouseEnabled)
    {
        double mouseX, mouseY;
        glfwGetCursorPos(window, &mouseX, &mouseY);

        if (firstMouse)
        {
            lastX = mouseX;
            lastY = mouseY;
            firstMouse = false;
        }

        float mouseXRate = cameraSens * static_cast<float>(mouseX - lastX);
        float mouseYRate = cameraSens * static_cast<float>(mouseY - lastY);
        lastX = mouseX;
        lastY = mouseY;

        glm::vec3 newDir = glm::rotate(direction, glm::radians(-mouseYRate), glm::normalize(glm::cross(direction, upDir)));

        float angleToUp = glm::degrees(glm::angle(newDir, upDir));
        if (angleToUp > 5.0f && angleToUp < 175.0f)
        {
            direction = newDir;
        }

        direction = glm::rotate(direction, glm::radians(-mouseXRate), upDir);
    }
}