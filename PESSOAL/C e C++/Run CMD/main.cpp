#include <windows.h>

int main() {

    ShellExecute( NULL, NULL, "calc.exe", NULL, NULL, SW_SHOW );
}