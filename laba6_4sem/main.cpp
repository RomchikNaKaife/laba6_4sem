#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>


int main() {
    std::vector<int> v;
    std::ifstream file("/Users/romanpereponov/Documents/laba6_4sem/laba6_4sem/input.txt");
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл" << std::endl;
        return 1;
    }
    int x;
    while (file >> x) {
        v.push_back(x);
    }
    file.close();

    reverse(v.begin(), v.end());

    auto min_element = *std::min_element(v.begin(), v.end());

    v.erase(remove_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; }), v.end());

    sort(v.begin(), v.end(), std::greater<int>());

    v.insert(upper_bound(v.begin(), v.end(), 9009), 9009); // вставить 5 в отсортированный вектор
    
    sort(v.begin(), v.end()); // сортируем вектор
    v.erase(unique(v.begin(), v.end()), v.end()); // удаляем дубликаты

    auto it = find(v.begin(), v.end(), 9009);
    if (it != v.end()) {
        std::cout << "Индекс элемента: " << distance(v.begin(), it) << std::endl;
    }
    else {
        std::cout << "Элемент не найден" << std::endl;
    }


    // Выводим результат
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
