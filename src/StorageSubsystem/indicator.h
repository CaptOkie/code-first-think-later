#ifndef INDICATOR_H
#define INDICATOR_H

class Indicator
{
    public:
        Indicator(bool value);
        ~Indicator();

    public:
        bool getValue();
        bool toggleValue();

    private:
        bool value;
};

#endif // INDICATOR_H
