#include <bits/stdc++.h> 
using namespace std; 

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++) 
    {  
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
        swap(&arr[min_idx], &arr[i]); 
    } 
}   
void sortedMerge(int a[], int b[], int res[], int n, int m) 
{ 
    selectionSort(a,n); 
    selectionSort(b,m); 
    int i = 0, j = 0, k = 0; 
    while (i < n && j < m) { 
        if (a[i] <= b[j]) { 
            res[k] = a[i]; 
            i += 1; 
            k += 1; 
        } else { 
            res[k] = b[j]; 
            j += 1; 
            k += 1; 
        } 
    }     
    while (i < n){ 
        res[k] = a[i]; 
        i += 1; 
        k += 1; 
    }     
    while (j < m){ 
        res[k] = b[j]; 
        j += 1; 
        k += 1; 
    } 
} 
int main() 
{ 
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    int res[n + m]; 
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];    
    sortedMerge(a, b, res, n, m); 
    cout << "Sorted merge list :"; 
    for (int i = 0; i < n + m; i++) 
        cout << " " << res[i]; 
    return 0; 
} 
