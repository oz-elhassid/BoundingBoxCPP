#include "BoundingBox.h"

const std::string intersectText = "intersect";
const std::string separateText = "separate";
const std::string invalidText = "invalid";

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
static std::domain_error* checkBox(BoundingBox box) {
    if (box.getLeft() > box.getRight())
        return new std::domain_error("fasdf");
    if (box.getBottom() > box.getTop())
        return new std::domain_error("top should be above bottom");
    return nullptr;
}

std::string checkRelation(BoundingBox box1, BoundingBox box2) {
    const std::domain_error *valid1 = checkBox(box1);
    const std::domain_error *valid2 = checkBox(box2);
    if (valid1 != nullptr)
        return invalidText + ": " + valid1->what();
    if (valid2 != nullptr)
        return invalidText + ": " + valid2->what();
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
