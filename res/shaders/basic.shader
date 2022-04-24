#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 vcolor;
layout(location = 2) in vec3 vnormal;

out vec3 v_Color;
out vec3 v_Normal;
out vec3 v_Pos;

uniform mat4 u_VP;
uniform mat4 u_Model;

void main()
{
    gl_Position = u_VP * u_Model * vec4(position, 1.0);
    v_Color = vcolor;
    v_Normal = mat3(transpose(inverse(u_Model))) * vnormal;
    //v_Normal = vnormal;
    v_Pos = vec3(u_Model * vec4(position, 1.0));
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec3 v_Color;
in vec3 v_Normal;
in vec3 v_Pos;

// uniform vec4 u_Color;
// uniform sampler2D u_Texture;
uniform vec3 u_LightColor;
uniform vec3 u_LightPos;
uniform vec3 u_ViewPos;

void main()
{
    float ambientStrength = 0.1;
    float specularStrength = 0.5;

    vec3 ambient = ambientStrength * u_LightColor;

    vec3 norm = normalize(v_Normal);
    vec3 lightDir = normalize(u_LightPos - v_Pos);
    float diff = max(dot(norm,lightDir), 0.0);
    vec3 diffuse = diff * u_LightColor;

    vec3 viewDir = normalize(u_ViewPos - v_Pos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * u_LightColor;  

    vec3 result = ( ambient + diffuse + specular ) * v_Color;

    color = vec4( result, 1.0);
} 