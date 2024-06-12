#include "list.h"

using namespace std;



char getFoldType(const string& folds, int edge) {
    int n = folds.size();
    int mask = 1 << (n - 1);
    for (int i = 0; i < n; i++) {
        if (edge & mask) {
            if (folds[i] == 'П') {
                edge >>= 1;
            }
            else {
                edge = (edge >> 1) ^ mask;
            }
        }
        mask >>= 1;
    }
    return edge ? 'К' : 'О';
}

string getFolds(const string& edges) {
    int n = edges.size();
    vector<bool> foldTypes(n);
    for (int i = 0; i < n; i++) {
        foldTypes[i] = (edges[i] == 'К');
    }
    string folds;
    for (int i = n - 1; i >= 0; i--) {
        if (foldTypes[i]) {
            if (i > 0 && foldTypes[i - 1]) {
                folds += 'П';
            }
            else {
                folds += 'З';
            }
        }
        else {
            if (i > 0 && !foldTypes[i - 1]) {
                folds += 'П';
            }
            else {
                folds += 'З';
            }
        }
    }
    return folds;
}

string getFoldsList(const string& edges, List<bool> foldTypesList) {
    int n = edges.size();
    for (int i = 0; i < n; i++) {
        foldTypesList.push_back(edges[i] == 'К');
    }
    string folds;
    for (int i = n - 1; i >= 0; i--) {
        if (foldTypesList[i]) {
            if (i > 0 && foldTypesList[i - 1]) {
                folds += 'П';
            }
            else {
                folds += 'З';
            }
        }
        else {
            if (i > 0 && !foldTypesList[i - 1]) {
                folds += 'П';
            }
            else {
                folds += 'З';
            }
        }
    }
    return folds;
}

string getFoldsMass(const string& edges, bool *foldTypes) {
    int n = edges.size();
    for (int i = 0; i < n; i++) {
        foldTypes[i] = (edges[i] == 'К');
    }
    string folds;
    for (int i = n - 1; i >= 0; i--) {
        if (foldTypes[i]) {
            if (i > 0 && foldTypes[i - 1]) {
                folds += 'П';
            }
            else {
                folds += 'З';
            }
        }
        else {
            if (i > 0 && !foldTypes[i - 1]) {
                folds += 'П';
            }
            else {
                folds += 'З';
            }
        }
    }
    return folds;
}

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Трифонов Матвей Михайлович\t" << "Группа: 090301 - ПОВа - о23\n" << endl;
    string folds;
    int edge;
    cout << "Введите строку символов из прописных букв \"П\" и \"З\": ";
    cin >> folds;
    cout << "Введите номер ребра: ";
    cin >> edge;
    char foldType = getFoldType(folds, edge);
    cout << "Тип ребра: " << foldType << endl;
    /////////////////////////////// с контейнером STL
    string edges;
    cout << "с контейнером STL" << endl;
    cout << "Введите строку символов из прописных букв \"О\" и \"К\": ";
    cin >> edges;
    auto start = chrono::high_resolution_clock::now();
    folds = getFolds(edges);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff =(end - start);
    cout << "Время выполнения: " << diff.count() << " секунд" << endl;
    if (folds.empty()) {
        cout << "Такой строки не существует." << endl;
    }
    else {
        cout << "Последовательность типов сгибаний: " << folds << endl;
    }
    /////////////////////////////////////////////// с массивом
    int n;
    n = edges.size();
    bool* foldTypes = new bool[n];
    cout << "с массивом" << endl;
    cout << "Введите строку символов из прописных букв \"О\" и \"К\": ";
    cin >> edges;
    start = chrono::high_resolution_clock::now();
    folds = getFoldsMass(edges, foldTypes);
    end = chrono::high_resolution_clock::now();
    diff = (end - start);
    cout << "Время выполнения: " << diff.count() << " секунд" << endl;
    if (folds.empty()) {
        cout << "Такой строки не существует." << endl;
    }
    else {
        cout << "Последовательность типов сгибаний: " << folds << endl;
    }
    delete[] foldTypes;
    ////////////////////////////////////////// с односвязным списком
    List <bool> foldTypesList;
    cout << "со списком" << endl;
    cout << "Введите строку символов из прописных букв \"О\" и \"К\": ";
    cin >> edges;
    start = chrono::high_resolution_clock::now();
    folds = getFoldsList(edges, foldTypesList);
    end = chrono::high_resolution_clock::now();
    diff =(end - start);
    cout << "Время выполнения: " << diff.count() << " секунд" << endl;
    if (folds.empty()) {
        cout << "Такой строки не существует." << endl;
    }
    else {
        cout << "Последовательность типов сгибаний: " << folds << endl;
    }
    foldTypesList.clear();
    return 0;
}
