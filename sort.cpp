#include "header.h"

void insertionSort(int array[], int n)
{
    int saved;
    int j;
    for (int i = 0; i < n; i++)
    {
        saved = array[i];
        for (j = i; j > 0 && saved < array[j - 1]; j--)
            array[j] = array[j - 1];
        array[j] = saved;
    }
}

void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void flashSort(int a[], int n) 
{
    int __L[300000];
    if (n <= 1) return;
    int m = n * 0.43;
    if (m <= 2) m = 2;
    // int m = n;
    for (int i = 0; i < m; ++i)
        __L[i] = 0;
    int Mx = a[0], Mn = a[0];
    for (int i = 1; i < n; ++i) {
        if (Mx < a[i]) Mx = a[i];
        if (Mn > a[i]) Mn = a[i];
    }
    if (Mx == Mn)
        return;
#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
    for (int i = 0; i < n; ++i)
        ++__L[getK(a[i])];
    for (int i = 1; i < m; ++i)
        __L[i] += __L[i - 1];
    //step 2
    int count = 0;
    int i = 0;
    while (count < n) {
        int k = getK(a[i]);
        while (i >= __L[k]) 
            k = getK(a[++i]);
        int z = a[i];
        while (i != __L[k]) {
            k = getK(z);
            int y = a[__L[k] - 1];
            a[--__L[k]] = z;
            z = y;
            ++count;
        }
    }   
    //step 3
    for (int k = 1; k < m; ++k) {
        for (int i = __L[k] - 2; i >= __L[k - 1]; --i)
            if (a[i] > a[i + 1]) {
                int t = a[i], j = i;
                while (t > a[j + 1]) {a[j] = a[j + 1]; ++j;}
                a[j] = t;
            }
    }
}

