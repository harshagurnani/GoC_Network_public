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
 
#define nrn_init _nrn_init__GolgiCaHVA
#define _nrn_initial _nrn_initial__GolgiCaHVA
#define nrn_cur _nrn_cur__GolgiCaHVA
#define _nrn_current _nrn_current__GolgiCaHVA
#define nrn_jacob _nrn_jacob__GolgiCaHVA
#define nrn_state _nrn_state__GolgiCaHVA
#define _net_receive _net_receive__GolgiCaHVA 
#define rates rates__GolgiCaHVA 
#define states states__GolgiCaHVA 
 
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
#define s_instances _p[2]
#define s_forwardRate_rate _p[3]
#define s_forwardRate_midpoint _p[4]
#define s_forwardRate_scale _p[5]
#define s_reverseRate_rate _p[6]
#define s_reverseRate_midpoint _p[7]
#define s_reverseRate_scale _p[8]
#define s_timeCourse_TIME_SCALE _p[9]
#define s_q10Settings_q10Factor _p[10]
#define s_q10Settings_experimentalTemp _p[11]
#define s_q10Settings_TENDEGREES _p[12]
#define u_instances _p[13]
#define u_forwardRate_rate _p[14]
#define u_forwardRate_midpoint _p[15]
#define u_forwardRate_scale _p[16]
#define u_reverseRate_rate _p[17]
#define u_reverseRate_midpoint _p[18]
#define u_reverseRate_scale _p[19]
#define u_q10Settings_q10Factor _p[20]
#define u_q10Settings_experimentalTemp _p[21]
#define u_q10Settings_TENDEGREES _p[22]
#define gion _p[23]
#define s_forwardRate_r _p[24]
#define s_reverseRate_r _p[25]
#define s_timeCourse_t _p[26]
#define s_q10Settings_q10 _p[27]
#define s_rateScale _p[28]
#define s_alpha _p[29]
#define s_beta _p[30]
#define s_fcond _p[31]
#define s_inf _p[32]
#define s_tauUnscaled _p[33]
#define s_tau _p[34]
#define u_forwardRate_r _p[35]
#define u_reverseRate_r _p[36]
#define u_q10Settings_q10 _p[37]
#define u_rateScale _p[38]
#define u_alpha _p[39]
#define u_beta _p[40]
#define u_fcond _p[41]
#define u_inf _p[42]
#define u_tau _p[43]
#define conductanceScale _p[44]
#define fopen0 _p[45]
#define fopen _p[46]
#define g _p[47]
#define s_q _p[48]
#define u_q _p[49]
#define temperature _p[50]
#define eca _p[51]
#define ica _p[52]
#define rate_s_q _p[53]
#define rate_u_q _p[54]
#define Ds_q _p[55]
#define Du_q _p[56]
#define v _p[57]
#define _g _p[58]
#define _ion_eca	*_ppvar[0]._pval
#define _ion_ica	*_ppvar[1]._pval
#define _ion_dicadv	*_ppvar[2]._pval
 
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
 "setdata_GolgiCaHVA", _hoc_setdata,
 "rates_GolgiCaHVA", _hoc_rates,
 0, 0
};
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gmax_GolgiCaHVA", "S/cm2",
 "conductance_GolgiCaHVA", "uS",
 "s_forwardRate_rate_GolgiCaHVA", "kHz",
 "s_forwardRate_midpoint_GolgiCaHVA", "mV",
 "s_forwardRate_scale_GolgiCaHVA", "mV",
 "s_reverseRate_rate_GolgiCaHVA", "kHz",
 "s_reverseRate_midpoint_GolgiCaHVA", "mV",
 "s_reverseRate_scale_GolgiCaHVA", "mV",
 "s_timeCourse_TIME_SCALE_GolgiCaHVA", "ms",
 "s_q10Settings_experimentalTemp_GolgiCaHVA", "K",
 "s_q10Settings_TENDEGREES_GolgiCaHVA", "K",
 "u_forwardRate_rate_GolgiCaHVA", "kHz",
 "u_forwardRate_midpoint_GolgiCaHVA", "mV",
 "u_forwardRate_scale_GolgiCaHVA", "mV",
 "u_reverseRate_rate_GolgiCaHVA", "kHz",
 "u_reverseRate_midpoint_GolgiCaHVA", "mV",
 "u_reverseRate_scale_GolgiCaHVA", "mV",
 "u_q10Settings_experimentalTemp_GolgiCaHVA", "K",
 "u_q10Settings_TENDEGREES_GolgiCaHVA", "K",
 "gion_GolgiCaHVA", "S/cm2",
 "s_forwardRate_r_GolgiCaHVA", "kHz",
 "s_reverseRate_r_GolgiCaHVA", "kHz",
 "s_timeCourse_t_GolgiCaHVA", "ms",
 "s_alpha_GolgiCaHVA", "kHz",
 "s_beta_GolgiCaHVA", "kHz",
 "s_tauUnscaled_GolgiCaHVA", "ms",
 "s_tau_GolgiCaHVA", "ms",
 "u_forwardRate_r_GolgiCaHVA", "kHz",
 "u_reverseRate_r_GolgiCaHVA", "kHz",
 "u_alpha_GolgiCaHVA", "kHz",
 "u_beta_GolgiCaHVA", "kHz",
 "u_tau_GolgiCaHVA", "ms",
 "g_GolgiCaHVA", "uS",
 0,0
};
 static double delta_t = 0.01;
 static double s_q0 = 0;
 static double u_q0 = 0;
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
 
