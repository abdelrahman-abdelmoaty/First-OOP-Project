#include "Notification.h"

bool Notification::checkId(string id2)
{
    if (id2 == id)
        return true;
    return false;
}
