#ifndef COMMANDLAUNCHER_H
#define COMMANDLAUNCHER_H

#include <QObject>

class VoyageMgr ;


/** the purpose of CommandLauncher is to commiinicate with BOINC
 * the same way as BOINCCmd is doing. Ir launchs a process */



class CommandLauncher
{
public:
    //

    //
    explicit CommandLauncher( VoyageMgr &c );
    ~CommandLauncher();

    void boincCommands();
private:
    VoyageMgr & m_VoyageMgr ;
};

#endif

