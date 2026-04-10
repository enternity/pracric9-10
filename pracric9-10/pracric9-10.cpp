#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

enum Type { VOLC, FOLD, PLAT };

class Country {
public:
    char name[20];
};

class Mountain {
    char name[20];
    int h;
    Country c;
    Type t;

public:
    void set(const char* n, int hh, const char* country, Type tt);
    void show();
    int get_h();
    const char* get_name();
    const char* get_country();
    void change();
};

void Mountain::set(const char* n, int hh, const char* country, Type tt) {
    strcpy(name, n);
    h = hh;
    strcpy(c.name, country);
    t = tt;
}

void Mountain::show() {
    cout << name << " " << h << " " << c.name << endl;
}

int Mountain::get_h() {
    return h;
}

const char* Mountain::get_name() {
    return name;
}

const char* Mountain::get_country() {
    return c.name;
}

void Mountain::change() {
    cout << "New height: ";
    cin >> h;
}

double avg(Mountain a[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++)
        s += a[i].get_h();
    return (double)s / n;
}

void sort(Mountain a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j].get_h() < a[j + 1].get_h()) {
                Mountain tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void print8000(Mountain a[], int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].get_h() >= 8000) {
            cout << a[i].get_country() << endl;
            k++;
            if (k == 4) break;
        }
    }
}

void changeM(Mountain a[], int n) {
    char x[20];
    cout << "Name: ";
    cin >> x;

    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].get_name(), x) == 0) {
            a[i].change();
        }
    }
}

int filter(Mountain a[], int n, Mountain b[]) {
    char country[20];
    cout << "Country: ";
    cin >> country;

    int k = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].get_country(), country) == 0) {
            b[k] = a[i];
            k++;
        }
    }
    return k;
}

void printArr(Mountain a[], int n) {
    for (int i = 0; i < n; i++)
        a[i].show();
}

int main() {

    Mountain a[20];

    a[0].set("Everest", 8848, "Nepal", FOLD);
    a[1].set("K2", 8611, "Pakistan", FOLD);
    a[2].set("Kang", 8586, "India", FOLD);
    a[3].set("Lhotse", 8516, "Nepal", FOLD);
    a[4].set("Makalu", 8485, "Nepal", FOLD);
    a[5].set("Cho", 8188, "Nepal", FOLD);
    a[6].set("Dhaul", 8167, "Nepal", FOLD);
    a[7].set("Manaslu", 8163, "Nepal", FOLD);
    a[8].set("Nanga", 8126, "Pakistan", FOLD);
    a[9].set("Anna", 8091, "Nepal", FOLD);
    a[10].set("Elbrus", 5642, "Russia", VOLC);
    a[11].set("Mont", 4808, "France", FOLD);
    a[12].set("Matter", 4478, "Swiss", FOLD);
    a[13].set("Kili", 5895, "Tanzania", VOLC);
    a[14].set("Denali", 6190, "USA", FOLD);
    a[15].set("Acon", 6960, "Argentina", FOLD);
    a[16].set("Fuji", 3776, "Japan", VOLC);
    a[17].set("Etna", 3329, "Italy", VOLC);
    a[18].set("Olymp", 2917, "Greece", FOLD);
    a[19].set("Table", 1085, "Africa", PLAT);

    cout << "Avg: " << avg(a, 20) << endl;

    sort(a, 20);

    cout << "8000+:\n";
    print8000(a, 20);

    changeM(a, 20);

    Mountain b[20];
    int k = filter(a, 20, b);

    cout << "Filtered:\n";
    printArr(b, k);

    return 0;
}