#include "SandBox.h"

#include "VertexBufferLayout.h"
#include "Texture.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

SandBox::SandBox(const std::string& name): Application(name) {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    m_Va = std::make_shared<VertexArray>();
    m_Vb = std::make_shared<VertexBuffer>(positions, 4 * 4 * sizeof(float));

    VertexBufferLayout layout;
    layout.Push<float>(2);
    layout.Push<float>(2);

    m_Ib = std::make_shared<IndexBuffer>(indices, 6);

    m_Shader = std::make_shared<Shader>("../res/shaders/basic.shader");

    Texture texture("../res/textures/steel.png");
    texture.Bind(0);
    m_Shader->Bind();
    m_Shader->SetUniform1i("u_Texture",0);
}

void SandBox::OnUpdate() 
{
//     float positions[16] = {
//         100.0f, 100.0f, 0.0f, 0.0f,
//         200.0f, 100.0f, 1.0f, 0.0f,
//         200.0f, 200.0f, 1.0f, 1.0f,
//         100.0f, 200.0f, 0.0f, 1.0f,
//     };

//     unsigned int indices[] = {
//         0, 1, 2,
//         2, 3, 0,
//     };
//     VertexArray va;
//     VertexBuffer vb(positions, 4 * 4 * sizeof(float));
//     // va.AddBuffer(vb);

//     VertexBufferLayout layout;
//     layout.Push<float>(2);
//     layout.Push<float>(2);
//     va.AddBuffer(vb, layout);

//     IndexBuffer ib(indices, 6);

//    Shader shader = Shader("../res/shaders/basic.shader");
//     shader.Bind();
//     //shader.SetUniform4f("u_Color", 0.8f, 0.5f, 0.0f, 1.0f);

//     Texture texture("../res/textures/steel.png");
//     texture.Bind(0);
//     shader.Bind();
//     shader.SetUniform1i("u_Texture",0);

//     va.Unind();
//     vb.Unbind();
//     ib.Unbind();
//     shader.Unbind();

// Renderer renderer;

    glClearColor(1.0,0.0,0.0,1.0);glClear(GL_COLOR_BUFFER_BIT);

    glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f,-1.0f, 1.0f);
    glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100, 0,0));
    glm::vec3 translation(200,200,0);
    glm::mat4 model = glm::translate(glm::mat4(1.0f), translation);
    glm::mat4 mvp = proj * view * model;
        // shader.Bind();
        //shader.SetUniform4f("u_Color", r, 0.5f, 0.0f, 1.0f);
        // shader.SetUniformMat4f("u_MVP", mvp);
// renderer.Draw(va,ib,shader);

   m_Shader->Bind();
   m_Shader->SetUniformMat4f("u_MVP", mvp);

   m_Va->Bind();
   m_Ib->Bind();

   glDrawElements(GL_TRIANGLES, m_Ib->GetCount(), GL_UNSIGNED_INT, nullptr);
    // Renderer renderer;
    // renderer.Clear();
    // renderer.Draw(*m_Va, *m_Ib, *m_Shader);
}