#define _cvode_ieq _ppvar[3]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.5.0",
"GolgiCaHVA",
 "gmax_GolgiCaHVA",
 "conductance_GolgiCaHVA",
 "s_instances_GolgiCaHVA",
 "s_forwardRate_rate_GolgiCaHVA",
 "s_forwardRate_midpoint_GolgiCaHVA",
 "s_forwardRate_scale_GolgiCaHVA",
 "s_reverseRate_rate_GolgiCaHVA",
 "s_reverseRate_midpoint_GolgiCaHVA",
 "s_reverseRate_scale_GolgiCaHVA",
 "s_timeCourse_TIME_SCALE_GolgiCaHVA",
 "s_q10Settings_q10Factor_GolgiCaHVA",
 "s_q10Settings_experimentalTemp_GolgiCaHVA",
 "s_q10Settings_TENDEGREES_GolgiCaHVA",
 "u_instances_GolgiCaHVA",
 "u_forwardRate_rate_GolgiCaHVA",
 "u_forwardRate_midpoint_GolgiCaHVA",
 "u_forwardRate_scale_GolgiCaHVA",
 "u_reverseRate_rate_GolgiCaHVA",
 "u_reverseRate_midpoint_GolgiCaHVA",
 "u_reverseRate_scale_GolgiCaHVA",
 "u_q10Settings_q10Factor_GolgiCaHVA",
 "u_q10Settings_experimentalTemp_GolgiCaHVA",
 "u_q10Settings_TENDEGREES_GolgiCaHVA",
 0,
 "gion_GolgiCaHVA",
 "s_forwardRate_r_GolgiCaHVA",
 "s_reverseRate_r_GolgiCaHVA",
 "s_timeCourse_t_GolgiCaHVA",
 "s_q10Settings_q10_GolgiCaHVA",
 "s_rateScale_GolgiCaHVA",
 "s_alpha_GolgiCaHVA",
 "s_beta_GolgiCaHVA",
 "s_fcond_GolgiCaHVA",
 "s_inf_GolgiCaHVA",
 "s_tauUnscaled_GolgiCaHVA",
 "s_tau_GolgiCaHVA",
 "u_forwardRate_r_GolgiCaHVA",
 "u_reverseRate_r_GolgiCaHVA",
 "u_q10Settings_q10_GolgiCaHVA",
 "u_rateScale_GolgiCaHVA",
 "u_alpha_GolgiCaHVA",
 "u_beta_GolgiCaHVA",
 "u_fcond_GolgiCaHVA",
 "u_inf_GolgiCaHVA",
 "u_tau_GolgiCaHVA",
 "conductanceScale_GolgiCaHVA",
 "fopen0_GolgiCaHVA",
 "fopen_GolgiCaHVA",
 "g_GolgiCaHVA",
 0,
 "s_q_GolgiCaHVA",
 "u_q_GolgiCaHVA",
 0,
 0};
 static Symbol* _ca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 59, _prop);
 	/*initialize range parameters*/
 	gmax = 0;
 	conductance = 1e-005;
 	s_instances = 2;
 	s_forwardRate_rate = 0.04944;
 	s_forwardRate_midpoint = -29.06;
 	s_forwardRate_scale = 15.873;
 	s_reverseRate_rate = 0.08298;
 	s_reverseRate_midpoint = -18.66;
 	s_reverseRate_scale = -25.641;
 	s_timeCourse_TIME_SCALE = 1;
 	s_q10Settings_q10Factor = 3;
 	s_q10Settings_experimentalTemp = 293.15;
 	s_q10Settings_TENDEGREES = 10;
 	u_instances = 1;
 	u_forwardRate_rate = 0.0013;
 	u_forwardRate_midpoint = -48;
 	u_forwardRate_scale = -18.1832;
 	u_reverseRate_rate = 0.0013;
 	u_reverseRate_midpoint = -48;
 	u_reverseRate_scale = 83.33;
 	u_q10Settings_q10Factor = 3;
 	u_q10Settings_experimentalTemp = 293.15;
 	u_q10Settings_TENDEGREES = 10;
 	_prop->param = _p;
 	_prop->param_size = 59;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_ca_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* eca */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dicadv */
 
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

 void _GolgiCaHVA_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("ca", 2.0);
 	_ca_sym = hoc_lookup("ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_prop_size(_mechtype, 59, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 GolgiCaHVA D:/Work/Comp Models/GoC_Network_public/GolgiCaHVA.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Mod file for component: Component(id=GolgiCaHVA type=ionChannelHH)";

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
   Ds_q = rate_s_q ;
   Du_q = rate_u_q ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rates ( _threadargs_ ) ;
 Ds_q = Ds_q  / (1. - dt*( 0.0 )) ;
 Du_q = Du_q  / (1. - dt*( 0.0 )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   rates ( _threadargs_ ) ;
    s_q = s_q - dt*(- ( rate_s_q ) ) ;
    u_q = u_q - dt*(- ( rate_u_q ) ) ;
   }
  return 0;
}
 
