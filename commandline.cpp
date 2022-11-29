#include "header.h"

template <class T>
void HoanVi(T &a, T &b)
{
    T x = a;
    a = b;
    b = x;
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % n;
    }
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = n - 1 - i;
    }
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int r1 = rand() % n;
        int r2 = rand() % n;
        HoanVi(a[r1], a[r2]);
    }
}

void GenerateData(int a[], int n, int dataType)
{
    switch (dataType)
    {
    case 0: // ngẫu nhiên
        GenerateRandomData(a, n);
        break;
    case 1: // gần như có thứ tự 
        GenerateNearlySortedData(a, n);
        break;
    case 2: // có thứ tự 
        GenerateSortedData(a, n);
        break;
    case 3: // có thứ tự ngược
        GenerateReverseData(a, n);
        break;
    default:
        printf("Error: unknown data type!\n");
    }
}

int algorithmNameToNumber(char *argv)
{
    /*
    1 - Selection sort
    2 - Insertion sort
    3 - Bubble sort
    4 - Heap sort
    5 - Merge sort
    6 - Quick sort
    7 - Radix sort
    8 - Shaker sort
    9 - Shell sort
    10 - Counting sort
    11  - Flash sort
    */
    int num = 0;
    if (strcmp(argv, "selection-sort") == 0)
        num = 1;
    else if (strcmp(argv, "insertion-sort") == 0)
        num = 2;
    else if (strcmp(argv, "bubble-sort") == 0)
        num = 3;
    else if (strcmp(argv, "heap-sort") == 0)
        num = 4;
    else if (strcmp(argv, "merge-sort") == 0)
        num = 5;
    else if (strcmp(argv, "quick-sort") == 0)
        num = 6;
    else if (strcmp(argv, "radix-sort") == 0)
        num = 7;
    else if (strcmp(argv, "shaker-sort") == 0)
        num = 8;
    else if (strcmp(argv, "shell-sort") == 0)
        num = 9;
    else if (strcmp(argv, "counting-sort") == 0)
        num = 10;
    else if (strcmp(argv, "flash-sort") == 0)
        num = 11;
    return num;
}

int dataOrderToNumber(char *argv)
{
    int num = 4;
    if (strcmp(argv, "-rand") == 0)
        num = 0;
    else if (strcmp(argv, "-nsorted") == 0)
        num = 1;
    else if (strcmp(argv, "-sorted") == 0)
        num = 2;
    else if (strcmp(argv, "-rev") == 0)
        num = 3;
    return num;
}

int outParameterToNumber(char *argv)
{
    int num = 3;
    if (strcmp(argv, "-time") == 0)
        num = 0;
    else if (strcmp(argv, "-comp") == 0)
        num = 1;
    else if (strcmp(argv, "-both") == 0)
        num = 2;
    return num;
}

int *copyArray(int *a, int n)
{
    int *copyArr = new int[n];
    for (int i = 0; i < n; i++)
        copyArr[i] = a[i];
    return copyArr;
}

void readInputFile(int *&array, int &n, string file_name)
{
    ifstream inputFile(file_name);
    if (inputFile.is_open())
    {
        string num;
        getline(inputFile, num);
        n = stoi(num);
        array = new int[n];
        int i = 0;
        while (i < n && getline(inputFile, num, ' '))
        {
            array[i] = stoi(num);
            i++;
        }
        inputFile.close();
    }
    else
        cout << "Error: Can't read file " << file_name << endl;
}

void print_output_compare_mode(float running_time1, float running_time2, unsigned long long comparison1, unsigned long long comparison2)
{
    cout << "\n----------------------------\n";
    cout << "Running time: " << running_time1 << " s | " << running_time2 << " s" << endl;
    cout << "Comparisions: " << comparison1 << "  |  " << comparison2 << endl;
}

void print_output_paramenter(int output_paramenter, float running_time, unsigned long long comparison)
{
    cout << "\n----------------------------\n";
    switch (output_paramenter)
    {
    case 0:
        cout << "Running time: " << running_time << " s" << endl;
        break;
    case 1:
        cout << "Comparisons: " << comparison << endl;
        break;
    case 2:
        cout << "Running time: " << running_time << " s" << endl;
        cout << "Comparisons: " << comparison << endl;
        break;
    default:
        break;
    }
}

void writeFile(int array[], int n, string file_name)
{
    ofstream outFile(file_name);
    if (outFile.is_open())
    {
        outFile << n << endl;
        for (int i = 0; i < n; i++)
            outFile << array[i] << " ";
        outFile << endl;
        outFile.close();
    }
    else
        cout << "Error: Can't write the output file" << endl;
}

