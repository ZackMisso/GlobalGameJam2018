#include <firal/input.h>

Input::Input() {
    mouseLeft = false;
    mouseRight = false;
    wKey = false;
    aKey = false;
    sKey = false;
    dKey = false;
    rArrowKey = false;
    lArrowKey = false;
    uArrowKey = false;
    dArrowKey = false;
    oneKey = false;
    twoKey = false;
    threeKey = false;
}

bool Input::getMouseLeftDown() {
    return mouseLeft;
}

bool Input::getMouseLeftUp() {
    return !mouseLeft;
}

bool Input::getMouseRightDown() {
    return mouseRight;
}

bool Input::getMouseRightUp() {
    return !mouseRight;
}

bool Input::getWKeyDown() {
    return wKey;
}

bool Input::getWKeyUp() {
    return !wKey;
}

bool Input::getAKeyDown() {
    return aKey;
}

bool Input::getAKeyUp() {
    return !aKey;
}

bool Input::getSKeyDown() {
    return sKey;
}

bool Input::getSKeyUp() {
    return !sKey;
}

bool Input::getDKeyDown() {
    return dKey;
}

bool Input::getDKeyUp() {
    return !dKey;
}

bool Input::getRArrowKeyDown() {
    return rArrowKey;
}

bool Input::getRArrowKeyUp() {
    return !rArrowKey;
}

bool Input::getLArrowKeyDown() {
    return lArrowKey;
}

bool Input::getLArrowKeyUp() {
    return !lArrowKey;
}

bool Input::getDArrowKeyDown() {
    return dArrowKey;
}

bool Input::getDArrowKeyUp() {
    return !dArrowKey;
}

bool Input::getUArrowKeyDown() {
    return uArrowKey;
}

bool Input::getUArrowKeyUp() {
    return !uArrowKey;
}

bool Input::getOneKeyDown() {
    return oneKey;
}

bool Input::getOneKeyUp() {
    return !oneKey;
}

bool Input::getTwoKeyDown() {
    return twoKey;
}

bool Input::getTwoKeyUp() {
    return !twoKey;
}

bool Input::getThreeKeyDown() {
    return threeKey;
}

bool Input::getThreeKeyUp() {
    return !threeKey;
}


void Input::setMouseLeft(bool param) {
    mouseLeft = param;
}

void Input::setMouseRight(bool param) {
    mouseRight = param;
}

void Input::setWKey(bool param) {
    wKey = param;
}

void Input::setAKey(bool param) {
    aKey = param;
}

void Input::setSKey(bool param) {
    sKey = param;
}

void Input::setDKey(bool param) {
    dKey = param;
}

void Input::setRArrowKey(bool param) {
    rArrowKey = param;
}

void Input::setLArrowKey(bool param) {
    lArrowKey = param;
}

void Input::setDArrowKey(bool param) {
    dArrowKey = param;
}

void Input::setUArrowKey(bool param) {
    uArrowKey = param;
}

void Input::setOneKey(bool param) {
    oneKey = param;
}

void Input::setTwoKey(bool param) {
    twoKey = param;
}

void Input::setThreeKey(bool param) {
    threeKey = param;
}
