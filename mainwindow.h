#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "videoplayer.h"
#include "videoslider.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // 播放状态改变
    void onPlayerStateChanged(VideoPlayer *player);

    // 播放时间改变
    void onPlayerTimeChanged(VideoPlayer *player);

    // 播放器初始化完成
    void onPlayerInitFinished(VideoPlayer *player);

    // 播放失败
    void onPlayerPlayFailed(VideoPlayer *player);

    // 静音
    void onSliderClicked(VideoSlider *slider);

    // 停止
    void on_stopBtn_clicked();

    // 点击打开文件
    void on_openFileBtn_clicked();

    // 点击播放条（快进、后退）
    void on_timeSlider_valueChanged(int value);

    // 改变音量
    void on_volumnSlider_valueChanged(int value);

    // 点击播放按钮
    void on_playBtn_clicked();

    // 静音/开音
    void on_muteBtn_clicked();

    // URL輸入完畢
    void on_URLInput_returnPressed();

    void on_URLInput_editingFinished();

private:
    Ui::MainWindow *ui;
    VideoPlayer *_player;

    QString getTimeText(int value);
};
#endif // MAINWINDOW_H
