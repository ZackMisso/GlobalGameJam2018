#include <firal/shade.h>

nanogui::GLShader Shade::quadShader;
nanogui::GLShader Shade::simpleShader;
nanogui::GLShader Shade::phongShader;
nanogui::GLShader Shade::lambertShader;

void Shade::initialize() {
    // simple shader for the heat map
    // if (initialized != 0x2151436A) {
    // if (initialized) return;

    // cout << "PRE INITIALIZE SHADER" << endl;

    Shade::quadShader.init(
        /* An identifying name */
        "a_simple_quad_shader",

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

    // cout << "WHOA" << endl;

    Shade::simpleShader.init(
        /* An identifying name */
        "a_simple_shader",

        /* Vertex shader */
        "#version 330\n"
        "uniform mat4 modelViewProj;\n"
        "in vec3 position;\n"
        "void main() {\n"
        "    gl_Position = modelViewProj * vec4(position, 1.0);\n"
        "}",

        /* Fragment shader */
        "#version 330\n"
        "out vec4 color;\n"
        "uniform float intensity;\n"
        "void main() {\n"
        "    color = vec4(vec3(intensity), 1.0);\n"
        "}"
    );

    Shade::phongShader.init(
        "a_phong_shader",

        /* Vertex shader */
        "uniform mat4 mvpMatrix;\n"
        "uniform mat4 mMatrix;\n"
        "uniform mat4 nMatrix;\n"
        "\n"
        "attribute vec3 pos;\n"
        "attribute vec3 norm;\n"
        "\n"
        "varying vec3 vWorldPos;\n"
        "varying vec3 vNorm;\n"
        "\n"
        "void main() {\n"
        "   vWorldPos = (mMatrix * vec4(pos, 1.0)).xyz;\n"
        "   vNorm = (nMatrix * vec4(norm, 0.0)).xyz;\n"
        "   \n"
        "   gl_Position = mvpMatrix * vec4(pos, 1.0);\n"
        "}",

        /* Fragment shader */
        "uniform vec3 lightPos;\n"
        "const vec3 lightInt = vec3(100);\n"
        "uniform vec3 ka;\n"
        "uniform vec3 kd;\n"
        "uniform vec3 ks;\n"
        "uniform float n;\n"
        "\n"
        "uniform mat4 invViewMatrix;\n"
        "varying vec3 vWorldPos;\n"
        "varying vec3 vNorm;\n"
        "\n"
        "void main() {\n"
        "   vec3 camPos = (invViewMatrix * vec4(0, 0, 0, 1)).xyz;\n"
        "   vec3 norm = normalize(vNorm);\n"
        "   vec3 camDir = normalize(camPos - vWorldPos);\n"
        "   vec3 lightDir = lightPos - vWorldPos;\n"
        "   float lMagSq = dot(lightDir, lightDir);\n"
        "   lightDir = normalize(lightDir);\n"
        "   vec3 h = normalize(camDir + lightDir);\n"
        "   vec3 lambert = kd * max(dot(norm, lightDir), 0.0);\n"
        "   vec3 blinnPhong = ks * pow(max(dot(norm, h), 0.0), n);\n"
        "   vec3 response = ka * lightInt / lMagSq * (lambert + blinnPhong);\n"
        "   gl_FragColor = vec4(response, 1.0);\n"
        "}"
    );

    Shade::lambertShader.init(
        "a_lambert_shader",

        /* Vertex shader */
        "uniform mat4 mvpMatrix;\n"
        "uniform mat4 mMatrix;\n"
        "uniform mat4 nMatrix;\n"
        "\n"
        "attribute vec3 pos;\n"
        "attribute vec3 norm;\n"
        "\n"
        "varying vec3 vWorldPos;\n"
        "varying vec3 vNorm;\n"
        "\n"
        "void main() {\n"
        "   vWorldPos = (mMatrix * vec4(pos, 1.0)).xyz;\n"
        "   vNorm = (nMatrix * vec4(norm, 0.0)).xyz;\n"
        "   \n"
        "   gl_Position = mvpMatrix * vec4(pos, 1.0);\n"
        "}",

        /* Fragment shader */
        "const vec3 lightInt = vec3(100);\n"
        "uniform vec3 lightPos;\n"
        "uniform vec3 ka;\n"
        "uniform vec3 kd;\n"
        "\n"
        "uniform mat4 invViewMatrix;\n"
        "varying vec3 vWorldPos;\n"
        "varying vec3 vNorm;\n"
        "\n"
        "void main() {\n"
        "   vec3 camPos = (invViewMatrix * vec4(0, 0, 0, 1)).xyz;\n"
        "   vec3 norm = normalize(vNorm);\n"
        "   vec3 camDir = normalize(camPos - vWorldPos);\n"
        "   vec3 lightDir = lightPos - vWorldPos;\n"
        "   float lMagSq = dot(lightDir, lightDir);\n"
        "   lightDir = normalize(lightDir);\n"
        "   vec3 h = normalize(camDir + lightDir);\n"
        "   vec3 lambert = kd * max(dot(norm, lightDir), 0.0);\n"
        "   vec3 response = ka * lightInt / lMagSq * (lambert);\n"
        "   gl_FragColor = vec4(response, 1.0);\n"
        "}"
    );

    // cout << "POST SHADER" << endl;
    // }
}

void Shade::deinitialize() {
    // cout << "In Deinitialize" << endl;
    Shade::quadShader.free();
    Shade::simpleShader.free();
    Shade::phongShader.free();
}
