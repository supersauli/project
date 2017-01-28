#ifndef _TIMER_TASK_H__
#define _TIMER_TASK_H__
#include <sys/signalfd.h>
class TimerTask{
	TimerTask()
	{
		tpollfd  = epoll_create(256);
	}
	bool start()
	bool AddTask(int time)
	{
		timerfd = timerfd_create(CLOCK_REALTIME,TFD_CLOEXEC);
		if(timerfd<=0)
		{
			cout<<__FIELD__<<__LINE__<<endl;	
		}

	};
private:

	int timefd;
	int epollfd;


};







#endif // _TIMER_TASK_H__
