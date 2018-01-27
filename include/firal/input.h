#pragma once

#include <firal/common.h>

class Input {
public:
    Input();

    bool getMouseLeftDown();
    bool getMouseLeftUp();

    bool getMouseRightDown();
    bool getMouseRightUp();

    bool getWKeyDown();
    bool getWKeyUp();

    bool getAKeyDown();
    bool getAKeyUp();

    bool getSKeyDown();
    bool getSKeyUp();

    bool getDKeyDown();
    bool getDKeyUp();

    bool getRArrowKeyDown();
    bool getRArrowKeyUp();

    bool getLArrowKeyDown();
    bool getLArrowKeyUp();

    bool getDArrowKeyDown();
    bool getDArrowKeyUp();

    bool getUArrowKeyDown();
    bool getUArrowKeyUp();

    bool getOneKeyDown();
    bool getOneKeyUp();

    bool getTwoKeyDown();
    bool getTwoKeyUp();

    bool getThreeKeyDown();
    bool getThreeKeyUp();


    void setMouseLeft(bool param);
    void setMouseRight(bool param);
    void setWKey(bool param);
    void setAKey(bool param);
    void setSKey(bool param);
    void setDKey(bool param);
    void setRArrowKey(bool param);
    void setLArrowKey(bool param);
    void setDArrowKey(bool param);
    void setUArrowKey(bool param);
    void setOneKey(bool param);
    void setTwoKey(bool param);
    void setThreeKey(bool param);

protected:
    bool mouseLeft;
    bool mouseRight;
    bool wKey;
    bool aKey;
    bool sKey;
    bool dKey;
    bool rArrowKey;
    bool lArrowKey;
    bool uArrowKey;
    bool dArrowKey;
    bool oneKey;
    bool twoKey;
    bool threeKey;
};
