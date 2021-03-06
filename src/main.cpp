#include "qt_opencv_samples/blur/Blur.h"
#include "qt_opencv_samples/canny/Canny.h"
#include "qt_opencv_samples/detect/DetectCorners.h"
#include "qt_opencv_samples/detect/DetectObjects.h"
#include "qt_opencv_samples/equalize/Equalize.h"
#include "qt_opencv_samples/flip/Flip.h"
#include "qt_opencv_samples/perspective/Perspective.h"
#include "qt_opencv_samples/rotation/Rotation.h"
#include "qt_opencv_samples/threshold/Threshold.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>

static void qmlRegistration()
{
    using qt_opencv_samples::blur::Blur;
    using qt_opencv_samples::canny::Canny;
    using qt_opencv_samples::detect::DetectCorners;
    using qt_opencv_samples::detect::DetectObjects;
    using qt_opencv_samples::equalize::Equalize;
    using qt_opencv_samples::flip::Flip;
    using qt_opencv_samples::perspective::Perspective;
    using qt_opencv_samples::rotation::Rotation;
    using qt_opencv_samples::threshold::Threshold;

    qmlRegisterType<Flip>("QtOpenCVSamples", 1, 0, "Flip");
    qmlRegisterType<Rotation>("QtOpenCVSamples", 1, 0, "Rotation");
    qmlRegisterType<Perspective>("QtOpenCVSamples", 1, 0, "Perspective");
    qmlRegisterType<Equalize>("QtOpenCVSamples", 1, 0, "Equalize");
    qmlRegisterType<Threshold>("QtOpenCVSamples", 1, 0, "Threshold");
    qmlRegisterType<Blur>("QtOpenCVSamples", 1, 0, "Blur");
    qmlRegisterType<Canny>("QtOpenCVSamples", 1, 0, "Canny");
    qmlRegisterType<DetectCorners>("QtOpenCVSamples", 1, 0, "DetectCorners");
    qmlRegisterType<DetectObjects>("QtOpenCVSamples", 1, 0, "DetectObjects");
}

int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    app.setOrganizationName("None");
    app.setOrganizationDomain("None");

    qmlRegistration();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/MainWindow.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
