#include <iostream>

class BoundingBox {
    public:
        BoundingBox(double left, double right, double top, double bottom);
        double getLeft() const;
        double getRight() const;
        double getTop() const;
        double getBottom() const;
        std::string to_string() const;
        static void checkBox(BoundingBox box);

    private:
        double left;
        double right;
        double top;
        double bottom;
};