//Jack Utzerath
#include <iostream>
#include "graph.h"
using namespace std;

int main() {




    int foo[15][15];

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {

            foo[i][j] = 0;

        }
    }

    foo[0][1] = 14;
    foo[0][11] = 14;
    foo[0][12] = 9;

    foo[1][0] = 14;
    foo[1][11] = 9;
    foo[1][10] = 17;
    foo[1][2] = 9;

    foo[2][1] = 9;
    foo[2][10] = 13;
    foo[2][9] = 20;
    foo[2][3] = 5;

    foo[3][2] = 5;
    foo[3][9] = 19;
    foo[3][4] = 17;

    foo[4][3] = 17;
    foo[4][9] = 19;
    foo[4][5] = 16;

    foo[5][4] = 16;
    foo[5][9] = 12;
    foo[5][7] = 9;
    foo[5][6] = 8;

    foo[6][5] = 8;
    foo[6][7] = 6;

    foo[7][6] = 6;
    foo[7][5] = 9;
    foo[7][9] = 12;
    foo[7][8] = 7;
    foo[7][14] = 10;
    foo[7][13] = 23;

    foo[8][10] = 5;
    foo[8][14] = 6;
    foo[8][7] = 7;
    foo[8][9] = 13;

    foo[9][2] = 20;
    foo[9][10] = 7;
    foo[9][8] = 13;
    foo[9][7] = 12;
    foo[9][5] = 12;
    foo[9][4] = 4;
    foo[9][3] = 19;

    foo[10][2] = 13;
    foo[10][1] = 17;
    foo[10][11] = 18;
    foo[10][14] = 8;
    foo[10][8] = 5;
    foo[10][9] = 7;

    foo[11][0] = 14;
    foo[11][12] = 15;
    foo[11][14] = 9;
    foo[11][10] = 18;
    foo[11][1] = 9;

    foo[12][0] = 9;
    foo[12][11] = 15;
    foo[12][14] = 15;
    foo[12][13] = 11;

    foo[13][12] = 11;
    foo[13][14] = 18;
    foo[13][7] = 23;

    foo[14][11] = 9;
    foo[14][12] = 15;
    foo[14][13] = 18;
    foo[14][7] = 10;
    foo[14][8] = 6;
    foo[14][10] = 8;

    graph g(foo);
    g.print();
    g.getNeighbors(1);
    g.path(9,1);
  
}