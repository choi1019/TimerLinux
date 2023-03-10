#include <01Base/Object/RootObject.h>
#include <01Base/Aspect/Directory.h>

unsigned RootObject::s_uObjectCount = 0;

RootObject::RootObject(unsigned nClassId, const char* pcClassName)
: m_uObjectId(RootObject::s_uObjectCount++)
, m_nClassId(nClassId)
, m_pcClassName(pcClassName)
, m_szThis(0)
{
    this->m_eState = EState::eCreated;
    Directory::s_dirClasses[m_nClassId] = pcClassName;
}
RootObject::~RootObject() 
{
    this->m_eState = EState::eDeleted;
}
void RootObject::Initialize()
{
    this->m_eState = EState::eInitialized;
}
void RootObject::Finalize()
{
    this->m_eState = EState::eFinalized;
}