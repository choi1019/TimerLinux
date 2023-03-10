#include <12PPlatform/PScheduler/PScheduler.h>
#include <01Base/Aspect/Exception.h>
#include <12PPlatform/PEventQueue/PEventQueue.h>

void* CallBackPScheduler(void *pObject) {
	PScheduler *pPScheduler = (PScheduler *)pObject;
	pPScheduler->RunAsAScheduler();
	return nullptr;
}

void PScheduler::Fork() {
	PThread::Fork(CallBackPScheduler, this);
}

void PScheduler::Join() {
	PThread::Join();
}

void PScheduler::RunThread() {

}

PScheduler::PScheduler(
	int uClassId,
	const char* pcClassName)
	: Scheduler(uClassId, pcClassName)
{
	this->SetPEventQueue(new("PEventQueue") PEventQueue());
}
PScheduler::~PScheduler() 
{
}

void PScheduler::InitializeAsAScheduler(int uPriority) {
	Scheduler::InitializeAsAScheduler(uPriority);
}

void PScheduler::FinalizeAsAScheduler() {
	Scheduler::FinalizeAsAScheduler();

}

void PScheduler::Initialize() {
	Scheduler::Initialize();
}
void PScheduler::Finalize() {
	Scheduler::Finalize();
}