bool checkStringIsNumber(string str)
{
    bool count;
    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]) == false)
        {
            count = 0;
            break;
        }
        else
            count = 1;
    }
    return count;
}

void sortWithAlgorithm(int array[], int n, int algorithm)
{
    /*
    1 - Selection sort
    2 - Insertion sort
    3 - Bubble sort
    4 - Heap sort
    5 - Merge sort
    6 - Quick sort
    7 - Radix sort
    8 - Shaker sort
    9 - Shell sort
    10 - Counting sort
    11  - Flash sort
    */
    switch (algorithm)
    {
    case 1:
        insertionSort(array, n);
        break;
    case 2:
        insertionSort(array, n);
        break;
    case 3:
        bubbleSort(array, n);
        break;
    case 4:
        mergeSort(array, 0, n - 1);
        break;
    case 5:
        mergeSort(array, 0, n - 1);
        break;
    case 6:
        quickSort(array,0, n - 1);
        break;
    case 7:
        radixSort(array, n);
        break;
    case 8:
        shakerSort(array, n);
        break;
    case 9:
        shellSort(array, n);
        break;
    case 10:
        countSort(array, n);
        break;
    case 11:
        flashSort(array, n);
        break;
    default:
        cout << "Error: Can't find the sort algorithm \n";
        break;
    }
}

void countComparisonAlgorithm(int array[], int n, int algorithm, unsigned long long &count_comparison)
{
    /*
    1 - Selection sort
    2 - Insertion sort
    3 - Bubble sort
    4 - Heap sort
    5 - Merge sort
    6 - Quick sort
    7 - Radix sort
    8 - Shaker sort
    9 - Shell sort
    10 - Counting sort
    11  - Flash sort
    */
    switch (algorithm)
    {
    case 1:
        countComparisonInsertionSort(array, n, count_comparison);
        break;
    case 2:
        countComparisonInsertionSort(array, n, count_comparison);
        break;
    case 3:
        countComparisonBubbleSort(array, n, count_comparison);
        break;
    case 4:
        countComparisonMergeSort(array, 0, n - 1, count_comparison);
        break;
    case 5:
        countComparisonMergeSort(array, 0, n - 1, count_comparison);
        break;
    case 6:
        countComparisonMergeSort(array, 0, n - 1, count_comparison);
        break;
    case 7:
        countComparisonRadixSort(array, n, count_comparison);
        break;
    case 8:
        countComparisonMergeSort(array, 0, n - 1, count_comparison);
        break;
    case 9:
        countComparisonMergeSort(array, 0, n - 1, count_comparison);
        break;
    case 10:
        countComparisonMergeSort(array, 0, n - 1, count_comparison);
        break;
    case 11:
        countComparisonFlashSort(array, n, count_comparison);
        break;
    default:
        cout << "Error: Can't find the sort algorithm\n";
        break;
    }
}

void command_line1(int argc, char *argv[])
{
    int *a = NULL, n;
    readInputFile(a, n, argv[3]);
    int *b = copyArray(a, n);

    cout << "Algorithm: " << argv[2] << endl;
    cout << "Input file: " << argv[3] << endl;
    cout << "Input size: " << n;

    int algorithm_name = algorithmNameToNumber(argv[2]),
        output_parameter = outParameterToNumber(argv[4]);

    float running_time = 0;
    unsigned long long count_comparison = 0;

    clock_t start_time, end_time;
    start_time = clock();
    sortWithAlgorithm(b, n, algorithm_name);
    end_time = clock();
    b = copyArray(a, n);
    running_time = (((float)end_time - start_time) / CLOCKS_PER_SEC) * 1000;
    countComparisonAlgorithm(b, n, algorithm_name, count_comparison);
    writeFile(b, n, "output.txt");
    print_output_paramenter(output_parameter, running_time, count_comparison);
}

void command_line2(int argc, char *argv[])
{
    int algorithm_name = algorithmNameToNumber(argv[2]),
        n = stoi(argv[3]),
        data_order = dataOrderToNumber(argv[4]),
        output_parameter = outParameterToNumber(argv[5]);
    string data_order_name[4] = {"Randomize", "Nearly Sorted", "Sorted", "Reversed"};

    cout << "Algorithm: " << argv[2] << endl;
    cout << "Input size: " << argv[3] << endl;
    cout << "Input order: " << data_order_name[data_order] << endl;

    int *a = new int[n];
    GenerateData(a, n, data_order);
    writeFile(a, n, "input.txt");
    int *b = copyArray(a, n);
    float running_time = 0;
    unsigned long long count_comparison = 0;
    clock_t start_time, end_time;
    start_time = clock();
    sortWithAlgorithm(b, n, algorithm_name);
    end_time = clock();
    running_time = (((float)end_time - start_time) / CLOCKS_PER_SEC) * 1000;
    countComparisonAlgorithm(a, n, algorithm_name, count_comparison);
    writeFile(b, n, "output.txt");
    print_output_paramenter(output_parameter, running_time, count_comparison);
}

