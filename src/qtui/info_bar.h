/*
 * info_bar.h
 * Copyright 2014 William Pitcock
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions, and the following disclaimer in the documentation
 *    provided with the distribution.
 *
 * This software is provided "as is" and without any warranty, express or
 * implied. In no event shall the authors be liable for any damages arising from
 * the use of this software.
 */

#include <QWidget>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

#include <libaudcore/hook.h>
#include <libaudcore/index.h>
#include <libaudcore/objects.h>
#include <libaudcore/runtime.h>

#ifndef INFO_BAR_H
#define INFO_BAR_H

class AlbumArtItem : public QGraphicsPixmapItem {
public:
    AlbumArtItem (QGraphicsItem * parent = nullptr);

private:
    const HookReceiver<AlbumArtItem> hook1, hook2;
    void update_cb ();
};

class InfoBar : public QGraphicsView {
public:
    InfoBar (QWidget * parent = nullptr);

    static constexpr int Spacing = 8;
    static constexpr int IconSize = 64;
    static constexpr int Height = IconSize + (2 * Spacing);

    QSize minimumSizeHint () const;
    void resizeEvent (QResizeEvent *);

private:
    QGraphicsScene * m_scene;
    AlbumArtItem * m_art;
};

#endif
