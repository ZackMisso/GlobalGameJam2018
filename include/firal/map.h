#pragma once

#include <firal/common.h>

// should this extend object??
// TODO : make a singleton

class Map {
public:
    Map(int w, int h);
    ~Map();

    void initializeFlatHeightMap();
    float getHeight(float x, float y);

    void render();

    vector<float> heightPoints;
    vector<int> tileTypes;
    
    int mapWidth;
    int mapHeight;
    float widthScale;
    float heightScale;
};
