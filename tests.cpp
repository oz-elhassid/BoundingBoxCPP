#include "BoundingBox.cpp"

using namespace std;
int main(int argc, char const *argv[])
{
    const BoundingBox boxA = BoundingBox(10, 30, 30, 10);
    const BoundingBox boxB = BoundingBox(20, 50, 50, 20);
    const BoundingBox boxC = BoundingBox(70, 90, 90, 70);
    const BoundingBox boxD = BoundingBox(100.9, 200.9, 200.9, 100.9);
    const BoundingBox boxE = BoundingBox(150, 190.5, 190.5, 150.5);
    vector<BoundingBox> arr = {boxA, boxB, boxC, boxD, boxE, boxB, boxD};

    // cout<<(checkRelation(boxA, boxB))<<endl;
    // cout<<(checkRelation(boxA, boxC))<<endl;
    vector<BoundingBox> checked = checkArray(arr);
    for (BoundingBox b : checked)
        cout<<(b.to_string())<<endl;

    // for (BoundingBox b : arr)
    //     cout<<(b.to_string())<<endl;
}