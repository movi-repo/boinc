#include "voyagemgr.h"

#include "commandlauncher.h"

// Qt
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>


/* ============================================================
   * the main window depends on the type of device being used.
   ========================================================= */

class VoyageTopWidget
{
public :
    explicit VoyageTopWidget( VoyageMgr::DeviceAspectType deviceAspect );
private:
    // the top widget aspect depends on the device.
    VoyageMgr::DeviceAspectType myDeviceAspect = VoyageMgr::DA_UNDEFINED ;
};


/* ============================================================
   * VoyageMgr is a BOINC manager.
   ========================================================= */

VoyageMgr::VoyageMgr(  const VoyageMgr::InitialAspectType & initialAspect ) : QMainWindow(nullptr)
{
    setObjectName(QStringLiteral("Voyage"));

    // define default size according to the device
    setMinimumSize( QSize(initialAspect.m_MinWidth,initialAspect.m_MinHeight) );
    resize(initialAspect.m_Width, initialAspect.m_Height);

    m_MenuBar = new QMenuBar(this);
    m_MenuBar->setObjectName(QStringLiteral("m_MenuBar"));
    setMenuBar(m_MenuBar);

    m_MainToolBar = new QToolBar(this);
    m_MainToolBar->setObjectName(QStringLiteral("m_MainToolBar"));
    addToolBar(m_MainToolBar);

    m_CentralWidget = new QWidget(this);
    m_CentralWidget->setObjectName(QStringLiteral("m_CentralWidget"));
    setCentralWidget(m_CentralWidget);

    m_StatusBar = new QStatusBar(this);
    m_StatusBar->setObjectName(QStringLiteral("m_StatusBar"));
    setStatusBar(m_StatusBar);

    retranslateUi();
    QMetaObject::connectSlotsByName(this);

    // update status

    // initial aspect
    m_CommandLauncher = new CommandLauncher( *this );
}


VoyageMgr::~VoyageMgr()
{
    // Qt deletes the widgets.
    // free the memory
    delete m_CommandLauncher ;
}


// make sure character string are ready to be translated.
void VoyageMgr::retranslateUi()
{
    setWindowTitle(QApplication::translate("Voyage", "Voyage", nullptr));
}


void VoyageMgr::resizeEvent(QResizeEvent *event)
{
    if ( event != nullptr ) { QMainWindow::resizeEvent(event); }
    // show/hide according to the size.

}


void VoyageMgr::updateStatus( bool clmChanged )
{

}


void VoyageMgr::messageFromCommandLauncher( VoyageMgr::CommandLauncherMessageType clm )
{
    if ( m_LastCommandLauncherMessage == clm ) {
        return ;
    }
    m_LastCommandLauncherMessage = clm ;
    switch( m_LastCommandLauncherMessage ) {
    case VoyageMgr::CL_CREATED : {
        updateStatus(true);
    } break;
    case VoyageMgr::CL_DELETED : {
        m_CommandLauncher = nullptr ;
    } break;
    }
}
