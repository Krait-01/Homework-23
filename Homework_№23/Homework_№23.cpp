#include <iostream>
using namespace std;

// Задача 1
void threeMax(int& a, int& b, int& c) 
{
    int max = a > b ? (a > c ? a : c) : (b > c) ? b : c;
    a = b = c = max;
}

// Задача 2
template <typename T>
auto& GetFirstNegative(T& array)
{
    for (auto& r : array)
    {
        if (r < 0)
            return r;
    }

    return array[0];
}

// Задача 3
void func(int* first, int nf, int* second, int ns)
{
    for (int* arr1 = first; arr1 != first + nf; ++arr1)
    {
        for (int* arr2 = second; arr2 != second + ns; ++arr2)
        {
            if (*arr2 == *arr1)
                *arr2 = 0;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    // Задача 1
    cout << "Задача 1\nФункция, принимающая 3 переменные и находящая среди них максимальную.\n\n";
    int a = 3, b = 5, c = 4;
    cout << "Вывод 3-х принятых переменных:\n" << a << " " << b << " " << c << "\n\n";
    threeMax(a, b, c);
    cout <<"Замена 2-х оставшихся переменных на значение максимальной и вывод 3-х переменных:\n" << a << " " << b << " " << c << "\n\n\n";

    // Задача 2
    cout << "Задача 2\nФункция, принимающая массив, его длину и возвращающая ссылку на его 1-ый отрицательный элемент.\n\n";
    cout << "Принятый массив:\n";
    const int size = 4;
    int array[size]{ 3, 11, -3, 8 };
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    auto& result{ GetFirstNegative(array) };
    cout << "\nОтрицательный или 1-ый элемент из принятого массива:\n" << result << "\n\n\n";

    // Задача 3
    cout << "Задача 3\nФункция, принимающая 2 массива, их длинну и обнуляющая все элементы 2-го массива встречающиеся в 1-ом.\n\n";
    cout << "Принятый массив № 1:\n";
    const int size1 = 7;
    int array1[size1] = { 3, 6, 4, 1, 4, 8, 2 };
    for (int i = 0; i < size1; i++)
    {
        cout << array1[i] << " ";
    }
    cout << "\n\n" << "Принятый массив № 2:\n";
    const int size2 = 6;
    int array2[size2] = { 5, 3, 1, 5, 10, 8 };
    for (int i = 0; i < size2; i++)
    {
        cout << array2[i] << " ";
    }
    func(array1, size1, array2, size2);
    cout << "\n\nМассив № 2 после работы функции:\n";
    for (int i = 0; i < size2; i++)
        cout << array2[i] << " ";
    cout << "\n\n";

    return 0;
}