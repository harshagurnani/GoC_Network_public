/* Created by Language version: 7.5.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__GolgiKA
#define _nrn_initial _nrn_initial__GolgiKA
#define nrn_cur _nrn_cur__GolgiKA
#define _nrn_current _nrn_current__GolgiKA
#define nrn_jacob _nrn_jacob__GolgiKA
#define nrn_state _nrn_state__GolgiKA
#define _net_receive _net_receive__GolgiKA 
#define rates rates__GolgiKA 
#define states states__GolgiKA 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define gmax _p[0]
#define conductance _p[1]
#define a_instances _p[2]
#define a_forwardRate_rate _p[3]
#define a_forwardRate_midpoint _p[4]
#define a_forwardRate_scale _p[5]
#define a_reverseRate_rate _p[6]
#define a_reverseRate_midpoint _p[7]
#define a_reverseRate_scale _p[8]
#define a_steadyState_rate _p[9]
#define a_steadyState_midpoint _p[10]
#define a_steadyState_scale _p[11]
#define a_q10Settings_q10Factor _p[12]
#define a_q10Settings_experimentalTemp _p[13]
#define a_q10Settings_TENDEGREES _p[14]
#define b_instances _p[15]
#define b_forwardRate_rate _p[16]
#define b_forwardRate_midpoint _p[17]
#define b_forwardRate_scale _p[18]
#define b_reverseRate_rate _p[19]
#define b_reverseRate_midpoint _p[20]
#define b_reverseRate_scale _p[21]
#define b_steadyState_rate _p[22]
#define b_steadyState_midpoint _p[23]
#define b_steadyState_scale _p[24]
#define b_q10Settings_q10Factor _p[25]
#define b_q10Settings_experimentalTemp _p[26]
#define b_q10Settings_TENDEGREES _p[27]
#define gion _p[28]
#define a_forwardRate_r _p[29]
#define a_reverseRate_r _p[30]
#define a_steadyState_x _p[31]
#define a_q10Settings_q10 _p[32]
#define a_rateScale _p[33]
#define a_alpha _p[34]
#define a_beta _p[35]
#define a_fcond _p[36]
#define a_inf _p[37]
#define a_tau _p[38]
#define b_forwardRate_r _p[39]
#define b_reverseRate_r _p[40]
#define b_steadyState_x _p[41]
#define b_q10Settings_q10 _p[42]
#define b_rateScale _p[43]
#define b_alpha _p[44]
#define b_beta _p[45]
#define b_fcond _p[46]
#define b_inf _p[47]
#define b_tau _p[48]
#define conductanceScale _p[49]
#define fopen0 _p[50]
#define fopen _p[51]
#define g _p[52]
#define a_q _p[53]
#define b_q _p[54]
#define temperature _p[55]
#define ek _p[56]
#define ik _p[57]
#define rate_a_q _p[58]
#define rate_b_q _p[59]
#define Da_q _p[60]
#define Db_q _p[61]
#define v _p[62]
#define _g _p[63]
#define _ion_ik	*_ppvar[0]._pval
#define _ion_dikdv	*_ppvar[1]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_rates(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_GolgiKA", _hoc_setdata,
 "rates_GolgiKA", _hoc_rates,
 0, 0
};
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gmax_GolgiKA", "S/cm2",
 "conductance_GolgiKA", "uS",
 "a_forwardRate_rate_GolgiKA", "kHz",
 "a_forwardRate_midpoint_GolgiKA", "mV",
 "a_forwardRate_scale_GolgiKA", "mV",
 "a_reverseRate_rate_GolgiKA", "kHz",
 "a_reverseRate_midpoint_GolgiKA", "mV",
 "a_reverseRate_scale_GolgiKA", "mV",
 "a_steadyState_midpoint_GolgiKA", "mV",
 "a_steadyState_scale_GolgiKA", "mV",
 "a_q10Settings_experimentalTemp_GolgiKA", "K",
 "a_q10Settings_TENDEGREES_GolgiKA", "K",
 "b_forwardRate_rate_GolgiKA", "kHz",
 "b_forwardRate_midpoint_GolgiKA", "mV",
 "b_forwardRate_scale_GolgiKA", "mV",
 "b_reverseRate_rate_GolgiKA", "kHz",
 "b_reverseRate_midpoint_GolgiKA", "mV",
 "b_reverseRate_scale_GolgiKA", "mV",
 "b_steadyState_midpoint_GolgiKA", "mV",
 "b_steadyState_scale_GolgiKA", "mV",
 "b_q10Settings_experimentalTemp_GolgiKA", "K",
 "b_q10Settings_TENDEGREES_GolgiKA", "K",
 "gion_GolgiKA", "S/cm2",
 "a_forwardRate_r_GolgiKA", "kHz",
 "a_reverseRate_r_GolgiKA", "kHz",
 "a_alpha_GolgiKA", "kHz",
 "a_beta_GolgiKA", "kHz",
 "a_tau_GolgiKA", "ms",
 "b_forwardRate_r_GolgiKA", "kHz",
 "b_reverseRate_r_GolgiKA", "kHz",
 "b_alpha_GolgiKA", "kHz",
 "b_beta_GolgiKA", "kHz",
 "b_tau_GolgiKA", "ms",
 "g_GolgiKA", "uS",
 0,0
};
 static double a_q0 = 0;
 static double b_q0 = 0;
 static double delta_t = 0.01;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[2]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.5.0",
"GolgiKA",
 "gmax_GolgiKA",
 "conductance_GolgiKA",
 "a_instances_GolgiKA",
 "a_forwardRate_rate_GolgiKA",
 "a_forwardRate_midpoint_GolgiKA",
 "a_forwardRate_scale_GolgiKA",
 "a_reverseRate_rate_GolgiKA",
 "a_reverseRate_midpoint_GolgiKA",
 "a_reverseRate_scale_GolgiKA",
 "a_steadyState_rate_GolgiKA",
 "a_steadyState_midpoint_GolgiKA",
 "a_steadyState_scale_GolgiKA",
 "a_q10Settings_q10Factor_GolgiKA",
 "a_q10Settings_experimentalTemp_GolgiKA",
 "a_q10Settings_TENDEGREES_GolgiKA",
 "b_instances_GolgiKA",
 "b_forwardRate_rate_GolgiKA",
 "b_forwardRate_midpoint_GolgiKA",
 "b_forwardRate_scale_GolgiKA",
 "b_reverseRate_rate_GolgiKA",
 "b_reverseRate_midpoint_GolgiKA",
 "b_reverseRate_scale_GolgiKA",
 "b_steadyState_rate_GolgiKA",
 "b_steadyState_midpoint_GolgiKA",
 "b_steadyState_scale_GolgiKA",
 "b_q10Settings_q10Factor_GolgiKA",
 "b_q10Settings_experimentalTemp_GolgiKA",
 "b_q10Settings_TENDEGREES_GolgiKA",
 0,
 "gion_GolgiKA",
 "a_forwardRate_r_GolgiKA",
 "a_reverseRate_r_GolgiKA",
 "a_steadyState_x_GolgiKA",
 "a_q10Settings_q10_GolgiKA",
 "a_rateScale_GolgiKA",
 "a_alpha_GolgiKA",
 "a_beta_GolgiKA",
 "a_fcond_GolgiKA",
 "a_inf_GolgiKA",
 "a_tau_GolgiKA",
 "b_forwardRate_r_GolgiKA",
 "b_reverseRate_r_GolgiKA",
 "b_steadyState_x_GolgiKA",
 "b_q10Settings_q10_GolgiKA",
 "b_rateScale_GolgiKA",
 "b_alpha_GolgiKA",
 "b_beta_GolgiKA",
 "b_fcond_GolgiKA",
 "b_inf_GolgiKA",
 "b_tau_GolgiKA",
 "conductanceScale_GolgiKA",
 "fopen0_GolgiKA",
 "fopen_GolgiKA",
 "g_GolgiKA",
 0,
 "a_q_GolgiKA",
 "b_q_GolgiKA",
 0,
 0};
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 64, _prop);
 	/*initialize range parameters*/
 	gmax = 0;
 	conductance = 1e-005;
 	a_instances = 3;
 	a_forwardRate_rate = 0.8147;
 	a_forwardRate_midpoint = -9.17203;
 	a_forwardRate_scale = 23.3271;
 	a_reverseRate_rate = 0.1655;
 	a_reverseRate_midpoint = -18.2791;
 	a_reverseRate_scale = 19.4718;
 	a_steadyState_rate = 1;
 	a_steadyState_midpoint = -38;
 	a_steadyState_scale = 17;
 	a_q10Settings_q10Factor = 3;
 	a_q10Settings_experimentalTemp = 298.65;
 	a_q10Settings_TENDEGREES = 10;
 	b_instances = 1;
 	b_forwardRate_rate = 0.0368;
 	b_forwardRate_midpoint = -111.332;
 	b_forwardRate_scale = -12.8433;
 	b_reverseRate_rate = 0.0345;
 	b_reverseRate_midpoint = -49.9537;
 	b_reverseRate_scale = 8.90123;
 	b_steadyState_rate = 1;
 	b_steadyState_midpoint = -78.8;
 	b_steadyState_scale = -8.4;
 	b_q10Settings_q10Factor = 3;
 	b_q10Settings_experimentalTemp = 298.65;
 	b_q10Settings_TENDEGREES = 10;
 	_prop->param = _p;
 	_prop->param_size = 64;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[1]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _GolgiKA_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("k", 1.0);
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_prop_size(_mechtype, 64, 3);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 GolgiKA D:/Work/Comp Models/GoC_Network_public/GolgiKA.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Mod file for component: Component(id=GolgiKA type=ionChannelHH)";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates(_threadargsproto_);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[2], _dlist1[2];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   rates ( _threadargs_ ) ;
   Da_q = rate_a_q ;
   Db_q = rate_b_q ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rates ( _threadargs_ ) ;
 Da_q = Da_q  / (1. - dt*( 0.0 )) ;
 Db_q = Db_q  / (1. - dt*( 0.0 )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   rates ( _threadargs_ ) ;
    a_q = a_q - dt*(- ( rate_a_q ) ) ;
    b_q = b_q - dt*(- ( rate_b_q ) ) ;
   }
  return 0;
}
 
