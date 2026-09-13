#pragma once
#include<glad/glad.h>

class VBO
{
    public:
        GLuint ID;
        VBO(GLfloat* vertices, GLsizeiptr size);

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

class EBO
{
    public:
        GLuint ID;
        EBO(GLint* indices, GLsizeiptr size);

        void Bind();
        void Unbind();
        void Delete();
};