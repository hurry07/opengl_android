uniform mat4 u_pvmMatrix;

attribute vec4 a_position;
attribute vec2 a_texCoord;
attribute vec4 a_color;

//varying mediump vec2 v_texCoord;
//varying mediump vec2 v_color;

varying vec2 v_texCoord;
varying vec4 v_color;

void main()												
{
    gl_Position = u_pvmMatrix * a_position;
	v_texCoord = a_texCoord;
	v_color = a_color;
}
