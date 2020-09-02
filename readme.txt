// To compile file
g++ -std=c++11 Assn2.cpp ShapeTwoD.cpp Square.cpp Circle.cpp Cross.cpp Rectangle.cpp -o csci251_a2.exe

// To execute file
./csci251_a2.exe

// This program works in general with some errors

// Shapes that are completely working with no errors
Rectangle

// Things to note:
Square
All Points within Shape for Square 
(15, 4) (15, 1) (18, 1) (18, 4) error 
- Point is repeated 
- What is shown: 2 sets of (17, 3) 
- Expected: (16, 3) & (17, 3)

Circle
All input sensor data did not display radius
Area of circle off by 0.01 units 
- For Circle (13, 14) (16, 11) (19, 14) (16, 17)
- What is shown: 28.26
- Expected: 28.27

- For Circle (1, 3) (3, 1) (5, 3) (3, 5)
- What is shown: 12.56
- Expected: 12.57

Cross
All Points within Shape for Cross 
(8, 17), (7, 17), (7, 16), (8, 16), (8, 15), (10, 15), 
(10, 16), (13, 16), (13, 17), (10, 17), (10, 18), (8, 18) error
- What is shown: none! 
- Expected: (9, 17), (9, 16)

Processing Choice 4: Sorting
After processing choice 2 (area), choose choice 3 (print) before choosing choice 4
- If not Shape details (Name, Special Type) will not be displayed