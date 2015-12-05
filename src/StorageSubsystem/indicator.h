#ifndef INDICATOR_H
#define INDICATOR_H

class Indicator
{
    public:
        Indicator(bool value);
        ~Indicator();

    public:
        bool getValue();
        void setValue(bool value);

    private:
        bool value;
};

#endif // INDICATOR_H
