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

// Шаблонная функция для заполнения контейнера произвольными элементами (vector и list)
template <typename Container, typename T>
void fillContainer(Container& container, T minVal, T maxVal, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        container.push_back(minVal + rand() % (maxVal - minVal + 1));
    }
}

// Специализация для multiset
template <typename T>
void fillContainer(multiset<T>& container, T minVal, T maxVal, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        container.insert(minVal + rand() % (maxVal - minVal + 1));
    }
}

// Специализация для map
template <typename Key, typename Value>
void fillContainer(map<Key, Value>& container, Key minVal, Key maxVal, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        Key key = minVal + rand() % (maxVal - minVal + 1);
        Value value = minVal + rand() % (maxVal - minVal + 1);
        container[key] = value;
    }
}

// Шаблонная функция для вывода содержимого контейнера на экран (общая версия)
template <typename Container>
void printContainer(const Container& container) {
    for (const auto& element : container) {
        cout << element << ' ';
    }
    cout << endl;
}

// Специализация для map
template <typename Key, typename Value>
void printContainer(const map<Key, Value>& container) {
    for (const auto& pair : container) {
        cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    cout << endl;
}

// Шаблонная функция для удвоения всех вхождений элемента со значением E
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

// Специализация для multiset (удваиваем вхождения, вставляя новые элементы)
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

// Специализация для map (удваиваем значения элементов с заданным ключом)
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

    srand(time(0)); // Инициализация генератора случайных чисел
    unsigned int smallSize;
    cout << "Введите размер контейнера: ";
    cin >> smallSize;
    const size_t largeSize = 1000000;
    cout << endl << "Введите пределы значений контейнера: ";
    int minVal;
    int maxVal;
    cin >> minVal >> maxVal;
    cout << endl << "Введите значение E: ";
    int targetValue;
    cin >> targetValue;
    cout << endl;

    // Демонстрация работы на малом количестве элементов
    vector<int> vec;
    fillContainer(vec, minVal, maxVal, smallSize);
    cout << "Vector перед дублированием: ";
    printContainer(vec);
    duplicateElement(vec, targetValue);
    cout << "Vector после дублирования: ";
    printContainer(vec);

    list<int> lst;
    fillContainer(lst, minVal, maxVal, smallSize);
    cout << "List перед дублированием: ";
    printContainer(lst);
    duplicateElement(lst, targetValue);
    cout << "List после дублирования: ";
    printContainer(lst);

    multiset<int> ms;
    fillContainer(ms, minVal, maxVal, smallSize);
    cout << "Multiset перед дублированием: ";
    printContainer(ms);
    duplicateElement(ms, targetValue);
    cout << "Multiset после дублирования: ";
    printContainer(ms);

    map<int, int> mp;
    fillContainer(mp, minVal, maxVal, smallSize);
    cout << "Map перед дублированием: ";
    printContainer(mp);
    duplicateElement(mp, targetValue);
    cout << "Map после дублирования: ";
    printContainer(mp);

    // Замеры времени для большого количества элементов

    // Vector
    vector<int> largeVec;
    auto start = chrono::high_resolution_clock::now();
    fillContainer(largeVec, minVal, maxVal, largeSize);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Время, затраченное на заполнение vector: " << duration.count() << " сек." << endl;

    start = chrono::high_resolution_clock::now();
    duplicateElement(largeVec, targetValue);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Время, затрачиваемое на дублирование элементов vector: " << duration.count() << " сек." << endl;

    // List
    list<int> largeList;
    start = chrono::high_resolution_clock::now();
    fillContainer(largeList, minVal, maxVal, largeSize);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Время, затраченное на заполнение list: " << duration.count() << " сек." << endl;

    start = chrono::high_resolution_clock::now();
    duplicateElement(largeList, targetValue);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Время, затрачиваемое на дублирование элементов list: " << duration.count() << " сек." << endl;

    // Multiset
    multiset<int> largeMultiset;
    start = chrono::high_resolution_clock::now();
    fillContainer(largeMultiset, minVal, maxVal, largeSize);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Время, затраченное на заполнение multiset: " << duration.count() << " сек." << endl;

    start = chrono::high_resolution_clock::now();
    duplicateElement(largeMultiset, targetValue);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Время, затрачиваемое на дублирование элементов multiset: " << duration.count() << " сек." << endl;

    // Map
    map<int, int> largeMap;
    start = chrono::high_resolution_clock::now();
    fillContainer(largeMap, minVal, maxVal, largeSize);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Время, затраченное на заполнение map: " << duration.count() << " сек." << endl;

    start = chrono::high_resolution_clock::now();
    duplicateElement(largeMap, targetValue);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Время, затрачиваемое на дублирование элементов map: " << duration.count() << " сек." << endl;

    return 0;
}