// C++ program to find the largest rectangle of 1's with swapping
// of columns allowed.


#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int A[16][16];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)cin>>A[i][j];
        //step 1:to make a temporary array to store the count of consecutive 1's in original matrix 
	   	//temp array to store count of 1's is hist[][]
        int temp[m][n];

		for (int i = 0; i < n; i++) {
		    temp[0][i]=A[0][i];
		    // Fill remaining rows of hist[][]
		    for (int j = 1; j < m; j++)
			temp[j][i] = (A[j][i] == 0) ? 0 : temp[j - 1][i] + 1;
		}

	// Step 2: Sort rows of hist[][] in non-increasing order
        for (int i = 0; i < m; i++) {
            int count[m + 1] = { };

            // counting occurrence
            for (int j = 0; j < n; j++)
                count[temp[i][j]]++;

            // Traverse the count array from right side
            int col_no = 0;
            for (int j = m; j >= 0; j--) {
                if (count[j] > 0)
                {
                    for (int k = 0; k < count[j]; k++) {
                        temp[i][col_no] = j;
                        col_no++;
                    }
                }
            }
        }

	// Step 3: Traverse the sorted hist[][] to find maximum area
        int curr_area, max_area = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                curr_area = (j + 1) * temp[i][j];
                if (curr_area > max_area)
                    max_area = curr_area;
            }
        }
        cout<<max_area<<endl;
    }
    return 0;
}

