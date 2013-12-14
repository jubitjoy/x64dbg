#ifndef BRIDGE_H
#define BRIDGE_H

#include <QObject>
#include <QDebug>
#include <QtGui>
#include "NewTypes.h"

#include "main.h"

#include "Exports.h"
#include "Imports.h"


class Bridge : public QObject
{
    Q_OBJECT
public:
    explicit Bridge(QObject *parent = 0);

    static Bridge* getBridge();
    static void initBridge();

    // Exports Binding
    void emitDisassembleAtSignal(int_t va, int_t eip);
    void emitUpdateDisassembly();
    void emitDbgStateChanged(DBGSTATE state);
    void emitAddMsgToLog(QString msg);
    void emitClearLog();
    void emitUpdateRegisters();
    void emitUpdateBreakpoints();
    void emitUpdateWindowTitle(QString filename);
    void emitUpdateCPUTitle(QString modname);
    
signals:
    void disassembleAt(int_t va, int_t eip);
    void repaintGui();
    void dbgStateChanged(DBGSTATE state);
    void addMsgToLog(QString msg);
    void clearLog();
    void updateRegisters();
    void updateBreakpoints();
    void updateWindowTitle(QString filename);
    void updateCPUTitle(QString modname);
    
public slots:

private:

public:

};

#endif // BRIDGE_H
