// ex6-1.cpp
#include <iostream>
#include <math.h>
using namespace std;

class quadrangle
{
public:
    class vertex;
    static quadrangle::vertex origin;
    quadrangle(quadrangle::vertex, quadrangle::vertex, 
               quadrangle::vertex, quadrangle::vertex);
    quadrangle(quadrangle::vertex, quadrangle::vertex);
    ~quadrangle() {};
    void move(quadrangle::vertex);
    void draw();

    class vertex
    {
        friend class quadrangle;
        int x, y;
    public:
        vertex() { x = 0; y = 0; }
        vertex(int c, int d) { x = c; y = d; }
        ~vertex() {};
    };

private:
    bool rect = false;
    vertex list[4];
    // static vertex origin;
};

quadrangle::vertex quadrangle::origin = quadrangle::vertex(0, 0);

quadrangle::quadrangle(quadrangle::vertex a, quadrangle::vertex b) {
    rect = true;
    list[0].x = a.x;
    list[0].y = a.y;
    list[1].x = b.x;
    list[1].y = a.y;
    list[2].x = b.x;
    list[2].y = b.y;
    list[3].x = a.x;
    list[3].y = b.y;
}

quadrangle::quadrangle(quadrangle::vertex a, quadrangle::vertex b, 
                       quadrangle::vertex c, quadrangle::vertex d) 
{
    if ((a.y == b.y) && (a.x == d.x) && (c.x == b.x) && (c.y == d.y))
        rect = true;
    list[0].x = a.x;
    list[0].y = a.y;
    list[1].x = b.x;
    list[1].y = b.y;
    list[2].x = c.x;
    list[2].y = c.y;
    list[3].x = d.x;
    list[3].y = d.y;
}

void quadrangle::move(quadrangle::vertex a) {
    int var_x = a.x - list[0].x;
    int var_y = a.y - list[0].y;
    float dist = sqrt(pow(a.x - origin.x, 2) + pow(a.y - origin.y, 2));

    list[0].x = a.x;
    list[0].y = a.y;

    for (int i = 1; i < 4; i++) {
        list[i].x += var_x;
        list[i].y += var_y;
    }

    cout << "Distance: " << dist << endl;
}

void quadrangle::draw() {
    cout << "v1: (" << list[0].x << "," << list[0].y << ")\t";
    cout << "v2: (" << list[1].x << "," << list[1].y << ")\t";
    cout << "v3: (" << list[2].x << "," << list[2].y << ")\t";
    cout << "v4: (" << list[3].x << "," << list[3].y << ")\t";
    if (rect)
        cout << "area: " << (list[1].x - list[0].x) * (list[2].y - list[1].y);
    cout << endl;
}

int main()
{
    quadrangle q1(quadrangle::vertex(0, 0),
                  quadrangle::vertex(3, 2),
                  quadrangle::vertex(10, 7),
                  quadrangle::vertex(8, 10));
    quadrangle q2(quadrangle::vertex(3, 6), quadrangle::vertex(10, 9));
    cout << "q1 information" << endl;
    q1.draw();
    cout << endl;
    cout << "q2 information" << endl;
    q2.draw();
    cout << endl;
    cout << "q1 move to (5, 5) " << endl;
    q1.move(quadrangle::vertex(5, 5));
    cout << "q1 information" << endl;
    q1.draw();
    cout << endl;
    quadrangle::origin = quadrangle::vertex(-5, 3);
    cout << "q2 move to (-1, 2) " << endl;
    q2.move(quadrangle::vertex(-1, 2));
    cout << "q2 information" << endl;
    q2.draw();
    cout << endl;
    return 0;
}   // end main