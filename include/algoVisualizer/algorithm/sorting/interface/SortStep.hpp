#pragma once

#include <cstddef>

enum StepType {
    SWAP,
    COMPARE,
};

struct SortStep {
    size_t i;
    size_t j;
    StepType type;
};
