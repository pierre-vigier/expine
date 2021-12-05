#pragma once

#include <vector>
#include <GL/glew.h>

struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int GetSizeOfType(unsigned int type)
    {
        switch (type)
        {
            case GL_FLOAT:          return sizeof(GLfloat);
            case GL_UNSIGNED_INT:   return sizeof(GLuint);
            case GL_UNSIGNED_BYTE:  return sizeof(GLubyte);
        }
        //TODO : ASSERT(false);
        return 0;
    }
};

class VertexBufferLayout
{
private:
    std::vector<VertexBufferElement> m_Elements;
    unsigned int m_Stride;

public:
    VertexBufferLayout() : m_Stride(0) {}

    template<typename T>
    void Push(unsigned int count)
    {
        // static_assert(false);
    };

    // void PushFloat(unsigned int count)
    // {
    //     m_Elements.push_back({GL_FLOAT, count, GL_FALSE});
    //     m_Stride += VertexBufferElement::GetSizeOfType(GL_FLOAT) * count;
    // }

    // void PushUint(unsigned int count)
    // {
    //     m_Elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
    //     m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT) * count;
    // }

    // void PushUChar(unsigned int count)
    // {
    //     m_Elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
    //     m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE) * count;
    // }

    inline unsigned int getStride() const { return m_Stride; }
    inline const std::vector<VertexBufferElement> GetElements() const { return m_Elements; }
};