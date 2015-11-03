#include "groupsize.h"

GroupSize::GroupSize(int min, int max)
    : min(min), max(max)
{ }

GroupSize::GroupSize(const GroupSize& copy)
    : min(copy.getMin()), max(copy.getMax())
{ }

GroupSize::~GroupSize()
{ }

int GroupSize::getMin() const
{
    return min;
}

int GroupSize::getMax() const
{
    return max;
}
