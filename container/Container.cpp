#include "Container.h"

// Конструктор контейнера
Container::Container():len{0} {};

// Деструктор контейнера
Container::~Container() {
    Clear();
}

struct Dequeue {
    int id;
    int max_distance;
};

// Очистка контейнера от памяти
void Container::Clear() {
    for(int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

// Ввод содержимого контейнера из указанного файла
void Container::In(FILE *file) {
    while(!feof(file)) {
        try {
            if ((storage[len] = Transport::StaticInput(file)) != nullptr) {
                len++;
            }
        } catch (int er) {
            fprintf(file, "Incorrect input!\n");
        }
    }
}

// Случайный ввод содержимого контейнера
void Container::Random(int size) {
    while(size > len) {
        if ((storage[len] = Transport::StaticRandom()) != nullptr) {
            len++;
        }
    }
}

// Вывод содержимого контейнера в указанный файл
void Container::Out(FILE* &file) {
    fprintf(file, "Container contains %d elements.\n", len);
    for(int i = 0; i < len; i++) {
        storage[i]->Out(file);
    }
}

// Вычисление максимального расстояния для каждого ТС
void Container::GetMaxDistance() {
    for (int i = 0; i < len; ++i) {
        storage[i]->GetMaxDistance();
    }
}

// Вывод содержимого контейнера в указанный файл
// (Используется для тестирования)
void Container::Parameters(FILE* file) {
    char* output = new char[len];
    for (int i = 0; i < len; ++i) {
        storage[i]->Parameters(file);
    }
}

//Сортирует контейнер по GetMaxDistance
/*void Sort1() {
    Dequeue a[10000];
    for(int i = 0; i < len; i++) {
        a[i].id = i;
        a[i].max_distance = storage[i]->GetMaxDistance();
    }
    int step = 1;

    auto *tmp = new Dequeue;
    while (step < len) {
        int index = 0;
        int l = 0;
        int m = l + step;

        int r = l + step * 2;
        do {
            m = m < len ? m : len;
            r = r < len ? r : len;
            int i1 = l, i2 = m;
            for (; i1 < m && i2 < r;) {
                if (tmp[i1].max_distance < tmp[i2].max_distance) { tmp[index++] = tmp[i1++]; }
                else { tmp[index++] = tmp[i2++]; }
            }
            while (i1 < m) tmp[index++] = tmp[i1++];
            while (i2 < r) tmp[index++] = tmp[i2++];
            m += step * 2;
            r += step * 2;
            l++;
        } while (l < len);
        for (int i = 0; i < len; i++) {
            //std::cout << 1 << ' ' << tmp[0].max_distance << '\n';
            storage[i]->fuel_consumption = tmp[i].max_distance;
        }

        step *= 2;
    }
}*/

void Container::Sort() {
    Dequeue a[10000];
    for(int i = 0; i < len; i++) {
        a[i].id = i;
        a[i].max_distance = storage[i]->GetMaxDistance();
    }
        size_t block_size_iterator;
        size_t block_iterator;
        size_t left_block_iterator;
        size_t right_block_iterator;
        size_t merge_iterator;
        size_t left_border;
        size_t mid_border;
        size_t right_border;

        // Сама сортировка.
        for (block_size_iterator = 1; block_size_iterator < len; block_size_iterator *= 2) {
            for (block_iterator = 0; block_iterator < len - block_size_iterator; block_iterator += 2 * block_size_iterator) {
                left_block_iterator = 0;
                right_block_iterator = 0;
                left_border = block_iterator;
                mid_border = block_iterator + block_size_iterator;
                right_border = block_iterator + 2 * block_size_iterator;
                right_border = (right_border < len) ? right_border : len;
                auto *SortedBlock = new Dequeue[right_border - left_border];


                while (left_border + left_block_iterator < mid_border && mid_border + right_block_iterator < right_border) {
                    if (a[left_border + left_block_iterator].max_distance <
                        a[mid_border + right_block_iterator].max_distance) {
                        SortedBlock[left_block_iterator + right_block_iterator] = a[left_border +
                                                                                    left_block_iterator];
                        left_block_iterator += 1;
                    } else {
                        SortedBlock[left_block_iterator + right_block_iterator] = a[mid_border +
                                                                                    right_block_iterator];
                        right_block_iterator += 1;
                    }
                }

                while (left_border + left_block_iterator < mid_border) {
                    SortedBlock[left_block_iterator + right_block_iterator] = a[left_border + left_block_iterator];
                    left_block_iterator += 1;
                }
                while (mid_border + right_block_iterator < right_border) {
                    SortedBlock[left_block_iterator + right_block_iterator] = a[mid_border + right_block_iterator];
                    right_block_iterator += 1;
                }

                for (merge_iterator = 0; merge_iterator < left_block_iterator + right_block_iterator; merge_iterator++) {
                    a[left_border + merge_iterator] = SortedBlock[merge_iterator];
                }
                delete[] SortedBlock;
            }
        }
    Transport *tmp[10000];
    for (int i = 0; i < len; i++) {
        tmp[i] = storage[i];
    }
    for (int i = 0; i < len; i++) {
        storage[i] = tmp[a[i].id];
    }
}

