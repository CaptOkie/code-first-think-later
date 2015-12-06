#ifndef PPIDCONTROL_H
#define PPIDCONTROL_H

#include "StorageSubsystem/project.h"
#include "ppidform.h"
#include "grouper.h"

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
        Grouper* grouper;
};

#endif // PPIDCONTROL_H
