#include <iostream>

class BoundingBox {
    public:
        BoundingBox(double left, double right, double top, double bottom);
        double getLeft();
        double getRight();
        double getTop();
        double getBottom();
        static std::domain_error checkBox(BoundingBox box1, BoundingBox box2);

    private:
        double left;
        double right;
        double top;
        double bottom;
};