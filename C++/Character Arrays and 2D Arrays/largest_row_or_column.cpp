#include<iostream>
#include<climits>
using namespace std;

int main() {
    int testCases;
    cin>>testCases;
    while (testCases > 0)
    {
        int m, n, arr[100][100], rowInd = 0, rowLargest = INT_MIN, colInd = 0, columnLargest = INT_MIN;
        cin>>m>>n;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        
        // Row largest
        for(int i=0; i<m; i++) {
            int rowSum = 0;
            for(int j=0; j<n; j++) {
                rowSum += arr[i][j];
            }
            if(rowSum > rowLargest){
                rowLargest = rowSum;
                rowInd = i;
            }
            
        }

        // Column largest
        for(int i=0; i<n; i++) {
            int columnSum = 0;
            for(int j=0; j<m; j++) {
                columnSum += arr[j][i];
            }
            if(columnSum > columnLargest){
                columnLargest = columnSum;
                colInd = i;
            }
        }

        if(rowLargest >= columnLargest)
            cout<<"row "<<rowInd<<" "<<rowLargest<<endl;
        else
            cout<<"column "<<colInd<<" "<<columnLargest<<endl;
        
        cout<<endl;
        testCases--;
    }
    
}