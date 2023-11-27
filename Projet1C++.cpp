#include <iostream>
#include <fstream>
#include <cmath>

const int CHAR_COUNT = 128;

double Product(const int Table1[], const int Table2[]);
double vectorLength(const int Table[]);

double cosineSimilarity(const int Table1[], const int Table2[]);

int main() {
    std::ifstream file1("C:/Users/Pavillion/Desktop/fc1.txt");
    std::ifstream file2("C:/Users/Pavillion/Desktop/fc2.txt");

    int Table1[CHAR_COUNT] = {0};
    int Table2[CHAR_COUNT] = {0};

    char c;

    while (file1.get(c)) {
        Table1[static_cast<unsigned char>(c)]++;
    }

    while (file2.get(c)) {
        Table2[static_cast<unsigned char>(c)]++;
    }

    double similarity = cosineSimilarity(Table1, Table2);

    std::cout << "Similarity between the files is " << similarity << "%" << std::endl;

    file1.close();
    file2.close();

    return 0;
}

double Product(const int Table1[], const int Table2[]) {
    double product = 0.0;

    for (int i = 0; i < CHAR_COUNT; ++i) {
        product += Table1[i] * Table2[i];
    }

    return product;
}

double vectorLength(const int Table[]) {
    double sumOfSquares = 0.0;

    for (int i = 0; i < CHAR_COUNT; ++i) {
        sumOfSquares += Table[i] * Table[i];
    }

    return sqrt(sumOfSquares);
}

double cosineSimilarity(const int Table1[], const int Table2[]) {
    double product = Product(Table1, Table2);
    double norm1 = vectorLength(Table1);
    double norm2 = vectorLength(Table2);

    if (norm1 == 0.0 || norm2 == 0.0) {
        return 0.0;
    }

    return acos(product / (norm1 * norm2)) * (180.0 / 3.14159265358979323846);
}
