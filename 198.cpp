#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


int main()
{
    ifstream input("198.txt");
    ofstream output("198(output).txt");

    setlocale(LC_ALL, "RU");

    int n, m;
    input >> n;
    m = n + 1;

    float** mat = new float* [n];
    for (int i = 0; i < n; i++)
        mat[i] = new float[m];


    for (int i = 0; i < n; i++)

        for (int j = 0; j < m; j++)
        {
            input >> mat[i][j];
        }

    float  var;
    float* ans = new float[m];
    int k;

    for (int i = 0; i < n; i++)
    {
        var = mat[i][i];
        for (int j = n; j >= i; j--)
            mat[i][j] /= var;

        for (int j = i + 1; j < n; j++)
        {
            var = mat[j][i];
            for (k = n; k >= i; k--)
                mat[j][k] -= var * mat[i][k];
        }
    }

    ans[n - 1] = mat[n - 1][n];

    for (int i = n - 2; i >= 0; i--)
    {
        ans[i] = mat[i][n];
        for (int j = i + 1; j < n; j++) ans[i] -= mat[i][j] * ans[j];
    }


    for (int i = 0; i < n; i++)
        output << ans[i] << " ";

    delete[] mat;


    input.close();
    output.close();
}