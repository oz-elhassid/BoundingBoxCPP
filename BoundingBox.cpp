#include "BoundingBox.h"
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

const string intersectText = "intersect";
const string separateText = "separate";
const string invalidVertical = "invalid - top should be above bottom";
const string invalidHorizontal = "invalid - right should be greater than left";
const string insideText = intersectText;

BoundingBox::BoundingBox (double left, double right, double top, double bottom):
                        left(left), right(right), top(top), bottom(bottom) {}

double BoundingBox::getLeft() const{
    return left;
}
double BoundingBox::getRight() const{
    return right;
}
double BoundingBox::getTop() const{
    return top;
}
double BoundingBox::getBottom() const{
    return bottom;
}

string BoundingBox::to_string() const {
    return ("left: "+std::to_string(getLeft())+" right: "+std::to_string(getRight())+" top: "+std::to_string(getTop())+" bottom: "+std::to_string(getBottom()));
}

void BoundingBox::checkBox(BoundingBox box) {
    if (box.getLeft() > box.getRight())
        throw domain_error(invalidHorizontal);
    if (box.getBottom() > box.getTop())
        throw domain_error(invalidVertical);
}

string checkRelation(BoundingBox box1, BoundingBox box2) {
    try {
        BoundingBox::checkBox(box1);
    }
    catch(const domain_error &e) {
        return ((string)e.what() + " - box1");
    }
    try {
        BoundingBox::checkBox(box2);
    }
    catch(const domain_error &e) {
        return ((string)e.what() + " - box2");
    }
    if (box1.getLeft() <= box2.getRight() && box2.getLeft() <= box1.getRight() && box1.getBottom() <= box2.getTop() && box2.getBottom() <= box1.getTop()){
        if ((box1.getLeft() > box2.getLeft() && box1.getRight() < box2.getRight() && box1.getBottom() > box2.getBottom() && box1.getTop() < box2.getTop()) || (box2.getLeft() > box1.getLeft() && box2.getRight() < box1.getRight() && box2.getBottom() > box1.getBottom() && box2.getTop() < box1.getTop()))
            return insideText;
        return intersectText;
    }
    return separateText;
}

vector<BoundingBox> removeIntersect(vector<BoundingBox> &arr, BoundingBox box) {
    vector<BoundingBox> output = {};
    for (auto box2 : arr)
        if ((checkRelation(box, box2).compare(separateText)) == 0)
            output.push_back(box2);
    return output;
}

vector<BoundingBox> checkArray(vector<BoundingBox> &arr){
    vector<BoundingBox> sorted = arr;
    sort(sorted.begin(), sorted.end(), [](BoundingBox box1, BoundingBox box2) -> bool {return box1.getRight() != box2.getRight() ? box1.getRight() < box2.getRight() : box1.getTop() < box2.getTop();});
    vector<BoundingBox> output = {};
    while (!sorted.empty()){
        output.push_back(sorted[0]);
        sorted = removeIntersect(sorted, sorted[0]);
    }
    return output;
}
