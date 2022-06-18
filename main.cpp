#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2) {
        cout << "musisz podać 2 nazwy plików\n";
        return 0;
    }
    string first_file = argv[1];
    string second_file = argv[2];

    ifstream first_stream(first_file, ios::binary);
    ifstream second_stream(second_file, ios::binary);

    int bit_counter = 0, different_counter = 0;

    char first_char, second_char;
    first_stream >> first_char;
    second_stream >> second_char;

    while(first_char != EOF && second_char != EOF) {
        bit_counter++;
        if (first_char != second_char) {
            different_counter++;
        }
        first_stream >> first_char;
        second_stream >> second_char;
    }

    if(first_char != EOF || second_char != EOF) {
        cout << "nie mozna porownac plikow roznej dlugosci";
    }
    else {
        double a = different_counter, b = bit_counter;
        // aby miec precyzje
        cout << a / b << "\n";
    }

    first_stream.close();
    second_stream.close();

    return 0;
}
