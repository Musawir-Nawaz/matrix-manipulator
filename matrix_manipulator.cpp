#include <iostream>
#include<fstream>
using namespace std;
void createMatrix(int**& matrix, int& row, int& column, bool value_Assigned)
{
	if (!value_Assigned)
	{
		cout << "Enter number of rows: ";
		cin >> row;
		cout << "Enter number of columns: ";
		cin >> column;
	}	matrix = new int* [row];
	cout << "Enter the elements of the matrix (row-wise):\n";
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[column];
		for (int j = 0; j < column; j++)
		{
			cin >> matrix[i][j];
		}
	}

}
void matrix_representation(int**& matrix, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
int matrixSum(int** matrix, int row, int column)
{
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			sum += matrix[i][j];
		}
	}
	return sum;
}
int matrixProduct(int** matrix, int row, int column)
{
	int product = 1;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			product *= matrix[i][j];
		}
	}
	return product;
}
void rowWiseAverage(int** matrix, int row, int column)
{
	int count;    //using count variable to count no of entries in each row
	float sum, avg;
	for (int i = 0; i < row; i++)
	{
		sum = 0;
		count = 0;
		for (int j = 0; j < column; j++)
		{
			sum += matrix[i][j];
			count++;
		}
		avg = sum / count;
		cout << "Row Wise Average of row no " << i + 1 << " is " << avg << endl;
	}
}
void colWiseAverage(int** matrix, int row, int column)
{
	int count;    //using count variable to count no of entries in each column
	float avg, sum;
	for (int j = 0; j < column; j++)
	{
		count = 0;
		sum = 0;
		for (int i = 0; i < row; i++)
		{
			sum += matrix[i][j];
			count++;
		}
		avg = (sum / count);
		cout << "column Wise Average of column no " << j + 1 << " is " << avg << endl;
	}
}
float matrixAverage(int** matrix, int row, int column)
{
	float sum
		= matrixSum(matrix, row, column);
	int size = row * column;
	float avg = sum / size;
	return avg;
}
void sortRows(int** matrix, int row, int column)
{
	//row wise sorting
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			for (int k = 0; k < row; k++)
			{
				for (int l = 0; l < column - 1; l++)
				{
					if (matrix[k][l] > matrix[k][l + 1])
					{
						int temp = matrix[k][l];
						matrix[k][l] = matrix[k][l + 1];
						matrix[k][l + 1] = temp;
					}
				}
			}
		}
	}
	//printing of updated matrix
	cout << "Row wise sorting of matrix:" << endl;
	matrix_representation(matrix, row, column);
}
void sortCols(int** matrix, int row, int column)
{
	//column wise sorting
	for (int j = 0; j < column; j++)
	{
		for (int i = 0; i < row; i++)
		{
			for (int l = 0; l < column; l++)
			{
				for (int k = 0; k < row - 1; k++)
				{
					if (matrix[k][l] > matrix[k + 1][l])
					{
						int temp = matrix[k][l];
						matrix[k][l] = matrix[k + 1][l];
						matrix[k + 1][l] = temp;
					}
				}
			}
		}
	}
	//printing of updated matrix
	cout << "column wise sorting of matrix:" << endl;
	matrix_representation(matrix, row, column);
}
void scalarAdd(int** matrix, int row, int column)
{
	int scalar_value;
	cout << "enter a scalar value:" << endl;
	cin >> scalar_value;
	cout << "matrix after scalar addition:" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << matrix[i][j] + scalar_value << " ";
		}
		cout << endl;
	}
}
void addMatrices(int** matrix, int row, int column)
{
	cout << "note: For performing this operation you need to enter one more matrix of same number of rows and columns:" << endl;
	cout << "\n enter matrix" << endl;
	int row2, column2;     //oprtn=operation
	bool value_assigned = true;
	int** matrix2 = nullptr;
	while (true)
	{
		cout << "\nEnter number of rows: ";
		cin >> row2;
		cout << "Enter number of columns: ";
		cin >> column2;

		if (row == row2 && column == column2)
		{
			createMatrix(matrix2, row2, column2, value_assigned);
			break; // Exit the loop if dimensions match
		}
		else
		{
			cout << "\nNote: Dimensions of the new matrix should be equal to the previous matrix." << endl;
			cout << "Please re-enter the number of rows and columns." << endl;
		}
	}
	cout << "\nNew Matrix entered:" << endl;
	matrix_representation(matrix2, row2, column2);

	cout << "Addition of two Matrices is showing below:" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << matrix[i][j] + matrix2[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < row; i++)
	{
		delete[]matrix2[i];
	}
	delete[]matrix2;
}
void scalarSubtract(int** matrix, int row, int column)
{

	int scalar_value;
	cout << "enter a scalar value:" << endl;
	cin >> scalar_value;
	cout << "matrix after scalar subtraction:" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << matrix[i][j] - scalar_value << " ";
		}
		cout << endl;
	}
}
void subtractMatrices(int** matrix, int row, int column)
{
	bool value_Assigned = true;
	cout << "note: For performing this operation you need to enter one more matrix of same number of rows and columns:" << endl;
	cout << "\n enter matrix" << endl;
	int row2, column2;             //oprtn=operation
	int** matrix2 = nullptr;
	while (true)
	{
		cout << "\nEnter number of rows: ";
		cin >> row2;
		cout << "Enter number of columns: ";
		cin >> column2;

		if (row == row2 && column == column2)
		{
			createMatrix(matrix2, row2, column2, value_Assigned);
			break; // Exit the loop if dimensions match
		}
		else
		{
			cout << "\nNote: Dimensions of the new matrix should be equal to the previous matrix." << endl;
			cout << "Please re-enter the number of rows and columns." << endl;
		}
	}
	cout << "\nNew Matrix entered:" << endl;
	matrix_representation(matrix2, row2, column2);
	cout << "Subtraction of two Matrices is showing below:" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << matrix[i][j] - matrix2[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < row; i++)
	{
		delete[]matrix2[i];
	}
	delete[]matrix2;
}
void scalarMultiply(int** matrix, int row, int column)
{

	int scalar_value;
	cout << "enter a scalar value:" << endl;
	cin >> scalar_value;
	cout << "matrix after scalar multiplication:" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << matrix[i][j] * scalar_value << " ";
		}
		cout << endl;
	}
}
void multiplyMatrices(int** matrix, int row, int column)
{
	bool value_Assigned = true;
	cout << "note: For performing this operation you need to enter one more matrix of same number of rows and columns:" << endl;
	cout << "\n enter matrix" << endl;
	int row2, column2;             //oprtn=operation
	int** matrix2 = nullptr;
	while (true)
	{
		cout << "\nEnter number of rows: ";
		cin >> row2;
		cout << "Enter number of columns: ";
		cin >> column2;

		if (row == row2 && column == column2)
		{
			createMatrix(matrix2, row2, column2, value_Assigned);
			break; // Exit the loop if dimensions match
		}
		else
		{
			cout << "\nNote: Dimensions of the new matrix should be equal to the previous matrix." << endl;
			cout << "Please re-enter the number of rows and columns." << endl;
		}
	}
	cout << "\nNew Matrix entered:" << endl;
	matrix_representation(matrix2, row2, column2);

	cout << "Multiplication of two Matrices is showing below:" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << matrix[i][j] * matrix2[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < row; i++)
	{
		delete[]matrix2[i];
	}
	delete[]matrix2;

}
void scalarDivide(int** matrix, int row, int column)
{

	float scalar_value, scalar_div;
	cout << "enter a scalar value:" << endl;
	cin >> scalar_value;
	cout << "matrix after scalar division:" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			scalar_div = matrix[i][j] / scalar_value;
			cout << scalar_div << " ";
		}
		cout << endl;
	}
}
void transpose(int** matrix, int row, int column)
{
	cout << "Tranpose of given matrix is showing below" << endl;
	for (int j = 0; j < column; j++)
	{
		for (int i = 0; i < row; i++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
int matrixDeterminant(int** matrix, int size)
{
	int row = 10, col = 10;
	int det = 0, ** submatrix = new int* [row]; // To store the submatrix
	for (int i = 0; i < row; i++)
	{
		submatrix[i] = new int[col];
	}
	if (size == 1)                           //special case
	{
		det = **matrix;
	}
	else if (size == 2)                     //special case
	{
		det = (matrix[0][0]) * (matrix[1][1]) - (matrix[0][1]) * (matrix[1][0]);
	}
	else
	{
		for (int x = 0; x < size; x++)
		{
			int subi = 0;
			for (int i = 1; i < size; i++)
			{
				int subj = 0;
				for (int j = 0; j < size; j++)
				{
					if (j == x)
					{
						continue;
					}
					submatrix[subi][subj] = matrix[i][j];
					subj++;
				}
				subi++;
			}
			int cofactor;
			if (x % 2 == 0)
			{
				cofactor = 1;
			}
			else
			{
				cofactor = -1;
			}
			int submatrix_determinant = matrixDeterminant(submatrix, size - 1);
			det += cofactor * matrix[0][x] * submatrix_determinant;
		}
		for (int i = 0; i < row; i++)
		{
			delete[]submatrix[i];
		}
		delete[]submatrix;
	}
	return det;
}
void cofactor(int** matrix, int** temp, int p, int q, int n)
{
	int i = 0, j = 0;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			if (row != p && col != q) {
				temp[i][j++] = matrix[row][col];
				if (j == n - 1) {
					j = 0;
					i++;
				}
			}
		}
	}
}

void adjoint(int** matrix, int** adj, int n)
{
	if (n == 1) {
		adj[0][0] = 1;
		return;
	}

	int** temp = new int* [n];
	for (int i = 0; i < n; i++)
		temp[i] = new int[n];

	int sign;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cofactor(matrix, temp, i, j, n);
			if ((i + j) % 2 == 0) {
				sign = 1;
			}
			else {
				sign = -1;
			}
			adj[j][i] = sign * matrixDeterminant(temp, n - 1);
		}
	}

	for (int i = 0; i < n; i++)
		delete[] temp[i];
	delete[] temp;
}
void matrixInverse(int** matrix, int& row, int& column)
{
	int n = row;
	int det = matrixDeterminant(matrix, n);
	if (det == 0) {
		cout << "Matrix is singular and cannot have an inverse." << endl;
		return;
	}
	int** adj = new int* [n];
	for (int i = 0; i < n; i++)
		adj[i] = new int[n];
	adjoint(matrix, adj, n);
	cout << "The inverse of the matrix is:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << (float)adj[i][j] / det << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++)
		delete[] adj[i];
	delete[] adj;
}
void menu(int**& matrix, int& row, int& column)
{
	int oprtn;
	cout << "  \nPlease choose an operation:" << endl;
	cout << "1.  Sum of Matrix (sum of all values)" << endl;
	cout << "2.  Product of Matrix(product of all values)" << endl;
	cout << "3.  Row - wise Average" << endl;
	cout << "4.  Column - wise Average" << endl;
	cout << "5.  Average or whole Matrix" << endl;
	cout << "6.  Row - wise sorting of Matrix" << endl;
	cout << "7.  Column - wise sorting of Matrix" << endl;
	cout << "8.  Scalar Matrix Addition" << endl;
	cout << "9.  Addition of two Matrices" << endl;
	cout << "10. Scalar Matrix Subtraction" << endl;
	cout << "11. Subtraction of two Matrices" << endl;
	cout << "12. Scalar Matrix Multiplication" << endl;
	cout << "13. Multiplication of two Matrices" << endl;
	cout << "14. Scalar Matrix Division" << endl;
	cout << "15. Matrix transpose" << endl;
	cout << "16. Matrix determinant" << endl;
	cout << "17. Matrix Inverse" << endl;
	cout << "operation: ";
	cin >> oprtn;

	if (oprtn == 1)
	{
		cout << "\nsum of matrix is " << matrixSum(matrix, row, column) << endl;

	}
	else if (oprtn == 2)
	{
		cout << "\nProduct of matrix is " << matrixProduct(matrix, row, column) << endl;

	}
	else if (oprtn == 3)
	{
		rowWiseAverage(matrix, row, column);
	}
	else if (oprtn == 4)
	{
		colWiseAverage(matrix, row, column);
	}
	else if (oprtn == 5)
	{
		cout << "\nAverage of matrix is " << matrixAverage(matrix, row, column) << endl;
	}
	else if (oprtn == 6)
	{
		sortRows(matrix, row, column);
	}
	else if (oprtn == 7)
	{
		sortCols(matrix, row, column);
	}
	else if (oprtn == 8)
	{
		scalarAdd(matrix, row, column);
	}
	else if (oprtn == 9)
	{
		addMatrices(matrix, row, column);
	}
	else if (oprtn == 10)
	{
		scalarSubtract(matrix, row, column);
	}
	else if (oprtn == 11)
	{
		subtractMatrices(matrix, row, column);
	}
	else if (oprtn == 12)
	{
		scalarMultiply(matrix, row, column);
	}
	else if (oprtn == 13)
	{
		multiplyMatrices(matrix, row, column);
	}
	else if (oprtn == 14)
	{
		scalarDivide(matrix, row, column);
	}
	else if (oprtn == 15)
	{
		transpose(matrix, row, column);
	}
	else if (oprtn == 16)
	{
		while (1)
		{
			if (row == column)
			{
				int size = row;
				cout << "determinant of matrix is: " << matrixDeterminant(matrix, size);
				break;
			}
			else
			{
				bool value_assigned = false;
				cout << "note: number of rows and columns should be equal" << endl;
				cout << "enter rows and columns again :";
				int** matrix = nullptr;
				createMatrix(matrix, row, column, value_assigned);
			}

		}

	}
	else if (oprtn == 17)
	{
		while (1)
		{
			if (row == column)
			{
				int size = row;
				matrixInverse(matrix, row, column);
				break;
			}
			else
			{
				bool value_assigned = false;
				cout << "note: number of rows and columns should be equal" << endl;
				cout << "enter rows and columns again :";
				int** matrix = nullptr;
				createMatrix(matrix, row, column, value_assigned);
			}

		}
	}
	else
		cout << "entry invalid!";

}
void readFileToArray(ifstream& read, const char* filename, int**& arr)
{
	int row = 3, col = 3, size = 0, * matrix = nullptr;
	int num;
	while (read >> num)
	{
		size++;
		int* temp = new int[size];
		for (int i = 0; i < size - 1; i++)
		{
			temp[i] = matrix[i];
		}
		temp[size - 1] = num;
		delete[] matrix;
		matrix = temp;
	}
	read.close();
	arr = new int* [row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}
	// Filling 2D array with values from 1D array
	int k = 0;
	if (matrix != nullptr)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (k < size)
				{
					arr[i][j] = matrix[k];
					k++;
				}
				else
				{
					arr[i][j] = 0; // Fill the rest with zeros if not enough elements
				}
			}
		}
	}
	delete[] matrix;
}
int main()
{
	int choice;
	cout << "Welcome to the Matrix Manipulator!" << endl;
	do
	{
		cout << "\nPlease choose an option:" << endl;
		cout << " 1. Enter matrix manually" << endl;
		cout << " 2. Load matrix from file" << endl;
		cout << " 3. Exit" << endl;
		cout << "\nchoice: ";
		cin >> choice;
		if (choice == 1)
		{
			bool value_assigned = false;
			int row, column;
			int** matrix = nullptr;
			createMatrix(matrix, row, column, value_assigned);
			cout << "\nMatrix entered:\n";
			matrix_representation(matrix, row, column);
			menu(matrix, row, column);
			for (int i = 0; i < row; i++)
			{
				delete[]matrix[i];
			}
			delete[]matrix;
		}
		else if (choice == 2)
		{
			int op;
			cout << "\nchoice a file:" << endl;
			cout << " 1. file.txt" << endl;
			cout << " 2. file2.txt" << endl;
			cout << " 3. file3.txt" << endl;
			cout << "\nchoice a file: ";
			cin >> op;
			if (op == 1)
			{
				ifstream read("file.txt");
				if (read.is_open())
				{
					int** matrix = nullptr;
					int size = 0;
					readFileToArray(read, "file.txt", matrix);
					int row = 3, col = 3;
					cout << "\nMatrix from file.txt is showing below : " << endl;
					matrix_representation(matrix, row, col);
					menu(matrix, row, col);
					for (int i = 0; i < row; i++)
					{
						delete[]matrix[i];
					}
					delete[]matrix;
				}
				else
					cout << "\nfile opening error" << endl;
			}
			else if (op == 2)
			{
				ifstream read("file2.txt");
				if (read.is_open())
				{
					int** matrix = nullptr;
					int size = 0;
					readFileToArray(read, "file2.txt", matrix);
					int row = 3, col = 3;
					cout << "\nMatrix from file2.txt is showing below : " << endl;
					matrix_representation(matrix, row, col);
					menu(matrix, row, col);

					for (int i = 0; i < row; i++)
					{
						delete[]matrix[i];
					}
					delete[]matrix;
				}
				else
					cout << "\nfile opening error" << endl;
			}
			else if (op == 3)
			{
				ifstream read("file3.txt");
				if (read.is_open())
				{
					int** matrix = nullptr;
					int size = 0;
					readFileToArray(read, "file3.txt", matrix);
					int row = 3, col = 3;
					cout << "\nMatrix from file3.txt is showing below : " << endl;
					matrix_representation(matrix, row, col);
					menu(matrix, row, col);
					for (int i = 0; i < row; i++)
					{
						delete[]matrix[i];
					}
					delete[]matrix;
				}
				else
					cout << "\nfile opening error" << endl;
			}
			else
				cout << "invalid entry!";
		}
		else if (choice == 3)
			cout << "program terminated sucessfully!";
		else
			cout << "invalid entry!";
	} while (choice != 3);
	return 0;
}