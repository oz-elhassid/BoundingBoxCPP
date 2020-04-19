#include "BoundingBox.h"

const std::string intersectText = "intersect";
const std::string separateText = "separate";
const std::string invalidVertical = "invalid - top should be abov bottom";
const std::string invalidHorizontal = "invalid - right should be greater than left";

BoundingBox::BoundingBox (double left, double right, double top, double bottom):
                        left(left), right(right), top(top), bottom(bottom) {}

double BoundingBox::getLeft(){
    return left;
}
double BoundingBox::getRight(){
    return right;
}
double BoundingBox::getTop(){
    return top;
}
double BoundingBox::getBottom(){
    return bottom;
}

static void checkBox(BoundingBox box) {
    if (box.getLeft() > box.getRight())
        throw std::domain_error(invalidHorizontal);
    if (box.getBottom() > box.getTop())
        throw std::domain_error(invalidVertical);
}

std::string checkRelation(BoundingBox box1, BoundingBox box2) {
    try {
        checkBox(box1);
    }
    catch(const std::domain_error e) {
        return ((std::string)e.what() + " - box1");
    }
    try {
        checkBox(box2);
    }
    catch(const std::domain_error e) {
        return ((std::string)e.what() + " - box2");
    }
    if (box1.getLeft() <= box2.getRight() && box2.getLeft() <= box1.getRight() && box1.getBottom() <= box2.getTop() && box2.getBottom() <= box1.getTop())
        return intersectText;
    return separateText;
} 

int main(int argc, char const *argv[])
{
    BoundingBox rectA = BoundingBox( 10,  30,  30,  10);
    BoundingBox rectB = BoundingBox( 20,  50,  50,  20);
    BoundingBox rectC = BoundingBox( 70,  90,  90,  170);

    std::cout<<(checkRelation(rectA, rectB))<<std::endl;
    std::cout<<(checkRelation(rectA, rectC))<<std::endl;
}
