#include <iostream>
#include <time.h>
using namespace std;

int aRows, aColumns, bRows, bColumns;


int** matrixInput(int i, int j);
int** iterativeMult(int** a, int** b);
int** strassenMulti(int** a, int** b, int ** c);
void paddMatrix(int** &a, int** &b);
void test(int** a);
void strassen(int** a, int** b, int rowStart, int rowEnd, int colStart, int colEnd, int** &ans);
void subMatrices(int**a, int**b);


int main()
{
	int** matrixA;
	int** matrixB;



	cout << "Please enter the number of rows of matrix A: ";
	cin >> aRows;

	cout << "Please enter the number of  columns of matrix A: ";
	cin >> aColumns;

	cout << "Please enter the matrix: " << endl;
	matrixA = matrixInput(aRows, aColumns);

	cout << "Please enter the number of rows of matrix B: ";
	cin >> bRows;

	cout << "Please enter the number of  columns of matrix B: ";
	cin >> bColumns;

	cout << "Please enter the matrix: " << endl;
	matrixB = matrixInput(bRows, bColumns);
	paddMatrix(matrixA, matrixB);

	for (int i = 0; i < aRows; i++)
	{
		for (int j = 0; j < aColumns; j++)
			cout << matrixA[i][j] << "\t";
		cout << endl;
	}

	cout << endl << endl;

	for (int i = 0; i < bRows; i++)
	{
		for (int j = 0; j < bColumns; j++)
			cout << matrixB[i][j] << "\t";
		cout << endl;
	}

	int **arr = new int*[aRows];
	for (int x = 0; x < aRows; ++x)
	{
		arr[x] = new int[aColumns];
		for (int y = 0; y < aColumns; y++)
		{
			//cout << "[" << x << "][" << y << "]:";
			arr[x][y] = rand() % 15 + 1;
		}
	}

	strassen(matrixA, matrixB, 0, aRows - 1, 0, aColumns - 1, arr);

	for (int i = 0; i < bRows; i++)
	{
		for (int j = 0; j < bColumns; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}

	int** c = iterativeMult(matrixA, matrixB);
	subMatrices(arr, c);
	/*
	int**c=new int*[2];;
	for (int i = 0; i < 2; ++i)
	{
	c[i] = new int[2];
	for (int j = 0; j < 2; j++)
	c[i][j] = 0;
	}


	c = strassenMulti(matrixA, matrixB, c);


	*/

	//iterativeMult(matrixA, matrixB);


	system("pause");
	for (int i = 0; i < aRows; ++i) {
		delete[] matrixA[i];
	}
	delete[] matrixA;

	for (int i = 0; i < bRows; ++i) {
		delete[] matrixB[i];
	}
	delete[] matrixB;


	return 0;
}

int** matrixInput(int i, int j)
{
	srand(time(NULL));
	int **arr = new int*[i];
	for (int x = 0; x < i; ++x)
	{
		arr[x] = new int[j];
		for (int y = 0; y < j; y++)
		{
			//cout << "[" << x << "][" << y << "]:";
			arr[x][y] = rand() % 15 + 1;
		}
	}
	return arr;
}

int** iterativeMult(int** a, int** b)
{
	int** result = new int*[aRows];;

	for (int i = 0; i < aRows; ++i)
	{
		result[i] = new int[bColumns];
		for (int j = 0; j < bColumns; j++)
			result[i][j] = 0;
	}

	for (int x = 0; x < aRows; x++)
	{
		for (int y = 0; y < bColumns; y++)
		{
			for (int z = 0; z < aColumns; z++)
			{
				result[x][y] += a[x][z] * b[z][y];
			}
		}
	}


	for (int i = 0; i < aRows; i++)
	{
		for (int j = 0; j < bColumns; j++)
			cout << result[i][j] << "  ";
		cout << endl;
	}


	return result;
}

int** strassenMulti(int** a, int** b, int ** c, int start, int end)
{
	int p1, p2, p3, p4, p5, p6, p7;

	p1 = a[start][start] * (b[start][start + 1] - b[start + 1][start + 1]);
	p2 = (a[start][start] + a[start][start + 1]) * b[start + 1][start + 1];
	p3 = (a[start + 1][start] + a[start + 1][start + 1])*b[start][start];
	p4 = a[start + 1][start + 1] * (b[start + 1][start] - b[start][start]);
	p5 = (a[start][start] + a[start + 1][start + 1])* (b[start][start] + b[start + 1][start + 1]);
	p6 = (a[start][start + 1] - a[start + 1][start + 1])*(b[start + 1][start] + b[start + 1][start + 1]);
	p7 = (a[start][start] - a[start + 1][start])*(b[start][start] + b[start][start + 1]);


	c[0][0] = p5 + p4 - p2 + p6;
	c[0][1] = p1 + p2;
	c[1][0] = p3 + p4;
	c[1][1] = p1 + p5 - p3 - p7;

	return c;
}


void strassen(int** a, int** b, int rowStart, int rowEnd, int colStart, int colEnd, int** &ans)
{
	/*
	if (rowEnd-rowStart >= 2)
	{
	strassen(a, b, rowStart, rowEnd / 2,colStart, colEnd/2, ans);
	strassen(a, b, (rowEnd / 2)+1, rowEnd, (colEnd/2)+1, colEnd, ans);

	}
	else
	strassenMulti(a, b, ans, rowStart, rowEnd);

	*/
	for (int i = 0; i < aRows; i = i + 2)
	{
		for (int j = 0; aRows; j = j + 2);

	}
	
}



void paddMatrix(int** &a, int** &b)
{
	int size;

	if (aRows > bRows) //get the highest row or column
		size = aRows;
	else
		size = bRows;

	if (aColumns > size)
		size = aColumns;
	else if (bColumns > size)
		size = bColumns;

	if ((floor(log2((float)size))) != (float)(log2(size)))
	{
		size = pow(2, (int)(ceil(log2(size))));
	}


	if (size != aRows)
	{
		int **temp = new int*[size];

		for (int i = 0; i < aRows; ++i)
		{
			temp[i] = a[i];
		}
		for (int i = aRows; i < size; i++)
		{
			temp[i] = new int[aColumns];
			for (int j = 0; j < aColumns; j++)
				temp[i][j] = 0;
		}
		a = temp;
		aRows = size;
	}

	if (size != bRows)
	{
		int **temp = new int*[size];

		for (int i = 0; i < bRows; ++i)
		{
			temp[i] = b[i];
		}
		for (int i = bRows; i < size; i++)
		{
			temp[i] = new int[bColumns];
			for (int j = 0; j < bColumns; j++)
				temp[i][j] = 0;
		}
		b = temp;
		bRows = size;
	}

	if (size != aColumns)
	{
		int* temp;
		for (int i = 0; i < aRows; i++)
		{
			temp = new int[size];
			for (int j = 0; j < aColumns; j++)
			{
				temp[j] = a[i][j];

			}
			delete[] a[i];
			a[i] = temp;

			for (int j = aColumns; j < size; j++)
				a[i][j] = 0;
		}
		aColumns = size;
	}

	if (size != bColumns)
	{
		int* temp;
		for (int i = 0; i < bRows; i++)
		{
			temp = new int[size];
			for (int j = 0; j < bColumns; j++)
			{
				temp[j] = b[i][j];

			}
			delete[] b[i];
			b[i] = temp;

			for (int j = bColumns; j < size; j++)
				b[i][j] = 0;
		}
		bColumns = size;
	}
}

void subMatrices(int**a, int**b)
{
	int **arr = new int*[aRows];
	for (int x = 0; x < aRows; ++x)
	{
		arr[x] = new int[aColumns];
	}

	for (int i = 0; i < aRows; i++)
	{
		for (int j = 0; j < aColumns; j++)
		{
			arr[i][j] = a[i][j] - b[i][j];
		}
	}


	for (int i = 0; i < bRows; i++)
	{
		for (int j = 0; j < bColumns; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}

}