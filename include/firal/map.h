#pragma once

#include <firal/common.h>
#include <firal/object.h>

class Map : public Object {
public:
    Map(int w, int h);
    ~Map();

    void initializeFlatHeightMap();
    float getHeight(float x, float y);

    void render();

    virtual void update(float dt);
    virtual void render(Matrix4f vp, Matrix4f invV);

    vector<float> heightPoints;
    vector<int> tileTypes;

    int mapWidth;
    int mapHeight;
    float widthScale;
    float heightScale;
};
