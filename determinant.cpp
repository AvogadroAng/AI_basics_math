#include <iostream>

int det_calc(int[20][20], int);

int main()
{
	int matrix[20][20] = {0}, l = 0, det = 0, i = 0, j = 0;
	
	std::cout << "Enter the length of the matrix:" << std::endl;
	std::cin >> l;
	
	for(j = 0, i = 0; i < l; i++)
	{
		std::cout << "Enter " << i+1 << "ROW:" << std::endl;
		for(j = 0; j < l; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
	
	det = det_calc(matrix, l);
	std::cout << "DETERMINANT: " << det << std::endl;
}

int det_calc(int arr[20][20], int l)
{
	if(l == 2)
	{
		return (arr[0][0]*arr[1][1] - arr[1][0]*arr[0][1]);
	}
	
	else
	{
		int new_mat[20][20] = {0}, i,j,k, det = 0, c = 1;
		
		for(k = 0,j = 0,i = 0; i < l; i++)
		{
			for(j = 1; j < l; j++)
			{
				for(k = 1; k < l; k++)
				{
					new_mat[j-1][k-1] = arr[j][k];
				}
			}
			det = det + c*arr[0][i]*det_calc(new_mat, l-1);
			c = -1*c;
		}
		return det;
	}
}

		
		
				
