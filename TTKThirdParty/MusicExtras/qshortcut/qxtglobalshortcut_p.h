/****************************************************************************
 **
 ** Copyright (C) Qxt Foundation. Some rights reserved.
 **
 ** This file is part of the QxtGui module of the Qxt library.
 **
 ** This library is free software; you can redistribute it and/or modify it
 ** under the terms of the Common Public License, version 1.0, as published
 ** by IBM, and/or under the terms of the GNU Lesser General Public License,
 ** version 2.1, as published by the Free Software Foundation.
 **
 ** This file is provided "AS IS", without WARRANTIES OR CONDITIONS OF ANY
 ** KIND, EITHER EXPRESS OR IMPLIED INCLUDING, WITHOUT LIMITATION, ANY
 ** WARRANTIES OR CONDITIONS OF TITLE, NON-INFRINGEMENT, MERCHANTABILITY OR
 ** FITNESS FOR A PARTICULAR PURPOSE.
 **
 ** You should have received a copy of the CPL and the LGPL along with this
 ** file. See the LICENSE file and the cpl1.0.txt/lgpl-2.1.txt files
 ** included with the source distribution for more information.
 ** If you did not receive a copy of the licenses, contact the Qxt Foundation.
 **
 ** <http://libqxt.org>  <foundation@libqxt.org>
 **
 ****************************************************************************/
#ifndef QXTGLOBALSHORTCUT_P_H
#define QXTGLOBALSHORTCUT_P_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (c) 2014 - 2016 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "qxtglobalshortcut.h"
#include <QAbstractEventDispatcher>
#include <QKeySequence>
#include <QHash>
#if(QT_VERSION>=0x050000)
#include <QAbstractNativeEventFilter>
#endif

/*! @brief The namespace of the qxt global shortcut private.
 * @author libqxt <foundation@libqxt.org>
 */
class MUSIC_EXTRAS_EXPORT QxtGlobalShortcutPrivate : public QxtPrivate<QxtGlobalShortcut>
#if(QT_VERSION>=0x050000)
        , public QAbstractNativeEventFilter
#endif
{
public:
    QXT_DECLARE_PUBLIC(QxtGlobalShortcut)
    QxtGlobalShortcutPrivate();
    /*!
     * Object contsructor.
     */
    ~QxtGlobalShortcutPrivate();

    bool enabled;
    Qt::Key key;
    Qt::KeyboardModifiers mods;

    bool setShortcut(const QKeySequence& shortcut);
    /*!
     * Set current shortcut.
     */
    bool unsetShortcut();
    /*!
     * Unset current shortcut.
     */

    static bool error;
    static int ref;
#if(QT_VERSION<0x050000)
    static QAbstractEventDispatcher::EventFilter prevEventFilter;
    static bool eventFilter(void* message);
#else
    bool nativeEventFilter(const QByteArray &eventType, void *message, long *result);
#endif
    /*!
     * Override the widget event.
     */

private:
    static quint32 nativeKeycode(Qt::Key keycode);
    /*!
     * Get native key code.
     */
    static quint32 nativeModifiers(Qt::KeyboardModifiers modifiers);
    /*!
     * Get native modifiers.
     */

    static bool registerShortcut(quint32 nativeKey, quint32 nativeMods);
    /*!
     * Register shortcut.
     */
    static bool unregisterShortcut(quint32 nativeKey, quint32 nativeMods);
    /*!
     * Unregister shortcut.
     */
    static void activateShortcut(quint32 nativeKey, quint32 nativeMods);
    /*!
     * Activate shortcut.
     */

    static QHash<QPair<quint32, quint32>, QxtGlobalShortcut*> shortcuts;
};

#endif // QXTGLOBALSHORTCUT_P_H
