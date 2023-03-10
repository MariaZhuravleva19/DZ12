#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


int main()
{
    ifstream input("557.txt");
    ofstream output("557(output).txt");

    int cMat, sizeMat, iMat, jMat, p;

    input >> cMat >> sizeMat >> iMat >> jMat >> p;

    iMat--; 
    jMat--;

    vector<vector<int>> a(sizeMat, vector<int>(sizeMat));

    for (int i = 0; i < sizeMat; i++)
    {
        for (int j = 0; j < sizeMat; j++)
        {
            input >> a[i][j];
        }
    }

    vector<vector<int>> b(sizeMat, vector<int>(sizeMat));
    vector<vector<int>> result(sizeMat, vector<int>(sizeMat));

    for (int m = 1; m < cMat; m++)
    {
        for (int i = 0; i < sizeMat; i++)
        {
            for (int j = 0; j < sizeMat; j++)
            {
                input >> b[i][j];
            }
        }

        for (int j = 0; j < sizeMat; j++)
        {
            result[iMat][j] = 0;
            for (int k = 0; k < sizeMat; k++)
            {
                result[iMat][j] = (result[iMat][j] + a[iMat][k] * b[k][j]) % p;
            }
        }

        result.swap(a);

    }

    output << a[iMat][jMat] << endl;


    input.close();
    output.close();
}