#include <firal/tree.h>
#include <firal/util.h>
#include <firal/shade.h>
#include <firal/render.h>

Tree::Tree() {
    trunkSize = 1.0f;
    heightScale = 0.5f;
    height = 3;

    leavesMaterial = new Material();
    trunkMaterial = new Material();
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

    trunkModel = firal_scale(1.0, 1.0, 1.0);

    float ytrans = 1.f;
    float width = 1.25;
    for (int i = 0; i < height; i++) {
        leavesModel[i] = firal_translate(0.f, ytrans, 0.f) * firal_scale(width, width, width);
        ytrans += width;
        width *= heightScale;
    }

    Vector3f lightPos = Vector3f(0.f, 0.f, -5.f);

    Shade::phongShader.bind();
    Shade::phongShader.uploadIndices(Render::cube_inds);
    Shade::phongShader.uploadAttrib("pos", Render::cube_verts);
    Shade::phongShader.uploadAttrib("norm", Render::cube_norms);
    Shade::phongShader.setUniform("invViewMatrix", invV);
    Shade::phongShader.setUniform("lightPos", lightPos);

    Matrix4f model = trunkModel;
    Matrix4f mvp = vp * model;
    Matrix4f normMat = model.inverse().transpose();

    Shade::phongShader.setUniform("mvpMatrix", mvp);
    Shade::phongShader.setUniform("mMatrix", model);
    Shade::phongShader.setUniform("nMatrix", normMat);
    Shade::phongShader.drawIndexed(GL_TRIANGLES, 0, 12);

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
