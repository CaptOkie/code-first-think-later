#ifndef GROUPSIZE_H
#define GROUPSIZE_H

class GroupSize
{
    public:
        GroupSize(int min, int max);
        GroupSize(const GroupSize&);

        int getMin() const;
        int getMax() const;

    private:
        int min,max;
};

#endif // GROUPSIZE_H
