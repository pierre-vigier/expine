#include "SandBox.h"

#include "VertexBufferLayout.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class MyLayer : public Expine::Layer
{
public:
    void OnMount() override
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    float positions[16] = {
        100.0f, 100.0f, 0.0f, 0.0f,
        200.0f, 100.0f, 1.0f, 0.0f,
        200.0f, 200.0f, 1.0f, 1.0f,
        100.0f, 200.0f, 0.0f, 1.0f,
    };

        m_Va = std::make_shared<VertexArray>();
        m_Vb = std::make_shared<VertexBuffer>(positions, 4 * 4 * sizeof(float));

        VertexBufferLayout layout;
        layout.Push<float>(2);
        layout.Push<float>(2);
        m_Va->AddBuffer(*m_Vb, layout);

        unsigned int indices[6] = {
            0, 1, 2,
            2, 3, 0,
        };
        m_Ib = std::make_shared<IndexBuffer>(indices, 6);

        m_Va->SetIndexBuffer(m_Ib);

        m_Shader = std::make_shared<Shader>("../res/shaders/basic.shader");

        m_Texture = std::make_shared<Texture>("../res/textures/steel.png");
        m_Texture->Bind(0);
        m_Shader->Bind();
        m_Shader->SetUniform1i("u_Texture", 0);
    }
    void OnUnmount() override
    {
    }
    void OnUpdate() override
    {
        Renderer renderer;

        glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100, 0, 0));
        glm::vec3 translation(200, 200, 0);
        glm::mat4 model = glm::translate(glm::mat4(1.0f), translation);
        glm::mat4 mvp = proj * view * model;
        m_Shader->Bind();
        m_Shader->SetUniformMat4f("u_MVP", mvp);
        renderer.Draw(*m_Va, *m_Shader);
    }
    void HandleEvent(Event &e) override {
        XP_LOG_INFO("Processing eventin layer");
    }
private:

    std::shared_ptr<VertexArray> m_Va;
    std::shared_ptr<VertexBuffer> m_Vb;
    std::shared_ptr<IndexBuffer> m_Ib;
    std::shared_ptr<Shader> m_Shader;
    std::shared_ptr<Texture> m_Texture;
};

SandBox::SandBox(const std::string &name) : Application(name)
{
    PushLayer(new MyLayer());
}
