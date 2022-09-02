#include "Types.h"

bool operator!(ActionResult res) {
    return res == ActionResult::FAILED;
}