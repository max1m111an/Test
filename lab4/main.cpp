#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <chrono>
#include <random>
#include <ctime>

using namespace std;

// ��������� ������� ��� ���������� ���������� ������������� ���������� (vector � list)
template <typename Container, typename T>
void fillContainer(Container& container, T minVal, T maxVal, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        container.push_back(minVal + rand() % (maxVal - minVal + 1));
    }
}

// ������������� ��� multiset
template <typename T>
void fillContainer(multiset<T>& container, T minVal, T maxVal, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        container.insert(minVal + rand() % (maxVal - minVal + 1));
    }
}

// ������������� ��� map
template <typename Key, typename Value>
void fillContainer(map<Key, Value>& container, Key minVal, Key maxVal, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        Key key = minVal + rand() % (maxVal - minVal + 1);
        Value value = minVal + rand() % (maxVal - minVal + 1);
        container[key] = value;
    }
}

// ��������� ������� ��� ������ ����������� ���������� �� ����� (����� ������)
template <typename Container>
void printContainer(const Container& container) {
    for (const auto& element : container) {
        cout << element << ' ';
    }
    cout << endl;
}

// ������������� ��� map
template <typename Key, typename Value>
void printContainer(const map<Key, Value>& container) {
    for (const auto& pair : container) {
        cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    cout << endl;
}

// ��������� ������� ��� �������� ���� ��������� �������� �� ��������� E
template <typename Container, typename T>
void duplicateElement(Container& container, const T& e) {
    auto it = container.begin();
    while (it != container.end()) {
        if (*it == e) {
            it = container.insert(it, e);
            ++it; // Move past the inserted element
        }
        ++it; // Move to the next element
    }
}

// ������������� ��� multiset (��������� ���������, �������� ����� ��������)
template <typename T>
void duplicateElement(multiset<T>& container, const T& e) {
    vector<T> duplicates;
    for (const auto& elem : container) {
        if (elem == e) {
            duplicates.push_back(elem);
        }
    }
    for (const auto& elem : duplicates) {
        container.insert(elem);
    }
}

// ������������� ��� map (��������� �������� ��������� � �������� ������)
template <typename Key, typename Value>
void duplicateElement(map<Key, Value>& container, const Key& e) {
    auto it = container.find(e);
    if (it != container.end()) {
        Key newKey = 2 * e;
        container[newKey] = it->second;
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    srand(time(0)); // ������������� ���������� ��������� �����
    unsigned int smallSize;
    cout << "������� ������ ����������: ";
    cin >> smallSize;
    const size_t largeSize = 1000000;
    cout << endl << "������� ������� �������� ����������: ";
    int minVal;
    int maxVal;
    cin >> minVal >> maxVal;
    cout << endl << "������� �������� E: ";
    int targetValue;
    cin >> targetValue;
    cout << endl;

    // ������������ ������ �� ����� ���������� ���������
    vector<int> vec;
    fillContainer(vec, minVal, maxVal, smallSize);
    cout << "Vector ����� �������������: ";
    printContainer(vec);
    duplicateElement(vec, targetValue);
    cout << "Vector ����� ������������: ";
    printContainer(vec);

    list<int> lst;
    fillContainer(lst, minVal, maxVal, smallSize);
    cout << "List ����� �������������: ";
    printContainer(lst);
    duplicateElement(lst, targetValue);
    cout << "List ����� ������������: ";
    printContainer(lst);

    multiset<int> ms;
    fillContainer(ms, minVal, maxVal, smallSize);
    cout << "Multiset ����� �������������: ";
    printContainer(ms);
    duplicateElement(ms, targetValue);
    cout << "Multiset ����� ������������: ";
    printContainer(ms);

    map<int, int> mp;
    fillContainer(mp, minVal, maxVal, smallSize);
    cout << "Map ����� �������������: ";
    printContainer(mp);
    duplicateElement(mp, targetValue);
    cout << "Map ����� ������������: ";
    printContainer(mp);

    // ������ ������� ��� �������� ���������� ���������

    // Vector
    vector<int> largeVec;
    auto start = chrono::high_resolution_clock::now();
    fillContainer(largeVec, minVal, maxVal, largeSize);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "�����, ����������� �� ���������� vector: " << duration.count() << " ���." << endl;

    start = chrono::high_resolution_clock::now();
    duplicateElement(largeVec, targetValue);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "�����, ������������� �� ������������ ��������� vector: " << duration.count() << " ���." << endl;

    // List
    list<int> largeList;
    start = chrono::high_resolution_clock::now();
    fillContainer(largeList, minVal, maxVal, largeSize);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "�����, ����������� �� ���������� list: " << duration.count() << " ���." << endl;

    start = chrono::high_resolution_clock::now();
    duplicateElement(largeList, targetValue);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "�����, ������������� �� ������������ ��������� list: " << duration.count() << " ���." << endl;

    // Multiset
    multiset<int> largeMultiset;
    start = chrono::high_resolution_clock::now();
    fillContainer(largeMultiset, minVal, maxVal, largeSize);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "�����, ����������� �� ���������� multiset: " << duration.count() << " ���." << endl;

    start = chrono::high_resolution_clock::now();
    duplicateElement(largeMultiset, targetValue);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "�����, ������������� �� ������������ ��������� multiset: " << duration.count() << " ���." << endl;

    // Map
    map<int, int> largeMap;
    start = chrono::high_resolution_clock::now();
    fillContainer(largeMap, minVal, maxVal, largeSize);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "�����, ����������� �� ���������� map: " << duration.count() << " ���." << endl;

    start = chrono::high_resolution_clock::now();
    duplicateElement(largeMap, targetValue);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "�����, ������������� �� ������������ ��������� map: " << duration.count() << " ���." << endl;

    return 0;
}