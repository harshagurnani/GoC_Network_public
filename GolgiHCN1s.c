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
 
#define nrn_init _nrn_init__GolgiHCN1s
#define _nrn_initial _nrn_initial__GolgiHCN1s
#define nrn_cur _nrn_cur__GolgiHCN1s
#define _nrn_current _nrn_current__GolgiHCN1s
#define nrn_jacob _nrn_jacob__GolgiHCN1s
#define nrn_state _nrn_state__GolgiHCN1s
#define _net_receive _net_receive__GolgiHCN1s 
#define rates rates__GolgiHCN1s 
#define states states__GolgiHCN1s 
 
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
#define s_timeCourse_TIME_SCALE _p[3]
#define s_timeCourse_VOLT_SCALE _p[4]
#define s_steadyState_VOLT_SCALE _p[5]
#define s_q10Settings_q10Factor _p[6]
#define s_q10Settings_experimentalTemp _p[7]
#define s_q10Settings_TENDEGREES _p[8]
#define gion _p[9]
#define s_timeCourse_V _p[10]
#define s_timeCourse_t2 _p[11]
#define s_timeCourse_t _p[12]
#define s_steadyState_V _p[13]
#define s_steadyState_x _p[14]
#define s_q10Settings_q10 _p[15]
#define s_rateScale _p[16]
#define s_fcond _p[17]
#define s_inf _p[18]
#define s_tauUnscaled _p[19]
#define s_tau _p[20]
#define conductanceScale _p[21]
#define fopen0 _p[22]
#define fopen _p[23]
#define g _p[24]
#define s_q _p[25]
#define temperature _p[26]
#define eh _p[27]
#define ih _p[28]
#define rate_s_q _p[29]
#define Ds_q _p[30]
#define v _p[31]
#define _g _p[32]
#define _ion_ih	*_ppvar[0]._pval
#define _ion_dihdv	*_ppvar[1]._pval
 
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
 "setdata_GolgiHCN1s", _hoc_setdata,
 "rates_GolgiHCN1s", _hoc_rates,
 0, 0
};
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gmax_GolgiHCN1s", "S/cm2",
 "conductance_GolgiHCN1s", "uS",
 "s_timeCourse_TIME_SCALE_GolgiHCN1s", "ms",
 "s_timeCourse_VOLT_SCALE_GolgiHCN1s", "mV",
 "s_steadyState_VOLT_SCALE_GolgiHCN1s", "mV",
 "s_q10Settings_experimentalTemp_GolgiHCN1s", "K",
 "s_q10Settings_TENDEGREES_GolgiHCN1s", "K",
 "gion_GolgiHCN1s", "S/cm2",
 "s_timeCourse_t_GolgiHCN1s", "ms",
 "s_tauUnscaled_GolgiHCN1s", "ms",
 "s_tau_GolgiHCN1s", "ms",
 "g_GolgiHCN1s", "uS",
 0,0
};
 static double delta_t = 0.01;
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
"GolgiHCN1s",
 "gmax_GolgiHCN1s",
 "conductance_GolgiHCN1s",
 "s_instances_GolgiHCN1s",
 "s_timeCourse_TIME_SCALE_GolgiHCN1s",
 "s_timeCourse_VOLT_SCALE_GolgiHCN1s",
 "s_steadyState_VOLT_SCALE_GolgiHCN1s",
 "s_q10Settings_q10Factor_GolgiHCN1s",
 "s_q10Settings_experimentalTemp_GolgiHCN1s",
 "s_q10Settings_TENDEGREES_GolgiHCN1s",
 0,
 "gion_GolgiHCN1s",
 "s_timeCourse_V_GolgiHCN1s",
 "s_timeCourse_t2_GolgiHCN1s",
 "s_timeCourse_t_GolgiHCN1s",
 "s_steadyState_V_GolgiHCN1s",
 "s_steadyState_x_GolgiHCN1s",
 "s_q10Settings_q10_GolgiHCN1s",
 "s_rateScale_GolgiHCN1s",
 "s_fcond_GolgiHCN1s",
 "s_inf_GolgiHCN1s",
 "s_tauUnscaled_GolgiHCN1s",
 "s_tau_GolgiHCN1s",
 "conductanceScale_GolgiHCN1s",
 "fopen0_GolgiHCN1s",
 "fopen_GolgiHCN1s",
 "g_GolgiHCN1s",
 0,
 "s_q_GolgiHCN1s",
 0,
 0};
 static Symbol* _h_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 33, _prop);
 	/*initialize range parameters*/
 	gmax = 0;
 	conductance = 1e-005;
 	s_instances = 1;
 	s_timeCourse_TIME_SCALE = 1;
 	s_timeCourse_VOLT_SCALE = 1;
 	s_steadyState_VOLT_SCALE = 1;
 	s_q10Settings_q10Factor = 3;
 	s_q10Settings_experimentalTemp = 306.15;
 	s_q10Settings_TENDEGREES = 10;
 	_prop->param = _p;
 	_prop->param_size = 33;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_h_sym);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* ih */
 	_ppvar[1]._pval = &prop_ion->param[4]; /* _ion_dihdv */
 
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

 void _GolgiHCN1s_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("h", 1.0);
 	_h_sym = hoc_lookup("h_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_prop_size(_mechtype, 33, 3);
  hoc_register_dparam_semantics(_mechtype, 0, "h_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "h_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 GolgiHCN1s D:/Work/Comp Models/GoC_Network_public/GolgiHCN1s.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Mod file for component: Component(id=GolgiHCN1s type=ionChannelHH)";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates(_threadargsproto_);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[1], _dlist1[1];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   rates ( _threadargs_ ) ;
   Ds_q = rate_s_q ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rates ( _threadargs_ ) ;
 Ds_q = Ds_q  / (1. - dt*( 0.0 )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   rates ( _threadargs_ ) ;
    s_q = s_q - dt*(- ( rate_s_q ) ) ;
   }
  return 0;
}
 
static int  rates ( _threadargsproto_ ) {
   s_timeCourse_V = v / s_timeCourse_VOLT_SCALE ;
   s_timeCourse_t2 = ( exp ( ( 0.01451 * s_timeCourse_V ) + 4.056 ) * 2.302585092 ) ;
   if ( s_timeCourse_t2 > ( 200.0 ) ) {
     s_timeCourse_t = 200.0 * s_timeCourse_TIME_SCALE ;
     }
   else if ( s_timeCourse_t2 < ( 0.1 ) ) {
     s_timeCourse_t = 0.1 * s_timeCourse_TIME_SCALE ;
     }
   else {
     s_timeCourse_t = s_timeCourse_t2 * s_timeCourse_TIME_SCALE ;
     }
   s_steadyState_V = v / s_steadyState_VOLT_SCALE ;
   s_steadyState_x = ( 1.0 - ( 0.002096 * s_steadyState_V + 0.9759 ) ) * 1.0 / ( 1.0 + exp ( ( s_steadyState_V + 72.49 ) * 0.11305 ) ) ;
   s_q10Settings_q10 = pow( s_q10Settings_q10Factor , ( ( temperature - s_q10Settings_experimentalTemp ) / s_q10Settings_TENDEGREES ) ) ;
   s_rateScale = s_q10Settings_q10 ;
   s_fcond = pow( s_q , s_instances ) ;
   s_inf = s_steadyState_x ;
   s_tauUnscaled = s_timeCourse_t ;
   s_tau = s_tauUnscaled / s_rateScale ;
   rate_s_q = ( s_inf - s_q ) / s_tau ;
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
 
static int _ode_count(int _type){ return 1;}
 
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
	for (_i=0; _i < 1; ++_i) {
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
   nrn_update_ion_pointer(_h_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_h_sym, _ppvar, 1, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  s_q = s_q0;
 {
   eh = - 20.0 ;
   temperature = celsius + 273.15 ;
   rates ( _threadargs_ ) ;
   rates ( _threadargs_ ) ;
   s_q = s_inf ;
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
   fopen0 = s_fcond ;
   fopen = conductanceScale * fopen0 ;
   g = conductance * fopen ;
   gion = gmax * fopen ;
   ih = gion * ( v - eh ) ;
   }
 _current += ih;

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
 	{ double _dih;
  _dih = ih;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dihdv += (_dih - ih)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ih += ih ;
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
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
