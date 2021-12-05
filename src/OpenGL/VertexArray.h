#pragma once

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include <memory>

class VertexBufferLayout;

class VertexArray
{
private:
    unsigned int m_RendererID;
    std::shared_ptr<IndexBuffer> m_IndexBuffer;
public:
    VertexArray();    
    ~VertexArray();

    void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
    void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer);

    const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const { return m_IndexBuffer;}
    void Bind() const;
    void Unind() const;
};