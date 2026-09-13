#pragma once
#include<GLFW/glfw3.h>

// Waiting for key press 'Escape' to exit the program

void waitForEscape(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, 1);
    }
}