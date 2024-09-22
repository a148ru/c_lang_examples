#include "api.h"

int main(int argc, char* argv[])
{
    ErrorCode status = func();
    {
        if(status == MINOR_ERROR)
        {
            /* Завершаем программу */
            return -1;
        }
        else if(status == MAJOR_ERROR)
        {
            /* обработать ошибку */
        }
        else if(status == OK)
        {
            /* продолжить выполнение*/
        }
    }
    return 0;
}