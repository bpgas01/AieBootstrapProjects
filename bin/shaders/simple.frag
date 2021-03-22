// a simple shader for flat colours
#version 410

out vec4 FragColor;

uniform vec4 randcolor;

void main(){
    FragColor = randcolor;
}