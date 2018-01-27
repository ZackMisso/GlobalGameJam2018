#include <firal/material.h>
#include <firal/shade.h>

Material::Material() {
    ka = 0.3f * Vector3f(1.f, 0.5f, 0.5f);
    ks = Vector3f(0.4f, 0.4f, 0.4f);
    kd = 0.7f * Vector3f(1.f, 0.5f, 0.5f);
    n = 60.f;
}

// bind should not be called in here
void Material::bindMaterialData() {
    if (shaderType == SH_SIMPLE) {
        // no material data
    } else if (shaderType == SH_PHONG) {
        Shade::lambertShader.setUniform("ka", ka);
        Shade::lambertShader.setUniform("kd", kd);
        Shade::lambertShader.setUniform("n", n);
    } else if (shaderType == SH_LAMBERT) {
        Shade::phongShader.setUniform("ka", ka);
        Shade::phongShader.setUniform("kd", kd);
        Shade::phongShader.setUniform("n", n);
        Shade::phongShader.setUniform("ks", ks);
    }
}

SHADER_TYPE Material::getShaderType() { return shaderType; }
Vector3f Material::getKA() { return ka; }
Vector3f Material::getKD() { return kd; }
Vector3f Material::getKS() { return ks; }
float Material::getN() { return n; }

void Material::setShaderType(SHADER_TYPE param) { shaderType = param; }
void Material::setKA(Vector3f param) { ka = param; }
void Material::setKD(Vector3f param) { kd = param; }
void Material::setKS(Vector3f param) { ks = param; }
void Material::setN(float param) { n = param; }
