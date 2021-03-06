#include "YakApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<YakApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

YakApp::YakApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  YakApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  YakApp::associateSyntax(_syntax, _action_factory);
}

YakApp::~YakApp()
{
}

// External entry point for dynamic application loading
extern "C" void YakApp__registerApps() { YakApp::registerApps(); }
void
YakApp::registerApps()
{
  registerApp(YakApp);
}

// External entry point for dynamic object registration
extern "C" void YakApp__registerObjects(Factory & factory) { YakApp::registerObjects(factory); }
void
YakApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void YakApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { YakApp::associateSyntax(syntax, action_factory); }
void
YakApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
