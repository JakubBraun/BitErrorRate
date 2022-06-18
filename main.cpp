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

    ifstream first_stream(first_file);
    ifstream second_stream(second_file);


    first_stream.close();
    second_stream.close();

    return 0;
}
