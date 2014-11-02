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
    setMinimumSize(320,240);
    setMaximumSize(640,480);

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
