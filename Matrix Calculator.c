#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <windows.h>
#define MAX_SIZE 10

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_RESET   "\x1b[0m"
#define COLOR_MAGENTA "\033[0;35m"
#define COLOR_CYAN "\033[0;36m"
#define PINK_TEXT "\033[1;38;2;255;192;203m"
#define ORANGE_TEXT "\033[38;2;255;165;0m"
#define ORANGE_BOLD_TEXT "\033[1;38;2;255;165;0m"

#define TEXT_BOLD "\033[1m"
#define TEXT_RESET "\033[0m"

void identity_mat(int rA,int cA,int matA[rA][cA])
{
	int i, j, count1, count2, x;
	for(i=0;i<rA;i++)
    {
    	for(j=0;j<cA;j++)
    	{
    		if(i==j)
    		{
    			if(matA[i][j]==1)
    			{
    				count1++;
				}
			}
			else
			{
				if(matA[i][j]==0)
				{
					count2++;
				}
			}
		}
	}
	x = rA * cA - rA;
	if(count1==rA && count2==x)
	{
		printf(COLOR_CYAN"Matrix is an identity matrix!\n"COLOR_RESET);
	}
	else
	{
		printf(COLOR_GREEN"Matrix is not an identity matrix!\n"COLOR_RESET);
	}
}
void scalar_matrix (int rA, int cA, int matA[rA][cA])
{
	int x, y, i, j, count1=0, count2=0;
	x = matA[0][0];
	for(i=0;i<rA;i++)
    {
    	for(j=0;j<cA;j++)
    	{
    		if(i==j)
    		{
    			if(matA[i][j]==x)
    			{
    				count1++;
				}
			}
			else
			{
				if(matA[i][j]==0)
				{
					count2++;
				}
			}
		}
	}
	y = rA * cA - rA;
	if(count1==y && count2==rA)
	{
		printf(COLOR_CYAN"Matrix is a scalar matrix!\n"COLOR_RESET);
	}
	else
	{
		printf(COLOR_GREEN"Matrix is not a scalar matrix!\n"COLOR_RESET);
	}
}
void diagnol_matrix (int rA, int cA, int matA[rA][cA])
{
	int x, i, j, count=0;
	for(i=0;i<rA;i++)
    {
    	for(j=0;j<cA;j++)
    	{
    		if(i!=j)
    		{
    			if(matA[i][j]==0)
    			{
    				count++;
				}
			}
		}
	}
	x = rA * cA - rA;
	if(count==x)
	{
		printf(COLOR_CYAN"Matrix is a diagnol matrix!\n"COLOR_RESET);
	}
	else
	{
		printf(COLOR_GREEN"Matrix is not a diagnol matrix!\n"COLOR_RESET);
	}
}
void upper_triangular(int rA,int cA,int matA[rA][cA])
{
    int i, j, count1=0, count2=0;
    if(rA!=cA)
    {
    	printf(COLOR_RED"This identity can not be verified for this matrix"COLOR_RESET);
	}
	else
	{
		for(i=0; i<rA; i++)
        {
            for(j=0; j<cA; j++)
        	{
        		if(i > j)
        		{
    	    		if( matA[i][j] == 0)
    	    		{
    	    			count1++;
	        		}
    	    		else
    	    		{
    	    			count2++;
	        			printf(COLOR_GREEN"Entered matrix is not an upper triangular matrix!\n"COLOR_RESET);
		    			i = rA - 1;
		    		    j = cA - 1;
		    		}
		        }
	    	}
    	}
        if(count1!=0 && count2==0)
    	{
			printf(COLOR_CYAN"Entered matrix is an upper triangular matrix!\n"COLOR_RESET);
		}
	}					
}
void lower_triangular(int rA,int cA,int matA[rA][cA])
{
    int i,j,count1=0,count2=0;
    if(rA!=cA)
    {
    	printf("This identity can not be verified for this matrix");
	}
	else
	{
		for(i=0;i<rA;i++)
    {
        for(j=0;j<cA;j++)
        {
     	    if(i < j)
     	    {
     	        if( matA[i][j] == 0)
     		    {
     			    count1++;
				}
				else
				{
					count2++;
					printf(COLOR_GREEN"Entered matrix is not a lower triangular matrix!\n"COLOR_RESET);
					i = rA - 1;
					j = cA - 1;
				}
			}
		}
	}
	if(count1!=0 && count2==0)
			{
				printf(COLOR_CYAN"Entered matrix is a lower triangular matrix!\n"COLOR_RESET);
			}
	}
   
}
void row_matrix(int rA)
{
	if(rA==1)
	{
		printf(COLOR_CYAN"Entered matrix is a row matrix!"COLOR_RESET);
	}
	else
	{
		printf(COLOR_GREEN"Entered matrix is not a row matrix!"COLOR_RESET);
	}
}
void column_matrix(int cA)
{
	if(cA==1)
	{
		printf(COLOR_CYAN"Entered matrix is a column matrix!"COLOR_RESET);
	}
	else
	{
		printf(COLOR_GREEN"Entered matrix is not a column matrix!"COLOR_RESET);
	}
}
void square_matrix(int rA,int cA)
{
	if(cA==rA)
	{
		printf(COLOR_CYAN"Entered matrix is a square matrix!"COLOR_RESET);
	}
	else
	{
		printf(COLOR_GREEN"Entered matrix is not a square matrix!"COLOR_RESET);
	}
}
void rectangular_matrix(int rA,int cA)
{
	if(cA!=rA)
	{
		printf(COLOR_CYAN"Entered matrix is a rectangular matrix!"COLOR_RESET);
	}
	else
	{
		printf(COLOR_GREEN"Entered matrix is not a rectangular matrix!"COLOR_RESET);
	}
}
void null_matrix(int rA,int cA,int mat[rA][cA])
{
	int i, j, cnt=0;
	for(i=0; i<rA; i++)
	{
		for(j=0; j<cA; j++)
		{
			if(mat[i][j]==0)
			{
				cnt++;
			}
		}
	}
	if(cnt==rA*cA)
	{
		printf(COLOR_CYAN"Entered matrix is a null matrix!"COLOR_RESET);
	}
	else
	{
		printf(COLOR_GREEN"Entered matrix is not a null matrix!"COLOR_RESET);
	}
}
/*function for adjoint:
void adjoint(int rA,int cA,int matA[rA][cA])
{
	int i, j, count=0;
	int adj[rA][cA];
	if(rA==1 && cA==1)
    {
    	adj[0][0] = matA[0][0];
    	printf("\nAdjoint of the matrix:\n");
    	for(i=0; i<rA; i++)
    	{
	    	for(j=0; j<cA; j++)
		    {
		    	printf(COLOR_YELLOW" %d "COLOR_RESET,adj[i][j]);
	    	}
	    	printf("\n");
    	}  
	}
	else if(rA==2 && cA==2)
	{
        adj[1][1] = matA[0][0];
	    adj[0][1] = -matA[0][1];
	    adj[1][0] = -matA[1][0];   
	    adj[0][0] = matA[1][1];
	    printf("\nAdjoint of the matrix:\n");
	    for(i=0; i<rA; i++)
    	{
		    for(j=0; j<cA; j++)
		    {
		    	printf(COLOR_YELLOW" %d "COLOR_RESET,adj[i][j]);
	    	}
	    	printf("\n");
    	}						
	}                    
	else if(rA==3 && cA==3)
	{
        int A1=(matA[1][1]*matA[2][2] - matA[2][1]*matA[1][2]);
	    int A2=(matA[1][2]*matA[2][0] - matA[1][0]*matA[2][2]);
	    int A3=(matA[1][0]*matA[2][1] - matA[2][0]*matA[1][1]);
	    int A4=(matA[0][2]*matA[2][1] - matA[0][1]*matA[2][2]);
	    int A5=(matA[0][0]*matA[2][2] - matA[0][2]*matA[2][0]);
	    int A6=(matA[0][1]*matA[2][0] - matA[0][0]*matA[2][1]);
	    int A7=(matA[0][1]*matA[1][2] - matA[0][2]*matA[1][1]);
	    int A8=(matA[0][2]*matA[1][0] - matA[0][0]*matA[1][2]);
	    int A9=(matA[0][0]*matA[1][1] - matA[0][1]*matA[1][0]);
	    printf("\nAdjoint of the matrix:\n");
	    printf(COLOR_YELLOW" %d\t%d\t%d\n %d\t%d\t%d\n %d\t%d\t%d"COLOR_RESET,A1,A4,A7,A2,A5,A8,A3,A6,A9);
	}
	else
	{
		printf(COLOR_RED"This calculator can not calculate this range of matrix!\n"COLOR_RESET);
	}				
}
*/
//function for determinant:
void getCofactor(int mat[MAX_SIZE][MAX_SIZE], int temp[MAX_SIZE][MAX_SIZE], int p, int q, int n) 
{
    int i=0, j=0, r, c;
    for (r=0; r<n; r++) 
	{
        for (c=0; c<n; c++) 
		{
            if (r!=p && c!=q) 
			{
                temp[i][j++] = mat[r][c];
                if (j == n - 1) 
				{
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant(int mat[MAX_SIZE][MAX_SIZE], int n) 
{
    int det=0;
    if (n==1) 
	{
        det = mat[0][0];
    } 
	else if (n == 2) 
	{
        det= (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
    }
    else 
	{
        int temp[MAX_SIZE][MAX_SIZE];
        int sign=1, f;
        for (f=0; f<n; f++) 
		{
            getCofactor(mat, temp, 0, f, n);
            det += sign*mat[0][f]*determinant(temp, n-1);
            sign = -sign;
        }
    }
    return det;
}

int main()
{
	int choice,i,j,option;
	printf("\n\n\n\n\n");
	printf(TEXT_BOLD COLOR_YELLOW"\t\t\t\t\t\tJAZ MATRIX CALCULATOR!\n"COLOR_RESET TEXT_RESET);
	sleep(3);
	system("cls");
	printf("\n");
	while(1)
	{
    	printf("What do you want to perform?\n\n");
    	printf(COLOR_BLUE "1. OPERATIONS \t" COLOR_RESET);
    	printf(COLOR_MAGENTA "2. IDENTITIES\n" COLOR_RESET);
    	printf("\n\nSelect an option: ");
    	scanf("%d", &option);
    	system ("cls");
    	printf("\n");
    	if(option<1 || option>2)
    	{
    		printf(COLOR_RED"Invalid choice! Enter again.\n\n"COLOR_RESET);
    		continue;
    	}
    	if (option==1)
		{
    		printf(ORANGE_BOLD_TEXT"Here are a few types of matrix calculations:\n"TEXT_RESET);
    		printf("\n");
		    printf(COLOR_GREEN"1. Addition\t        \t2. Subtraction\n");
    	    printf("3. Scalar Division\t\t4. Scalar Multiplication\n");
	        printf("5. Matrix Multiplication\t6. Determinant\n");
    	    printf("7. Adjoint\t        \t8. Transpose\n");
    	    printf("9. Inverse\n"COLOR_RESET);
    	    printf("\nSelect an option: ");
    	    scanf("%d", &choice);
    	    system ("cls");
    	    if(choice<1 || choice>9)
			{
    	    	printf(COLOR_RED"\nEnter Valid option number\n"COLOR_RESET);
    	    	continue;
			}
    	    int rA,cA;
           	printf("Enter the no. of rows of matrix: ");
        	scanf("%d",&rA);
        	printf("Enter the no. of columns of matrix: ");
    	    scanf("%d",&cA);
    	    if (choice == 7 || choice == 9)
    	    {
    	    	if (rA>3 && cA>3)
    	    	{
    	    		printf("Calculator cannot solve for this matrix size.\n");
    	    		printf("\n");
    	    		system ("cls");
    	    		continue;
				}
			}
			int matA[MAX_SIZE][MAX_SIZE];
        	printf("\n");
        	if (choice!=7 && choice!=9)
        	{
				for (i=0; i<rA; i++)
            	{
        	    	for (j=0; j<cA; j++)
        	    	{
        	    		printf(PINK_TEXT"Enter the element of matrix: "TEXT_RESET);
                        scanf("%d", &matA[i][j]);
			    	}
		    	}
		    	printf("\n");
			}
    	    if(choice==1)
		    {
		        int rB, cB;
		        printf("Enter the no. of rows of the second matrix: ");
            	scanf("%d", &rB);
        	    printf("Enter the no. of columns of the second matrix: ");
        	    scanf("%d", &cB);
        	    printf("\n");
        	    int matB[rB][cB];
        	    if (rA==rB && cA==cB)
        	    {
                	for (i=0; i<rB; i++)
            	    {
            		    for (j=0; j<cB; j++)
        	    	    {
    	        		    printf(PINK_TEXT"Enter the element of the second matrix:"TEXT_RESET);
    	        		    scanf ("%d", &matB[i][j]);
    	        	    }
        	        }
            	    printf ("\n");
            	    int matC[rA][cA];
    	            for (i=0; i<rA; i++)
                 	{
            	     	for (j=0; j<cA; j++)
            		    {  
            			    matC[i][j] = matA[i][j] + matB[i][j];
        	    	    } 
            	    }
            	    printf("\n");
            	    printf("Matrix A:\n");
            	    for (i=0; i<rA; i++)
            	    {
            	        for (j=0; j<cA; j++)
            	      	{
        	    		    printf(COLOR_CYAN" %d "COLOR_RESET, matA[i][j]);
    	        	    }
        	    	    printf("\n");
        	        }
        	        printf("\n");
            	    printf("Matrix B:\n");
            	    for (i=0; i<rB; i++)
        	        {
    			        for (j=0; j<cB; j++)
                        {
            			    printf(COLOR_CYAN" %d "COLOR_RESET, matB[i][j]);
        	    	    }
        	    	    printf("\n");
            	    }
            	    printf("\n");
            	    printf("Resultant matrix after addition:\n");
            	    for (i=0; i<rA; i++)
            	    {
            		    for (j=0; j<cA; j++)
            		    {
            			    printf(COLOR_YELLOW" %d  "COLOR_RESET, matC[i][j]);
            		    }
            		    printf("\n");
            	    } 	
			    }
        	    else
	    	    {
	    		    printf(COLOR_RED"Addition not possible!"COLOR_RESET);
	    	    }		
    	    }
    	    else if(choice==2)
    	    {
    		    int rB, cB, i, j;
        	    printf("Enter the no. of rows of the second matrix: ");
        	    scanf("%d", &rB);
        	    printf("Enter the no. of columns of the second matrix: ");
        	    scanf("%d", &cB);
        	    printf("\n");
        	    int matB[rB][cB];
        	    if (rA==rB && cA==cB)
        	    {
            	    for (i=0; i<rB; i++)
            	    { 
            		    for (j=0; j<cB; j++)
        	    	    {
        	    		    printf(PINK_TEXT"Enter the element of the second matrix:"TEXT_RESET);
    	        		    scanf ("%d", &matB[i][j]);
        	    	    }
            	    }
            	    printf ("\n");
            	    int matC[rA][cA];
        	        for (i=0; i<rA; i++)
            	    {
            		    for (j=0; j<cA; j++)
            		    {
            			    matC[i][j] = matA[i][j] - matB[i][j];
    	        	    }
            	    }
            	    printf("\n");
            	    printf("Matrix A:\n");
            	    for (i=0; i<rA; i++)
            	    {
            		    for (j=0; j<cA; j++)
            		    {
        	    		    printf(COLOR_CYAN" %d "COLOR_RESET, matA[i][j]);
        	    	    }
        	    	    printf("\n");
        	        }
        	        printf("\n");
            	    printf("Matrix B:\n");
            	    for (i=0; i<rB; i++)
        	        {
        		        for (j=0; j<cB; j++)
            		    {
            			    printf(COLOR_CYAN" %d "COLOR_RESET, matB[i][j]);
            		    }
            		printf("\n");
            	    }
            	    printf("\n");
            	    printf("Resultant matrix after subtraction:\n");
            	    for (i=0; i<rA; i++)
            	    {
            		    for (j=0; j<cA; j++)
            		    {
            			    printf(COLOR_YELLOW" %d  "COLOR_RESET, matC[i][j]);
            		    }
            		printf("\n");
            	    }
        	    }
        	    else
            	{
        	    	printf(COLOR_RED"Subtraction not possible!"COLOR_RESET);
        	    }
            }
        	else if(choice==3)
    	    {
    	        int num;
    	        printf("Enter the scalar number you want to divide your matrix with: ");
    	        scanf("%d", &num);
    	        printf("\n");
    	        printf("Original matrix:\n");
    	        for(i=0; i<rA; i++)
    		    {
    		        for(j=0; j<cA; j++)
    			    {
    		        	printf(COLOR_CYAN" %d "COLOR_RESET,matA[i][j]);	
    		        }
    		        printf("\n");
    	        }
    	        printf("\n");
    	        for(i=0; i<rA; i++)
    		    {
    		        for(j=0;j<cA;j++)
    			    {   
    			        matA[i][j] = matA[i][j] / num;
    		       }
    	        }
				//the resultant matrix only gives the integer value after being divided by the scalar number.  
    	        printf("Resultant matrix after scalar division:\n");
    	        for(i=0; i<rA; i++)
    		    {
    		        for(j=0; j<cA; j++)
    			    {   
    		    	    printf(COLOR_YELLOW"%d "COLOR_RESET,matA[i][j]);	
    		        }
        		    printf("\n");
    	        }
    	    }  
    	    else if(choice==4)
         	{
    		    int k, i, j;
                printf("Enter the scalar number you want to multiply your matrix with: ");
                scanf("%d", &k);
                printf("\n");
                printf("Original matrix:\n");
                for (i=0; i<rA; i++)
                {
                    for (j=0; j<cA; j++)
                    {
                        printf(COLOR_CYAN" %d "COLOR_RESET, matA[i][j]);
                    }
                    printf("\n");
                }
                for (i=0; i<rA; i++)
                {
                    for (j=0; j<cA; j++)
                    {   
                        matA[i][j] = k * matA[i][j];
                    }
                }
                printf("\n");
                printf("Resultant matrix after scalar multiplication:\n"); 
                for (i=0; i<rA; i++)
                {
                    for (j=0; j<cA; j++)
                    {   
                        printf(COLOR_YELLOW" %d "COLOR_RESET, matA[i][j]);
                    }
                    printf("\n");
                }
         	}
            else if(choice==5)
    	    {
    	        int rB, cB, i, j, k, l, m, p, q, sum=0;
                printf("Enter the no. of rows of the second matrix: ");
                scanf("%d", &rB);
		        printf("Enter the no. of columns of the second matrix: ");
                scanf("%d", &cB);
                printf("\n");
	            int matB[rB][cB], result[rA][cB];
	            if(rA==cB)
	    	    {
        	        for(i=0; i<rB; i++)
		    	    {
		                for(j=0; j<cB; j++)
		    		    {
			                printf(PINK_TEXT"Enter the element of second matrix: "TEXT_RESET);
			                scanf("%d",&matB[i][j]);
		                }
            	    }
            	    for(l=0; l<rA; l++)
		    	    {
    	        	    for(m=0; m<cB; m++)
		    		    {
    	    	    	    for(k=0; k<rB; k++)
		    			    {  
		        		        sum = sum + (matA[l][k]*matB[k][m]);
                	    	}
    	            	    result[l][m]=sum;
    	            	    sum=0;
		        	    }	
	        	    }
	        	    printf("\n");
            	    printf("Matrix A:\n");
	                for(i=0;i<rA;i++)
			        {
		                for(j=0;j<cA;j++)
				        {
		    	            printf(COLOR_CYAN" %d "COLOR_RESET,matA[i][j]);
		                }
	        	        printf("\n");
	                }
	                printf("\n");
	                printf("Matrix B:\n");
	                for(i=0; i<rB; i++)
		    	    {
		                for(j=0; j<cB; j++)
		    		    {
		        	        printf(COLOR_CYAN" %d "COLOR_RESET,matB[i][j]);
		                }
		                printf("\n");
                    }
                    printf("\n");
                    printf("Resultant matrix after matrix multiplication:\n");
		            for(p=0; p<rA; p++)
		    	    {
    	        	    for(q=0; q<cB; q++)
		    	    	{
    	        	     	printf(COLOR_YELLOW" %d "COLOR_RESET,result[p][q]);	
		            	}
	                	printf("\n");
	        	    }	
        	    }
	            else
	        	{
	            	printf(COLOR_RED"Multiplication not possible!"COLOR_RESET);
	    	    }
            }
            else if(choice==6)
    	    {
				if (rA != cA)
				{
					printf(COLOR_RED"Determinant not possible!\n"COLOR_RESET);
				}
				else
				{
					printf("Matrix:\n");
                    for (i=0; i<rA; i++) 
			    	{
                        for (j=0; j<cA; j++) 
			    		{
                            printf(COLOR_CYAN" %d  "COLOR_RESET, matA[i][j]);
                        }
                        printf("\n");
                    }
                    int det = determinant(matA, rA);
                    printf("Determinant is: ");
                    printf(COLOR_YELLOW"%d\n"COLOR_RESET, det);
				}
            }
        	else if(choice==7)
      	    {
    	        if(rA!=cA || rA==0 || cA==0)
    	        { 
    	        	printf(COLOR_RED"Adjoint not possible!"COLOR_RESET);
    	        }
    	        else
    	        {
	    	        for (i=0; i<rA; i++)
                	{
                		for (j=0; j<cA; j++)
                		{
                			printf(PINK_TEXT"Enter the element of matrix: "TEXT_RESET);
                            scanf("%d", &matA[i][j]);
	        			}
	        		}
		        	printf("\n");
	    			int i, j, count=0;
                	int adj[rA][cA];
                	if(rA==1 && cA==1)
                    {
    	                adj[0][0] = matA[0][0];
                    	printf("\nAdjoint of the matrix:\n");
                    	for(i=0; i<rA; i++)
                    	{
	                    	for(j=0; j<cA; j++)
	                	    {
	                	    	printf(COLOR_YELLOW" %d "COLOR_RESET,adj[i][j]);
	                    	}
	                    	printf("\n");
                    	}  
                	}
                	else if(rA==2 && cA==2)
                	{
                        adj[1][1] = matA[0][0];
                	    adj[0][1] = -matA[0][1];
	                    adj[1][0] = -matA[1][0];   
	                    adj[0][0] = matA[1][1];
	                    printf("\nAdjoint of the matrix:\n");
	                    for(i=0; i<rA; i++)
                       	{
	                	    for(j=0; j<cA; j++)
	                	    {
	                	    	printf(COLOR_YELLOW" %d "COLOR_RESET,adj[i][j]);
	                    	}
	    	                printf("\n");
                    	}						
                	}                    
	else if(rA==3 && cA==3)
	{
        int A1=(matA[1][1]*matA[2][2] - matA[2][1]*matA[1][2]);
	    int A2=(matA[1][2]*matA[2][0] - matA[1][0]*matA[2][2]);
	    int A3=(matA[1][0]*matA[2][1] - matA[2][0]*matA[1][1]);
	    int A4=(matA[0][2]*matA[2][1] - matA[0][1]*matA[2][2]);
	    int A5=(matA[0][0]*matA[2][2] - matA[0][2]*matA[2][0]);
	    int A6=(matA[0][1]*matA[2][0] - matA[0][0]*matA[2][1]);
	    int A7=(matA[0][1]*matA[1][2] - matA[0][2]*matA[1][1]);
	    int A8=(matA[0][2]*matA[1][0] - matA[0][0]*matA[1][2]);
	    int A9=(matA[0][0]*matA[1][1] - matA[0][1]*matA[1][0]);
	    printf("\nAdjoint of the matrix:\n");
	    printf(COLOR_YELLOW" %d\t%d\t%d\n %d\t%d\t%d\n %d\t%d\t%d"COLOR_RESET,A1,A4,A7,A2,A5,A8,A3,A6,A9);
	}
	else
	{
		printf(COLOR_RED"This calculator can not calculate this range of matrix!\n"COLOR_RESET);
	}
	        	}
            }
    	    else if(choice==8)
    	    {
    	        int i, j, transpose[cA][rA];
    	        for(i=0; i<rA; i++)
    		    {
    		        for(j=0; j<cA; j++)
    			    {
	    		        transpose[j][i] = matA[i][j];
	    	        }
	            }
	            printf("Original matrix:\n");
	            for (i=0; i<rA; i++)
	            {
	        	    for (j=0; j<cA; j++)
	        	    {  
	        	    	printf(COLOR_CYAN" %d "COLOR_RESET, matA[i][j]);
				    } 
				    printf("\n");
			    }
			    printf("\n");
			    printf("Transposed matrix:\n");
	            for(i=0; i<cA; i++)
	    	    {
	    	        for(j=0; j<rA; j++)
		    	    {  
		    	        printf(COLOR_YELLOW" %d "COLOR_RESET,transpose[i][j]);
		            }
		            printf("\n");
	            }  	
        	}
        	else if(choice==9)
        	{
    		    float matA[rA][cA];
				for (i=0; i<rA; i++)
                {
                	for (j=0; j<cA; j++)
                	{
                		printf(PINK_TEXT"Enter the element of matrix: "TEXT_RESET);
                        scanf("%f", &matA[i][j]);
	        		}
	        	}
		        printf("\n");
				float det = determinant(matA, rA);
    		    float adj[rA][cA], inv[rA][cA];
    		    if(rA==1 && cA==1)
                {
					inv[0][0] = matA[0][0] / det;
					printf("\nInverse of the Matrix:\n");
                	for(i=0; i<rA; i++)
                	{
            	    	for(j=0; j<cA; j++)
            		    {
            		    	printf(COLOR_YELLOW" %f "COLOR_RESET,inv[i][j]);
            	    	}
	                	printf("\n");
                	}  
            	}
            	else if(rA==2 && cA==2)
            	{
                    adj[1][1] = matA[0][0];
            	    adj[0][1] = -matA[0][1];
            	    adj[1][0] = -matA[1][0];   
            	    adj[0][0] = matA[1][1];
            	    
            	    inv[0][0] = adj[0][0] / det;
            	    inv[0][1] = adj[0][1] / det;
            	    inv[1][0] = adj[1][0] / det;
            	    inv[1][1] = adj[1][1] / det;
            	    printf("\nInverse of the Matrix:\n");
            	    for(i=0; i<rA; i++)
                	{
	            	    for(j=0; j<cA; j++)
	            	    {
	            	    	printf(COLOR_YELLOW" %f "COLOR_RESET,inv[i][j]);
	                	}
	                	printf("\n");
                	}						
            	}                    
            	else if(rA==3 && cA==3)
            	{
                    float A1=(matA[1][1]*matA[2][2] - matA[2][1]*matA[1][2]);
            	    float A2=(matA[1][2]*matA[2][0] - matA[1][0]*matA[2][2]);
            	    float A3=(matA[1][0]*matA[2][1] - matA[2][0]*matA[1][1]);
	                float A4=(matA[0][2]*matA[2][1] - matA[0][1]*matA[2][2]);
	                float A5=(matA[0][0]*matA[2][2] - matA[0][2]*matA[2][0]);
	                float A6=(matA[0][1]*matA[2][0] - matA[0][0]*matA[2][1]);
	                float A7=(matA[0][1]*matA[1][2] - matA[0][2]*matA[1][1]);
	                float A8=(matA[0][2]*matA[1][0] - matA[0][0]*matA[1][2]);
	                float A9=(matA[0][0]*matA[1][1] - matA[0][1]*matA[1][0]);
	                A1 = A1 / det;
	                A2 = A2 / det;
	                A3 = A3 / det;
	                A4 = A4 / det;
	                A5 = A5 / det;
	                A6 = A6 / det;
	                A7 = A7 / det;
	                A8 = A8 / det;
	                A9 = A9 / det;
	                printf("\nInverse of the matrix:\n");
	                printf(COLOR_YELLOW" %f\t%f\t%f\n %f\t%f\t%f\n %f\t%f\t%f"COLOR_RESET,A1,A4,A7,A2,A5,A8,A3,A6,A9);
            	}
            	else
            	{
            		printf(COLOR_RED"This calculator can not calculate this range of matrix!\n"COLOR_RESET);
            	}	
            }
            char exit;
            printf(COLOR_MAGENTA"\n\nPress 0 to exit or any other key to continue with other calculations "COLOR_RESET);
            scanf(" %c",&exit);
            if(exit=='0')
			{
            	break;
			}
			else
			{
				continue;
			}
        }
        else if(option==2)
		{
        	printf(ORANGE_BOLD_TEXT"Here are a few types of matrix identities:\n\n"TEXT_RESET);
		    printf(COLOR_GREEN"1. Row Matrix\t        \t2. Column Matrix\n");
    	    printf("3. Rectangle Matrix\t\t4. Square Matrix\n");
	        printf("5. Identity Matrix\t\t6. Scalar Matrix\n");
    	    printf("7. Diagnol Matrix\t        8. Upper Triangle Matrix\n");
    	    printf("9. Lower Triangle Matrix\t10. Null Matrix\n"COLOR_RESET);
    	    printf("\n");
    	    printf("Select an option: ");
    	    scanf("%d", &choice);
    	    system("cls");
    	    if(choice<1 || choice>10)
			{
    	    	printf(COLOR_RED"\nEnter a valid option!"COLOR_RESET);
    	    	continue;
			}
    	    int row,col,i,j;
    	    printf("Enter the no. of rows of matrix: ");
        	scanf("%d",&row);
        	printf("Enter the no. of columns of matrix: ");
    	    scanf("%d",&col);
    	    printf("\n");
        	int mat[row][col];
        	for(i=0;i<row;i++)
    		{
    		    for(j=0;j<col;j++)
    			{
    			    printf(PINK_TEXT"Enter the element of matrix: "TEXT_RESET);
    			    scanf("%d", &mat[i][j]);
    		    }
        	}
        	printf("\n");
        	for(i=0;i<row;i++)
    		{
    		    for(j=0;j<col;j++)
    			{
    			    printf(COLOR_CYAN" %d "COLOR_RESET, mat[i][j]);
    		    }
    		    printf("\n");
        	}
        	printf("\n");
        	if(choice==1)
			{
        		row_matrix(row);
			}
			if(choice==2)
			{
        		column_matrix(row);
			}
			if(choice==3)
			{
        		rectangular_matrix(row,col);
			}
			if(choice==4)
			{
        		square_matrix(row,col);
			}
			if(choice==5)
			{
        		identity_mat(row,col,mat);
			}
			if(choice==6)
			{
        		scalar_matrix(row,col,mat);
			}
			if(choice==7)
			{
        		diagnol_matrix(row,col,mat);
			}
			if(choice==8)
			{
        		upper_triangular(row,col,mat);
			}
			if(choice==9)
			{
        		lower_triangular(row,col,mat);
			}
			if(choice==10)
			{
        		null_matrix(row,col,mat);
			}
		    char exit;
            printf(COLOR_MAGENTA"\n\nPress 0 to exit or any other key to continue with other calculations "COLOR_RESET);
            scanf(" %c",&exit);
            if(exit=='0')
			{
           	    break;
		    }   
		    else
		    {
		    	system("cls");
			    continue;
			}	  
		}
	}
}