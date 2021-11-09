#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

#include "Renderer.h"

VertexArray::VertexArray()
{
    GLCall(glGenVertexArrays(1, &m_RendereID));
    GLCall(glBindVertexArray(m_RendereID));
}

VertexArray::~VertexArray()
{
    GLCall(glDeleteTransformFeedbacks(1,&m_RendereID));
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
    Bind();
    vb.Bind();
    const auto& elements = layout.GetElements();
    unsigned int offset = 0;
    for(unsigned int i = 0; i < elements.size(); i++)
    {
        const auto& element = elements[i];
        GLCall(glEnableVertexAttribArray(i));
        // index 0 of vertex array bound to current bound array buffer
        GLCall(glVertexAttribPointer(i, element.count, element.type,
            element.normalized, layout.getStride(), (const void*)(uintptr_t)(offset)) );
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }

}

void VertexArray::Bind() const
{
    GLCall(glBindVertexArray(m_RendereID));
}

void VertexArray::Unind() const
{
    GLCall(glBindVertexArray(0));
}
