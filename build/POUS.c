void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void TRAFIC_LIGHT_init__(TRAFIC_LIGHT *data__, BOOL retain) {
  TOF_init__(&data__->TOF0,retain);
  TOF_init__(&data__->TOF1,retain);
  TOF_init__(&data__->TOF2,retain);
  __INIT_LOCATED(BOOL,__QX0_0,data__->O_LEDRED,retain)
  __INIT_LOCATED_VALUE(data__->O_LEDRED,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_1,data__->O_LEDORANGE,retain)
  __INIT_LOCATED_VALUE(data__->O_LEDORANGE,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_2,data__->O_LEDGREEN,retain)
  __INIT_LOCATED_VALUE(data__->O_LEDGREEN,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_3,data__->FIRST_CYCLE,retain)
  __INIT_LOCATED_VALUE(data__->FIRST_CYCLE,__BOOL_LITERAL(TRUE))
  F_TRIG_init__(&data__->F_TRIG0,retain);
  F_TRIG_init__(&data__->F_TRIG1,retain);
  F_TRIG_init__(&data__->F_TRIG2,retain);
  __INIT_VAR(data__->_TMP_OR67_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void TRAFIC_LIGHT_body__(TRAFIC_LIGHT *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->F_TRIG0.,CLK,,__GET_LOCATED(data__->O_LEDORANGE,));
  F_TRIG_body__(&data__->F_TRIG0);
  __SET_VAR(data__->,_TMP_OR67_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->F_TRIG0.Q,),
    (BOOL)__GET_LOCATED(data__->FIRST_CYCLE,)));
  __SET_VAR(data__->TOF0.,IN,,__GET_VAR(data__->_TMP_OR67_OUT,));
  __SET_VAR(data__->TOF0.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
  TOF_body__(&data__->TOF0);
  __SET_LOCATED(data__->,O_LEDRED,,__GET_VAR(data__->TOF0.Q,));
  __SET_VAR(data__->F_TRIG1.,CLK,,__GET_LOCATED(data__->O_LEDGREEN,));
  F_TRIG_body__(&data__->F_TRIG1);
  __SET_VAR(data__->TOF1.,IN,,__GET_VAR(data__->F_TRIG1.Q,));
  __SET_VAR(data__->TOF1.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
  TOF_body__(&data__->TOF1);
  __SET_LOCATED(data__->,O_LEDORANGE,,__GET_VAR(data__->TOF1.Q,));
  __SET_VAR(data__->F_TRIG2.,CLK,,__GET_LOCATED(data__->O_LEDRED,));
  F_TRIG_body__(&data__->F_TRIG2);
  __SET_VAR(data__->TOF2.,IN,,__GET_VAR(data__->F_TRIG2.Q,));
  __SET_VAR(data__->TOF2.,PT,,__time_to_timespec(1, 500, 0, 0, 0, 0));
  TOF_body__(&data__->TOF2);
  __SET_LOCATED(data__->,O_LEDGREEN,,__GET_VAR(data__->TOF2.Q,));
  __SET_LOCATED(data__->,FIRST_CYCLE,,__BOOL_LITERAL(FALSE));

  goto __end;

__end:
  return;
} // TRAFIC_LIGHT_body__() 





