#include <iostream>
#include <string>
using namespace std;

void perevod(int k)
{
    int i;
    // для прочих размерностей меняем i
    for (i = 31; i >= 0; i--)
    {
        printf("%d", (k >> i) & 1);
        if (0 == i % 8) printf(" ");
    }
    puts("\n");
}

void proverka(int n) {
    cout << "Найти первые " << n << " целых чисел, у которых старший байт является зеркальным отражением предыдущего байта." << endl;
    int i = 0, k = 0, number = 0;
    // для понятного результата пишите 25165823 и больше (например, 35177823)
    while (k < n) {
        unsigned char lo = (unsigned char)(number >> 16); // предыдущий байт
        unsigned char hi = (unsigned char)(number >> 24);  // старший байт
        // для прочих размерностей меняем 16 и 24
        int flag = 1; //является ли число зеркальным
        for (int i = 0; (i < 8) && flag; i++) {
            flag = (((lo >> i) & 1) == ((hi >> (7 - i)) & 1));
        }
        if (flag) {
            cout << number << endl;
            perevod(number);
            k++;
        }
        number++;
    }
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru");
    if (argc == 2) {
        try
        {
            int N = stoi(argv[1]);
            proverka(N);
        }
        catch (const exception&)
        {
            cout << "Повторите ввод" << endl;
        }
    }
    else {
        cout << "Сначала введите название программы, а затем количество чисел." << endl;
    }
    return 0;
}