static int  rates ( _threadargsproto_ ) {
   s_forwardRate_r = s_forwardRate_rate * exp ( ( v - s_forwardRate_midpoint ) / s_forwardRate_scale ) ;
   s_reverseRate_r = s_reverseRate_rate * exp ( ( v - s_reverseRate_midpoint ) / s_reverseRate_scale ) ;
   if ( 1.0 / ( s_alpha + s_beta ) > ( 1000.0 ) ) {
     s_timeCourse_t = 1000.0 * s_timeCourse_TIME_SCALE ;
     }
   else if ( 1.0 / ( s_alpha + s_beta ) < ( 0.1 ) ) {
     s_timeCourse_t = 0.1 * s_timeCourse_TIME_SCALE ;
     }
   else {
     s_timeCourse_t = 1.0 / ( s_alpha + s_beta ) ;
     }
   s_q10Settings_q10 = pow( s_q10Settings_q10Factor , ( ( temperature - s_q10Settings_experimentalTemp ) / s_q10Settings_TENDEGREES ) ) ;
   s_rateScale = s_q10Settings_q10 ;
   s_alpha = s_forwardRate_r ;
   s_beta = s_reverseRate_r ;
   s_fcond = pow( s_q , s_instances ) ;
   s_inf = s_alpha / ( s_alpha + s_beta ) ;
   s_tauUnscaled = s_timeCourse_t ;
   s_tau = s_tauUnscaled / s_rateScale ;
   u_forwardRate_r = u_forwardRate_rate * exp ( ( v - u_forwardRate_midpoint ) / u_forwardRate_scale ) ;
   u_reverseRate_r = u_reverseRate_rate * exp ( ( v - u_reverseRate_midpoint ) / u_reverseRate_scale ) ;
   u_q10Settings_q10 = pow( u_q10Settings_q10Factor , ( ( temperature - u_q10Settings_experimentalTemp ) / u_q10Settings_TENDEGREES ) ) ;
   u_rateScale = u_q10Settings_q10 ;
   u_alpha = u_forwardRate_r ;
   u_beta = u_reverseRate_r ;
   u_fcond = pow( u_q , u_instances ) ;
   u_inf = u_alpha / ( u_alpha + u_beta ) ;
   u_tau = 1.0 / ( ( u_alpha + u_beta ) * u_rateScale ) ;
   rate_s_q = ( s_inf - s_q ) / s_tau ;
   rate_u_q = ( u_inf - u_q ) / u_tau ;
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
  eca = _ion_eca;
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
  eca = _ion_eca;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 2, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  s_q = s_q0;
  u_q = u_q0;
 {
   temperature = celsius + 273.15 ;
   rates ( _threadargs_ ) ;
   rates ( _threadargs_ ) ;
   s_q = s_inf ;
   u_q = u_inf ;
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
  eca = _ion_eca;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   conductanceScale = 1.0 ;
   fopen0 = s_fcond * u_fcond ;
   fopen = conductanceScale * fopen0 ;
   g = conductance * fopen ;
   gion = gmax * fopen ;
   ica = gion * ( v - eca ) ;
   }
 _current += ica;

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
  eca = _ion_eca;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dica;
  _dica = ica;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dicadv += (_dica - ica)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ica += ica ;
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
  eca = _ion_eca;
 {   states(_p, _ppvar, _thread, _nt);
  } }}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(s_q) - _p;  _dlist1[0] = &(Ds_q) - _p;
 _slist1[1] = &(u_q) - _p;  _dlist1[1] = &(Du_q) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
