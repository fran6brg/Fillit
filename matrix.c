int m[4][4] = {
	{11, 12, 13, 14},
	{21, 22, 23, 24},
	{31, 32, 33, 34},
	{41, 42, 43, 44}
};

void	ft_swap(int *a, int *b)
{
	int broker;

	broker = *a;
	*a = *b;
	*b = broker;
}

void print_matrix(int m[4][4], int n)
{
	 printf("\n");
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         printf(" %d ", m[i][j]);
      }
      printf("\n");
   }
	 printf("\n");
}


	print_matrix(m, 4);
	int r;
	int c;

	//reverse elements on col order
	r = -1;
	while(++r < 4)
	{
		c = r - 1;
		while(++c < 4)
			ft_swap(&m[r][c], &m[c][r]);
	}
	//reverse elements on row order
	r = -1;
	while(++r < 4)
	{
		c = -1;
		while(++c < 4/2)
			ft_swap(&m[r][c], &m[r][4-c-1]);
	}
	print_matrix(m, 4);
