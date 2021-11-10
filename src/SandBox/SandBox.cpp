#include "SandBox.h"

#include "VertexBufferLayout.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

SandBox::SandBox(const std::string &name) : Application(name)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    m_Va = std::make_shared<VertexArray>();
    m_Vb = std::make_shared<VertexBuffer>(positions, 4 * 4 * sizeof(float));

    VertexBufferLayout layout;
    layout.Push<float>(2);
    layout.Push<float>(2);
    m_Va->AddBuffer(*m_Vb, layout);

    m_Ib = std::make_shared<IndexBuffer>(indices, 6);

    m_Shader = std::make_shared<Shader>("../res/shaders/basic.shader");

    m_Texture = std::make_shared<Texture>("../res/textures/steel.png");
    m_Texture->Bind(0);
    m_Shader->Bind();
    m_Shader->SetUniform1i("u_Texture", 0);
}

void SandBox::OnUpdate()
{
    Renderer renderer;

    glClearColor(1.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
    glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100, 0, 0));
    glm::vec3 translation(200, 200, 0);
    glm::mat4 model = glm::translate(glm::mat4(1.0f), translation);
    glm::mat4 mvp = proj * view * model;
    m_Shader->Bind();
    m_Shader->SetUniformMat4f("u_MVP", mvp);
    renderer.Draw(*m_Va, *m_Ib, *m_Shader);
}
