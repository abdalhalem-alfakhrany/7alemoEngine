#version 330 core

out vec4 FragColor;

in vec2 texCords;
in float texId;

uniform sampler2D[9] textures;

void main() {
  // FragColor = vec4(1, 0, 1, 1);

  vec4 textureColor;
  
  if (texId == 0.0f) {
    textureColor = texture(textures[0], texCords);
  } else if (texId == 1.0f) {
    textureColor = texture(textures[1], texCords);
  } else if (texId == 2.0f) {
    textureColor = texture(textures[2], texCords);
  } else if (texId == 3.0f) {
    textureColor = texture(textures[3], texCords);
  } else if (texId == 4.0f) {
    textureColor = texture(textures[4], texCords);
  } else if (texId == 5.0f) {
    textureColor = texture(textures[5], texCords);
  } else if (texId == 6.0f) {
    textureColor = texture(textures[6], texCords);
  } else if (texId == 7.0f) {
    textureColor = texture(textures[7], texCords);
  } else if (texId == 8.0f) {
    textureColor = texture(textures[8], texCords);
  }
  
  if(textureColor.a < 0.1){
    discard;
  }
  FragColor = textureColor;
}