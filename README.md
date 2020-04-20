# BoundingBoxTS

Running the project is pretty straight forward.

First, you'll need a C++ compiler, such as g++.

Then, clone the repository:
```
git clone https://github.com/oz-elhassid/BoundingBoxCPP.git
```
if you don't have git installed or don't want to use the command line, you can use the green `Clone or download` button to download as zip.

Then, to build, navigate to the cloned directory and run:
```
make
```
In order to run the tests, run:
```
./tests
```
## Usage
`BoundingBox`: A class consists mainly of four numerical values describing each of the bounds.  
`BoundingBox(double left, double right, double top, double bottom)`: A constructor for the class.
`boxRelation`: An enum representing the different relations between boxes.   
`checkRelation(BoundingBox box1, BoundingBox box2, boxRelation inside)`: Given two BoundingBoxes and an optional boxRelation to determine how to treat a box inside another box (default is `separate`), returns a string describing the relation between the boxes.  
`checkArray(std::vector<BoundingBox> &arr, boxRelation inside)`: Given an array of BoundingBoxes, and an optional boxRelation to determine how to treat a box inside another box (default is `separate`), returns an array containing only separate boxes.

## Test Cases
The `tests.ts` file includes a few simple tests, and some basic usage examples.  
It creates 6 BoundingBoxes, and creates an array containing said BoundingBoxes.  
Than it goes on to check the relations between some of the boxes and creates an array of separate boxes from the original array.  
The `tests.ts` file demonstrate how to use the optional `inside` argument. By passing one of the `boxRelation` enum items, one can decide how to treat a box inside another box (default is to treat the boxes as separate).  
That functionality is tested by checking the relation between a box inside another box twice, once with the parameter set to `inside` and once without passing the parameter at all.  
The array is also tested twice, when the two boxes are not considered separate, one of the boxes is removed.
