#include "movements.h"

Movement make_movement(long amount) {
    Movement r = { .amount = amount };

    time_t stamp;
    time(&stamp);
    struct tm *info = localtime(&stamp);
    // acrescentar a data do movimento
    sprintf(
        r.date,
        "%d-%02d-%02d %02d:%02d:%02d",
        info->tm_year + 1900,
        info->tm_mon + 1,
        info->tm_mday,
        info->tm_hour,
        info->tm_min,
        info->tm_sec
    );
    return r;
}

MovementType type_of_movement(Movement *m) {
   return m->amount > 0 ? CREDIT : DEBIT;
}