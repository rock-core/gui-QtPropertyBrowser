/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
**
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of a Qt Solutions component.
**
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
****************************************************************************/


#ifndef QTEDITORFACTORY_P_H
#define QTEDITORFACTORY_P_H

#include <QtCore/QObject>
#if QT_VERSION < 0x050000
#include <QtGui/QWidget>
#else
#include <QWidget>
#endif

#if QT_VERSION >= 0x040400
QT_BEGIN_NAMESPACE
#endif

class QLabel;
class QLineEdit;
class QToolButton;

class QtCharEdit : public QWidget
{
    Q_OBJECT
public:
    QtCharEdit(QWidget *parent = 0);

    QChar value() const;
    bool eventFilter(QObject *o, QEvent *e);
public Q_SLOTS:
    void setValue(const QChar &value);
Q_SIGNALS:
    void valueChanged(const QChar &value);
protected:
    void focusInEvent(QFocusEvent *e);
    void focusOutEvent(QFocusEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    void paintEvent(QPaintEvent *);
    bool event(QEvent *e);
private slots:
    void slotClearChar();
private:
    void handleKeyEvent(QKeyEvent *e);

    QChar m_value;
    QLineEdit *m_lineEdit;
};

class QtColorEditWidget : public QWidget {
    Q_OBJECT

public:
    QtColorEditWidget(QWidget *parent);

    bool eventFilter(QObject *obj, QEvent *ev);

public Q_SLOTS:
    void setValue(const QColor &value);

Q_SIGNALS:
    void valueChanged(const QColor &value);

protected:
    void paintEvent(QPaintEvent *);

private Q_SLOTS:
    void buttonClicked();

private:
    QColor m_color;
    QLabel *m_pixmapLabel;
    QLabel *m_label;
    QToolButton *m_button;
};

class QtFontEditWidget : public QWidget {
    Q_OBJECT

public:
    QtFontEditWidget(QWidget *parent);

    bool eventFilter(QObject *obj, QEvent *ev);

public Q_SLOTS:
    void setValue(const QFont &value);

Q_SIGNALS:
    void valueChanged(const QFont &value);

protected:
    void paintEvent(QPaintEvent *);

private Q_SLOTS:
    void buttonClicked();

private:
    QFont m_font;
    QLabel *m_pixmapLabel;
    QLabel *m_label;
    QToolButton *m_button;
};

#if QT_VERSION >= 0x040400
QT_END_NAMESPACE
#endif

#endif
