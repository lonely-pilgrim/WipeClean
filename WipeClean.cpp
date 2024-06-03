#include <iostream>
#include <cstdlib> 
#include <thread>
#include <Windows.h>
#include <Shellapi.h>


using namespace std;

int main()
{
    HWND hwnd = GetConsoleWindow(); // Получить дескриптор окна консоли
    RECT rect;
    GetWindowRect(hwnd, &rect); // Получить текущий размер окна
    int width = 800;
    int height = 500;
    // Установить новый размер окна
    SetWindowPos(hwnd, NULL, rect.left, rect.top, width, height, SWP_NOZORDER | SWP_NOACTIVATE);
    SetConsoleTitle(TEXT("WipeClean"));

    bool isError = false;
    bool isFinish = false;

    //ВЫБОР ОПЦИИ
    while (true) {

        cout << R"( __      __     ______      ____     ____       ____       __         ____       ______      __  __     
/\ \  __/\ \   /\__  _\    /\  _`\  /\  _`\    /\  _`\    /\ \       /\  _`\    /\  _  \    /\ \/\ \    
\ \ \/\ \ \ \  \/_/\ \/    \ \ \L\ \\ \ \L\_\  \ \ \/\_\  \ \ \      \ \ \L\_\  \ \ \L\ \   \ \ `\\ \   
 \ \ \ \ \ \ \    \ \ \     \ \ ,__/ \ \  _\L   \ \ \/_/_  \ \ \  __  \ \  _\L   \ \  __ \   \ \ , ` \  
  \ \ \_/ \_\ \    \_\ \__   \ \ \/   \ \ \L\ \  \ \ \L\ \  \ \ \L\ \  \ \ \L\ \  \ \ \/\ \   \ \ \`\ \ 
   \ `\___x___/    /\_____\   \ \_\    \ \____/   \ \____/   \ \____/   \ \____/   \ \_\ \_\   \ \_\ \_\
    '\/__//__/     \/_____/    \/_/     \/___/     \/___/     \/___/     \/___/     \/_/\/_/    \/_/\/_/
                                                                                                        
                                                                                                        
)" << '\n';


        //ОПЦИИ
        cout << R"([1] - minimal cleaning (cleaning temporary files)
[2] - full cleaning (cleaning temporary files and old drivers)
[0] - exit
)" << endl;

        if (isError) {
            cout << "\033[31mError!\033[0m\n";
            isError = false;
        }
        if (isFinish) {
            cout << "\033[32mFinish!\033[0m\n";
            isFinish = false;
        }
        int n;
        cout << endl << "Choose a menu option: ";
        cin >> n;

        //Выполнение команд
        switch (n) {
        case 0:
            cout << endl << "Exiting the program..." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            exit(0);
        case 1:

            system("for /d %i in (\"C:\\Users\\%USERNAME%\\AppData\\Local\\Temp\\*\") do rd /s /q \"%i\"> nul 2>&1");
            system("del / s / q C:\\Users\\%USERNAME%\\AppData\\Local\\Temp> nul 2>&1");

            system("for /d %i in (\"C:\\Windows\\Temp\\*\") do rd /s /q \"%i\"> nul 2>&1");
            system("del / s / q C:\\Windows\\Temp> nul 2>&1");

            system("for /d %i in (\"C:\\Windows\\Prefetch\\*\") do rd /s /q \"%i\"> nul 2>&1");
            system("del / s / q C:\\Windows\\Prefetch> nul 2>&1");
            system("cls");
            isFinish = true;
            break;

        case 2:

            system("for /d %i in (\"C:\\Users\\%USERNAME%\\AppData\\Local\\Temp\\*\") do rd /s /q \"%i\"> nul 2>&1");
            system("del / s / q C:\\Users\\%USERNAME%\\AppData\\Local\\Temp> nul 2>&1");

            system("for /d %i in (\"C:\\Windows\\Temp\\*\") do rd /s /q \"%i\"> nul 2>&1");
            system("del / s / q C:\\Windows\\Temp> nul 2>&1");

            system("for /d %i in (\"C:\\Windows\\Prefetch\\*\") do rd /s /q \"%i\"> nul 2>&1");
            system("del / s / q C:\\Windows\\Prefetch> nul 2>&1");

            system("for /d %i in (\"C:\\Windows\\SoftwareDistribution\\Download\\*\") do rd /s /q \"%i\"> nul 2>&1");
            system("del / s / q C:\\Windows\\SoftwareDistribution\\Download> nul 2>&1");

            system("for /d %i in (\"C:\\Users\\%USERNAME%\\AppData\\Local\\NVIDIA\\GLCache\\*\") do rd /s /q \"%i\"> nul 2>&1");
            system("del / s / q C:\\Users\\%USERNAME%\\AppData\\Local\\NVIDIA\\GLCache> nul 2>&1");
            system("cls");
            isFinish = true;
            break;
        default:
            // В случае неправильного ввода
            system("cls");
            isError = true;
            break;
        }

    }
    return 0;
}