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
    string folds;
    int edge;
    cout << "Введите строку символов из прописных букв \"П\" и \"З\": ";
    cin >> folds;
    cout << "Введите номер ребра: ";
    cin >> edge;
    char foldType = getFoldType(folds, edge);
    cout << "Тип ребра: " << foldType << endl;
    ///////////////////////////////
    string edges;
    cout << "Введите строку символов из прописных букв \"О\" и \"К\": ";
    cin >> edges;
    folds = getFolds(edges);
    if (folds.empty()) {
        cout << "Такой строки не существует." << endl;
    }
    else {
        cout << "Последовательность типов сгибаний: " << folds << endl;
    }
    ///////////////////////////////////////////////
    int n;
    n = edges.size();
    bool* foldTypes = new bool[n];
    cout << "Введите строку символов из прописных букв \"О\" и \"К\": ";
    cin >> edges;
    
    folds = getFoldsMass(edges, foldTypes);
    if (folds.empty()) {
        cout << "Такой строки не существует." << endl;
    }
    else {
        cout << "Последовательность типов сгибаний: " << folds << endl;
    }
    delete[] foldTypes;
    //////////////////////////////////////////
    List <bool> foldTypesList;
    cout << "Введите строку символов из прописных букв \"О\" и \"К\": ";
    cin >> edges;
    folds = getFoldsList(edges, foldTypesList);
    if (folds.empty()) {
        cout << "Такой строки не существует." << endl;
    }
    else {
        cout << "Последовательность типов сгибаний: " << folds << endl;
    }
    foldTypesList.clear();
    return 0;
}