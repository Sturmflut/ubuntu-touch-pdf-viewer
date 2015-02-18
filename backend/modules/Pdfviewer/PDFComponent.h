#ifndef MYTYPE_H
#define MYTYPE_H

#include <QtGui/QImage>

#include <QtQuick/QQuickPaintedItem>

#include <poppler/qt5/poppler-qt5.h>


class PDFComponent : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString documentPath READ documentPath WRITE setDocumentPath)
    Q_PROPERTY(qint32 pageNumber READ pageNumber WRITE setPageNumber)
    Q_PROPERTY(qint32 numberOfPages READ numberOfPages)

public:
    explicit PDFComponent(QQuickItem *parent = 0);
    ~PDFComponent();

    QString documentPath() const;
    void setDocumentPath(const QString &documentPath);

    qint32 pageNumber() const;
    void setPageNumber(const qint32 pageNumber);

    Q_SLOT void nextPage();
    Q_SLOT void previousPage();

    qint32 numberOfPages() const;

    void paint(QPainter *painter);

private:
    QString m_documentPath;
    qint32 m_pageNumber;

    Poppler::Document* m_document;
    Poppler::Page* m_pageBuffer;
};

#endif // MYTYPE_H

