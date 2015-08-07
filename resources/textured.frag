#version 130

uniform sampler2D tex;

in vec2 textureCoord;

out vec4 finalColor;

void main() 
{
    //note: the texture function was called texture2D in older versions of GLSL
    finalColor = texture(tex, textureCoord);
}

