#include <iostream>
using namespace std;

class Array {
protected:
    double* arr;
    int n;

public:
    Array() {
        arr = nullptr;
        n = 0;
    }

    Array(int size) {
        arr = new double[size];
        n = size;
    }

    Array(double* a, int size) {
        this->n = size;
        arr = new double[size];
        for (int i = 0; i < size; i++)
            this->arr[i] = *(a + i);
    }

    ~Array() {
        delete[] arr;
    }

    virtual Array* add(Array*) = 0;
    virtual void foreach() = 0;

    friend ostream& operator<<(ostream& out, Array* Arr) {
        for (int i = 0; i < Arr->n; i++)
            out << Arr->arr[i] << ' ';
        out << "\n";
        return out;
    }
};


class SortArray : public Array {
public:
    SortArray() : Array() {}

    SortArray(int size) : Array(size) {}

    SortArray(double* a, int size) : Array(a, size) {}

    Array* add(Array* other) {
        SortArray* sArr = dynamic_cast<SortArray*>(other);
        SortArray* temp = new SortArray(n + sArr->n);

        for (int i = 0; i < n; i++)
            temp->arr[i] = arr[i];

        for (int j = n; j < n + sArr->n; j++)
            temp->arr[j] = sArr->arr[j - n];

        return temp;
    }

    void foreach() {
        double temp;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }

        }
    }
};


class XorArray : public Array {
public:
    XorArray() : Array() {}

    XorArray(int size) : Array(size) {}

    XorArray(double* a, int size) : Array(a, size) {}

    Array* add(Array* x) {
        XorArray* xArr = dynamic_cast<XorArray*>(x);
        XorArray* temp = new XorArray(n * 2);
        XorArray* Simular = new XorArray(n);

        int count = 1;

        for (int i = 0; i < n; i++)  // тут заполнил массив всеми числами, что повторяются
            for (int j = 0; j < n; j++)
                if (arr[i] == xArr->arr[j])
                {
                    Simular->arr[count - 1] = xArr->arr[j];
                    count++;
                }

        bool t;
        int j, totalCount = 1;
        for (int i = 0; i < n; i++) {
            t = false;
            j = 0;
            while (!t && j < count) {
                t = (Simular->arr[j] == arr[i]);
                j++;
            }

            if (!t) {
                temp->arr[totalCount - 1] = arr[i];
                totalCount++;
            }

            t = false;
            j = 0;
            while (!t && j < count) {
                t = (Simular->arr[j] == xArr->arr[i]);
                j++;
            }

            if (!t) {
                temp->arr[totalCount - 1] = xArr->arr[i];
                totalCount++;
            }
        }


        XorArray* result = new XorArray(totalCount - 1);
        for (int i = 0; i < totalCount; i++)
            result->arr[i] = temp->arr[i];
        return result;
    }

    void foreach() {
        for (int i = 0; i < n; i++) {
            arr[i] = sqrt(arr[i]);
        }
    }
};


int main()
{
    setlocale(0, "");

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    double* a1 = new double[n];
    double* b1 = new double[n];
    double* a2 = new double[n];
    double* b2 = new double[n];

    /*cout << "Задайте массив а1: ";
    for (int i = 0; i < n; i++)
        cin >> *(a1 + i);
        */
    cout << "Задайте массив b1: ";

    for (int i = 0; i < n; i++)
        cin >> *(b1 + i);

    /*cout << "Задайте массив a2: ";

    for (int i = 0; i < n; i++)
        cin >> *(a2 + i); */

    cout << "Задайте массив b2: ";

    for (int i = 0; i < n; i++)
        cin >> *(b2 + i);

    Array* sort1 = new SortArray(a1, n);
    Array* xorr1 = new XorArray(b1, n);

    Array* sort2 = new SortArray(a2, n);
    Array* xorr2 = new XorArray(b2, n);

   // cout << "a1: " << sort1 << "b1: " << xorr1 << "a2: " << sort2 << "b2: " << xorr2 << "\n";

   //cout << "a1 and a2: " << sort1->add(sort2) << "\n";
    cout << "b1 xor b2: " << xorr1->add(xorr2) << "\n";

    sort2->foreach();   // сортирует
    xorr2->foreach();   // берет корень

    //cout << "a2: " << sort2 << "b2: " << xorr2;
}

