#include "indicator.h"

Indicator::Indicator(bool value)
    : value(value)
{ }

Indicator::~Indicator()
{ }

bool Indicator::getValue()
{
    return value;
}

bool Indicator::toggleValue()
{
    return value = !value;
}
