#ifndef MUSICVIDEOPLAYWIDGET_H
#define MUSICVIDEOPLAYWIDGET_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (c) 2015 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "musicabstractmovewidget.h"

class QLabel;
class QPushButton;
class QToolButton;
class QStackedWidget;
class MusicVideoView;
class MusicVideoFloatWidget;
class MusicVideoTableWidget;
class MusicLocalSongSearchEdit;

/*! @brief The class of the video play widget.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_VIDEO_EXPORT MusicVideoPlayWidget : public MusicAbstractMoveWidget
{
    Q_OBJECT
public:
    explicit MusicVideoPlayWidget(QWidget *parent = 0);
    /*!
     * Object contsructor.
     */
    ~MusicVideoPlayWidget();

    static QString getClassName();
    /*!
     * Get class object name.
     */

    void popup(bool popup);
    /*!
     * Set the window is popup or not.
     */
    bool isPopup() const;
    /*!
     * Get the window is popup or not.
     */
    void resizeWindow();
    /*!
     * Resize window bound by widgte resize called.
     */
    void resizeWindow(bool resize);
    /*!
     * Resize widget size or not.
     */
    void resizeWindow(int width, int height);
    /*!
     * Resize widget size or not.
     */
    QString getSearchText() const;
    /*!
     * Get search text in search line.
     */

Q_SIGNALS:
    void freshButtonClicked(bool popup);
    /*!
     * Fresh button state changed.
     */
    void fullscreenButtonClicked(bool popup);
    /*!
     * Fullscreen button clicked.
     */

public Q_SLOTS:
    void switchToSearchTable();
    /*!
     * Switch to search table.
     */
    void switchToPlayView();
    /*!
     * Switch to play view.
     */
    void searchButtonClicked();
    /*!
     * Search button clicked.
     */
    void windowTopStateChanged();
    /*!
     * Window top state changed.
     */
    void videoResearchButtonSearched(const QString &name);
    /*!
     * Video research button searched by name.
     */
    void mvURLChanged(const QString &data);
    /*!
     * Set current media url by selected quality.
     */
    void mvURLNameChanged(const QString &name, const QString &data);
    /*!
     * Set current media name and url to play.
     */

    void freshButtonClicked();
    /*!
     * Fresh button clicked.
     */
    void fullscreenButtonClicked();
    /*!
     * Fullscreen button clicked.
     */
    void downloadButtonClicked();
    /*!
     * Download button clicked.
     */
    void shareButtonClicked();
    /*!
     * Share button clicked.
     */

protected:
    virtual void resizeEvent(QResizeEvent *event) override;
    virtual void contextMenuEvent(QContextMenuEvent *event) override;
    /*!
     * Override the widget event.
     */
    void setTitleText(const QString &text);
    /*!
     * Set current title text(song name).
     */

    bool m_windowPopup;
    QWidget *m_topWidget;
    QLabel *m_textLabel;
    QString m_currentMediaName;
    QToolButton *m_backButton;
    QPushButton *m_searchButton, *m_closeButton, *m_winTopButton;
    QStackedWidget *m_stackedWidget;
    MusicVideoView *m_videoView;
    MusicVideoTableWidget *m_videoTable;
    MusicLocalSongSearchEdit *m_searchEdit;
    MusicVideoFloatWidget *m_videoFloatWidget;

};

#endif //MUSICVIDEOPLAYWIDGET_H

