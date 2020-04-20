#include "BoundingBox.h"

using namespace std;
int main()
{
    const BoundingBox boxA = BoundingBox(10, 30, 30, 10);
    const BoundingBox boxB = BoundingBox(20, 50, 50, 20);
    const BoundingBox boxC = BoundingBox(70, 90, 90, 70);
    const BoundingBox boxD = BoundingBox(100.9, 200.9, 200.9, 100.9);
    const BoundingBox boxE = BoundingBox(150, 190.5, 190.5, 150.5);
    vector<BoundingBox> arr = {boxA, boxB, boxC, boxD, boxE, boxB, boxD};

    cout<<(BoundingBox::checkRelation(boxA, boxB))<<endl;
    cout<<(BoundingBox::checkRelation(boxA, boxC))<<endl;
    vector<BoundingBox> checked1 = BoundingBox::checkArray(arr);
    for (BoundingBox b : checked1)
        cout<<(b.to_string())<<endl;
    cout<<(BoundingBox::checkRelation(boxD, boxE, BoundingBox::boxRelation::inside))<<endl;
    vector<BoundingBox> checked2 = BoundingBox::checkArray(arr, BoundingBox::boxRelation::inside);
    for (BoundingBox b : checked2)
        cout<<(b.to_string())<<endl;
}