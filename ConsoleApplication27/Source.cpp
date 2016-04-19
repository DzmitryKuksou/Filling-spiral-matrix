#include <iostream>
using namespace std;
int** matrix(int);
int** EnterPoSpiraliMatrix(int**, int);
void DisplayMatrix(int**, int);
int main()
{
	int n;
	cout << "Enter size of matrix:";
	cin >> n;
	int** a = matrix(n);
	EnterPoSpiraliMatrix(a, n);
	DisplayMatrix(a, n);
	system("pause");
}
int** matrix(int n)
{
	int** matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}
	return matrix;
}
int** EnterPoSpiraliMatrix(int** matrix, int n)
{
	int k, l;
	k = l = n / 2;
	if (!k)
	{
		cin >> matrix[0][0];
		return matrix;
	}
	for (int h = 0, i = 0, j = 0; h < n / 2; h++)
	{
		if (k == l)
		{
			int s = k, g = l;
			if (!h)
			{
				cin >> matrix[s][g];
			}
			i++; j++;
			for (;;)
			{


				if (k == l)
				{
					l++; cin >> matrix[k][l];
					for (;;)
					{
						k--;
						if (k < n / 2 - i)break;

						cin >> matrix[k][l];
					}
					k++;
				}
				if (k < l)
				{
					for (;;)
					{
						l--;
						if (l < n / 2 - j)break;
						cin >> matrix[k][l];
					}
					l++;
				}
				if (k == l)
				{
					for (;;)
					{
						k++;
						if (k > n / 2 + i)break;
						cin >> matrix[k][l];
					}
					k--;
				}
				if (k > l)
				{
					for (;;)
					{
						l++;
						if (l > n / 2 + j)break;
						cin >> matrix[k][l];
					}
					l--;
				}
				if (k == l && k > s)break;

			}
		}
	}
	return matrix;
}
void DisplayMatrix(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(4);
			cout << matrix[i][j];

		}
		cout << endl;
	}
}