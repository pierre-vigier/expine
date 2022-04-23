#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 vcolor;
layout(location = 2) in vec2 texCoord;

out vec3 v_Color;
out vec2 v_TexCoord;

uniform mat4 u_MVP;

void main()
{
    gl_Position = u_MVP * vec4(position, 1.0);
    v_Color = vcolor;
    v_TexCoord = texCoord;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec3 v_Color;
in vec2 v_TexCoord;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
    // vec4 texColor = texture(u_Texture,v_TexCoord);
    // texColor = vec4(1.0,0.0,0.0,1.0);
    color = vec4(v_Color, 1.0);
} 