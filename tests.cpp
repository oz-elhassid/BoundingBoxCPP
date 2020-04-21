#include "BoundingBox.h"

using namespace std;

void print(const vector<BoundingBox>& v) {
    for (auto item : v)
        cout<<(item.to_string())<<endl;
}

const string passed = "Test passed";
const string failed = "Test failed";
int totalTests = 0;
int  passedTests = 0;
string test(const string& str1, const string& str2) {
    totalTests++;
    if (str1.compare(0, str2.length(), str2) == 0) {
        passedTests++;
        return passed;
    }
    return failed;
}

string testLen (const vector<BoundingBox>& arr, unsigned int n) {
    totalTests++;
    if (arr.size() <= n){
        passedTests++;
        return passed;
    }
    return failed;
}

int main()
{
    const BoundingBox boxA = BoundingBox(10, 30, 30, 10);
    const BoundingBox boxB = BoundingBox(20, 50, 50, 20);
    const BoundingBox boxC = BoundingBox(70, 90, 90, 70);
    const BoundingBox boxD = BoundingBox(100.9, 200.9, 200.9, 100.9);
    const BoundingBox boxE = BoundingBox(150, 190.5, 190.5, 150.5);
    const BoundingBox boxF = BoundingBox(40, 30, 30, 10);
    vector<BoundingBox> arr = {boxA, boxB, boxC, boxD, boxE, boxB, boxD};
    
    cout<<("boxA and boxF: " + BoundingBox::checkRelation(boxA, boxF) + " - " + test(BoundingBox::checkRelation(boxA, boxF), BoundingBox::boxRelationMap.at(BoundingBox::invalidHorizontal)))<<endl;
    cout<<("boxA and boxB: " + BoundingBox::checkRelation(boxA, boxB) + " - " + test(BoundingBox::checkRelation(boxA, boxB), BoundingBox::boxRelationMap.at(BoundingBox::intersect)))<<endl;
    cout<<("boxA and boxC: " + BoundingBox::checkRelation(boxA, boxC) + " - " + test(BoundingBox::checkRelation(boxA, boxC), BoundingBox::boxRelationMap.at(BoundingBox::separate)))<<endl;
    cout<<("boxD and boxE: " + BoundingBox::checkRelation(boxD, boxE) + " - " + test(BoundingBox::checkRelation(boxD, boxE), BoundingBox::boxRelationMap.at(BoundingBox::separate)))<<endl;
    vector<BoundingBox> checked1 = BoundingBox::checkArray(arr);
    cout<<("a separate array created from arr:")<<endl;
    print(checked1);
    cout<<("the array's length is " + (testLen(checked1, 4) == passed ? " <= 4 - " + passed : " > 4 - " + failed))<<endl;
    cout<<("boxD and boxE not assuming a box in a box is separate: " + BoundingBox::checkRelation(boxD, boxE, BoundingBox::boxRelation::inside) + " - " + test(BoundingBox::checkRelation(boxD, boxE, BoundingBox::boxRelation::inside), BoundingBox::boxRelationMap.at(BoundingBox::inside)))<<endl;
    vector<BoundingBox> checked2 = BoundingBox::checkArray(arr, BoundingBox::boxRelation::inside);
    cout<<("a separate array created from arr not assuming a box in a box is separate:")<<endl;
    print(checked2);
    cout<<("the array's length is " + (testLen(checked2,3) == passed ? " <= 3 - " + passed : " > 3 - " + failed))<<endl;
    cout<<("passed " + to_string(passedTests) + "/" + to_string(totalTests) + " tests")<<endl;

}