#include "Notification.h"

bool Notification::checkId(string _id){
    if (_id == id) return true;
    return false;
}

