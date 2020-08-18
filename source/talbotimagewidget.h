#ifndef TALBOT_IMAGEWIDGET_H
#define TALBOT_IMAGEWIDGET_H

#include "imagewidget.h"
#include "imageprocesser.h"
#include "chartwidget.h"

#include <QMouseEvent>

#include <talbotmatrix.h>

using namespace std;

class TalbotImageProcesser : public ImageProcesser
{
public:
    TalbotImageProcesser() = default;

    void process(QImage &image) override;
    void updateTalbotParams(const TalbotParams &newParams);
private:
    TalbotMatrix ohThisIsTalbot;
};

class TalbotImageWidget : public ImageWidget
{
    Q_OBJECT
public:
    explicit TalbotImageWidget(QWidget *parent = nullptr);
    void reprocess() override;

    vector<double> getGraph();
    void connectChart(ChartWidget *widget);

    void updateTalbotParams(const TalbotParams &newParams);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
private:
    ChartWidget *talbotChart;
    TalbotImageProcesser processer;
    void drawChart();
    int viewX;
};

#endif // IMAGEWIDGET_H
