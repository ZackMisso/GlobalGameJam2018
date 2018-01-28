#include <firal/tree.h>
#include <firal/util.h>
#include <firal/shade.h>
#include <firal/render.h>

Tree::Tree() {
    trunkSize = 1.0f;
    heightScale = 0.68f;
    height = 4;

    leavesMaterial = new Material();
    trunkMaterial = new Material();

    leavesMaterial->setShaderType(SH_PHONG);
    leavesMaterial->setKA(Vector3f(0.0f, 0.1f, 0.0f));
    leavesMaterial->setKD(Vector3f(0.1f, 0.9f, 0.2f));
    leavesMaterial->setKS(Vector3f(0.0f, 1.0f, 0.0f));
    leavesMaterial->setN(60.f);

    trunkMaterial->setShaderType(SH_LAMBERT);
    trunkMaterial->setKA(Vector3f(0.0f, 0.0f, 0.0f));
    trunkMaterial->setKD(Vector3f(165.f / 255.f, 42.f / 255.f, 42.f / 255.f));
    // trunkMaterial->setKS(Vector3f(0.0f, 1.0f, 0.0f));
    // trunkMaterial->setN(60.f);
}

void Tree::update(float dt) {
    // does nothing
    // cout << "WHAT" << endl;
}

// TODO : make this not happen every frame
void Tree::render(Matrix4f vp, Matrix4f invV) {
    Matrix4f trunkModel;
    vector<Matrix4f> leavesModel;

    trunkModel.setIdentity();
    for (int i = 0; i < height; i++) {
        Matrix4f tmp;
        tmp.setIdentity();
        leavesModel.push_back(tmp);
    }

    float initialScale = 1.0;

    Matrix4f trans = translate(position[0], position[1], position[2]);

    trunkModel = trans * scale(initialScale, initialScale, initialScale);
    // trunkModel = scale(1.0, 1.0, 1.0);

    float ytrans = 0.6f;
    float width = initialScale * 1.5;
    float oldWidth = initialScale;
    for (int i = 0; i < height; i++) {
        leavesModel[i] = trans * translate(0.f, ytrans + width, 0.f) * scale(width, width, width);
        oldWidth = width;
        width *= heightScale;
        ytrans += 1.9 * oldWidth;
        // ytrans += 2.0 * width;
        // width *= heightScale;
    }

    Vector3f lightPos = Vector3f(0.f, 0.f, -5.f);

    Shade::lambertShader.bind();
    Shade::lambertShader.uploadIndices(Render::cube_inds);
    Shade::lambertShader.uploadAttrib("pos", Render::cube_verts);
    Shade::lambertShader.uploadAttrib("norm", Render::cube_norms);
    Shade::lambertShader.setUniform("lightPos", lightPos);

    Matrix4f model = trunkModel;
    Matrix4f mvp = vp * model;
    Matrix4f normMat = model.inverse().transpose();

    trunkMaterial->bindMaterialData();
    // leavesMaterial->bindMaterialData();
    // Shade::lambertShader.setUniform("invView", invV);

    Shade::lambertShader.setUniform("mvpMatrix", mvp);
    Shade::lambertShader.setUniform("mMatrix", model);
    Shade::lambertShader.setUniform("nMatrix", normMat);

    Shade::lambertShader.drawIndexed(GL_TRIANGLES, 0, 12);

    Shade::phongShader.bind();
    Shade::phongShader.uploadIndices(Render::cube_inds);
    Shade::phongShader.uploadAttrib("pos", Render::cube_verts);
    Shade::phongShader.uploadAttrib("norm", Render::cube_norms);
    Shade::phongShader.setUniform("invViewMatrix", invV);
    Shade::phongShader.setUniform("lightPos", lightPos);

    leavesMaterial->bindMaterialData();

    for (int i = 0; i < leavesModel.size(); i++) {
        model = leavesModel[i];
        mvp = vp * model;
        normMat = model.inverse().transpose();

        Shade::phongShader.setUniform("mvpMatrix", mvp);
        Shade::phongShader.setUniform("mMatrix", model);
        Shade::phongShader.setUniform("nMatrix", normMat);
        Shade::phongShader.drawIndexed(GL_TRIANGLES, 0, 12);
    }

    // // Shade::phongShader.setUniform("mvpMatrix", mvp);
    // // Shade::phongShader.setUniform("mMatrix", model);
    // // Shade::phongShader.setUniform("nMatrix", normMat);
    // Shade::phongShader.drawIndexed(GL_TRIANGLES, 0, 12);
    //
    // // Shade::phongShader.setUniform("mvpMatrix", mvp);
    // // Shade::phongShader.setUniform("mMatrix", model);
    // // Shade::phongShader.setUniform("nMatrix", normMat);
    // Shade::phongShader.drawIndexed(GL_TRIANGLES, 0, 12);
}
