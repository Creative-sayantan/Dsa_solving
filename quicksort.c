#include<stdio.h>
int partition(int arr[], int low, int high) 
{
int temp;
int pivot = arr[high];
int i = (low - 1); 
for (int j = low; j <= high - 1; j++)
{ 
if (arr[j] <= pivot) 
{ 
i++;
temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
} 
} 
temp = arr[i + 1];
arr[i + 1] = arr[high];
arr[high] = temp;
return (i + 1); 
} 
void quick_sort(int arr[], int low, int high) 
{ 
if (low < high) 
{ 
int pi = partition(arr, low, high); 
quick_sort(arr, low, pi - 1); 
quick_sort(arr, pi + 1, high); 
} 
} 
int print(int arr[], int n)
{
for(int i = 0; i < n; i++)
{
printf("%d ", arr[i]);
}
}

int main()
{
int n, i;
scanf("%d", &n);
int arr[n];
for(i = 0; i < n; i++)
{
scanf("%d", &arr[i]);
}
quick_sort(arr, 0, n - 1);
print(arr, n);
}