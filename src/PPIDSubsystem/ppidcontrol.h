#ifndef PPIDCONTROL_H
#define PPIDCONTROL_H

#include "StorageSubsystem/project.h"

class PPIDForm;

class PPIDControl
{
    public:
        PPIDControl(Project& project);
        ~PPIDControl();

        void start();
        void group();

    private:
        Project& project;
        PPIDForm form;
};

#endif // PPIDCONTROL_H
