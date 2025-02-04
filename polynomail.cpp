
#include<bits/stdc++.h>

using namespace std;

// A class to handle solving linear systems using Gaussian elimination
class LinearSystem {
public:
    // Swap two rows in the augmented matrix
    void swapRows(vector<vector<double>>& matrix, int row1, int row2) {
        int n = matrix.size();
        for (int col = 0; col <= n; col++) {
            swap(matrix[row1][col], matrix[row2][col]);
        }
    }

    // Perform Gaussian elimination to get the matrix into row echelon form
    int rowEchelonForm(vector<vector<double>>& matrix) {
        int n = matrix.size();

        for (int col = 0; col < n; col++) {
            double maxVal = matrix[col][col];
            int maxRow = col;

            // Find the row with the maximum value in the current column
            for (int row = col + 1; row < n; row++) {
                if (abs(matrix[row][col]) > abs(maxVal)) {
                    maxVal = matrix[row][col];
                    maxRow = row;
                }
            }

            // If the pivot element is zero, the system may have no or infinite solutions
            if (abs(matrix[col][maxRow]) < 1e-6) return col;  // Return the row of a zero pivot

            // Swap the rows if the maximum value row is not the current row
            if (maxRow != col) swapRows(matrix, maxRow, col);

            // Eliminate the values below the pivot element
            for (int row = col + 1; row < n; row++) {
                double factor = matrix[row][col] / matrix[col][col];
                for (int j = col; j <= n; j++) {
                    matrix[row][j] -= matrix[col][j] * factor;
                }
                matrix[row][col] = 0; // Make the lower triangle zero
            }
        }

        return -1;  // Return -1 when the matrix is in row echelon form
    }

    // Perform back substitution to find the solution vector
    vector<double> backSubstitution(vector<vector<double>>& matrix) {
        int n = matrix.size();
        vector<double> solution(n);

        // Start from the last row and work upwards
        for (int row = n - 1; row >= 0; row--) {
            solution[row] = matrix[row][n];  // Start with the constant term
            for (int col = row + 1; col < n; col++) {
                solution[row] -= matrix[row][col] * solution[col];  // Subtract the already solved variables
            }
            solution[row] /= matrix[row][row];  // Divide by the diagonal element to get the value of the variable
        }

        return solution;
    }

    // Solve the linear system
    vector<double> solve(vector<vector<double>>& matrix) {
        int n = matrix.size();
        int flag = rowEchelonForm(matrix);  // Perform Gaussian elimination to row echelon form

        // Check if the system is inconsistent or has infinite solutions
        if (flag != -1) {
            if (matrix[flag][n] != 0) cout << "Inconsistent system\n";
            else cout << "Infinite solutions\n";
            return {};  // Return an empty solution if there's no unique solution
        }

        // Perform back substitution to get the solution
        return backSubstitution(matrix);
    }
};

// A structure to represent a point (x, y) in 2D space
struct Point {
    double x, y;
};

// A class to handle polynomial curve fitting using the method of least squares
class PolynomialCurve {
public:
    // Method to find the coefficients of a polynomial of degree N fitting the given points
    vector<double> fitPolynomialCurve(vector<Point> points, int degree) {
        int n = points.size();
        vector<vector<double>> matrix(degree + 1, vector<double>(degree + 2, 0));

        // Fill the augmented matrix for the polynomial system
        for (int i = 0; i <= degree; i++) {
            for (int j = 0; j <= degree; j++) {
                for (int k = 0; k < n; k++) {
                    matrix[i][j] += pow(points[k].x, i + j);  // Sum of powers of x
                }
            }

            // Fill the last column with the right-hand side values (y values)
            for (int k = 0; k < n; k++) {
                matrix[i][degree + 1] += points[k].y * pow(points[k].x, i);  // Weighted sum of y values
            }
        }

        LinearSystem equationSolver;
        return equationSolver.solve(matrix);  // Solve the system of equations to get the coefficients
    }
};

int main() {
    PolynomialCurve curve;
    vector<Point> points;
    int degree;

    // Read degree of the polynomial (degree + 1 coefficients will be found)
    cin >> degree;

    // Read points from input
    double x, y;
    while (cin >> x >> y) {
        points.push_back({x, y});
    }

    // Find the polynomial coefficients that fit the points
    vector<double> coefficients = curve.fitPolynomialCurve(points, degree);

    // Print the polynomial coefficients with a precision of 6 decimal places
    cout << fixed << setprecision(6);
    for (int i = 0; i < coefficients.size(); i++) {
        cout << "a" << i << " = " << coefficients[i] << endl;
    }

    return 0;
}
