#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;

out vec2 v_TexCoord;
out vec4 v_VertPos;

uniform mat4 u_MVP;
uniform mat4 u_modelMat = mat4(1.0);

void main()
{
	gl_Position = u_MVP * position;
	v_TexCoord = texCoord;
	v_VertPos = u_modelMat * position;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;
in vec4 v_VertPos;

uniform vec4 u_Color;
uniform vec2 u_LightPos;
uniform sampler2D u_Texture;

void main()
{
	//vec4 texColor = texture(u_Texture, v_Position.xy * 4);
	//vec4 texColor = texture(u_Texture, vec2(1.0f, 0.0f));
	//vec4 texColor = texture(u_Texture, v_TexCoord);
	//color = texColor + u_Color;

	float intensity = 1.0 / length(v_VertPos.xy - u_LightPos);
	//intensity = clamp(intensity, 0, 1);

	color = vec4(1.0, 0.0, 1.0, 1.0);
	color = u_Color * intensity;
}
