#include "groupsize.h"

GroupSize::GroupSize(int min, int max)
    : min(1), max(2)
{
    setMin(min);
    setMax(max);
}

GroupSize::GroupSize(const GroupSize& copy)
    : min(copy.getMin()), max(copy.getMax())
{ }

int GroupSize::getMin() const
{
    return min;
}

int GroupSize::getMax() const
{
    return max;
}

void GroupSize::setMin(int min)
{
    this->min = min;
    if (min >= max) {
        setMax(min + 1);
    }
}

void GroupSize::setMax(int max)
{
    this->max = max;
    if (max <= min) {
        setMin(max - 1);
    }
}
