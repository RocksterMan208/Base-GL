#pragma once
#include<GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include"camera.h"

void waitForEscape(GLFWwindow* window) // Waiting for key press 'Escape' to exit the program
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, 1);
    }
}

int checkChangeF(float variable) // Checks whether a variable has been changed from its set value. Especially useful for configuring variables through ImGUI
{
    static float lastVariable = variable;
    if (lastVariable != variable)
    {
        lastVariable = variable;
        return 1;
    }
    return 0;
}

void initImGui(GLFWwindow* window) // Place after window creation/initialization stage
{
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
    ImGui_ImplOpenGL3_Init();
}

void startImGuiFrame(Camera* camera) // Place after pollEvents() function
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    
    ImGui::Begin("ImGui window");

    ImGui::Text("Camera Position:");
    ImGui::DragFloat("X", &camera->position.x, 1.0f, -FLT_MAX, FLT_MAX, "%.3f");
    ImGui::DragFloat("Y", &camera->position.y, 1.0f, -FLT_MAX, FLT_MAX, "%.3f");
    ImGui::DragFloat("Z", &camera->position.z, 1.0f, -FLT_MAX, FLT_MAX, "%.3f");

    ImGui::End();
}

void endImGuiFrame() // Place before glSwapBuffers() function
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    // (Your code calls glfwSwapBuffers() etc.)
}

void imGuiEnd() // Place in shutdown
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}