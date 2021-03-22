// Phong shader for simple game lighting
#version 410

in vec4 vPosition;
in vec3 vNormal;

uniform vec3 Ka; // Ambient color of the models material
uniform vec3 Kd; // The Diffuse color of the models material
uniform vec3 Ks; // Specular Color
uniform float Ns; // Specular power


uniform vec3 AmbientColor; // Ambient Color of the light
uniform vec3 LightColor; // Color of the light

uniform vec3 LightDirection;

uniform vec3 CameraPosition; // Position Of The Camera for Specular calculations

out vec4 FragColor;

void main(){
    // Make sure the normal and light directions have been normalized
    vec3 N = normalize(vNormal);
    vec3 L = normalize(LightDirection);

    // Now we calculate the lambert term
    float lambertTerm = max(0, min(1,dot(N,-L)));

    // Calculate the view vector and the reflection vector
    vec3 V = normalize(CameraPosition - vPosition.xyz);
    vec3 R = reflect(L,N);

    // Determine the specular term
    float specularTerm = pow(max(0, dot(R, V)), 32);


    // Calcilate the value of the ambient
    vec3 ambient = AmbientColor * Ka;

    // Determine the value of the diffuse
    vec3 diffuse = LightColor * Kd * lambertTerm;

    // Determine the value of the specular 
    vec3 specular = LightColor * Ks * specularTerm;

    // Ouput the final color
    FragColor = vec4(ambient + diffuse + specular,1);

    
}