#include "SandBox.h"

#include "Renderer/Renderer.h"
#include "Renderer/Camera.h"
#include "VertexBufferLayout.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

struct Vertex
{
    glm::vec3 position;
    glm::vec3 color;
    glm::vec2 uv;

    static VertexBufferLayout getLayout()
    {
        VertexBufferLayout layout;
        layout.PushFloat(3);
        layout.PushFloat(3);
        layout.PushFloat(2);
        return layout;
    }
};

class MyLayer : public Expine::Layer
{
public:
    void OnMount() override
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_CULL_FACE);
        //glFrontFace(GL_CW);
        glCullFace(GL_BACK);
        glEnable(GL_DEPTH_TEST);

        // Vertex positions[8] = {
        //     glm::vec3(0.5f, 0.5f, 0.5f),
        //     glm::vec3(0.0f, 1.0f, 0.0f),
        //     glm::vec2(0.0f, 0.0f),
        //     glm::vec3(-0.5f, 0.5f, -0.5f),
        //     glm::vec3(1.0f, 0.0f, 0.0f),
        //     glm::vec2(1.0f, 0.0f),
        //     glm::vec3(-0.5f, 0.5f, 0.5f),
        //     glm::vec3(0.0f, 0.0f, 1.0f),
        //     glm::vec2(1.0f, 1.0f),
        //     glm::vec3(0.5f, -0.5f, -0.5f),
        //     glm::vec3(1.0f, 1.0f, 0.0f),
        //     glm::vec2(0.0f, 1.0f),
        //     glm::vec3(-0.5f, -0.5f, -0.5f),
        //     glm::vec3(0.0f, 1.0f, 1.0f),
        //     glm::vec2(0.0f, 0.0f),
        //     glm::vec3(0.5f, 0.5f, -0.5f),
        //     glm::vec3(1.0f, 0.0f, 1.0f),
        //     glm::vec2(1.0f, 0.0f),
        //     glm::vec3(0.5f, -0.5f, 0.5f),
        //     glm::vec3(1.0f, 1.0f, 1.0f),
        //     glm::vec2(1.0f, 1.0f),
        //     glm::vec3(-0.5f, -0.5f, 0.5f),
        //     glm::vec3(0.0f, 0.0f, 0.0f),
        //     glm::vec2(0.0f, 1.0f),
        // };
        Vertex positions[8] = {
            glm::vec3(0.5f, 0.5f, 0.5f),
            glm::vec3(1.0f, 0.5f, 0.31f),
            glm::vec2(0.0f, 0.0f),
            glm::vec3(-0.5f, 0.5f, -0.5f),
            glm::vec3(1.0f, 0.5f, 0.31f),
            glm::vec2(1.0f, 0.0f),
            glm::vec3(-0.5f, 0.5f, 0.5f),
            glm::vec3(1.0f, 0.5f, 0.31f),
            glm::vec2(1.0f, 1.0f),
            glm::vec3(0.5f, -0.5f, -0.5f),
            glm::vec3(1.0f, 0.5f, 0.31f),
            glm::vec2(0.0f, 1.0f),
            glm::vec3(-0.5f, -0.5f, -0.5f),
            glm::vec3(1.0f, 0.5f, 0.31f),
            glm::vec2(0.0f, 0.0f),
            glm::vec3(0.5f, 0.5f, -0.5f),
            glm::vec3(1.0f, 0.5f, 0.31f),
            glm::vec2(1.0f, 0.0f),
            glm::vec3(0.5f, -0.5f, 0.5f),
            glm::vec3(1.0f, 0.5f, 0.31f),
            glm::vec2(1.0f, 1.0f),
            glm::vec3(-0.5f, -0.5f, 0.5f),
            glm::vec3(1.0f, 0.5f, 0.31f),
            glm::vec2(0.0f, 1.0f),
        };
        Vertex lightPositions[8] = {
            glm::vec3(0.5f, 0.5f, 0.5f),
            glm::vec3(1.f, 1.f, 1.f),
            glm::vec2(0.0f, 0.0f),
            glm::vec3(-0.5f, 0.5f, -0.5f),
            glm::vec3(1.f, 1.f, 1.f),
            glm::vec2(0.0f, 0.0f),
            glm::vec3(-0.5f, 0.5f, 0.5f),
            glm::vec3(1.f, 1.f, 1.f),
            glm::vec2(0.0f, 0.0f),
            glm::vec3(0.5f, -0.5f, -0.5f),
            glm::vec3(1.f, 1.f, 1.f),
            glm::vec2(0.0f, 0.0f),
            glm::vec3(-0.5f, -0.5f, -0.5f),
            glm::vec3(1.f, 1.f, 1.f),
            glm::vec2(0.0f, 0.0f),
            glm::vec3(0.5f, 0.5f, -0.5f),
            glm::vec3(1.f, 1.f, 1.f),
            glm::vec2(0.0f, 0.0f),
            glm::vec3(0.5f, -0.5f, 0.5f),
            glm::vec3(1.f, 1.f, 1.f),
            glm::vec2(0.0f, 0.0f),
            glm::vec3(-0.5f, -0.5f, 0.5f),
            glm::vec3(1.f, 1.f, 1.f),
            glm::vec2(0.0f, 0.0f),
        };
        unsigned int indices[36] = {
            0, 1, 2,
            1, 3, 4,
            5, 6, 3,
            7, 3, 6,
            2, 4, 7,
            0, 7, 6,
            0, 5, 1,
            1, 5, 3,
            5, 0, 6,
            7, 4, 3,
            2, 1, 4,
            0, 2, 7};

        m_Va = std::make_shared<VertexArray>();
        m_lightVa = std::make_shared<VertexArray>();
        m_Vb = std::make_shared<VertexBuffer>(positions, 8 * sizeof(Vertex));
        m_lightVb = std::make_shared<VertexBuffer>(lightPositions, 8 * sizeof(Vertex));

        m_Va->AddBuffer(*m_Vb, Vertex::getLayout());
        m_lightVa->AddBuffer(*m_lightVb, Vertex::getLayout());

        m_Ib = std::make_shared<IndexBuffer>(indices, 36);
        m_lightIb = std::make_shared<IndexBuffer>(indices, 36);

        m_Va->SetIndexBuffer(m_Ib);
        m_lightVa->SetIndexBuffer(m_lightIb);

        m_Shader = std::make_shared<Shader>("../res/shaders/basic.shader");
        m_lightShader = std::make_shared<Shader>("../res/shaders/light.shader");

        // m_Texture = std::make_shared<Texture>("../res/textures/steel.png");
        // m_Texture->Bind(0);
        //m_Shader->Bind();
        // m_Shader->SetUniform1i("u_Texture", 0);
        m_Camera.SetPosition(0.f,0.f,5.f);
    }
    void OnUnmount() override
    {
    }
    void OnUpdate(float elapsed) override
    {
        m_Camera.OnUpdate(elapsed);
        static float Angle = 0.0f;
        Angle += 0.01f;
        Angle = fmod(Angle, glm::two_pi<float>());
        glm::vec3 lightPos{2.f,1.f,0.f};

        //glm::mat4 proj = glm::ortho(-2.f, 2.f, -2.f, 2.f, -0.0f, 1.0f);
        //glm::mat4 proj = glm::perspective(90.0f, 960.f/540.f, 0.1f, 100.0f);
        //glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0.f));
        glm::mat4 viewProjection = m_Camera.GetMatrix();
        glm::vec3 translation(0, 0, 0);
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, translation);
        model = glm::rotate(model, Angle, glm::vec3(1.0f, 1.0f, 0.0f));
        glm::mat4 mvp = viewProjection * model;
        m_Shader->Bind();
        m_Shader->SetUniformMat4f("u_MVP", mvp);
        m_Shader->SetUniformVec3f("u_LightColor", glm::vec3(0.f, 1.0f, 0.f));
        Renderer::Submit(*m_Va, *m_Shader);

        glm::mat4 mMatrix = glm::mat4(1.0f);
        mMatrix = glm::translate(mMatrix, lightPos);
        mMatrix = glm::scale(mMatrix,glm::vec3(0.2f));
        glm::mat4 mvp2 = viewProjection * mMatrix;
        m_lightShader->Bind();
        m_lightShader->SetUniformMat4f("u_MVP", mvp2);
        Renderer::Submit(*m_lightVa, *m_lightShader);

    }
    void HandleEvent(Event &e) override
    {
        // XP_LOG_INFO("Processing eventin layer");
        m_Camera.HandleEvent(e);
    }

private:
    std::shared_ptr<VertexArray> m_Va;
    std::shared_ptr<VertexBuffer> m_Vb;
    std::shared_ptr<IndexBuffer> m_Ib;
    std::shared_ptr<Shader> m_Shader;
    std::shared_ptr<Texture> m_Texture;

    std::shared_ptr<VertexArray> m_lightVa;
    std::shared_ptr<VertexBuffer> m_lightVb;
    std::shared_ptr<IndexBuffer> m_lightIb;
    std::shared_ptr<Shader> m_lightShader;

    PerspectiveCamera m_Camera{};
};

SandBox::SandBox(const std::string &name) : Application(name)
{
    PushLayer(new MyLayer());
}
