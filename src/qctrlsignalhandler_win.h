#ifndef QCTRLSIGNALHANDLER_WIN_H
#define QCTRLSIGNALHANDLER_WIN_H

#include "qctrlsignalhandler_p.h"

#include <qt_windows.h>

class QCtrlSignalHandlerWin : public QCtrlSignalHandlerPrivate
{
public:
	QCtrlSignalHandlerWin(QCtrlSignalHandler *q_ptr);

	bool setSignalHandlerEnabled(bool enabled) override;
	bool registerSignal(int) override;
	bool unregisterSignal(int) override;
	void changeAutoShutMode(bool) override;

private:
	bool handleAutoShut(DWORD signal);

	static BOOL WINAPI HandlerRoutine(_In_ DWORD dwCtrlType);
};

#endif // QCTRLSIGNALHANDLER_WIN_H