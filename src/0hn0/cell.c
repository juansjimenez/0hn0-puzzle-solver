#include <stdlib.h>
#include <stdio.h>
#include "cell.h"


Cell cell_init(int grade) {
    Cell cell = {grade};
    cell.seen_count = 0;
    return cell;
}
