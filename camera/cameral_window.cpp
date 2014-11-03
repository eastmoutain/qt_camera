#include "cameral_window.h"

cameral_window::cameral_window(QWidget *parent)
    : QMainWindow(parent)
{
    centralwidget = new QWidget(this);
    setCentralWidget(centralwidget);
  //  QGridLayout *mainLayout = new QGridLayout;
   // centralWidget->setLayout(mainLayout);
    centraLayout = new QGridLayout(centralwidget);
    centraLayout->setObjectName(tr("centreLayout"));
    //stackedWidget = new QStackedWidget(centralwidget);
    //stackedWidget->setObjectName(tr("stackedWidget"));

    viewFinderPage = new QWidget(centralwidget);
    viewFinderPage->setObjectName(tr("viewFinderPage"));

    centraLayout->addWidget(viewFinderPage);
    viewFinder = new QCameraViewfinder(centralwidget);
    viewFinder->setObjectName(tr("viewFinder"));
    gridLayout_viewFinder = new QGridLayout(viewFinderPage);
    gridLayout_viewFinder->addWidget(  viewFinder, 0, 0, 1, 1);


    //setLayout(centralwidget);
    setWindowTitle(tr("camera window"));
    centralwidget->setMinimumSize(320,240);
    centralwidget->setMaximumSize(640,480);

    createActions();
    createMenus();
    createToolBars();
    createStatusBar();

    QByteArray cameraDevice;
    setCamera(cameraDevice);


}

cameral_window::~cameral_window()
{

}

void cameral_window::setCamera(const QByteArray &deviceName)
{
    if(deviceName.isEmpty())
    {
        camera = new QCamera;
    }
    else
    {
        camera = new QCamera(deviceName);
    }

//    connect(camera, SIGNAL(stateChanged(QCamera::State)), this, SLOT(updateCameraState(QCamera::State)));
//    connect(camera, SIGNAL(error(QCamera::Error)), this, SLOT(displayCameraError()));

    camera->setViewfinder(viewFinder);
    camera->start();
}

void cameral_window::startCamera()
{
    camera->start();
}
void cameral_window::stopCamera()
{
    camera->stop();
}
void cameral_window::about()
{
       QMessageBox::about(this, tr("About Dock Widgets"),
                tr("The <b>Dock Widgets</b> example demonstrates how to "
                   "use Qt's dock widgets. You can enter your own text, "
                   "click a customer to add a customer name and "
                   "address, and click standard paragraphs to add them."));
}

void cameral_window::createActions()
{
    /*
    * Create actions for "File Menubar"
    * There are "start camera", "stop camera" and "exit camera"
    */

    startCameraAction = new QAction(QIcon("start.png"), tr("Start camera"), this);
    startCameraAction->setStatusTip(tr("start camera"));
    connect(startCameraAction,SIGNAL(triggered()),this,SLOT(startCamera()));

    stopCameraAction = new QAction(QIcon("stop.png"),tr("Stop camera"), this);
    stopCameraAction->setStatusTip(tr("stop camera"));
    connect(stopCameraAction,SIGNAL(triggered()),this,SLOT(stopCamera()));

    exitAction = new QAction(QIcon("exit.png"),tr("Exit"),this);
    exitAction->setStatusTip(tr("quit application"));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));

    aboutAction = new QAction(QIcon("about.png"), tr("About"),this);
    aboutAction->setStatusTip(tr("about Qt"));
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(about()));


}
void cameral_window::createMenus()
{
    /*
    *   Create MenuBars for the main window, here only realise two menu bar,
    *   There are "File menu" and "About menu"
    */
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(startCameraAction);
    fileMenu->addAction(stopCameraAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    aboutMenu = menuBar()->addMenu(tr("&About"));
    aboutMenu->addAction(aboutAction);


}
void cameral_window::createToolBars()
{
    /*
    *   Create toolBar for the main window.
    *   They are "start camera", "stop camera" and "exit"
    */

    fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(startCameraAction);
    fileToolBar->addAction(stopCameraAction);
    fileToolBar->addAction(exitAction);

    aboutToolBar = addToolBar(tr("&About"));
    aboutToolBar->addAction(aboutAction);

}
void cameral_window::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

