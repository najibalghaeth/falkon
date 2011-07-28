/* ============================================================
* QupZilla - WebKit based browser
* Copyright (C) 2010-2011  nowrep
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* ============================================================ */
#include "autosaver.h"
#include "mainapplication.h"

AutoSaver::AutoSaver(QObject* parent) :
     QObject(parent)
{
    m_timer.start(1000*5, this);
}

void AutoSaver::timerEvent(QTimerEvent* event)
{
    if (event->timerId() == m_timer.timerId() && mApp->isStateChanged())
        emit saveApp();
    else
        QObject::timerEvent(event);
}
