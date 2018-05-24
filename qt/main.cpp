#include "voyagemgr.h"
#include <QApplication>

/**
 * the main detects some parameters and launchs Voyage that is a BOINC manager.
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // have some information about the device/size.
    VoyageMgr::InitialAspectType initialAspect ;
    initialAspect.m_DeviceAspect = VoyageMgr::DA_UNDEFINED;
    initialAspect.m_MinWidth     = 300;
    initialAspect.m_MinHeight    = 150;
    initialAspect.m_Width        = 400;
    initialAspect.m_Height       = 300;
    // get some information about the device.


    // launch main window.
    VoyageMgr w(initialAspect);
    w.show();

    return a.exec();
}
