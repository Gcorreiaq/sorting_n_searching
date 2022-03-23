#include <time.h>

int loop = 0; //  used to compare algorithm efficiency

int print_array(int array[], int size)
{
    for (int i = 0;i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
    return size;
}

void swap(int *a, int *b)
{
    loop += 5;
    int t = *a;
    *a = *b;
    *b = t;
}

int random_array(int array[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size;i++) array[i] = rand() % 100;
    return size;
}

int find_smallest(int array[], int size)
{
    int t = array[0];
    int pos = 0;
    loop += 3;
    for (int i = 0;i < size;i++)
    {
        loop++;
        if (array[i] < t){
            t = array[i];
            pos = i;
            loop += 3;
        }
    }
    return pos;
}

int binary_search(int array[], int key, int size)
{
    int mid;
    size -= 1;
    for (int i = 0;;)
    {
        mid = (size - i) / 2;
        mid += i;
        if ((size - i) == 1)
            if (array[mid+1] == key) 
                return mid+2;
        if (array[mid] == key) 
            return mid+1;
        else if ((size - i) == 1) 
            return -1;
        else if (array[mid] < key) 
            i = mid;
        else size = mid;
    }
}

int bubble_sort(int array[], int size)
{
    loop = 0;
    for (int i = 0;i < size;i++)
    {
        for (int j = i+1;j < size;j++)
        {
            loop += 2;
            if (array[j] < array[i])
            {
                int t = array[i];
                array[i] = array[j];
                array[j] = t;
                loop += 5;
            }
        }
    }
    return loop;
}

int selection_sort(int array[], int size)
{
    loop = 0;
    for (int i = 0;i < size - 1;i++)
    {
        loop += 7;
        int j = find_smallest(&array[i], size-i);
        j += i;
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
    }
    return loop;
}

int insertion_sort(int array[], int size)
{  
    int pos;
    loop = 0;
    for (int i = 1;i < size;i++)
    {
        pos = i - 1;
        loop++;
        while((array[pos+1] < array[pos]) && (pos >= 0))
        {
            loop += 2;
            swap(&array[pos+1], &array[pos]);
            pos--;
        }
    }
    return loop;
}

int quick_sort(int array[], int size)
{
    if (size < 1) return 0;
    int pivot = array[size-1];
    int i = -1;
    loop += 3;
    for (int j = 0;j<size;j++)
    {
        loop++;
        if (array[j] < pivot)
        {
            i++;
            swap(&array[j], &array[i]);
        }
    }
    swap(&array[size-1], &array[i+1]);
    quick_sort(array, i+1);
    quick_sort(&array[i+2], size-i-2);
    return 0;
}
