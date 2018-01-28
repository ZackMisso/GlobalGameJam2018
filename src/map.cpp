#include <firal/map.h>
#include <firal/shade.h>

Map::Map(int w, int h) : mapWidth(w), mapHeight(h), widthScale(1.f), heightScale(1.f) {
    heightPoints = vector<float>();
    tileTypes = vector<int>();
    initializeFlatHeightMap();
}

Map::~Map() {}

void Map::initializeFlatHeightMap() {
    for (int i = 0; i < mapHeight; ++i)
        for (int j = 0; j < mapWidth; ++j)
            heightPoints.push_back(0.f);
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

void Map::render(Matrix4f vp, Matrix4f invV) {
    MatrixXu indices(3, 2);
    indices.col(0) << 0, 1, 2;
    indices.col(1) << 2, 3, 0;

    Matrix4f model;
    model.setIdentity();

    Matrix4f mvp = vp * model;

    for (int i = 0; i < mapHeight; i++) {
        for (int j = 0; j < mapWidth; j++) {
            if (i == 0 || j == 0) continue;

            // stored as (x, y, h)
            Vector3f tr = Vector3f((float)j * widthScale, (float)i * heightScale, heightPoints[i * mapWidth + j]);
            Vector3f tl = Vector3f((float)(j-1) * widthScale, (float)i * heightScale, heightPoints[i * mapWidth + j]);
            Vector3f br = Vector3f((float)j * widthScale, (float)(i-1) * heightScale, heightPoints[i * mapWidth + j]);
            Vector3f bl = Vector3f((float)(j-1) * widthScale, (float)(i-1) * heightScale, heightPoints[i * mapWidth + j]);

            MatrixXf positions(3, 4);
            positions.col(0) << bl[0], bl[1], bl[2];
            positions.col(1) << br[0], br[1], br[2];
            positions.col(2) << tr[0], tr[1], tr[2];
            positions.col(3) << tl[0], tl[1], tl[2];

            MatrixXf norms(3, 4); // TODO : fix
            norms.col(0) << 0, 1, 0;
            norms.col(1) << 0, 1, 0;
            norms.col(2) << 0, 1, 0;
            norms.col(3) << 0, 1, 0;

            Shade::lambertShader.bind();
        }
    }
    // TODO
}