void swap(int *a, int *b) 
{
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) 
{
  int pivot = array[low + (high-low)/2];
  int i = (low - 1);

  for (int j = low; j < high; j++) 
  {
    if (array[j] <= pivot) 
    {     
      i++; 
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) 
{
  if (low < high) 
  {    
    int pi = partition(array, low, high);

    quickSort(array, low, pi - 1);

    quickSort(array, pi + 1, high);
  }
}

void bubbleSort(int a[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {

        bool flag = 0;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void countRadix(int a[], int n, int exp)
{

    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

void radixSort(int a[], int n)
{

    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    for (int exp = 1; max / exp >= 1; exp *= 10)
    {
        countRadix(a, n, exp);
    }
}

void countSort(int a[], int n)
{

    int max = a[0];

    for (int i = 1; i < n; i++)
        if (max < a[i])
            max = a[i];

    int count[max+1];
    for(int i = 0; i <= max + 1; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[a[i]]++;

    int j = 0;

    for (int i = 0; i < max + 1; i++)
    {
        while (count[i] > 0)
        {
            a[j++] = i;
            count[i]--;
        }
    }
}

void shellSort(int a[], int n)
{

    int gap, j, tmp;

    for (gap = n / 2; gap >= 1; gap /= 2)
    {

        for (int i = gap; i < n; i++)
        {
            tmp = a[i];
            j = i - gap;
            while (j >= 0 && a[j] > tmp)
            {
                a[j + gap] = a[j];
                j -= gap;
            }
            a[j + gap] = tmp;
        }
    }
}

void shakerSort(int a[], int n)
{

    int start = 0;
    int end = n - 1;
    bool swapped = 1;

    while (swapped)
    {

        swapped = 0;

        for (int i = start; i < end; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        end--;

        for (int i = end; i >= start; i--)
        {
            if (a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                swapped = 1;
            }
        }
        start++;
    }
}

void countComparisonInsertionSort(int array[], int n, unsigned long long &countComparison)
{
    int saved;
    int j;
    for (int i = 0; ++countComparison && i < n; i++)
    {
        saved = array[i];
        for (j = i; ++countComparison && j > 0 && saved < array[j - 1]; j--)
            array[j] = array[j - 1];
        array[j] = saved;
    }
}

void countComparisonRadix(int a[], int n, int exp, unsigned long long &count_compare)
{

    int i, count[10] = {0};
    int *output = new int[n];

    for (i = 0; ++count_compare && i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (i = 1; ++count_compare && i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; ++count_compare && i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (i = 0; ++count_compare && i < n; i++)
        a[i] = output[i];

    delete[] output;
}

void countComparisonRadixSort(int a[], int n, unsigned long long &count_compare)
{

    int mx = a[0];
    for (int i = 1; ++count_compare && i < n; i++)
    {
        if (++count_compare && a[i] > mx)
        {
            mx = a[i];
        }
    }
    int i = 0;
    for (int exp = 1; ++count_compare && mx / exp > 0; exp *= 10)
    {
        countComparisonRadix(a, n, exp, count_compare);
    }
}

void countComparisonShakerSort(int a[], int n, unsigned long long &count_compare)
{

    int start = 0;
    int end = n - 1;
    bool swapped = 1;

    while (++count_compare && swapped)
    {

        swapped = 0;
        for (int i = start; ++count_compare && i < end; i++)
        {
            if (++count_compare && a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                swapped = 1;
            }
        }

        if (++count_compare && !swapped)
        {
            break;
        }

        swapped = 0;
        end--;
        for (int i = end; ++count_compare && i >= start; i--)
        {
            if (++count_compare && a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                swapped = 1;
            }
        }
        start++;
    }
}

void countComparisonShellSort(int a[], int n, unsigned long long &count_compare)
{

    int gap, j, tmp;

    for (gap = n / 2; ++count_compare && gap >= 1; gap /= 2)
    {

        for (int i = gap; ++count_compare && i < n; i++)
        {
            tmp = a[i];
            j = i - gap;
            while ((++count_compare && j >= 0) && (++count_compare && a[j] > tmp))
            {
                a[j + gap] = a[j];
                j -= gap;
            }
            a[j + gap] = tmp;
        }
    }
}

void countComparisonCountSort(int a[], int n, unsigned long long &count_compare)
{
    int max = a[0];

    for (int i = 1; ++count_compare && i < n; i++)
        if (++count_compare && max < a[i])
            max = a[i];

    int count[max + 1];
    for (int i = 0; ++count_compare && i <= max + 1; i++)
        count[i] = 0;

    for (int i = 0; ++count_compare && i < n; i++)
        count[a[i]]++;

    int j = 0;

    for (int i = 0; ++count_compare && i < max + 1; i++)
    {
        while (++count_compare && count[i] > 0)
        {
            a[j++] = i;
            count[i]--;
        }
    }
}

void countComparisonBubbleSort(int a[], int n, unsigned long long &count_compare)
{

    for (int i = 0; (++count_compare && i < n - 1); i++)
    {

        bool flag = 0;

        for (int j = 0; (++count_compare && j < n - 1 - i); j++)
        {
            if (++count_compare && a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                flag = 1;
            }
        }
        if (++count_compare && flag == 0)
        {
            break;
        }
    }
}

void countComparisonMerge(int arr[], int p, int q, int r, unsigned long long &count_comparison)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; ++count_comparison && i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; ++count_comparison && j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while ((++count_comparison && i < n1) && (++count_comparison && j < n2))
    {
        if (++count_comparison && L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (++count_comparison && i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (++count_comparison && j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void countComparisonMergeSort(int arr[], int l, int r, unsigned long long &count_comparison)
{
    if (++count_comparison && l < r)
    {
        int m = l + (r - l) / 2;

        countComparisonMergeSort(arr, l, m, count_comparison);
        countComparisonMergeSort(arr, m + 1, r, count_comparison);
        countComparisonMerge(arr, l, m, r, count_comparison);
    }
}

void countComparisonFlashSort(int a[], int n, unsigned long long &countComparison)
{
    int __L[500000];
    if (++countComparison && n <= 1)
        return;
    int m = n * 0.43;
    if (++countComparison && m <= 2)
        m = 2;
    // int m = n;
    for (int i = 0; ++countComparison && i < m; ++i)
        __L[i] = 0;
    int Mx = a[0], Mn = a[0];
    for (int i = 1; ++countComparison && i < n; ++i)
    {
        if (Mx < a[i])
            Mx = a[i];
        if (Mn > a[i])
            Mn = a[i];
    }
    if (Mx == Mn)
        return;
#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
    for (int i = 0; ++countComparison && i < n; ++i)
        ++__L[getK(a[i])];
    for (int i = 1; ++countComparison && i < m; ++i)
        __L[i] += __L[i - 1];
    // step 2
    int count = 0;
    int i = 0;
    while (++countComparison && count < n)
    {
        int k = getK(a[i]);
        while (++countComparison && i >= __L[k])
            k = getK(a[++i]);
        int z = a[i];
        while (++countComparison && i != __L[k])
        {
            k = getK(z);
            int y = a[__L[k] - 1];
            a[--__L[k]] = z;
            z = y;
            ++count;
        }
    }
    // step 3
    for (int k = 1;++countComparison && k < m; ++k)
    {
        for (int i = __L[k] - 2; ++countComparison && i >= __L[k - 1]; --i)
            if (a[i] > a[i + 1])
            {
                int t = a[i], j = i;
                while (++countComparison && t > a[j + 1])
                {
                    a[j] = a[j + 1];
                    ++j;
                }
                a[j] = t;
            }
    }
}