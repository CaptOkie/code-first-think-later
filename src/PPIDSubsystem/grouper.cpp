#include "grouper.h"

Grouper::Grouper(Matcher* matcher)
    : matcher(matcher)
{ }

Grouper::~Grouper()
{
    delete matcher;
}
