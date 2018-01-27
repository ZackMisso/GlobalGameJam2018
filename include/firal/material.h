#pragma once

#include <firal/common.h>

class Material {
public:
    Material();

    void bindMaterialData();

    SHADER_TYPE getShaderType();
    Vector3f getKA();
    Vector3f getKS();
    Vector3f getKD();
    float getN();

    void setShaderType(SHADER_TYPE param);
    void setKA(Vector3f param);
    void setKS(Vector3f param);
    void setKD(Vector3f param);
    void setN(float param);

protected:
    SHADER_TYPE shaderType;
    Vector3f ka;
    Vector3f ks;
    Vector3f kd;
    float n;
};
