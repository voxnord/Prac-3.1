#include <iostream>
#include <string>
#include <Windows.h>


using namespace std;

class n1
{
private:
    int i = 0;
public:
    int n1_1(int arr[], int n)
    {
        int Max = 0;

        for (i; i < n; i++)
        {
            Max = max(Max, arr[i + 1]);
        }

        return Max;
    }

    int n1_2(int arr[], int n)
    {
        int sum = 0;

        for (i; i < n; i++)
        {
            sum += arr[i];
        }

        return sum;
    }

    bool n1_3(int arr[], int n, int search_num)
    {
        for (i; i < n; i++)
        {
            if (arr[i] == search_num)
            {
                return true;

                break;
            }
        }

        return false;
    }
};

void num2()
{
    int arr[] = { 1,4,5,6,8,7,6,5,9,4,10,12,14,27 };
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n-1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int b = arr[j]; // создали дополнительную переменную
                arr[j] = arr[j + 1]; // меняем местами
                arr[j + 1] = b; // значения элементов
            }
        }
    }

    for (int num : arr)
    {
        cout << num << ' ';
    }
    cout << endl;

    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(arr[i], arr[min_index]);
        }
    }

    for (int num : arr)
    {
        cout << num << ' ';
    }
    cout << endl;
}

string n3_1(string str[], int n)
{
    string maxStr = "";
    string secondMax = "";

    for (int i = 0; i < n; i++)
    {
        if (str[i] > maxStr)
        {
            secondMax = maxStr;
            maxStr = str[i];
        }
        else if (str[i] > secondMax && str[i] != maxStr)
        {
            secondMax = str[i];
        }
    }

    return secondMax;
}


void n3_2()
{

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr[] = { 7,9,6,5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int search_num = 5;
    n1 num1;

    cout << "Максимальный элемент в массиве: " << num1.n1_1(arr, n) << endl;
    cout << "Сумма всех элементов массива: " << num1.n1_2(arr, n) << endl;
    cout << "Число " << "не содержится в массиве " << "содержится в массиве " << num1.n1_3(arr, n, search_num) << endl;

    num2();

    string str1[]
    {
        "5",
        "apple",
        "banana",
        "cherry",
        "date",
        "elderberry"
    };
    int nstr = sizeof(str1) / sizeof(str1[0]);

    string str2 = "A man, a plan, a canal, Panama";

    cout << "Второе по длине(лексикографически) слово: " << n3_1(str1, nstr) << endl;

    return 0;
}
