#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

struct n1
{
    int n1_1(int arr[], int n)
    {
        int Max = 0;

        for (int i = 0; i < n; i++)
        {
            Max = max(Max, arr[i + 1]);
        }

        return Max;
    }

    int n1_2(int arr[], int n)
    {
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        return sum;
    }

    bool n1_3(int arr[], int n, int search_num)
    {
        for (int i = 0; i < n; i++)
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

void n2()
{

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

    string str[]
    {
        "5",
        "apple",
        "banana",
        "cherry",
        "date",
        "elderberry"
    };
    int nstr = sizeof(str) / sizeof(str[0]);

    cout << "Второе по длине(лексикографически) слово: " << n3_1(str, nstr) << endl;

    return 0;
}
