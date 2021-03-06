/***************************************************************************
  qgsmaprenderersequentialjob.h
  --------------------------------------
  Date                 : December 2013
  Copyright            : (C) 2013 by Martin Dobias
  Email                : wonder dot sk at gmail dot com
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSMAPRENDERERSEQUENTIALJOB_H
#define QGSMAPRENDERERSEQUENTIALJOB_H

#include "qgsmaprendererjob.h"

class QgsMapRendererCustomPainterJob;

/** job implementation that renders everything sequentially in one thread */
class CORE_EXPORT QgsMapRendererSequentialJob : public QgsMapRendererQImageJob
{
    Q_OBJECT
  public:
    QgsMapRendererSequentialJob( const QgsMapSettings& settings );
    ~QgsMapRendererSequentialJob();

    virtual void start();
    virtual void cancel();
    virtual void waitForFinished();
    virtual bool isActive() const;

    virtual QgsLabelingResults* takeLabelingResults();

    // from QgsMapRendererJobWithPreview
    virtual QImage renderedImage();

  public slots:

    void internalFinished();

  protected:

    QgsMapRendererCustomPainterJob* mInternalJob;
    QImage mImage;
    QPainter* mPainter;
    QgsLabelingResults* mLabelingResults;
};


#endif // QGSMAPRENDERERSEQUENTIALJOB_H
