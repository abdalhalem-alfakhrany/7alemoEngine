#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCords;
layout(location = 2) in float atexId;

out vec2 texCords;
out float texId;

uniform mat4 projection;
uniform mat4 view;

void main() {
  gl_Position = projection * view * vec4(aPos, 1.0f);
  texCords = aTexCords;
  texId = atexId;
}