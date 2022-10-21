#version 330 core

out vec4 FragColor;

in float Height;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D textureHeight;

void main()
{
    color = texture(textureHeight, TexCoord);
};

