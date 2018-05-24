#ifndef VOYAGEMGR_H
#define VOYAGEMGR_H

#include <QMainWindow>

/** VoyageMgr has several puposes:
 * = provide the GUI the same way as a BOINC Manager does.
 * = launch BOINC (if not already running) and
 * = get the state of the application that is running (e.g.: presence of the files that are present).
 * = update the GUI according to the state and the .
 * */

class VoyageMgr : public QMainWindow
{
    Q_OBJECT
public:
    // device type: it rules the aspect and the possibilities.
    enum DeviceAspectType { DA_UNDEFINED , DA_LAPTOP , DA_TABLET , DA_MOBILE };
    // initial parameters detected by the main and provided at the initialisation.
    struct InitialAspectType {
        // type of device
        DeviceAspectType m_DeviceAspect ; // to be defined.
        // size
        int m_MinWidth  ;
        int m_MinHeight ;
        int m_Width     ;
        int m_Height    ;
    };

    explicit VoyageMgr( const InitialAspectType & );
    ~VoyageMgr();

    // message from components
    enum CommandLauncherMessageType { CL_UNDEFINED , CL_CREATED , CL_READY , CL_DELETED };
    void messageFromCommandLauncher( CommandLauncherMessageType );

private:
    /*=========================== GUI ===========================*/
    // GUI aspect: the resize
    void retranslateUi();
    void resizeEvent(QResizeEvent *event);

    // GUI: main window.
    QMenuBar   *m_MenuBar       = nullptr;
    QToolBar   *m_MainToolBar   = nullptr;
    QWidget    *m_CentralWidget = nullptr;
    QStatusBar *m_StatusBar     = nullptr;


    /*=========================== COMMANDS ===========================*/
    // Commands area: it launchs applications and get information about the status.
    class CommandLauncher * m_CommandLauncher = nullptr ;


    /*=========================== STATUS ===========================*/
    // the status runs the aspect of the GUI.
    VoyageMgr::CommandLauncherMessageType m_LastCommandLauncherMessage = CL_UNDEFINED ;
    // Status area:
    void updateStatus( bool commandLauncherMessageHasChanged );
};

#endif

