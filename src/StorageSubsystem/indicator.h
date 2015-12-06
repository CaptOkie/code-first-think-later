#ifndef INDICATOR_H
#define INDICATOR_H

/**
 * @brief The Indicator class. Used for the purpose of having const objects.
 *        Used as pointer in other classes to change a boolean while it is const.
 */
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