static int  rates ( _threadargsproto_ ) {
   a_forwardRate_r = a_forwardRate_rate / ( 1.0 + exp ( 0.0 - ( v - a_forwardRate_midpoint ) / a_forwardRate_scale ) ) ;
   a_reverseRate_r = a_reverseRate_rate * 1.0 / exp ( ( v - a_reverseRate_midpoint ) / a_reverseRate_scale ) ;
   a_steadyState_x = a_steadyState_rate / ( 1.0 + exp ( 0.0 - ( v - a_steadyState_midpoint ) / a_steadyState_scale ) ) ;
   a_q10Settings_q10 = pow( a_q10Settings_q10Factor , ( ( temperature - a_q10Settings_experimentalTemp ) / a_q10Settings_TENDEGREES ) ) ;
   a_rateScale = a_q10Settings_q10 ;
   a_alpha = a_forwardRate_r ;
   a_beta = a_reverseRate_r ;
   a_fcond = pow( a_q , a_instances ) ;
   a_inf = a_steadyState_x ;
   a_tau = 1.0 / ( ( a_alpha + a_beta ) * a_rateScale ) ;
   b_forwardRate_r = b_forwardRate_rate / ( 1.0 + exp ( 0.0 - ( v - b_forwardRate_midpoint ) / b_forwardRate_scale ) ) ;
   b_reverseRate_r = b_reverseRate_rate / ( 1.0 + exp ( 0.0 - ( v - b_reverseRate_midpoint ) / b_reverseRate_scale ) ) ;
   b_steadyState_x = b_steadyState_rate / ( 1.0 + exp ( 0.0 - ( v - b_steadyState_midpoint ) / b_steadyState_scale ) ) ;
   b_q10Settings_q10 = pow( b_q10Settings_q10Factor , ( ( temperature - b_q10Settings_experimentalTemp ) / b_q10Settings_TENDEGREES ) ) ;
   b_rateScale = b_q10Settings_q10 ;
   b_alpha = b_forwardRate_r ;
   b_beta = b_reverseRate_r ;
   b_fcond = pow( b_q , b_instances ) ;
   b_inf = b_steadyState_x ;
   b_tau = 1.0 / ( ( b_alpha + b_beta ) * b_rateScale ) ;
   rate_a_q = ( a_inf - a_q ) / a_tau ;
   rate_b_q = ( b_inf - b_q ) / b_tau ;
    return 0; }
 
static void _hoc_rates(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 rates ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 2;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 2; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_k_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 1, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  a_q = a_q0;
  b_q = b_q0;
 {
   ek = - 84.69 ;
   temperature = celsius + 273.15 ;
   rates ( _threadargs_ ) ;
   rates ( _threadargs_ ) ;
   a_q = a_inf ;
   b_q = b_inf ;
   }
 
}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   conductanceScale = 1.0 ;
   fopen0 = a_fcond * b_fcond ;
   fopen = conductanceScale * fopen0 ;
   g = conductance * fopen ;
   gion = gmax * fopen ;
   ik = gion * ( v - ek ) ;
   }
 _current += ik;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dik;
  _dik = ik;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ik += ik ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}
 
}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}
 
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
 {   states(_p, _ppvar, _thread, _nt);
  } }}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(a_q) - _p;  _dlist1[0] = &(Da_q) - _p;
 _slist1[1] = &(b_q) - _p;  _dlist1[1] = &(Db_q) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
