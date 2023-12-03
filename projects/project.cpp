#include <iostream>
#include <vector>

using namespace std;

vector<vector<double>> invMatrix(const vector<vector<double>>& matrix) {
    int n = matrix.size();
    vector<vector<double>> augMatrix(n, vector<double>(2 * n, 0.0));

    // Create an augmented matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            augMatrix[i][j] = matrix[i][j];
            augMatrix[i][j + n] = (i == j) ? 1.0 : 0.0;
        }
    }

    // Perform Gauss-Jordan elimination 
    for (int i = 0; i < n; ++i) {
        // Make the diagonal element 1
        double pivot = augMatrix[i][i];
        for (int j = 0; j < 2 * n; ++j) {
            augMatrix[i][j] /= pivot;
        }

        // Make other elements in the column 0
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = augMatrix[k][i];
                for (int j = 0; j < 2 * n; ++j) {
                    augMatrix[k][j] -= factor * augMatrix[i][j];
                }
            }
        }
    }

    // Extract the inverse matrix from the augmented matrix
    vector<vector<double>> inverse(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inverse[i][j] = augMatrix[i][j + n];
        }
    }

    return inverse;
}

int main() {
    // User input for matrix size
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    // User input for matrix elements
    cout << "Enter the elements of the square matrix:" << endl;
    vector<vector<double>> matrix(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Element at position (" << i + 1 << ", " << j + 1 << "): ";
            cin >> matrix[i][j];
        }
    }

    // Calculate and display the inverse matrix
    vector<vector<double>> inv = invMatrix(matrix);
    cout << "\n Inverse Matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << inv[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
