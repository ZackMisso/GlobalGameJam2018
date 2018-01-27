#include <firal/shade.h>

nanogui::GLShader Shade::quadShader;

void Shade::initialize() {
    // simple shader for the heat map
    // if (initialized != 0x2151436A) {
    // if (initialized) return;

    // cout << "PRE INITIALIZE SHADER" << endl;

    Shade::quadShader.init(
        /* An identifying name */
        "a_simple_shader",

        /* Vertex shader */
        "#version 330\n"
        "in vec3 position;\n"
        "in vec2 uvs;\n"
        "out vec2 uv;\n"
        "void main() {\n"
        "    uv = uvs;\n"
        "    gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
        "}",

        /* Fragment shader */
        "#version 330\n"
        "out vec4 color;\n"
        "uniform vec3 tl;\n"
        // "uniform vec3 tr;\n"
        // "uniform vec3 bl;\n"
        // "uniform vec3 br;\n"
        "in vec2 uv;\n"
        "void main() {\n"
        // "    vec3 one = (tl * (1.0 - uv.st.x) + tr * (uv.st.x));\n"
        // "    vec3 two = (bl * (1.0 - uv.st.x) + br * (uv.st.x));\n"
        // "    vec3 three = one * (uv.st.y) + two * (1.0 - uv.st.y);\n"
        // "    color = vec4(three / 2.0, 1.0);\n"
        "    color = vec4(tl, 1.0);\n"
        "}"
    );

    // cout << "POST SHADER" << endl;
    // }
}

void Shade::deinitialize() {
    // cout << "In Deinitialize" << endl;
    Shade::quadShader.free();
}
