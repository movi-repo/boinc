#include "commandlauncher.h"

#include "voyagemgr.h"


CommandLauncher::CommandLauncher( VoyageMgr & voyageMgr ) : m_VoyageMgr(voyageMgr)
{
    m_VoyageMgr.messageFromCommandLauncher( VoyageMgr::CL_CREATED );
    // find out if BOINC is running.

    // If not launch it, and wait till it is ready...

    // When BOINC is ready, grab the available information.

}


CommandLauncher::~CommandLauncher()
{
    m_VoyageMgr.messageFromCommandLauncher( VoyageMgr::CL_DELETED );
}


// This area is creating process (command lines).
void CommandLauncher::boincCommands()
{
}

#if 0
// Source code from BOINCcmd.cpp.
// The main




#endif





