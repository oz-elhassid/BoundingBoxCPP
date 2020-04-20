#include "BoundingBox.h"

using namespace std;

BoundingBox::BoundingBox (double left, double right, double top, double bottom):
                        left(left), right(right), top(top), bottom(bottom) {}


const unordered_map<BoundingBox::boxRelation, string> BoundingBox::boxRelationMap = {{BoundingBox::boxRelation::intersect, "intersect"},
                                                                        {BoundingBox::boxRelation::separate, "separate"},
                                                                        {BoundingBox::boxRelation::invalidVertical, "invalid - top should be above bottom"},
                                                                        {BoundingBox::boxRelation::invalidHorizontal, "invalid - right should be greater than left"},
                                                                        {BoundingBox::boxRelation::invalidInside, "invalid - one box is inside the other"},
                                                                        {BoundingBox::boxRelation::inside, "one box is inside the other"}};

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
        throw domain_error(boxRelationMap.at(boxRelation::invalidHorizontal));
    if (box.getBottom() > box.getTop())
        throw domain_error(boxRelationMap.at(boxRelation::invalidVertical));
}

string BoundingBox::checkRelation(BoundingBox box1, BoundingBox box2, boxRelation inside) {
    try {
        checkBox(box1);
    }
    catch(const domain_error &e) {
        return ((string)e.what() + " - box1");
    }
    try {
        checkBox(box2);
    }
    catch(const domain_error &e) {
        return ((string)e.what() + " - box2");
    }
    if (box1.getLeft() <= box2.getRight() && box2.getLeft() <= box1.getRight() && box1.getBottom() <= box2.getTop() && box2.getBottom() <= box1.getTop()){
        if ((box1.getLeft() > box2.getLeft() && box1.getRight() < box2.getRight() && box1.getBottom() > box2.getBottom() && box1.getTop() < box2.getTop()) || (box2.getLeft() > box1.getLeft() && box2.getRight() < box1.getRight() && box2.getBottom() > box1.getBottom() && box2.getTop() < box1.getTop()))
            return boxRelationMap.at(inside);
        return boxRelationMap.at(BoundingBox::boxRelation::intersect);
    }
    return boxRelationMap.at(BoundingBox::boxRelation::separate);
}

vector<BoundingBox> BoundingBox::removeIntersect(vector<BoundingBox> &arr, BoundingBox box, BoundingBox::boxRelation inside) {
    vector<BoundingBox> output = {};
    for (auto box2 : arr)
        if ((checkRelation(box, box2, inside).compare(boxRelationMap.at(BoundingBox::boxRelation::separate))) == 0)
            output.push_back(box2);
    return output;
}

vector<BoundingBox> BoundingBox::checkArray(vector<BoundingBox> &arr, BoundingBox::boxRelation inside){
    vector<BoundingBox> sorted = arr;
    sort(sorted.begin(), sorted.end(), [](BoundingBox box1, BoundingBox box2) -> bool {return box1.getRight() != box2.getRight() ? box1.getRight() < box2.getRight() : box1.getTop() < box2.getTop();});
    vector<BoundingBox> output = {};
    while (!sorted.empty()){
        output.push_back(sorted[0]);
        sorted = removeIntersect(sorted, sorted[0], inside);
    }
    return output;
}
