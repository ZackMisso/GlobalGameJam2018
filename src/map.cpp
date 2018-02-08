#include <firal/map.h>
#include <firal/shade.h>
#include <firal/random.h>

Map::Map(int w, int h) : mapWidth(w), mapHeight(h), widthScale(10.f), heightScale(10.f) {
    heightPoints = vector<float>();
    tileTypes = vector<int>();
    initializeFlatHeightMap();
}

Map::~Map() {}

void Map::initializeFlatHeightMap() {
    for (int i = 0; i < mapHeight; ++i)
        for (int j = 0; j < mapWidth; ++j) {
            // heightPoints.push_back(0.f);
            heightPoints.push_back(Random::getDouble());
        }
    for (int i = 1; i < mapHeight; ++i)
        for (int j = 1; j < mapHeight; ++j)
            tileTypes.push_back(0);
}

// this will have issues when if the map is transformed....
float Map::getHeight(float x, float y) {
    // simple interpolation
    // float maxWidth = mapWidth * widthScale;
    // float maxHeight = mapHeight * heightScale;

    float tx = x / widthScale;
    float ty = y / heightScale;

    int minx = floor(tx);
    int maxx = ceil(tx);
    int miny = floor(ty);
    int maxy = ceil(ty);

    // can save computation time here later
    float tl = heightPoints[minx + widthScale * miny];
    float tr = heightPoints[maxx + widthScale * miny];
    float bl = heightPoints[minx + widthScale * maxy];
    float br = heightPoints[maxx + widthScale * maxy];

    float ix = (tx - minx) / (maxx - minx);
    float iy = (ty - miny) / (maxy - miny);

    float one = (tr - tl) * ix + tl;
    float two = (br - bl) * ix + bl;

    float height = (two - one) * iy + one;

    return height;


    // float height = (ix) * heightPoints(pos(minx,miny));
}

void Map::update(float dt) {
    // TODO
}

// TODO - REWRITE
void Map::render(Matrix4f vp, Matrix4f invV) {
    MatrixXu indices(3, 2);
    indices.col(0) << 0, 1, 2;
    indices.col(1) << 2, 3, 0;

    Matrix4f model;
    model.setIdentity();

    Matrix4f mvp = vp * model;

    Vector3f lightPos = Vector3f(0.f, 4.f, 0.f);

    for (int i = 0; i < mapHeight; i++) {
        for (int j = 0; j < mapWidth; j++) {
            if (i == 0 || j == 0) continue;

            // stored as (x, y, h)
            Vector3f tr = Vector3f((float)j * widthScale, (float)i * heightScale, heightPoints[i * mapWidth + j]);
            Vector3f tl = Vector3f((float)(j-1) * widthScale, (float)i * heightScale, heightPoints[i * mapWidth + (j-1)]);
            Vector3f br = Vector3f((float)j * widthScale, (float)(i-1) * heightScale, heightPoints[(i-1) * mapWidth + j]);
            Vector3f bl = Vector3f((float)(j-1) * widthScale, (float)(i-1) * heightScale, heightPoints[(i-1) * mapWidth + (j-1)]);

            float xOffset = mapWidth * widthScale / 2.f;
            float yOffset = mapHeight * heightScale / 2.f;

            MatrixXf positions(3, 4);
            positions.col(0) << bl[0] - xOffset, bl[2], bl[1] - yOffset;
            positions.col(1) << br[0] - xOffset, br[2], br[1] - yOffset;
            positions.col(2) << tr[0] - xOffset, tr[2], tr[1] - yOffset;
            positions.col(3) << tl[0] - xOffset, tl[2], tl[1] - yOffset;

            MatrixXf norms(3, 4); // TODO : fix
            norms.col(0) << 0, 1, 0;
            norms.col(1) << 0, 1, 0;
            norms.col(2) << 0, 1, 0;
            norms.col(3) << 0, 1, 0;

            float color = (float)(i * mapWidth + j) / (float)heightPoints.size();

            Vector3f kd = Vector3f(color, 0.f, 1.f - color);
            Vector3f ka = Vector3f(0.0f, 0.4f, 0.0f);

            Shade::lambertShader.bind();
            Shade::lambertShader.uploadIndices(indices);
            Shade::lambertShader.uploadAttrib("pos", positions);
            Shade::lambertShader.uploadAttrib("norm", norms);
            Shade::lambertShader.setUniform("lightPos", lightPos);
            Shade::lambertShader.setUniform("ka", ka);
            Shade::lambertShader.setUniform("kd", kd);
            Shade::lambertShader.setUniform("mvpMatrix", mvp); // fix
            Shade::lambertShader.setUniform("mMatrix", model); // fix
            Shade::lambertShader.setUniform("nMatrix", mvp); // fix

            Shade::lambertShader.drawIndexed(GL_TRIANGLES, 0, 2);
        }
    }
    // TODO
}
