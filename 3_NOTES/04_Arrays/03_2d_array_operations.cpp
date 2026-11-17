// ======================================================================
// ADDED (gap-fill): 2D arrays - declare, init, pass to function, row/column sums,
// max element with position, diagonal, dynamic 2D array, vector of vectors
// Not from your original repo - written to fill a missing topic.
// ======================================================================

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROWS = 3;
const int COLS = 4;

// When passing a 2D array, every dimension except the first must be given.
void fill(int tab[][COLS], int rows)
{
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < COLS; c++)
            tab[r][c] = rand() % 10;
}

void print(const int tab[][COLS], int rows)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < COLS; c++)
            cout << tab[r][c] << "\t";
        cout << endl;
    }
}

int main()
{
    srand(time(0));

    // ---------------- declaration + initialization ----------------
    int fixed[2][3] = { {1, 2, 3},
                        {4, 5, 6} };
    cout << "fixed[1][2] = " << fixed[1][2] << endl;     // row 1, column 2 -> 6

    int tab[ROWS][COLS];
    fill(tab, ROWS);
    print(tab, ROWS);

    // ---------------- row sums ----------------
    for (int r = 0; r < ROWS; r++)
    {
        int rowSum = 0;
        for (int c = 0; c < COLS; c++) rowSum += tab[r][c];
        cout << "row " << r << " sum = " << rowSum << endl;
    }

    // ---------------- column sums (swap the loops) ----------------
    for (int c = 0; c < COLS; c++)
    {
        int colSum = 0;
        for (int r = 0; r < ROWS; r++) colSum += tab[r][c];
        cout << "col " << c << " sum = " << colSum << endl;
    }

    // ---------------- max with its position ----------------
    int maxR = 0, maxC = 0;
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            if (tab[r][c] > tab[maxR][maxC]) { maxR = r; maxC = c; }
    cout << "max " << tab[maxR][maxC] << " at [" << maxR << "][" << maxC << "]" << endl;

    // ---------------- square matrix diagonal ----------------
    int sq[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int diag = 0, anti = 0;
    for (int i = 0; i < 3; i++)
    {
        diag += sq[i][i];          // main diagonal
        anti += sq[i][2 - i];      // other diagonal
    }
    cout << "diagonal sum " << diag << ", anti-diagonal sum " << anti << endl;

    // ---------------- dynamic 2D array (size known only at runtime) ----------------
    int rows = 2, cols = 5;
    int **dyn = new int*[rows];            // array of row pointers
    for (int r = 0; r < rows; r++)
        dyn[r] = new int[cols];            // each row
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            dyn[r][c] = r * cols + c;
    cout << "dyn[1][4] = " << dyn[1][4] << endl;
    for (int r = 0; r < rows; r++) delete[] dyn[r];   // free rows first
    delete[] dyn;                                     // then the row-pointer array

    // ---------------- easier: vector of vectors ----------------
    vector<vector<int>> grid(rows, vector<int>(cols, 0));   // rows x cols filled with 0
    grid[0][3] = 7;
    for (const auto &row : grid)
    {
        for (int v : row) cout << v << " ";
        cout << endl;
    }

    return 0;
}
