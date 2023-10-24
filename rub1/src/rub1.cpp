#include <iostream>
#include <cstring>
//Вариант №3 Данилов Артём ИУ1-12Б

using namespace std;

int main() {
    int size;
    cout << "Введите количество заказанных блюд: ";
    cin >> size;

    int cost_all=0;
    char** names = new char*[size];
    int*  count = new int[size];
    double* cost = new double[size];
    cin.ignore();
    for (int i = 0; i < size; i++) {
        cout << "Введите название блюда " << i + 1 << ": ";
        char buff[100];
        cin.getline(buff, 100);
        names[i] = new char[strlen(buff) + 1];
        strcpy(names[i], buff);

        cout << "Введите количество порций блюда  " << i + 1 << ": ";
        cin >> count[i];
        cout << "Введите стоимость за порцию блюда " << i + 1 << ": ";
        cin >> cost[i];
        cin.ignore();
        int cost_zakaz=count[i]*cost[i];
        cost_all+=cost_zakaz;
        cout<<"Стоимость заказа: "<<cost_zakaz<<endl;
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                swap(names[j], names[j + 1]);
                swap(count[j], count[j + 1]);
                swap(cost[j],cost[j+1]);
            }
        }
    }

    cout << "\nОтсортированный список блюд:\n";
    for (int i = 0; i < size; i++) {
        cout << "Название: " << names[i] << ", Количество: " << count[i]<< ", Цена за штуку: " << cost[i] << endl;
    }

    cout<<"Стоимость всез заказов:"<<cost_all<<endl;

    for (int i = 0; i < size; ++i) {
        delete[] names[i];
    }
    delete[] names;
    delete[] count;
    delete[] cost;

    return 0;
}
