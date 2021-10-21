#include "time.h"
#include "container/Container.h"

#define INFO    "Дисциплина: Архитектура Вычислительных Систем\n"\
                "Тип работы: Индивидуальное домашнее задание №2\n"\
                "Исполнитель:Греков Николай Сергеевич БПИ204\n"\
                "Дата: 08.10.2021"  \

#define HELP    "Генерация случайных объектов:\n" \
                "-r <кол-во генерируемых объектов> <название выходного файла>.txt" \
                "Пример: -rnd 10 output.txt\n"\
                "Чтение обьектов из файла\n"      \
                "-w <название входного файла>.txt <название выходного файла>.txt"\
                "-w input.txt output.txt"

// Возвращает число из массива
int get_size(char* num) {
    int i = 0, k = 1, output = 0;
    while(num[i++]){
        k*=10;
    }
    k/=10;
    i = 0;
    while(num[i]) {
        output += (num[i]-'0')*k;
        i++;
        k/=10;
    }
    return output;
}

int main(int argc, char* argv[]) {
    time_t start, finish;
    start = clock();
    Container* container = new Container();
// Генерация объектов output
    if(argv[1][1] == 'r') {
        container->Random( get_size(argv[2]));
        //std::cout << argv[3];
        FILE *fp;
        fp = fopen(argv[3], "w");
        container->Out(fp);
        container->Sort();
        container->Out(fp);
    } // Чтение файла и запись в файл
    else if (argv[1][1] == 'w') {
        FILE *fp1, *fp2;
        fp1 = fopen(argv[2], "r");
        fp2 = fopen(argv[3], "w");
        container->In(fp1);
        container->Out(fp2);
        container->Sort();
        container->Out(fp2);
        // -c для создания тестовых данных
    } // Генерация входного файла
    else if (argv[1][1] == 'c') {
        container->Random(get_size(argv[2]));
        FILE* fp;
        fp = fopen(argv[3], "w");
        container->Parameters(fp);
    }
    return 0;
}
