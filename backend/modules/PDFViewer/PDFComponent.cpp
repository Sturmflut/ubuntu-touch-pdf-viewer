#include <QtGui/QPainter>
#include <QtGui/QPen>

#include <iostream>

#include "PDFComponent.h"

using namespace std;


PDFComponent::PDFComponent(QQuickItem *parent) :
    QQuickPaintedItem(parent),
    m_documentPath(""),
    m_pageNumber(0)
{

}

QString PDFComponent::documentPath() const
{
    return m_documentPath;
}


void PDFComponent::setDocumentPath(const QString &documentPath)
{
    m_document = Poppler::Document::load(documentPath);

    if(!m_document || m_document->isLocked())
    {
        delete m_document;
        return;
    }

    m_document->setRenderHint(Poppler::Document::Antialiasing);
    m_document->setRenderHint(Poppler::Document::TextAntialiasing);

    setPageNumber(1);
}


qint32 PDFComponent::pageNumber() const
{
    return m_pageNumber;
}


void PDFComponent::setPageNumber(const qint32 pageNumber)
{
    if(pageNumber > 0 && pageNumber <= numberOfPages() && m_document)
    {
        if(m_pageBuffer)
            delete m_pageBuffer;

        m_pageBuffer = m_document->page(pageNumber - 1);

        m_pageNumber = pageNumber;

        update();

        qDebug() << "setPageNumber";
    }
}


void PDFComponent::nextPage()
{
    setPageNumber(m_pageNumber + 1);
}


void PDFComponent::previousPage()
{
    setPageNumber(m_pageNumber - 1);
}


qint32 PDFComponent::numberOfPages() const
{
    if(m_document || m_document->isLocked())
    {
        return m_document->numPages();
    }

    return 0;
}


void PDFComponent::paint(QPainter *painter)
{
    qDebug() << "paint";

    if(m_pageBuffer)
    {
        qDebug() << "renderToPainter";
        painter->drawImage(QPointF(0,0),m_pageBuffer->renderToImage(72,72));
    }
}

PDFComponent::~PDFComponent() {

}

