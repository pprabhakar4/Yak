#ifndef YAKAPP_H
#define YAKAPP_H

#include "MooseApp.h"

class YakApp;

template<>
InputParameters validParams<YakApp>();

class YakApp : public MooseApp
{
public:
  YakApp(InputParameters parameters);
  virtual ~YakApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* YAKAPP_H */
