#include <QtQml>
#include <QtQml/QQmlContext>
#include "backend.h"
#include "PDFComponent.h"


void BackendPlugin::registerTypes(const char *uri)
{
    Q_ASSERT(uri == QLatin1String("Pdfviewer"));

    qmlRegisterType<PDFComponent>(uri, 1, 0, "PDFComponent");
}

void BackendPlugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
    QQmlExtensionPlugin::initializeEngine(engine, uri);
}

