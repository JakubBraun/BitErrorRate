#include <iostream>
#include <fstream>
#include <chrono>
using namespace std::chrono;
using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2) {
        cout << "musisz podać 2 nazwy plików\n";
        return 0;
    }
    auto start = high_resolution_clock::now();

    string first_file = argv[1];
    string second_file = argv[2];

    ifstream first_stream(first_file, ios::binary);
    ifstream second_stream(second_file, ios::binary);

    ofstream logs_file;
    logs_file.open("logs.txt");

    int bit_counter = 0, different_counter = 0;

    char first_char, second_char;
    first_stream >> first_char;
    second_stream >> second_char;

    while(!first_stream.eof() && !second_stream.eof()) {
        bit_counter++;
        if (first_char != second_char) {
            different_counter++;
        }
        first_stream >> first_char;
        second_stream >> second_char;
    }

    if(!first_stream.eof() || !second_stream.eof()) {
        auto now = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(now.time_since_epoch());
        logs_file << duration.count() << "nie mozna porownac plikow roznej dlugosci\n";
        cout << duration.count() << "nie mozna porownac plikow roznej dlugosci";
    }
    else {
        double a = different_counter, b = bit_counter;
        // aby miec precyzje
        auto now = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(now.time_since_epoch());
        cout << duration.count() << " ilosc roznych bajtow: " << a << "\n";
        cout << duration.count() << " ilosc porownanych bajtow: " << b << "\n";
        cout << duration.count() << " BER: " << a / b << "\n";
        logs_file << duration.count() << " ilosc roznych bajtow: " << a << "\n";
        logs_file << duration.count() << " ilosc porownanych bajtow: " << b << "\n";
        logs_file << duration.count() << " BER: " << a / b << "\n";
        auto stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "czas: " << duration.count() << "\n";
    }

    first_stream.close();
    second_stream.close();
    logs_file.close();

    return 0;
}
