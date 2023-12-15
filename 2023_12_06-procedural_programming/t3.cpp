#include <iostream>
using namespace std;

// размеры нашего игрового поля
const int SIZE_AREA_X = 10;
const int SIZE_AREA_Y = 8;

// координаты собаки
int dog_x = 3;
int dog_y = 1;

// координаты точки, куда стремится собака
int point_x = 4;
int point_y = 5;

void draw_area() { // подпрограмма для отрисовки поля
    int x = 0;
    int y = 0;
    while (y<SIZE_AREA_Y) { // цикл для отрисовки строк
        x = 0;
        while(x<SIZE_AREA_X) { // цикл для отрисовки строки (одной)
            if (x==dog_x && y==dog_y) { // если в этой точки собака
                cout << "#"; // рисуем собаку
            }
            else if (x==point_x && y==point_y) { // иначе если в этой точке "финиш"
                cout << "!"; // рисуем финиш
            }
            else { // иначе
                cout << "."; // рисуем пустое место
            }
            x++; // переходим к следующему пикселю
        }
        // переходим на новую строку
        cout << endl;
        y++;
    }
}

void move_dog() { // данные получаем из консоли
    char a; // переменная для получения данных из консоли
    cin >> a; // получаем данные из консоли
    if (a=='w' && dog_y>0) { // если двигаться вверх и мы не выходим за рамки поля
        dog_y--; // то двигаем собаку вверх (ось У инвертирована)
    }
    if (a=='s' && dog_y<SIZE_AREA_Y-1) { // аналогично
        dog_y++;
    }
    if (a=='a' && dog_x>0) {
        dog_x--;
    }
    if (a=='d' && dog_x<SIZE_AREA_X-1) {
        dog_x++;
    }
}

int main() { // подпрограмма main
    while (dog_x!=point_x || dog_y!=point_y) { // пока собака не пришла на финиш
        draw_area(); // вызвать отрисовку поля
        move_dog(); // вызвать перемещение собаки по полю
    }
    cout << "you win!" << endl; // вывести сообщение о завершении игры
    return 0;
}

