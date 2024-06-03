#include  "Client.h"
#include <ctime>
#include <algorithm>
#define FILES 4

int main()
{
    srand(time(0));
    FILE* file = nullptr;
 

#if FILES == 1
     Client Daniil{"Gryshenko Daniil", "1234123412341234", 2500};

    fopen_s(&file, "bank.txt", "w");
    if (file != NULL) {
        Daniil.saveToTextFile(file);
        fclose(file);
    }
#elif  FILES == 2
    Client Daniil; // "", "", 0
    Daniil.showClient();
    cout << "-------------------------------------\n\n";
    fopen_s(&file, "bank.txt", "r");
    if (file != NULL) {
        Daniil.loadFromTextFile(file);
        fclose(file);
    }
    Daniil.showClient();

#elif  FILES == 3
    int N = 0;
    Client* arr = nullptr;

    fopen_s(&file, "bank.txt", "r");
    if (file != NULL) {
        fscanf_s(file, "%d", &N); // 3
        arr = new Client[N];
        for (int i = 0; i < N; i++) {
            arr[i].loadFromTextFile(file);
        }
        fclose(file);
    }
   
    sort(arr, arr + N, [](Client a, Client b) { return a.cash > b.cash; });
    for (int i = 0; i < N; i++) {
        cout << "\t Client#" << i + 1 << endl;
        arr[i].showClient();
    }

    fopen_s(&file, "bank.txt", "w");
    if (file != NULL) {
        fprintf(file, "%d", N);
        for (int i = 0; i < N; i++){
            arr[i].saveToTextFile(file);
        }
        fclose(file);
    }
#elif  FILES == 4
    int N = 0;
    Client* arr = nullptr;

    fopen_s(&file, "bank-2.txt", "rb");
    if (file != NULL) {
        fread(&N, sizeof(int), 1, file);
        arr = new Client[N];
        for (int i = 0; i < N; i++) {
            arr[i].loadFromBinFile(file);
        }
        fclose(file);
    }

    sort(arr, arr + N, [](Client a, Client b) { return a.cash > b.cash; });
    for (int i = 0; i < N; i++) {
        cout << "\t Client#" << i + 1 << endl;
        arr[i].showClient();
    }

    fopen_s(&file, "bank-2.txt", "wb");
    if (file != NULL) {
        fwrite(&N, sizeof(int), 1, file);
        for (int i = 0; i < N; i++) {
            arr[i].saveToBinFile(file);
        }
        fclose(file);
    }

#endif // FILES

    
}

