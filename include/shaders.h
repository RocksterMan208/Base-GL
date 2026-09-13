#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

std::string getFileContents(const char* fileName);

class Shader
{
    public:
        GLuint ID;
        Shader(const char* vertexFilePath, const char* fragFilePath);

        void Activate();
        void Delete();

        void compileErrors(unsigned int shader, const char* type);
};