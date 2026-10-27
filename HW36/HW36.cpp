#include <iostream>
#include <vector>
using namespace std;

class MinFinder
{
public:
    int operator()(const vector<int>& v) const
    {
        int result = v[0];
        for (int i = 1; i < (int)v.size(); i++)
            if (v[i] < result)
                result = v[i];
        return result;
    }
};

class MaxFinder
{
public:
    int operator()(const vector<int>& v) const
    {
        int result = v[0];
        for (int i = 1; i < (int)v.size(); i++)
            if (v[i] > result)
                result = v[i];
        return result;
    }
};

class SortDescending
{
public:
    void operator()(vector<int>& v) const
    {
        for (int i = 0; i < (int)v.size() - 1; i++)
        {
            for (int j = 0; j < (int)v.size() - 1 - i; j++)
            {
                if (v[j] < v[j + 1])
                {
                    int tmp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = tmp;
                }
            }
        }
    }
};

class SortAscending
{
public:
    void operator()(vector<int>& v) const
    {
        for (int i = 0; i < (int)v.size() - 1; i++)
        {
            for (int j = 0; j < (int)v.size() - 1 - i; j++)
            {
                if (v[j] > v[j + 1])
                {
                    int tmp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = tmp;
                }
            }
        }
    }
};

class AddConstant
{
    int value;
public:
    AddConstant(int value) : value(value) {}
    void operator()(vector<int>& v) const
    {
        for (int& x : v)
            x += value;
    }
};

class SubtractConstant
{
    int value;
public:
    SubtractConstant(int value) : value(value) {}
    void operator()(vector<int>& v) const
    {
        for (int& x : v)
            x -= value;
    }
};

class RemoveValue
{
    int value;
public:
    RemoveValue(int value) : value(value) {}
    void operator()(vector<int>& v) const
    {
        vector<int> result;
        for (int x : v)
            if (x != value)
                result.push_back(x);
        v = result;
    }
};

void printVector(const vector<int>& v)
{
    if (v.empty())
    {
        cout << "Container is empty" << endl;
        return;
    }
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter elements: ";
    for (int& x : v)
        cin >> x;

    int choice;
    do
    {
        cout << "\n1. Find minimum\n"
            << "2. Find maximum\n"
            << "3. Sort descending\n"
            << "4. Sort ascending\n"
            << "5. Increase all values by constant\n"
            << "6. Decrease all values by constant\n"
            << "7. Remove elements equal to value\n"
            << "8. Print container\n"
            << "0. Exit\n"
            << "Choose action: ";
        cin >> choice;

        if (choice >= 1 && choice <= 2 && v.empty())
        {
            cout << "Container is empty" << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            cout << "Minimum: " << MinFinder()(v) << endl;
            break;
        case 2:
            cout << "Maximum: " << MaxFinder()(v) << endl;
            break;
        case 3:
            SortDescending()(v);
            printVector(v);
            break;
        case 4:
            SortAscending()(v);
            printVector(v);
            break;
        case 5:
        {
            int c;
            cout << "Enter constant: ";
            cin >> c;
            AddConstant adder(c);
            adder(v);
            printVector(v);
            break;
        }
        case 6:
        {
            int c;
            cout << "Enter constant: ";
            cin >> c;
            SubtractConstant subtractor(c);
            subtractor(v);
            printVector(v);
            break;
        }
        case 7:
        {
            int target;
            cout << "Enter value to remove: ";
            cin >> target;
            RemoveValue remover(target);
            remover(v);
            printVector(v);
            break;
        }
        case 8:
            printVector(v);
            break;
        }
    } while (choice != 0);
}