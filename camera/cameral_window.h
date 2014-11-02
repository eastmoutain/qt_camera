#ifndef CAMERAL_WINDOW_H
#define CAMERAL_WINDOW_H


#include <QCamera>
#include <QCameraImageCapture>
#include <QMediaRecorder>

#include <QMainWindow>

#include  <QObject>
#include <QGridLayout>
#include <QStackedWidget>
#include <QCameraViewfinder>
#include <QActionGroup>
#include <QString>
#include <QWidget>



class cameral_window : public QMainWindow
{
    Q_OBJECT

public:
    cameral_window(QWidget *parent = 0);
    ~cameral_window();
private slots:
    void setCamera(const QByteArray &cameraDevice);

    void startCamera();
    void stopCamera();

private:
    QWidget *centralwidget;
    QCamera *camera;
    QGridLayout *centraLayout;
    QGridLayout *gridLayout_viewFinder;
    QStackedWidget *stackedWidget;
    QWidget *viewFinderPage;
    QCameraViewfinder *viewFinder;
};

#endif // CAMERAL_WINDOW_H
