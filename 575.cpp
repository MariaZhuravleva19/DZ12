#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


int main()
{
    ifstream input("575.txt");
    ofstream output("575(output).txt");

    int iMat, jMat;
    input >> iMat >> jMat;

    vector<vector<int>> a(iMat, vector<int>(jMat));
    for (int i = 0; i < iMat; i++)
    {
        for (int j = 0; j < jMat; j++)
        {
            input >> a[i][j];
        }
    }

    int collums = 0;
    for (int i = 0; i + 1 < iMat; i++)
    {
        for (int j = 0; j + 1 < jMat; j++)
        {
            if (!(a[i][j] == a[i + 1][j] && a[i][j] == a[i][j + 1] && a[i][j] == a[i + 1][j + 1]))
            {
                collums++;
            }
        }
    }

    int walls = 0;
    for (int i = 0; i < iMat; i++)
    {
        for (int j = 0; j + 1 < jMat; j++)
        {
            if (a[i][j] != a[i][j + 1])
            {
                walls++;
            }
        }
    }

    for (int i = 0; i + 1 < iMat; i++)
    {
        for (int j = 0; j < jMat; j++)
        {
            if (a[i][j] != a[i + 1][j])
            {
                walls++;
            }
        }
    }

    output << (0.2 * 0.2 * 3 * collums) + (0.2 * 0.8 * 3 * walls) << endl;


    input.close();
    output.close();
}





