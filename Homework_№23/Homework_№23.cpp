#include <iostream>
using namespace std;

// ������ 1
void threeMax(int& a, int& b, int& c) 
{
    int max = a > b ? (a > c ? a : c) : (b > c) ? b : c;
    a = b = c = max;
}

// ������ 2
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

// ������ 3
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

    // ������ 1
    cout << "������ 1\n�������, ����������� 3 ���������� � ��������� ����� ��� ������������.\n\n";
    int a = 3, b = 5, c = 4;
    cout << "����� 3-� �������� ����������:\n" << a << " " << b << " " << c << "\n\n";
    threeMax(a, b, c);
    cout <<"������ 2-� ���������� ���������� �� �������� ������������ � ����� 3-� ����������:\n" << a << " " << b << " " << c << "\n\n\n";

    // ������ 2
    cout << "������ 2\n�������, ����������� ������, ��� ����� � ������������ ������ �� ��� 1-�� ������������� �������.\n\n";
    cout << "�������� ������:\n";
    const int size = 4;
    int array[size]{ 3, 11, -3, 8 };
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    auto& result{ GetFirstNegative(array) };
    cout << "\n������������� ��� 1-�� ������� �� ��������� �������:\n" << result << "\n\n\n";

    // ������ 3
    cout << "������ 3\n�������, ����������� 2 �������, �� ������ � ���������� ��� �������� 2-�� ������� ������������� � 1-��.\n\n";
    cout << "�������� ������ � 1:\n";
    const int size1 = 7;
    int array1[size1] = { 3, 6, 4, 1, 4, 8, 2 };
    for (int i = 0; i < size1; i++)
    {
        cout << array1[i] << " ";
    }
    cout << "\n\n" << "�������� ������ � 2:\n";
    const int size2 = 6;
    int array2[size2] = { 5, 3, 1, 5, 10, 8 };
    for (int i = 0; i < size2; i++)
    {
        cout << array2[i] << " ";
    }
    func(array1, size1, array2, size2);
    cout << "\n\n������ � 2 ����� ������ �������:\n";
    for (int i = 0; i < size2; i++)
        cout << array2[i] << " ";
    cout << "\n\n";

    return 0;
}