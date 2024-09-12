#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <chrono> // chrono::steady_clock::now | chrono::duration_cast<chrono::nanoseconds>
#include <algorithm> // sort | reverse
#include <cctype> // isalpha() | tolower()

using namespace std;

class n1
{
public:
    // O(n)
    int n1_1(int arr[], int n)
    {
        int Max = 0;

        for (int i = 0; i < n; i++)
        {
            Max = max(Max, arr[i + 1]);
        }

        return Max;
    }
    // O(n)
    int n1_2(int arr[], int n)
    {
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        return sum;
    }
    // O(n)
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

class n2
{
public:
    // O(n^2)
    auto bubbleSort(vector<int>& arr, int n)
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
    auto choiceSort(vector<int>& arr, int n)
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

class n3
{
public:
    class n3_1
    {
    public:
        // O(n)
        string n3_1_1(vector<string>& str)
        {
            string maxStr = "";
            string secondMax = "";

            for (const auto& strin : str)
            {
                if (strin > maxStr)
                {
                    secondMax = maxStr;
                    maxStr = strin;
                }
                else if (strin > secondMax && strin != maxStr)
                {
                    secondMax = strin;
                }
            }

            return secondMax;
        }
        // O(n log n)
        string n3_1_2(vector<string>& str)
        {
            sort(str.begin(), str.end()); 

            return str[str.size() - 2];
        }
    };

    class n3_2
    {
    public:
        // O(n)
        bool n3_2_1(string& str)
        {
            string cleaned;

            for (char ch : str)
            {
                if (isalpha(ch))
                {
                    cleaned += tolower(ch);
                }
            }

            string reversed = cleaned;

            reverse(reversed.begin(), reversed.end());

            return cleaned == reversed;
        }
        // O(n^2)
        bool n3_2_2(string& str)
        {
            string cleared;

            for (char ch : str)
            {
                if (isalpha(ch))
                {
                    cleared += tolower(ch);
                }
            }

            int n = cleared.length();

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (cleared[i] != cleared[n - i - 1])
                    {
                        return false;
                    }
                    break;
                }
            }
        
            return true;
        }
    };

    class n3_3
    {
    public:
        // O(n^2)
        int n3_3_1(vector<int> arr)
        {
            int unique_count = 0;
            bool unique;

            for (int i = 0; i < arr.size(); i++)
            {
                unique = true;

                for (int j = 0; j < arr.size(); j++)
                {
                    if (i != j && arr[i] == arr[j])
                    {
                        unique = false;
                        break;
                    }
                }

                if (unique)
                {
                    unique_count++;
                }
            }

            return unique_count;
        }
        // O(n)
        int n3_3_2(vector<int> arr)
        {
            int unique_count = 0;
            const int ASCI_SIZE = 256;
            int freq[ASCI_SIZE] = { 0 };

            for (int i = 0; i < arr.size(); i++)
            {
                freq[arr[i]]++;
            }

            for (int i = 0; i < arr.size(); i++)
            {
                if (freq[arr[i]] == 1)
                {
                    unique_count++;
                }
            }

            return unique_count;
        }
    };

    class n3_4
    {
    public:
        // O(n)
        int n3_4_1(vector<int>& arr)
        {
            for (int i = 0; i < arr.size(); i++)
            {
                while (arr[i] > 0 && arr[i] <= arr.size() && arr[arr[i] - 1] != arr[i])
                {
                    swap(arr[i], arr[arr[i] - 1]);
                }
            }

            for (int i = 0; i < arr.size(); i++)
            {
                if (arr[i] != i + 1)
                {
                    return i + 1;
                }
            }

            return arr.size() + 1;
        }
        // O(n log n)
        int n3_4_2(vector<int> arr)
        {
            int smallest = 1;
            sort(arr.begin(), arr.end());

            for (int num : arr)
            {
                if (num == smallest)
                {
                    smallest++;
                }
            }

            return smallest;
        }
    };
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr1[] = { 7,9,6,5 };
    int n_1 = sizeof(arr1) / sizeof(arr1[0]);
    int searchNum = 5;
    n1 num1;

    cout << "\nМаксимальный элемент в массиве: " << num1.n1_1(arr1, n_1) << endl;
    cout << "\nСумма всех элементов массива: " << num1.n1_2(arr1, n_1) << endl;
    cout << "\nЧисло " << searchNum << (num1.n1_3(arr1, n_1, searchNum) ? " содержится в массиве" : " не содержится в массиве") << endl;

    vector<int> arr2 = { 1,4,5,6,8,7,6,5,9,4,10,12,14,27 };
    int n_2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "\nПредставлен следующий массив: ";

    for (int num : arr2) { cout << num << ' '; } cout << endl;

    n2 num2;

    cout << "\nПузырьковая сортировка заняла " << num2.bubbleSort(arr2, n_2) << " наносекунд" << endl;
    cout << "\nСортировка выбором заняла " << num2.choiceSort(arr2, n_2) << " наносекунд" << endl;
    cout << (num2.bubbleSort(arr2, n_2) > num2.choiceSort(arr2, n_2) ? "\nСортировка выбором" : "\nПузырьковая сортировка") << " эффективнее, чем пузырьковая сортирвка" << endl;

    vector<string> str1
    {
        "5",
        "apple",
        "banana",
        "cherry",
        "date",
        "elderberry"
    };
    string str2 = "A man, a plan, a canal, Panama";
    vector<int> arr3 = { 6,1,2,3,4,4,5 };
    vector<int> arr4 = { 5,1,2,0,-1,3 };
    n3::n3_1 num3_1;
    n3::n3_2 num3_2;
    n3::n3_3 num3_3;
    n3::n3_4 num3_4;

    cout << "\nВторое по длине(лексикографически) слово: " << num3_1.n3_1_1(str1) << endl;

    cout << "\nСтрока \"" << str2 << "\"" << (num3_2.n3_2_1 (str2) ? " является палиндромом" : " не является палиндромом") << endl;

    cout << "\nКоличество уникальных элементов в массиве: " << num3_3.n3_3_1(arr3) << endl;

    cout << "\nНаименьшее отсутсвующее число: " << num3_4.n3_4_1(arr4) << endl;

    return 0;
}

/*string n3_1_1(vector<string> str, int n)
{
    vector<string> maxStr = { "" };
    vector<string> secondMax = { "" };

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
}*/