#ifndef LAUNCH_BACKEND_CPP
#define LAUNCH_BACKEND_CPP

#include "BackendOption.h"
class Frontend;

#define EXTERN_F(little_name) \
extern void launch_##little_name##backend(Frontend*, BackendOption&);

#define LAUNCHBACKEND(big_name,little_name) \
        else if (backend == #big_name || backend == #little_name ) \
                launch_##little_name##backend(fe, option) ;

EXTERN_F(tweto)
EXTERN_F(42)
EXTERN_F(promela)
EXTERN_F(simple)
EXTERN_F(run)


bool launch_backends(Frontend* fe, std::string backend, BackendOption& option)
{
if (backend == "-") ;
LAUNCHBACKEND(Tweto,tweto)
LAUNCHBACKEND(42,42)
LAUNCHBACKEND(Promela,promela)
LAUNCHBACKEND(Simple,simple)
LAUNCHBACKEND(Run,run) 
else return false;
return true;
}

#endif
