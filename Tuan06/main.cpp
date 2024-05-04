#include "CLibrary.h"

int main()
{
    CLibrary Library;
    Library.Input();
    Library.Output("output.txt");
    Library.Delete();
    Library.SortYear();
    Library.SortCount();

    return 0;
}