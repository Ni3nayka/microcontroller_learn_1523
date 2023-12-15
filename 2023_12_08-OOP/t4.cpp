#include <iostream>
using namespace std;

// =========================================================================

class robot {
    public:
        int x;
        int y;
        
        void up() {
            robot::y--;
        }
        void down() {
            robot::y++;
        }
        void left() {
            robot::x--;
        }
        void right() {
            robot::x++;
        }
    private:
};

robot vasiliy;
robot ivan;

// =========================================================================

const int SIZE_AREA_X = 8;
const int SIZE_AREA_Y = 5;

void draw_area() {
    for (int y = 0; y<SIZE_AREA_Y; y++) {
        for (int x = 0; x<SIZE_AREA_X; x++) {
            if (x==vasiliy.x && y==vasiliy.y) {
                cout << "#";    
            }
            else if (x==ivan.x && y==ivan.y) {
                cout << "@";    
            }
            else {
                cout << ".";    
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vasiliy.x = 7;
    vasiliy.y = 4;
    ivan.x = 1;
    ivan.y = 1;
    draw_area();
    
    vasiliy.up();
    vasiliy.up();
    
    ivan.right();
    ivan.right();
    
    draw_area();
    return 0;
}