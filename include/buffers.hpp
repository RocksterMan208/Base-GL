#pragma once
#include<glad/glad.h>

class VBO // In any classes which create then upload a mesh, please create a pointer towards this class
{
    public:
        GLuint ID;
        VBO(const void* vertices, GLsizeiptr size);

        void Bind();
        void Unbind();
        void Delete();
};

class VAO
{
    public:
        GLuint ID;
        VAO();

        void LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
        void Bind();
        void Unbind();
        void Delete();
};

class EBO // In any classes which create then upload a mesh, please create a pointer towards this class
{
    public:
        GLuint ID;
        EBO(const void*, GLsizeiptr size);

        void Bind();
        void Unbind();
        void Delete();
};