void command_line3(int argc, char *argv[])
{
    int algorithm_name = algorithmNameToNumber(argv[2]),
        n = stoi(argv[3]),
        output_parameter = outParameterToNumber(argv[4]);

    cout << "Algorithm: " << argv[2] << endl;
    cout << "Input size: " << argv[3] << endl;

    int *a = new int[n],
        *b = NULL;
    string file_name[4] = {"input_1.txt", "input_2.txt", "input_3.txt", "input_4.txt"};
    string data_order_name[4] = {"Randomize", "Nearly Sorted", "Sorted", "Reversed"};
    for (int i = 0; i < 4; i++)
    {
        cout << "\nInput order: " << data_order_name[i];
        GenerateData(a, n, i);
        b = copyArray(a, n);
        writeFile(a, n, file_name[i]);
        float running_time = 0;
        unsigned long long count_comparison = 0;
        clock_t start_time, end_time;
        start_time = clock();
        sortWithAlgorithm(b, n, algorithm_name);
        end_time = clock();
        running_time = (((float)end_time - start_time) / CLOCKS_PER_SEC) * 1000;
        countComparisonAlgorithm(a, n, algorithm_name, count_comparison);
        print_output_paramenter(output_parameter, running_time, count_comparison);
    }
}

void command_line4(int argc, char *argv[])
{
    int *a = NULL, n;
    readInputFile(a, n, argv[4]);
    int *b = copyArray(a, n);

    cout << "Algorithm: " << argv[2] << " | " << argv[3] << endl;
    cout << "Input file: " << argv[4] << endl;
    cout << "Input size: " << n;

    int algorithm1_name = algorithmNameToNumber(argv[2]),
        algorithm2_name = algorithmNameToNumber(argv[3]);

    float running_time1 = 0,
          running_time2 = 0;
    unsigned long long count_comparison1 = 0,
                       count_comparison2 = 0;

    clock_t start_time, end_time;
    start_time = clock();
    sortWithAlgorithm(b, n, algorithm1_name);
    end_time = clock();
    b = copyArray(a, n);
    running_time1 = (((float)end_time - start_time) / CLOCKS_PER_SEC) * 1000;
    countComparisonAlgorithm(b, n, algorithm1_name, count_comparison1);

    b = copyArray(a, n);
    start_time = clock();
    sortWithAlgorithm(b, n, algorithm2_name);
    end_time = clock();
    running_time2 = (((float)end_time - start_time) / CLOCKS_PER_SEC) * 1000;
    b = copyArray(a, n);
    countComparisonAlgorithm(b, n, algorithm2_name, count_comparison2);
    print_output_compare_mode(running_time1, running_time2, count_comparison1, count_comparison2);
}

void command_line5(int argc, char *argv[])
{
    int algorithm1_name = algorithmNameToNumber(argv[2]),
        algorithm2_name = algorithmNameToNumber(argv[3]),
        n = stoi(argv[4]),
        data_order = dataOrderToNumber(argv[5]);
    string data_order_name[4] = {"Randomize", "Nearly Sorted", "Sorted", "Reversed"};

    cout << "Algorithm: " << argv[2] << " | " << argv[3] << endl;
    cout << "Input size: " << argv[4] << endl;
    cout << "Input order: " << data_order_name[data_order];

    int *a = new int[n];
    GenerateData(a, n, data_order);
    writeFile(a, n, "input.txt");
    int *b = copyArray(a, n);
    float running_time1 = 0,
          running_time2 = 0;
    unsigned long long count_comparison1 = 0,
                       count_comparison2 = 0;

    clock_t start_time, end_time;
    start_time = clock();
    sortWithAlgorithm(b, n, algorithm1_name);
    end_time = clock();
    b = copyArray(a, n);
    running_time1 = (((float)end_time - start_time) / CLOCKS_PER_SEC) * 1000;
    countComparisonAlgorithm(b, n, algorithm1_name, count_comparison1);

    b = copyArray(a, n);
    start_time = clock();
    sortWithAlgorithm(b, n, algorithm2_name);
    end_time = clock();
    running_time2 = (((float)end_time - start_time) / CLOCKS_PER_SEC) * 1000;
    b = copyArray(a, n);
    countComparisonAlgorithm(b, n, algorithm2_name, count_comparison2);
    print_output_compare_mode(running_time1, running_time2, count_comparison1, count_comparison2);
    //
}
