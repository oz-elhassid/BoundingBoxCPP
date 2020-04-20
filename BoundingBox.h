#ifndef BOUNDING_BOX
#define BOUNDING_BOX

#include <iostream>         // cout
#include <vector>
#include <unordered_map>
#include <algorithm>        // sort

class BoundingBox {
    public:
        BoundingBox(double left, double right, double top, double bottom);
        double getLeft() const;
        double getRight() const;
        double getTop() const;
        double getBottom() const;
        std::string to_string() const;
        enum boxRelation {
            intersect,
            separate,
            invalidVertical,
            invalidHorizontal,
            invalidInside,
            inside
        };
        static std::string checkRelation(BoundingBox box1, BoundingBox box2, boxRelation inside = defaultInside);
        static std::vector<BoundingBox> checkArray(std::vector<BoundingBox> &arr, boxRelation inside = defaultInside);

    private:
        double left;
        double right;
        double top;
        double bottom;
        static const std::unordered_map<boxRelation, std::string> boxRelationMap;
        static const boxRelation defaultInside = boxRelation::separate;
        static void checkBox(BoundingBox box);
        static std::vector<BoundingBox> removeIntersect(std::vector<BoundingBox> &arr, BoundingBox box, boxRelation inside = defaultInside);
};

#endif