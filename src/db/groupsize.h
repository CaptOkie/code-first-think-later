#ifndef GROUPSIZE_H
#define GROUPSIZE_H

/**
 * @brief The GroupSize class
 *
 * Stores information about the group size of a Project.
 */
class GroupSize
{
    public:
        /**
         * @brief GroupSize Creates a new instance, which claims ownership of, and responsibility for deleting, pointers.
         * @param min The minimum allowed group size (inclusive).
         * @param max The maximum allowed group size (inclusive).
         */
        GroupSize(int min, int max);

        /**
         * @brief GroupSize Creates a new instance.
         * @param copy The other GroupSize to copy.
         */
        GroupSize(const GroupSize& copy);

        ~GroupSize();

        /**
         * @brief getMin
         * @return The minimum allowed group size (inclusive).
         */
        int getMin() const;

        /**
         * @brief getMax
         * @return The maximum allowed group size (inclusive).
         */
        int getMax() const;

    private:
        int min,max; // The minimum and maximum allowed group size
};

#endif // GROUPSIZE_H
