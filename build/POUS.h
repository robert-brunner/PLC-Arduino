#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM TRAFIC_LIGHT
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  TOF TOF0;
  TOF TOF1;
  TOF TOF2;
  __DECLARE_LOCATED(BOOL,O_LEDRED)
  __DECLARE_LOCATED(BOOL,O_LEDORANGE)
  __DECLARE_LOCATED(BOOL,O_LEDGREEN)
  __DECLARE_LOCATED(BOOL,FIRST_CYCLE)
  F_TRIG F_TRIG0;
  F_TRIG F_TRIG1;
  F_TRIG F_TRIG2;
  __DECLARE_VAR(BOOL,_TMP_OR67_OUT)

} TRAFIC_LIGHT;

void TRAFIC_LIGHT_init__(TRAFIC_LIGHT *data__, BOOL retain);
// Code part
void TRAFIC_LIGHT_body__(TRAFIC_LIGHT *data__);
#endif //__POUS_H
