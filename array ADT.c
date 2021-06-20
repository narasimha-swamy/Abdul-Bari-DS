#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int length;
    int size;
};

// Display the given array
void Display(struct Array *array)
{
    printf("Displaying the elements\n");
    for (int i = 0; i < (*array).length; i++)
    {
        printf("%d\n", (*array).A[i]);
    }
}

// append/add item at the end
void Append(struct Array *array, int item)
{
    if (array->length < array->size)
        array->A[array->length++] = item;
}

// Insert item at a given index
void Insert(struct Array *array, int item, int index)
{
    if (index >= 0 && index <= array->length)
    {
        for (int i = array->length; i > index -1; i--)
        {
            array->A[i] = array->A[i - 1]; // improved search
        }
        array->A[index] = item;
        array->length++;
    }
}

// Delete item at a given index
int Delete(struct Array *array, int index)
{
    int item = array->A[index];
    if (index >= 0 && array->length > index)
    {
        // array->length--;
        for (int i = index; i < array->length - 1; i++)
        {
            array->A[i] = array->A[i + 1];
        }
        array->length--;
        return item;
    }
    return -1;
}

// Swap two elements
void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/* 
    search item one by one
    Time - O(n)
    Space- O(1)
*/
int LinearSearch(struct Array *array, int key)
{
    for (int i = 0; i < array->length; i++)
    {
        if (key == array->A[i])
        {
            if (i != 0)
            {
                Swap(&array->A[i], &array->A[i - 1]);
            }
            return i;
        }
    }
    return -1;
}

/*
    Sorted array
    Recursive Binary Search
    Time - O(logn) - O(lognbase2)
    Space- O(logn) - O(lognbase2)
*/
int RBinarySearch(struct Array *array, int l, int h, int key)
{
    int mid = (l + h) / 2;
    if (l <= h)
    {
        if (key == array->A[mid])
        {
            return mid;
        }
        else if (key > array->A[mid])
        {
            return RBinarySearch(array, mid + 1, h, key);
        }
        else
        {
            return RBinarySearch(array, l, mid - 1, key);
        }
    }
    return -1;
}

/*
    Sorted array
    Binary Search
    Time - O(logn) - O(lognbase2)
    Space- O(1)
*/
int BinarySearch(struct Array *array, int key)
{
    int l = 0;
    int h = array->length - 1;
    int mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == array->A[mid])
        {
            return mid;
        }
        else if (key > array->A[mid])
        {
            l = mid + 1;
        }
        else if (key < array->A[mid])
        {
            h = mid - 1;
        }
    }
    return -1;
}

/*
    Get Element at given index 
*/
int Get(struct Array *array, int index)
{
    if (index >= 0 && index < array->length)
        return array->A[index];

    return -1;
}

/*
    Set the Element at given index to given item
*/
int Set(struct Array *array, int index, int item)
{
    if (index >= 0 && index < array->length)
        array->A[index] = item;
}

/*
    Find max value of an array
*/
int Max(struct Array *array)
{
    int max = array->A[0];
    for (int i = 1; i < array->length; i++)
    {
        if (max < array->A[i])
        {
            max = array->A[i];
        }
    }
    return max;
}

/*
    Find min value of an array
*/
int Min(struct Array *array)
{
    int min = array->A[0];
    for (int i = 1; i < array->length; i++)
    {
        if (min > array->A[i])
        {
            min = array->A[i];
        }
    }
    return min;
}

/*
    Find sum of all elements in an array
*/
int Sum(struct Array *array)
{
    int sum = 0;
    for (int i = 0; i < array->length; i++)
        sum += array->A[i];
    return sum;
}

/*
    Find avg value of an array
*/
float Avg(struct Array *array)
{
    return (float)Sum(array) / array->length;
}

/*
    Reversing an array
*/
void Reverse(struct Array *array)
{
    int i = 0;
    int j = array->length - 1;
    while (i < j)
    {
        Swap(&array->A[i], &array->A[j]);

        i++;
        j--;
    }
}


void LeftRotate(struct Array *array)
{
    int store = array->A[0];
    for (int i = 0; i < array->length - 1; i++)
    {
        array->A[i] = array->A[i + 1];
    }
    array->A[array->length - 1] = store;
}

void LeftShift(struct Array *array)
{
    for (int i = 0; i < array->length - 1; i++)
    {
        array->A[i] = array->A[i + 1];
    }
    array->length--;
}

/*
    Insert element in a sorted array
*/
void InsertSort(struct Array *array, int item)
{
    int i = array->length - 1;
    if (array->length == array->size)
        return;
    while (i >= 0 && array->A[i] > item)
    {
        array->A[i + 1] = array->A[i];
        i--;
    }
    array->A[i + 1] = item;
    array->length++;
}

/*
    Check if the array is sorted
*/
int IsSorted(struct Array *array)
{
    int i = 0;
    while (i < array->length - 1)
    {
        if (array->A[i] > array->A[i + 1])
            return -1;
        i++;
    }
    return 0;
}

void Rearrange(struct Array *array)
{
    int i = 0;
    int j = array->length - 1;
    while (i < j)
    {
        while (array->A[i] < 0)
        {
            i++;
        }
        while (array->A[j] > 0)
        {
            j--;
        }
        if (i < j)
            Swap(&array->A[j], &array->A[i]);
    }
}

