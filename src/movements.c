#include "movements.h"

Movement make_movement(long amount, MovementType t) {
    Movement r = { 
        .amount = amount,
        .t = t
    };

    time_t stamp;
    time(&stamp);
    struct tm *info = localtime(&stamp);
    // acrescentar a data do movimento
    sprintf(
        r.date,
        "%hd-%02hd-%02hd %02hd:%02hd:%02hd",
        info->tm_year + 1900,
        info->tm_mon + 1,
        info->tm_mday,
        info->tm_hour,
        info->tm_min,
        info->tm_sec
    );
    return r;
}