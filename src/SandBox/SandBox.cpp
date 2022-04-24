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

struct VertexNormal
{
    glm::vec3 position;
    glm::vec3 color;
    glm::vec3 normal;

    static VertexBufferLayout getLayout()
    {
        VertexBufferLayout layout;
        layout.PushFloat(3);
        layout.PushFloat(3);
        layout.PushFloat(3);
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
        glFrontFace(GL_CCW);
        glCullFace(GL_BACK);
        glEnable(GL_DEPTH_TEST);

        VertexNormal cubePositions[24] = { 
    glm::vec3(-0.5f, -0.5f, -0.5f),  glm::vec3(1.f,0.5f,0.31f), glm::vec3(0.0f,  0.0f, -1.0f), //0
    glm::vec3( 0.5f, -0.5f, -0.5f),  glm::vec3(1.f,0.5f,0.31f), glm::vec3(0.0f,  0.0f, -1.0f), //1
    glm::vec3( 0.5f,  0.5f, -0.5f),  glm::vec3(1.f,0.5f,0.31f), glm::vec3(0.0f,  0.0f, -1.0f), //2
    glm::vec3(-0.5f,  0.5f, -0.5f),  glm::vec3(1.f,0.5f,0.31f), glm::vec3(0.0f,  0.0f, -1.0f), //3
    
    glm::vec3(-0.5f, -0.5f,  0.5f),  glm::vec3(1.f,0.5f,0.31f), glm::vec3(0.0f,  0.0f, 1.0f), //4
    glm::vec3( 0.5f, -0.5f,  0.5f),  glm::vec3(1.f,0.5f,0.31f), glm::vec3(0.0f,  0.0f, 1.0f), //5
    glm::vec3( 0.5f,  0.5f,  0.5f),  glm::vec3(1.f,0.5f,0.31f), glm::vec3(0.0f,  0.0f, 1.0f), //6
    glm::vec3(-0.5f,  0.5f,  0.5f),  glm::vec3(1.f,0.5f,0.31f), glm::vec3(0.0f,  0.0f, 1.0f), //7

    glm::vec3(-0.5f, -0.5f, -0.5f),  glm::vec3(1.f,0.5f,0.31f), glm::vec3(0.0f, -1.0f, 0.0f), //8
    glm::vec3( 0.5f, -0.5f, -0.5f),  glm::vec3(1.f,0.5f,0.31f), glm::vec3(0.0f, -1.0f, 0.0f), //9
    glm::vec3( 0.5f, -0.5f,  0.5f),  glm::vec3(1.f,0.5f,0.31f), glm::vec3(0.0f, -1.0f, 0.0f), //10
    glm::vec3(-0.5f, -0.5f,  0.5f),  glm::vec3(1.f,0.5f,0.31f), glm::vec3(0.0f, -1.0f, 0.0f), //11

    glm::vec3(-0.5f,  0.5f, -0.5f),  glm::vec3(1.f,0.5f,0.31f), glm::vec3(0.0f,  1.0f, 0.0f), //12
    glm::vec3( 0.5f,  0.5f, -0.5f),  glm::vec3(1.f,0.5f,0.31f), glm::vec3(0.0f,  1.0f, 0.0f), //13
    glm::vec3( 0.5f,  0.5f,  0.5f),  glm::vec3(1.f,0.5f,0.31f), glm::vec3(0.0f,  1.0f, 0.0f), //14
    glm::vec3(-0.5f,  0.5f,  0.5f),  glm::vec3(1.f,0.5f,0.31f), glm::vec3(0.0f,  1.0f, 0.0f), //15

    glm::vec3(-0.5f,  0.5f,  0.5f),  glm::vec3(1.f,0.5f,0.31f), glm::vec3(-1.0f,  0.0f, 0.0f), //16
    glm::vec3(-0.5f,  0.5f, -0.5f),  glm::vec3(1.f,0.5f,0.31f), glm::vec3(-1.0f,  0.0f, 0.0f), //17
    glm::vec3(-0.5f, -0.5f, -0.5f),  glm::vec3(1.f,0.5f,0.31f), glm::vec3(-1.0f,  0.0f, 0.0f), //18
    glm::vec3(-0.5f, -0.5f,  0.5f),  glm::vec3(1.f,0.5f,0.31f), glm::vec3(-1.0f,  0.0f, 0.0f), //19

    glm::vec3(0.5f,  0.5f,  0.5f),   glm::vec3(1.f,0.5f,0.31f), glm::vec3(1.0f,  0.0f, 0.0f), //20
    glm::vec3(0.5f,  0.5f, -0.5f),   glm::vec3(1.f,0.5f,0.31f), glm::vec3(1.0f,  0.0f, 0.0f), //21
    glm::vec3(0.5f, -0.5f, -0.5f),   glm::vec3(1.f,0.5f,0.31f), glm::vec3(1.0f,  0.0f, 0.0f), //22
    glm::vec3(0.5f, -0.5f,  0.5f),   glm::vec3(1.f,0.5f,0.31f), glm::vec3(1.0f,  0.0f, 0.0f), //23
};
        unsigned int cubeIndices[36] = {
            0,2,1,0,3,2, //back face with normal
            4,5,6,6,7,4, //front face with normal
            8,9,10,10,11,8,//bottom face with normal
            12,14,13,12,15,14,//top face with normal
            16,17,18,18,19,16,//left face with normal
            20,22,21,20,23,22,//right face with normal
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
        unsigned int lightIndices[36] = {
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
        m_Vb = std::make_shared<VertexBuffer>(cubePositions, sizeof(cubePositions));
        m_lightVb = std::make_shared<VertexBuffer>(lightPositions, 8 * sizeof(Vertex));

        m_Va->AddBuffer(*m_Vb, VertexNormal::getLayout());
        m_lightVa->AddBuffer(*m_lightVb, Vertex::getLayout());

        m_Ib = std::make_shared<IndexBuffer>(cubeIndices, sizeof(cubeIndices) / sizeof(unsigned int));
        m_lightIb = std::make_shared<IndexBuffer>(lightIndices, 36);

        m_Va->SetIndexBuffer(m_Ib);
        m_lightVa->SetIndexBuffer(m_lightIb);

        m_Shader = std::make_shared<Shader>("../res/shaders/basic.shader");
        m_lightShader = std::make_shared<Shader>("../res/shaders/light.shader");

        // m_Texture = std::make_shared<Texture>("../res/textures/steel.png");
        // m_Texture->Bind(0);
        //m_Shader->Bind();
        // m_Shader->SetUniform1i("u_Texture", 0);
        m_Camera.SetPosition(1.5f,0.f,5.f);
    }
    void OnUnmount() override
    {
    }
    void OnUpdate(float elapsed) override
    {
        m_Camera.OnUpdate(elapsed);
        static float Angle = 1.0f;
        Angle -= 0.02f;
        Angle = fmod(Angle, glm::two_pi<float>());
        static float lightAngle = 0.0f;
        lightAngle += 0.01f;
        lightAngle = fmod(lightAngle, glm::two_pi<float>());
        glm::vec3 lightPos{2.f,1.f,0.f};
        lightPos = glm::vec3(
            glm::rotate(glm::mat4(1.f),lightAngle,glm::vec3(0.0,1.0,0.0))
            * glm::vec4(lightPos, 1.f)
        );

        //glm::mat4 proj = glm::ortho(-2.f, 2.f, -2.f, 2.f, -0.0f, 1.0f);
        //glm::mat4 proj = glm::perspective(90.0f, 960.f/540.f, 0.1f, 100.0f);
        //glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0.f));
        glm::mat4 viewProjection = m_Camera.GetMatrix();
        glm::vec3 translation(0, 0, 0);
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, translation);
        model = glm::rotate(model, Angle, glm::vec3(1.0f, 1.0f, 0.0f));
        m_Shader->Bind();
        m_Shader->SetUniformMat4f("u_VP", viewProjection);
        m_Shader->SetUniformMat4f("u_Model", model);
        m_Shader->SetUniformVec3f("u_LightColor", glm::vec3(1.f, 1.0f, 1.f));
        m_Shader->SetUniformVec3f("u_LightPos", lightPos);
        m_Shader->SetUniformVec3f("u_ViewPos", m_Camera.GetPosition());
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
