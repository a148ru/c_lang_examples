#include <stdbool.h>
#include "api.h"


bool minorErrorOccurs();
bool majorErrorOccurs();



ErrorCode func()
{
    if(minorErrorOccurs())
    {
        return MINOR_ERROR;
    }
    else if(majorErrorOccurs())
    {
        return MAJOR_ERROR;
    }
    else
    {
        return OK;
    }
}


bool minorErrorOccurs()
{
    return false;
}
bool majorErrorOccurs()
{
    return false;
}