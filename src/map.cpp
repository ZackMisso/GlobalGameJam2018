#include <firal/map.h>

Map::Map(int w, int h) : mapWidth(w), mapHeight(h), widthScale(1.f), heightScale(1.f) {
    heightPoints = vector<float>();
    tileTypes = vector<int>();
    initializeFlatHeightMap();
}

Map::~Map() {}

void Map::initializeFlatHeightMap() {
    for (int i = 0; i < mapHeight; ++i)
        for (int j = 0; j < mapWidth; ++j)
            heightPoints.push_back(1.f);
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

void Map::render() {
    // TODO
}
