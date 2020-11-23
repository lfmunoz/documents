#include <bits/stdc++.h>
using namespace std;
// Direction Matrix
static int D[][2] = { {0,1},{1,0},{-1,0},{0,-1},
                        {1,1},{1,-1},{-1,1},{-1,-1} };

void show_point(int x, int y) {
    cout << "(" << x << "," << y << ")";
}

void take_steps_in_direction(int direction, int steps) {
    int x = 0;
    int y = 0;
    while(steps--) {
        x += D[direction][0]; 
        y += D[direction][1];
    }
    show_point(x, y); cout << "\n";
}

int step_in_every_direction_from_every_square(int size) {
    int i, j, k;
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            for(k = 0; k < 8; k++) {
                int x = i + D[k][0]; 
                int y = j + D[k][1];
                if(x < 0 || y < 0 || x >= size || y >= size) continue;
                show_point(x, y); cout << " ";
            }
        }
    }
    return 0;
}
// ________________________________________________________________________________
// Main
//  g++ matrix.cpp 
// ________________________________________________________________________________
int main() {
    take_steps_in_direction(0, 2); // (0,0) -> (0,2)
    take_steps_in_direction(1, 2); // (0,0) -> (2,0)
    take_steps_in_direction(2, 2); // (0,0) -> (-2,0)
    take_steps_in_direction(3, 2); // (0,0) -> (0,-2)
    take_steps_in_direction(4, 2); // (0,0) -> (2,2)
    take_steps_in_direction(5, 2); // (0,0) -> (2,-2)
    take_steps_in_direction(6, 2); // (0,0) -> (-2,2)
    take_steps_in_direction(7, 2); // (0,0) -> (-2,-2)
    cout << endl;
    step_in_every_direction_from_every_square(2);
    // (0,1) (1,0) (1,1) (1,1) (0,0) (1,0) (1,1) (0,0) (0,1) (0,1) (1,0) (0,0)
    cout << endl;
    return 0;

}