/*
    Merge two sorted arrays
*/
struct Array *Merge(struct Array *arr1, struct Array *arr2)
{
    int i = 0, j = 0, k = 0;
    int m = arr1->length;
    int n = arr2->length;
    struct Array *arr3 = malloc(sizeof(struct Array));
    while (i < m && j < n)
    {
        if (arr1->A[i] > arr2->A[j])
            arr3->A[k++] = arr2->A[j++];
        else
            arr3->A[k++] = arr1->A[i++];
    }
    for (; i < m; i)
        arr3->A[k++] = arr1->A[i++];
    for (; j < n; j)
        arr3->A[k++] = arr2->A[j++];

    arr3->length = m + n;
    arr3->size = m + n;

    return arr3;
}

/*
    Union of two arrays
    sorted
        Time - O(n)
    unsorted
        Time - O(n^2)
*/
struct Array *Union(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = malloc(sizeof(struct Array));
    int i = 0, j = 0, k = 0;
    int m = arr1->length;
    int n = arr2->length;
    arr3->length = 0;
    arr3->size = m + n;
    if (IsSorted(arr1) == -1 || IsSorted(arr2) == -1)
    {

        while (i < m)
        {
            arr3->length++;
            arr3->A[k++] = arr1->A[i++];
        }

        while (j < n)
        {
            if (LinearSearch(arr1, arr2->A[j]) == -1)
            {
                arr3->A[k] = arr2->A[j++];
                k++;
                arr3->length++;
            }
            else
                j++;
        }
    }
    else
    {
        while (i < m && j < n)
        {
            if (arr1->A[i] > arr2->A[j])
                arr3->A[k++] = arr2->A[j++];
            else if (arr1->A[i] < arr2->A[j])
                arr3->A[k++] = arr1->A[i++];
            else if (arr1->A[i] == arr2->A[j])
            {
                arr3->A[k++] = arr1->A[i++];
                j++;
            }
        }
        for (; i < m; i)
            arr3->A[k++] = arr1->A[i++];
        for (; j < n; j)
            arr3->A[k++] = arr2->A[j++];

        arr3->length = k;
    }

    return arr3;
}

/*
    Intersection of two arrays
    sorted
        Time - O(n)
    unsorted
        Time - O(n^2)
*/
struct Array *Intersection(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = malloc(sizeof(struct Array));
    int i = 0, j = 0, k = 0;
    int m = arr1->length;
    int n = arr2->length;
    arr3->length = 0;
    arr3->size = m + n;
    if (IsSorted(arr1) == -1 || IsSorted(arr2) == -1)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr1->A[i] == arr2->A[j])
                {
                    arr3->A[k++] = arr1->A[i];
                }
            }
        }
    }
    else
    {
        while (i < m && j < n)
        {
            if (arr1->A[i] > arr2->A[j])
                j++;
            else if (arr1->A[i] < arr2->A[j])
                i++;
            else if (arr1->A[i] == arr2->A[j])
            {
                arr3->A[k++] = arr1->A[i++];
            }
        }

        arr3->length = k;
    }

    return arr3;
}

/*
    Difference of two arrays
     = A - B
    sorted
        Time - O(n)
    unsorted
        Time - O(n^2)
*/
struct Array *Difference(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = malloc(sizeof(struct Array));
    int i = 0, j = 0, k = 0;
    int m = arr1->length;
    int n = arr2->length;
    arr3->length = 0;
    arr3->size = m + n;
    if (IsSorted(arr1) == -1 || IsSorted(arr2) == -1)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (LinearSearch(arr2, arr1->A[i]) == -1)
                {
                    arr3->A[k++] = arr1->A[i];
                }
            }
        }
    }
    else
    {
        while (i < m && j < n)
        {
            if (arr1->A[i] < arr2->A[j])
            {
                arr3->A[k++] = arr1->A[i++];
                i++;
            }
            else if (arr1->A[i] > arr2->A[j])
                j++;
            else if (arr1->A[i] == arr2->A[j])
                i++, j++;
        }
        for (; i < m; i)
            arr3->A[k++] = arr1->A[i++];

        arr3->length = k;
    }

    return arr3;
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    struct Array *arr = malloc(sizeof(struct Array));
    arr->size = size;
    printf("\n\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Sum\n");
    printf("5. Display\n");
    printf("6. Exit\n");
    printf("\n\n");

    int item;
    int index;
    int ch;
    do
    {
        printf("Choose the option\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:

            printf("Enter the item:");
            scanf("%d", &item);
            printf("Enter the index:");
            scanf("%d", &index);
            Insert(arr, item, index);
            break;
        case 2:
            printf("Enter the index:");
            scanf("%d", &index);
            Delete(arr, index);
            break;

        case 3:
            printf("Enter the item:");
            scanf("%d", &item);
            printf("Index found: %d", LinearSearch(arr, item));
            break;

        case 4:
            printf("Sum is %d ", Sum(arr));
            break;
        case 5:
            Display(arr);
            break;
        }
    } while (ch < 6);

    return 0;
}
