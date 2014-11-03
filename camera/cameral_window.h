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
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QIcon>

#include <QMessageBox>

QT_BEGIN_NAMESPACE
class QAction;
class QListWidget;
class QMenu;
class QTextEdit;
class QToolBar;
QT_END_NAMESPACE


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
    void about();

private:
    QWidget *centralwidget;
    QCamera *camera;
    QGridLayout *centraLayout;
    QGridLayout *gridLayout_viewFinder;
    QStackedWidget *stackedWidget;
    QWidget *viewFinderPage;
    QCameraViewfinder *viewFinder;

    QAction *stopCameraAction;
    QAction *startCameraAction;
    QAction *exitAction;
    QAction *aboutAction;

    QMenu *fileMenu;
    QMenu *aboutMenu;

    QToolBar *fileToolBar;
    QToolBar *aboutToolBar;

    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
};

#endif // CAMERAL_WINDOW_H
