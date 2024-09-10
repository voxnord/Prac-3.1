#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <chrono>

using namespace std;

class n1
{
private:
    int i = 0;
public:
    // O(n)
    int n1_1(int arr[], int n)
    {
        int Max = 0;

        for (i; i < n; i++)
        {
            Max = max(Max, arr[i + 1]);
        }

        return Max;
    }
    // O(n)
    int n1_2(int arr[], int n)
    {
        int sum = 0;

        for (i; i < n; i++)
        {
            sum += arr[i];
        }

        return sum;
    }
    // O(n)
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

class sorts
{
public:
    // O(n^2)
    auto bubbleSort(vector<int> arr, int n)
    {
        auto start_time = std::chrono::steady_clock::now();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int b = arr[j]; // создали дополнительную переменную
                    arr[j] = arr[j + 1]; // меняем местами
                    arr[j + 1] = b; // значения элементов
                }
            }
        }

        auto end_time = chrono::steady_clock::now();
        auto elapsed_s = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);

        return elapsed_s.count();
    }
    // O(n^2)
    auto choiceSort(vector<int> arr, int n)
    {
        auto start_time = std::chrono::steady_clock::now();

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

        auto end_time = chrono::steady_clock::now();
        auto elapsed_s = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);

        return elapsed_s.count();
    }
};

//O(n)
string n3_1_1(string str[], int n)
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

string n3_1_2(string str[], int n)
{

}

void n3_2()
{

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr1[] = { 7,9,6,5 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int search_num = 5;
    n1 num1;

    cout << "Максимальный элемент в массиве: " << num1.n1_1(arr1, n) << endl;
    cout << "Сумма всех элементов массива: " << num1.n1_2(arr1, n) << endl;
    cout << "Число " << "не содержится в массиве " << "содержится в массиве " << num1.n1_3(arr1, n, search_num) << endl;

    vector<int> arr2 = { 1,4,5,6,8,7,6,5,9,4,10,12,14,27 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Представлен следующий массив: ";

    for (int num : arr2)
    {
        cout << num << ' ';
    }

    cout << endl;

    sorts num2;

    cout << "Пузырьковая сортировка заняла " << num2.bubbleSort(arr2, n2) << " наносекунд" << endl;
    cout << "Сортировка выбором заняла " << num2.choiceSort(arr2, n2) << " наносекунд" << endl;

    if (num2.bubbleSort(arr2, n2) > num2.choiceSort(arr2, n2))
    {
        cout << "Сортировка вставками эффективнее, чем пузырьковая сортирвка" << endl;
    }
    else if (num2.bubbleSort(arr2, n2) < num2.choiceSort(arr2, n2))
    {
        cout << "Пузырьковая сортировка эффективнее, чем сортирвка вставками" << endl;
    }

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

    cout << "Второе по длине(лексикографически) слово: " << n3_1_1(str1, nstr) << endl;

    return 0;
}
