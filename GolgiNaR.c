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
 
#define nrn_init _nrn_init__GolgiNaR
#define _nrn_initial _nrn_initial__GolgiNaR
#define nrn_cur _nrn_cur__GolgiNaR
#define _nrn_current _nrn_current__GolgiNaR
#define nrn_jacob _nrn_jacob__GolgiNaR
#define nrn_state _nrn_state__GolgiNaR
#define _net_receive _net_receive__GolgiNaR 
#define rates rates__GolgiNaR 
#define states states__GolgiNaR 
 
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
#define s_forwardRate_shift _p[6]
#define s_reverseRate_rate _p[7]
#define s_reverseRate_midpoint _p[8]
#define s_reverseRate_scale _p[9]
#define s_reverseRate_shift _p[10]
#define s_timeCourse_TIME_SCALE _p[11]
#define s_q10Settings_q10Factor _p[12]
#define s_q10Settings_experimentalTemp _p[13]
#define s_q10Settings_TENDEGREES _p[14]
#define f_instances _p[15]
#define f_forwardRate_rate _p[16]
#define f_forwardRate_midpoint _p[17]
#define f_forwardRate_scale _p[18]
#define f_reverseRate_rate _p[19]
#define f_reverseRate_midpoint _p[20]
#define f_reverseRate_scale _p[21]
#define f_timeCourse_TIME_SCALE _p[22]
#define f_q10Settings_q10Factor _p[23]
#define f_q10Settings_experimentalTemp _p[24]
#define f_q10Settings_TENDEGREES _p[25]
#define gion _p[26]
#define s_forwardRate_r _p[27]
#define s_reverseRate_r _p[28]
#define s_timeCourse_ALPHA _p[29]
#define s_timeCourse_BETA _p[30]
#define s_timeCourse_t _p[31]
#define s_q10Settings_q10 _p[32]
#define s_rateScale _p[33]
#define s_alpha _p[34]
#define s_beta _p[35]
#define s_fcond _p[36]
#define s_inf _p[37]
#define s_tauUnscaled _p[38]
#define s_tau _p[39]
#define f_forwardRate_r _p[40]
#define f_reverseRate_r _p[41]
#define f_timeCourse_ALPHA _p[42]
#define f_timeCourse_BETA _p[43]
#define f_timeCourse_t _p[44]
#define f_q10Settings_q10 _p[45]
#define f_rateScale _p[46]
#define f_alpha _p[47]
#define f_beta _p[48]
#define f_fcond _p[49]
#define f_inf _p[50]
#define f_tauUnscaled _p[51]
#define f_tau _p[52]
#define conductanceScale _p[53]
#define fopen0 _p[54]
#define fopen _p[55]
#define g _p[56]
#define s_q _p[57]
#define f_q _p[58]
#define temperature _p[59]
#define ena _p[60]
#define ina _p[61]
#define rate_s_q _p[62]
#define rate_f_q _p[63]
#define Ds_q _p[64]
#define Df_q _p[65]
#define v _p[66]
#define _g _p[67]
#define _ion_ina	*_ppvar[0]._pval
#define _ion_dinadv	*_ppvar[1]._pval
 
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
 "setdata_GolgiNaR", _hoc_setdata,
 "rates_GolgiNaR", _hoc_rates,
 0, 0
};
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gmax_GolgiNaR", "S/cm2",
 "conductance_GolgiNaR", "uS",
 "s_forwardRate_rate_GolgiNaR", "kHz",
 "s_forwardRate_midpoint_GolgiNaR", "mV",
 "s_forwardRate_scale_GolgiNaR", "mV",
 "s_forwardRate_shift_GolgiNaR", "kHz",
 "s_reverseRate_rate_GolgiNaR", "kHz",
 "s_reverseRate_midpoint_GolgiNaR", "mV",
 "s_reverseRate_scale_GolgiNaR", "mV",
 "s_reverseRate_shift_GolgiNaR", "kHz",
 "s_timeCourse_TIME_SCALE_GolgiNaR", "ms",
 "s_q10Settings_experimentalTemp_GolgiNaR", "K",
 "s_q10Settings_TENDEGREES_GolgiNaR", "K",
 "f_forwardRate_rate_GolgiNaR", "kHz",
 "f_forwardRate_midpoint_GolgiNaR", "mV",
 "f_forwardRate_scale_GolgiNaR", "mV",
 "f_reverseRate_rate_GolgiNaR", "kHz",
 "f_reverseRate_midpoint_GolgiNaR", "mV",
 "f_reverseRate_scale_GolgiNaR", "mV",
 "f_timeCourse_TIME_SCALE_GolgiNaR", "ms",
 "f_q10Settings_experimentalTemp_GolgiNaR", "K",
 "f_q10Settings_TENDEGREES_GolgiNaR", "K",
 "gion_GolgiNaR", "S/cm2",
 "s_forwardRate_r_GolgiNaR", "kHz",
 "s_reverseRate_r_GolgiNaR", "kHz",
 "s_timeCourse_t_GolgiNaR", "ms",
 "s_alpha_GolgiNaR", "kHz",
 "s_beta_GolgiNaR", "kHz",
 "s_tauUnscaled_GolgiNaR", "ms",
 "s_tau_GolgiNaR", "ms",
 "f_forwardRate_r_GolgiNaR", "kHz",
 "f_reverseRate_r_GolgiNaR", "kHz",
 "f_timeCourse_t_GolgiNaR", "ms",
 "f_alpha_GolgiNaR", "kHz",
 "f_beta_GolgiNaR", "kHz",
 "f_tauUnscaled_GolgiNaR", "ms",
 "f_tau_GolgiNaR", "ms",
 "g_GolgiNaR", "uS",
 0,0
};
 static double delta_t = 0.01;
 static double f_q0 = 0;
 static double s_q0 = 0;
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
"GolgiNaR",
 "gmax_GolgiNaR",
 "conductance_GolgiNaR",
 "s_instances_GolgiNaR",
 "s_forwardRate_rate_GolgiNaR",
 "s_forwardRate_midpoint_GolgiNaR",
 "s_forwardRate_scale_GolgiNaR",
 "s_forwardRate_shift_GolgiNaR",
 "s_reverseRate_rate_GolgiNaR",
 "s_reverseRate_midpoint_GolgiNaR",
 "s_reverseRate_scale_GolgiNaR",
 "s_reverseRate_shift_GolgiNaR",
 "s_timeCourse_TIME_SCALE_GolgiNaR",
 "s_q10Settings_q10Factor_GolgiNaR",
 "s_q10Settings_experimentalTemp_GolgiNaR",
 "s_q10Settings_TENDEGREES_GolgiNaR",
 "f_instances_GolgiNaR",
 "f_forwardRate_rate_GolgiNaR",
 "f_forwardRate_midpoint_GolgiNaR",
 "f_forwardRate_scale_GolgiNaR",
 "f_reverseRate_rate_GolgiNaR",
 "f_reverseRate_midpoint_GolgiNaR",
 "f_reverseRate_scale_GolgiNaR",
 "f_timeCourse_TIME_SCALE_GolgiNaR",
 "f_q10Settings_q10Factor_GolgiNaR",
 "f_q10Settings_experimentalTemp_GolgiNaR",
 "f_q10Settings_TENDEGREES_GolgiNaR",
 0,
 "gion_GolgiNaR",
 "s_forwardRate_r_GolgiNaR",
 "s_reverseRate_r_GolgiNaR",
 "s_timeCourse_ALPHA_GolgiNaR",
 "s_timeCourse_BETA_GolgiNaR",
 "s_timeCourse_t_GolgiNaR",
 "s_q10Settings_q10_GolgiNaR",
 "s_rateScale_GolgiNaR",
 "s_alpha_GolgiNaR",
 "s_beta_GolgiNaR",
 "s_fcond_GolgiNaR",
 "s_inf_GolgiNaR",
 "s_tauUnscaled_GolgiNaR",
 "s_tau_GolgiNaR",
 "f_forwardRate_r_GolgiNaR",
 "f_reverseRate_r_GolgiNaR",
 "f_timeCourse_ALPHA_GolgiNaR",
 "f_timeCourse_BETA_GolgiNaR",
 "f_timeCourse_t_GolgiNaR",
 "f_q10Settings_q10_GolgiNaR",
 "f_rateScale_GolgiNaR",
 "f_alpha_GolgiNaR",
 "f_beta_GolgiNaR",
 "f_fcond_GolgiNaR",
 "f_inf_GolgiNaR",
 "f_tauUnscaled_GolgiNaR",
 "f_tau_GolgiNaR",
 "conductanceScale_GolgiNaR",
 "fopen0_GolgiNaR",
 "fopen_GolgiNaR",
 "g_GolgiNaR",
 0,
 "s_q_GolgiNaR",
 "f_q_GolgiNaR",
 0,
 0};
 static Symbol* _na_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 68, _prop);
 	/*initialize range parameters*/
 	gmax = 0;
 	conductance = 1e-005;
 	s_instances = 1;
 	s_forwardRate_rate = 0.0336167;
 	s_forwardRate_midpoint = 4.48754;
 	s_forwardRate_scale = 6.81881;
 	s_forwardRate_shift = 8e-005;
 	s_reverseRate_rate = 0.00168544;
 	s_reverseRate_midpoint = -43.9749;
 	s_reverseRate_scale = -0.10818;
 	s_reverseRate_shift = 0.04752;
 	s_timeCourse_TIME_SCALE = 1;
 	s_q10Settings_q10Factor = 3;
 	s_q10Settings_experimentalTemp = 293.15;
 	s_q10Settings_TENDEGREES = 10;
 	f_instances = 1;
 	f_forwardRate_rate = 0.31836;
 	f_forwardRate_midpoint = -80;
 	f_forwardRate_scale = -62.5262;
 	f_reverseRate_rate = 0.01014;
 	f_reverseRate_midpoint = -83.3332;
 	f_reverseRate_scale = 16.0538;
 	f_timeCourse_TIME_SCALE = 1;
 	f_q10Settings_q10Factor = 3;
 	f_q10Settings_experimentalTemp = 293.15;
 	f_q10Settings_TENDEGREES = 10;
 	_prop->param = _p;
 	_prop->param_size = 68;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* ina */
 	_ppvar[1]._pval = &prop_ion->param[4]; /* _ion_dinadv */
 
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

 void _GolgiNaR_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("na", 1.0);
 	_na_sym = hoc_lookup("na_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_prop_size(_mechtype, 68, 3);
  hoc_register_dparam_semantics(_mechtype, 0, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 GolgiNaR D:/Work/Comp Models/GoC_Network_public/GolgiNaR.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Mod file for component: Component(id=GolgiNaR type=ionChannelHH)";

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
   Df_q = rate_f_q ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rates ( _threadargs_ ) ;
 Ds_q = Ds_q  / (1. - dt*( 0.0 )) ;
 Df_q = Df_q  / (1. - dt*( 0.0 )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   rates ( _threadargs_ ) ;
    s_q = s_q - dt*(- ( rate_s_q ) ) ;
    f_q = f_q - dt*(- ( rate_f_q ) ) ;
   }
  return 0;
}
 
static int  rates ( _threadargsproto_ ) {
   s_forwardRate_r = ( s_forwardRate_shift + s_forwardRate_rate * ( ( v - s_forwardRate_midpoint ) / s_forwardRate_scale ) / ( 1.0 - ( exp ( - ( v - s_forwardRate_midpoint ) / s_forwardRate_scale ) ) ) ) ;
   s_reverseRate_r = ( s_reverseRate_shift + s_reverseRate_rate * ( ( v - s_reverseRate_midpoint ) / s_reverseRate_scale ) / ( 1.0 - ( exp ( - ( v - s_reverseRate_midpoint ) / s_reverseRate_scale ) ) ) ) ;
   s_timeCourse_ALPHA = s_alpha * s_timeCourse_TIME_SCALE ;
   s_timeCourse_BETA = s_beta * s_timeCourse_TIME_SCALE ;
   if ( ( s_timeCourse_ALPHA + s_timeCourse_BETA ) < 1e-3 ) {
     s_timeCourse_t = 1000.0 * s_timeCourse_TIME_SCALE ;
     }
   else if ( 1.0 / ( s_timeCourse_ALPHA + s_timeCourse_BETA ) < ( 0.01 ) ) {
     s_timeCourse_t = 0.01 * s_timeCourse_TIME_SCALE ;
     }
   else {
     s_timeCourse_t = ( 1.0 / ( s_timeCourse_ALPHA + s_timeCourse_BETA ) ) * s_timeCourse_TIME_SCALE ;
     }
   s_q10Settings_q10 = pow( s_q10Settings_q10Factor , ( ( temperature - s_q10Settings_experimentalTemp ) / s_q10Settings_TENDEGREES ) ) ;
   s_rateScale = s_q10Settings_q10 ;
   s_alpha = s_forwardRate_r ;
   s_beta = s_reverseRate_r ;
   s_fcond = pow( s_q , s_instances ) ;
   s_inf = s_alpha / ( s_alpha + s_beta ) ;
   s_tauUnscaled = s_timeCourse_t ;
   s_tau = s_tauUnscaled / s_rateScale ;
   f_forwardRate_r = f_forwardRate_rate * exp ( ( v - f_forwardRate_midpoint ) / f_forwardRate_scale ) ;
   f_reverseRate_r = f_reverseRate_rate * exp ( ( v - f_reverseRate_midpoint ) / f_reverseRate_scale ) ;
   f_timeCourse_ALPHA = f_alpha * f_timeCourse_TIME_SCALE ;
   f_timeCourse_BETA = f_beta * f_timeCourse_TIME_SCALE ;
   if ( ( f_timeCourse_ALPHA + f_timeCourse_BETA ) < 1e-3 ) {
     f_timeCourse_t = 1000.0 * f_timeCourse_TIME_SCALE ;
     }
   else if ( 1.0 / ( f_timeCourse_ALPHA + f_timeCourse_BETA ) < ( 0.01 ) ) {
     f_timeCourse_t = 0.01 * f_timeCourse_TIME_SCALE ;
     }
   else {
     f_timeCourse_t = ( 1.0 / ( f_timeCourse_ALPHA + f_timeCourse_BETA ) ) * f_timeCourse_TIME_SCALE ;
     }
   f_q10Settings_q10 = pow( f_q10Settings_q10Factor , ( ( temperature - f_q10Settings_experimentalTemp ) / f_q10Settings_TENDEGREES ) ) ;
   f_rateScale = f_q10Settings_q10 ;
   f_alpha = f_forwardRate_r ;
   f_beta = f_reverseRate_r ;
   f_fcond = pow( f_q , f_instances ) ;
   f_inf = f_alpha / ( f_alpha + f_beta ) ;
   f_tauUnscaled = f_timeCourse_t ;
   f_tau = f_tauUnscaled / f_rateScale ;
   rate_s_q = ( s_inf - s_q ) / s_tau ;
   rate_f_q = ( f_inf - f_q ) / f_tau ;
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
   nrn_update_ion_pointer(_na_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_na_sym, _ppvar, 1, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  f_q = f_q0;
  s_q = s_q0;
 {
   ena = 87.39 ;
   temperature = celsius + 273.15 ;
   rates ( _threadargs_ ) ;
   rates ( _threadargs_ ) ;
   s_q = s_inf ;
   f_q = f_inf ;
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
   fopen0 = s_fcond * f_fcond ;
   fopen = conductanceScale * fopen0 ;
   g = conductance * fopen ;
   gion = gmax * fopen ;
   ina = gion * ( v - ena ) ;
   }
 _current += ina;

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
 	{ double _dina;
  _dina = ina;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dinadv += (_dina - ina)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ina += ina ;
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
 _slist1[0] = &(s_q) - _p;  _dlist1[0] = &(Ds_q) - _p;
 _slist1[1] = &(f_q) - _p;  _dlist1[1] = &(Df_q) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
