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
 
#define nrn_init _nrn_init__GolgiSK2
#define _nrn_initial _nrn_initial__GolgiSK2
#define nrn_cur _nrn_cur__GolgiSK2
#define _nrn_current _nrn_current__GolgiSK2
#define nrn_jacob _nrn_jacob__GolgiSK2
#define nrn_state _nrn_state__GolgiSK2
#define _net_receive _net_receive__GolgiSK2 
#define activation activation__GolgiSK2 
#define rates rates__GolgiSK2 
 
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
#define n_instances _p[2]
#define n_q10Settings_q10Factor _p[3]
#define n_q10Settings_experimentalTemp _p[4]
#define n_q10Settings_TENDEGREES _p[5]
#define n_c1_relativeConductance _p[6]
#define n_c2_relativeConductance _p[7]
#define n_c3_relativeConductance _p[8]
#define n_c4_relativeConductance _p[9]
#define n_o1_relativeConductance _p[10]
#define n_o2_relativeConductance _p[11]
#define n_alpha_c1_c2_SEC _p[12]
#define n_alpha_c1_c2_rate_scale _p[13]
#define n_alpha_c1_c2_rate_diff _p[14]
#define n_alpha_c1_c2_rate_CONC_SCALE _p[15]
#define n_beta_c1_c2_SEC _p[16]
#define n_beta_c1_c2_rate_scale _p[17]
#define n_alpha_c2_c3_SEC _p[18]
#define n_alpha_c2_c3_rate_scale _p[19]
#define n_alpha_c2_c3_rate_diff _p[20]
#define n_alpha_c2_c3_rate_CONC_SCALE _p[21]
#define n_beta_c2_c3_SEC _p[22]
#define n_beta_c2_c3_rate_scale _p[23]
#define n_alpha_c3_c4_SEC _p[24]
#define n_alpha_c3_c4_rate_scale _p[25]
#define n_alpha_c3_c4_rate_diff _p[26]
#define n_alpha_c3_c4_rate_CONC_SCALE _p[27]
#define n_beta_c3_c4_SEC _p[28]
#define n_beta_c3_c4_rate_scale _p[29]
#define n_alpha_c3_o1_SEC _p[30]
#define n_alpha_c3_o1_rate_scale _p[31]
#define n_beta_c3_o1_SEC _p[32]
#define n_beta_c3_o1_rate_scale _p[33]
#define n_alpha_c4_o2_SEC _p[34]
#define n_alpha_c4_o2_rate_scale _p[35]
#define n_beta_c4_o2_SEC _p[36]
#define n_beta_c4_o2_rate_scale _p[37]
#define gion _p[38]
#define n_q10Settings_q10 _p[39]
#define n_c1_q _p[40]
#define n_c2_q _p[41]
#define n_c3_q _p[42]
#define n_c4_q _p[43]
#define n_o1_q _p[44]
#define n_o2_q _p[45]
#define n_alpha_c1_c2_rate_r _p[46]
#define n_alpha_c1_c2_rf0 _p[47]
#define n_alpha_c1_c2_rf _p[48]
#define n_alpha_c1_c2_rr _p[49]
#define n_beta_c1_c2_rate_r _p[50]
#define n_beta_c1_c2_rr0 _p[51]
#define n_beta_c1_c2_rr _p[52]
#define n_beta_c1_c2_rf _p[53]
#define n_alpha_c2_c3_rate_r _p[54]
#define n_alpha_c2_c3_rf0 _p[55]
#define n_alpha_c2_c3_rf _p[56]
#define n_alpha_c2_c3_rr _p[57]
#define n_beta_c2_c3_rate_r _p[58]
#define n_beta_c2_c3_rr0 _p[59]
#define n_beta_c2_c3_rr _p[60]
#define n_beta_c2_c3_rf _p[61]
#define n_alpha_c3_c4_rate_r _p[62]
#define n_alpha_c3_c4_rf0 _p[63]
#define n_alpha_c3_c4_rf _p[64]
#define n_alpha_c3_c4_rr _p[65]
#define n_beta_c3_c4_rate_r _p[66]
#define n_beta_c3_c4_rr0 _p[67]
#define n_beta_c3_c4_rr _p[68]
#define n_beta_c3_c4_rf _p[69]
#define n_alpha_c3_o1_rate_r _p[70]
#define n_alpha_c3_o1_rf0 _p[71]
#define n_alpha_c3_o1_rf _p[72]
#define n_alpha_c3_o1_rr _p[73]
#define n_beta_c3_o1_rate_r _p[74]
#define n_beta_c3_o1_rr0 _p[75]
#define n_beta_c3_o1_rr _p[76]
#define n_beta_c3_o1_rf _p[77]
#define n_alpha_c4_o2_rate_r _p[78]
#define n_alpha_c4_o2_rf0 _p[79]
#define n_alpha_c4_o2_rf _p[80]
#define n_alpha_c4_o2_rr _p[81]
#define n_beta_c4_o2_rate_r _p[82]
#define n_beta_c4_o2_rr0 _p[83]
#define n_beta_c4_o2_rr _p[84]
#define n_beta_c4_o2_rf _p[85]
#define n_rateScale _p[86]
#define n_q _p[87]
#define n_fcond _p[88]
#define fopen _p[89]
#define g _p[90]
#define n_c1_occupancy _p[91]
#define n_c2_occupancy _p[92]
#define n_c3_occupancy _p[93]
#define n_c4_occupancy _p[94]
#define n_o1_occupancy _p[95]
#define n_o2_occupancy _p[96]
#define temperature _p[97]
#define ek _p[98]
#define ik _p[99]
#define cai _p[100]
#define cao _p[101]
#define Dn_c1_occupancy _p[102]
#define Dn_c2_occupancy _p[103]
#define Dn_c3_occupancy _p[104]
#define Dn_c4_occupancy _p[105]
#define Dn_o1_occupancy _p[106]
#define Dn_o2_occupancy _p[107]
#define v _p[108]
#define _g _p[109]
#define _ion_cai	*_ppvar[0]._pval
#define _ion_cao	*_ppvar[1]._pval
#define _ion_ik	*_ppvar[2]._pval
#define _ion_dikdv	*_ppvar[3]._pval
 
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
 "setdata_GolgiSK2", _hoc_setdata,
 "rates_GolgiSK2", _hoc_rates,
 0, 0
};
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gmax_GolgiSK2", "S/cm2",
 "conductance_GolgiSK2", "uS",
 "n_q10Settings_experimentalTemp_GolgiSK2", "K",
 "n_q10Settings_TENDEGREES_GolgiSK2", "K",
 "n_alpha_c1_c2_SEC_GolgiSK2", "ms",
 "n_alpha_c1_c2_rate_scale_GolgiSK2", "kHz",
 "n_alpha_c1_c2_rate_CONC_SCALE_GolgiSK2", "mM",
 "n_beta_c1_c2_SEC_GolgiSK2", "ms",
 "n_beta_c1_c2_rate_scale_GolgiSK2", "kHz",
 "n_alpha_c2_c3_SEC_GolgiSK2", "ms",
 "n_alpha_c2_c3_rate_scale_GolgiSK2", "kHz",
 "n_alpha_c2_c3_rate_CONC_SCALE_GolgiSK2", "mM",
 "n_beta_c2_c3_SEC_GolgiSK2", "ms",
 "n_beta_c2_c3_rate_scale_GolgiSK2", "kHz",
 "n_alpha_c3_c4_SEC_GolgiSK2", "ms",
 "n_alpha_c3_c4_rate_scale_GolgiSK2", "kHz",
 "n_alpha_c3_c4_rate_CONC_SCALE_GolgiSK2", "mM",
 "n_beta_c3_c4_SEC_GolgiSK2", "ms",
 "n_beta_c3_c4_rate_scale_GolgiSK2", "kHz",
 "n_alpha_c3_o1_SEC_GolgiSK2", "ms",
 "n_alpha_c3_o1_rate_scale_GolgiSK2", "kHz",
 "n_beta_c3_o1_SEC_GolgiSK2", "ms",
 "n_beta_c3_o1_rate_scale_GolgiSK2", "kHz",
 "n_alpha_c4_o2_SEC_GolgiSK2", "ms",
 "n_alpha_c4_o2_rate_scale_GolgiSK2", "kHz",
 "n_beta_c4_o2_SEC_GolgiSK2", "ms",
 "n_beta_c4_o2_rate_scale_GolgiSK2", "kHz",
 "gion_GolgiSK2", "S/cm2",
 "n_alpha_c1_c2_rate_r_GolgiSK2", "kHz",
 "n_alpha_c1_c2_rf0_GolgiSK2", "kHz",
 "n_alpha_c1_c2_rf_GolgiSK2", "kHz",
 "n_alpha_c1_c2_rr_GolgiSK2", "kHz",
 "n_beta_c1_c2_rate_r_GolgiSK2", "kHz",
 "n_beta_c1_c2_rr0_GolgiSK2", "kHz",
 "n_beta_c1_c2_rr_GolgiSK2", "kHz",
 "n_beta_c1_c2_rf_GolgiSK2", "kHz",
 "n_alpha_c2_c3_rate_r_GolgiSK2", "kHz",
 "n_alpha_c2_c3_rf0_GolgiSK2", "kHz",
 "n_alpha_c2_c3_rf_GolgiSK2", "kHz",
 "n_alpha_c2_c3_rr_GolgiSK2", "kHz",
 "n_beta_c2_c3_rate_r_GolgiSK2", "kHz",
 "n_beta_c2_c3_rr0_GolgiSK2", "kHz",
 "n_beta_c2_c3_rr_GolgiSK2", "kHz",
 "n_beta_c2_c3_rf_GolgiSK2", "kHz",
 "n_alpha_c3_c4_rate_r_GolgiSK2", "kHz",
 "n_alpha_c3_c4_rf0_GolgiSK2", "kHz",
 "n_alpha_c3_c4_rf_GolgiSK2", "kHz",
 "n_alpha_c3_c4_rr_GolgiSK2", "kHz",
 "n_beta_c3_c4_rate_r_GolgiSK2", "kHz",
 "n_beta_c3_c4_rr0_GolgiSK2", "kHz",
 "n_beta_c3_c4_rr_GolgiSK2", "kHz",
 "n_beta_c3_c4_rf_GolgiSK2", "kHz",
 "n_alpha_c3_o1_rate_r_GolgiSK2", "kHz",
 "n_alpha_c3_o1_rf0_GolgiSK2", "kHz",
 "n_alpha_c3_o1_rf_GolgiSK2", "kHz",
 "n_alpha_c3_o1_rr_GolgiSK2", "kHz",
 "n_beta_c3_o1_rate_r_GolgiSK2", "kHz",
 "n_beta_c3_o1_rr0_GolgiSK2", "kHz",
 "n_beta_c3_o1_rr_GolgiSK2", "kHz",
 "n_beta_c3_o1_rf_GolgiSK2", "kHz",
 "n_alpha_c4_o2_rate_r_GolgiSK2", "kHz",
 "n_alpha_c4_o2_rf0_GolgiSK2", "kHz",
 "n_alpha_c4_o2_rf_GolgiSK2", "kHz",
 "n_alpha_c4_o2_rr_GolgiSK2", "kHz",
 "n_beta_c4_o2_rate_r_GolgiSK2", "kHz",
 "n_beta_c4_o2_rr0_GolgiSK2", "kHz",
 "n_beta_c4_o2_rr_GolgiSK2", "kHz",
 "n_beta_c4_o2_rf_GolgiSK2", "kHz",
 "g_GolgiSK2", "uS",
 0,0
};
 static double delta_t = 0.01;
 static double n_o2_occupancy0 = 0;
 static double n_o1_occupancy0 = 0;
 static double n_c4_occupancy0 = 0;
 static double n_c3_occupancy0 = 0;
 static double n_c2_occupancy0 = 0;
 static double n_c1_occupancy0 = 0;
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
 
#define _cvode_ieq _ppvar[4]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.5.0",
"GolgiSK2",
 "gmax_GolgiSK2",
 "conductance_GolgiSK2",
 "n_instances_GolgiSK2",
 "n_q10Settings_q10Factor_GolgiSK2",
 "n_q10Settings_experimentalTemp_GolgiSK2",
 "n_q10Settings_TENDEGREES_GolgiSK2",
 "n_c1_relativeConductance_GolgiSK2",
 "n_c2_relativeConductance_GolgiSK2",
 "n_c3_relativeConductance_GolgiSK2",
 "n_c4_relativeConductance_GolgiSK2",
 "n_o1_relativeConductance_GolgiSK2",
 "n_o2_relativeConductance_GolgiSK2",
 "n_alpha_c1_c2_SEC_GolgiSK2",
 "n_alpha_c1_c2_rate_scale_GolgiSK2",
 "n_alpha_c1_c2_rate_diff_GolgiSK2",
 "n_alpha_c1_c2_rate_CONC_SCALE_GolgiSK2",
 "n_beta_c1_c2_SEC_GolgiSK2",
 "n_beta_c1_c2_rate_scale_GolgiSK2",
 "n_alpha_c2_c3_SEC_GolgiSK2",
 "n_alpha_c2_c3_rate_scale_GolgiSK2",
 "n_alpha_c2_c3_rate_diff_GolgiSK2",
 "n_alpha_c2_c3_rate_CONC_SCALE_GolgiSK2",
 "n_beta_c2_c3_SEC_GolgiSK2",
 "n_beta_c2_c3_rate_scale_GolgiSK2",
 "n_alpha_c3_c4_SEC_GolgiSK2",
 "n_alpha_c3_c4_rate_scale_GolgiSK2",
 "n_alpha_c3_c4_rate_diff_GolgiSK2",
 "n_alpha_c3_c4_rate_CONC_SCALE_GolgiSK2",
 "n_beta_c3_c4_SEC_GolgiSK2",
 "n_beta_c3_c4_rate_scale_GolgiSK2",
 "n_alpha_c3_o1_SEC_GolgiSK2",
 "n_alpha_c3_o1_rate_scale_GolgiSK2",
 "n_beta_c3_o1_SEC_GolgiSK2",
 "n_beta_c3_o1_rate_scale_GolgiSK2",
 "n_alpha_c4_o2_SEC_GolgiSK2",
 "n_alpha_c4_o2_rate_scale_GolgiSK2",
 "n_beta_c4_o2_SEC_GolgiSK2",
 "n_beta_c4_o2_rate_scale_GolgiSK2",
 0,
 "gion_GolgiSK2",
 "n_q10Settings_q10_GolgiSK2",
 "n_c1_q_GolgiSK2",
 "n_c2_q_GolgiSK2",
 "n_c3_q_GolgiSK2",
 "n_c4_q_GolgiSK2",
 "n_o1_q_GolgiSK2",
 "n_o2_q_GolgiSK2",
 "n_alpha_c1_c2_rate_r_GolgiSK2",
 "n_alpha_c1_c2_rf0_GolgiSK2",
 "n_alpha_c1_c2_rf_GolgiSK2",
 "n_alpha_c1_c2_rr_GolgiSK2",
 "n_beta_c1_c2_rate_r_GolgiSK2",
 "n_beta_c1_c2_rr0_GolgiSK2",
 "n_beta_c1_c2_rr_GolgiSK2",
 "n_beta_c1_c2_rf_GolgiSK2",
 "n_alpha_c2_c3_rate_r_GolgiSK2",
 "n_alpha_c2_c3_rf0_GolgiSK2",
 "n_alpha_c2_c3_rf_GolgiSK2",
 "n_alpha_c2_c3_rr_GolgiSK2",
 "n_beta_c2_c3_rate_r_GolgiSK2",
 "n_beta_c2_c3_rr0_GolgiSK2",
 "n_beta_c2_c3_rr_GolgiSK2",
 "n_beta_c2_c3_rf_GolgiSK2",
 "n_alpha_c3_c4_rate_r_GolgiSK2",
 "n_alpha_c3_c4_rf0_GolgiSK2",
 "n_alpha_c3_c4_rf_GolgiSK2",
 "n_alpha_c3_c4_rr_GolgiSK2",
 "n_beta_c3_c4_rate_r_GolgiSK2",
 "n_beta_c3_c4_rr0_GolgiSK2",
 "n_beta_c3_c4_rr_GolgiSK2",
 "n_beta_c3_c4_rf_GolgiSK2",
 "n_alpha_c3_o1_rate_r_GolgiSK2",
 "n_alpha_c3_o1_rf0_GolgiSK2",
 "n_alpha_c3_o1_rf_GolgiSK2",
 "n_alpha_c3_o1_rr_GolgiSK2",
 "n_beta_c3_o1_rate_r_GolgiSK2",
 "n_beta_c3_o1_rr0_GolgiSK2",
 "n_beta_c3_o1_rr_GolgiSK2",
 "n_beta_c3_o1_rf_GolgiSK2",
 "n_alpha_c4_o2_rate_r_GolgiSK2",
 "n_alpha_c4_o2_rf0_GolgiSK2",
 "n_alpha_c4_o2_rf_GolgiSK2",
 "n_alpha_c4_o2_rr_GolgiSK2",
 "n_beta_c4_o2_rate_r_GolgiSK2",
 "n_beta_c4_o2_rr0_GolgiSK2",
 "n_beta_c4_o2_rr_GolgiSK2",
 "n_beta_c4_o2_rf_GolgiSK2",
 "n_rateScale_GolgiSK2",
 "n_q_GolgiSK2",
 "n_fcond_GolgiSK2",
 "fopen_GolgiSK2",
 "g_GolgiSK2",
 0,
 "n_c1_occupancy_GolgiSK2",
 "n_c2_occupancy_GolgiSK2",
 "n_c3_occupancy_GolgiSK2",
 "n_c4_occupancy_GolgiSK2",
 "n_o1_occupancy_GolgiSK2",
 "n_o2_occupancy_GolgiSK2",
 0,
 0};
 static Symbol* _ca_sym;
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 110, _prop);
 	/*initialize range parameters*/
 	gmax = 0;
 	conductance = 1e-005;
 	n_instances = 1;
 	n_q10Settings_q10Factor = 3;
 	n_q10Settings_experimentalTemp = 296.15;
 	n_q10Settings_TENDEGREES = 10;
 	n_c1_relativeConductance = 0;
 	n_c2_relativeConductance = 0;
 	n_c3_relativeConductance = 0;
 	n_c4_relativeConductance = 0;
 	n_o1_relativeConductance = 1;
 	n_o2_relativeConductance = 1;
 	n_alpha_c1_c2_SEC = 1000;
 	n_alpha_c1_c2_rate_scale = 200;
 	n_alpha_c1_c2_rate_diff = 3;
 	n_alpha_c1_c2_rate_CONC_SCALE = 1;
 	n_beta_c1_c2_SEC = 1000;
 	n_beta_c1_c2_rate_scale = 0.08;
 	n_alpha_c2_c3_SEC = 1000;
 	n_alpha_c2_c3_rate_scale = 160;
 	n_alpha_c2_c3_rate_diff = 3;
 	n_alpha_c2_c3_rate_CONC_SCALE = 1;
 	n_beta_c2_c3_SEC = 1000;
 	n_beta_c2_c3_rate_scale = 0.08;
 	n_alpha_c3_c4_SEC = 1000;
 	n_alpha_c3_c4_rate_scale = 80;
 	n_alpha_c3_c4_rate_diff = 3;
 	n_alpha_c3_c4_rate_CONC_SCALE = 1;
 	n_beta_c3_c4_SEC = 1000;
 	n_beta_c3_c4_rate_scale = 0.2;
 	n_alpha_c3_o1_SEC = 1000;
 	n_alpha_c3_o1_rate_scale = 0.16;
 	n_beta_c3_o1_SEC = 1000;
 	n_beta_c3_o1_rate_scale = 1;
 	n_alpha_c4_o2_SEC = 1000;
 	n_alpha_c4_o2_rate_scale = 1.2;
 	n_beta_c4_o2_SEC = 1000;
 	n_beta_c4_o2_rate_scale = 0.1;
 	_prop->param = _p;
 	_prop->param_size = 110;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 5, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_ca_sym);
 nrn_promote(prop_ion, 1, 0);
 	_ppvar[0]._pval = &prop_ion->param[1]; /* cai */
 	_ppvar[1]._pval = &prop_ion->param[2]; /* cao */
 prop_ion = need_memb(_k_sym);
 	_ppvar[2]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[3]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _thread_cleanup(Datum*);
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _GolgiSK2_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("ca", 2.0);
 	ion_reg("k", 1.0);
 	_ca_sym = hoc_lookup("ca_ion");
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 3);
  _extcall_thread = (Datum*)ecalloc(2, sizeof(Datum));
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 0, _thread_cleanup);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_prop_size(_mechtype, 110, 5);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 GolgiSK2 D:/Work/Comp Models/GoC_Network_public/GolgiSK2.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Mod file for component: Component(id=GolgiSK2 type=ionChannelKS)";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates(_threadargsproto_);
 
#define _MATELM1(_row,_col) *(_nrn_thread_getelm(_so, _row + 1, _col + 1))
 
#define _RHS1(_arg) _rhs[_arg+1]
  static int _cvspth1 = 1;
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 extern double *_nrn_thread_getelm();
 
#define _MATELM1(_row,_col) *(_nrn_thread_getelm(_so, _row + 1, _col + 1))
 
#define _RHS1(_arg) _rhs[_arg+1]
  
#define _linmat1  1
 static int _spth1 = 0;
 static int _slist1[6], _dlist1[6]; static double *_temp1;
 static int activation();
 
static int activation (void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt)
 {int _reset=0;
 {
   double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=1;_i<6;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 rates ( _threadargs_ ) ;
   /* ~ n_c1_occupancy <-> n_c2_occupancy ( n_alpha_c1_c2_rate_r , n_beta_c1_c2_rate_r )*/
 f_flux =  n_alpha_c1_c2_rate_r * n_c1_occupancy ;
 b_flux =  n_beta_c1_c2_rate_r * n_c2_occupancy ;
 _RHS1( 5) -= (f_flux - b_flux);
 
 _term =  n_alpha_c1_c2_rate_r ;
 _MATELM1( 5 ,5)  += _term;
 _term =  n_beta_c1_c2_rate_r ;
 _MATELM1( 5 ,0)  -= _term;
 /*REACTION*/
  /* ~ n_c2_occupancy <-> n_c3_occupancy ( n_alpha_c2_c3_rate_r , n_beta_c2_c3_rate_r )*/
 f_flux =  n_alpha_c2_c3_rate_r * n_c2_occupancy ;
 b_flux =  n_beta_c2_c3_rate_r * n_c3_occupancy ;
 _RHS1( 4) += (f_flux - b_flux);
 
 _term =  n_alpha_c2_c3_rate_r ;
 _MATELM1( 4 ,0)  -= _term;
 _term =  n_beta_c2_c3_rate_r ;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ n_c3_occupancy <-> n_c4_occupancy ( n_alpha_c3_c4_rate_r , n_beta_c3_c4_rate_r )*/
 f_flux =  n_alpha_c3_c4_rate_r * n_c3_occupancy ;
 b_flux =  n_beta_c3_c4_rate_r * n_c4_occupancy ;
 _RHS1( 4) -= (f_flux - b_flux);
 _RHS1( 3) += (f_flux - b_flux);
 
 _term =  n_alpha_c3_c4_rate_r ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  n_beta_c3_c4_rate_r ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ n_c3_occupancy <-> n_o1_occupancy ( n_alpha_c3_o1_rate_r , n_beta_c3_o1_rate_r )*/
 f_flux =  n_alpha_c3_o1_rate_r * n_c3_occupancy ;
 b_flux =  n_beta_c3_o1_rate_r * n_o1_occupancy ;
 _RHS1( 4) -= (f_flux - b_flux);
 _RHS1( 2) += (f_flux - b_flux);
 
 _term =  n_alpha_c3_o1_rate_r ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 2 ,4)  -= _term;
 _term =  n_beta_c3_o1_rate_r ;
 _MATELM1( 4 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ n_c4_occupancy <-> n_o2_occupancy ( n_alpha_c4_o2_rate_r , n_beta_c4_o2_rate_r )*/
 f_flux =  n_alpha_c4_o2_rate_r * n_c4_occupancy ;
 b_flux =  n_beta_c4_o2_rate_r * n_o2_occupancy ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 1) += (f_flux - b_flux);
 
 _term =  n_alpha_c4_o2_rate_r ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 1 ,3)  -= _term;
 _term =  n_beta_c4_o2_rate_r ;
 _MATELM1( 3 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
   /* n_c1_occupancy + n_o1_occupancy + n_o2_occupancy + n_c3_occupancy + n_c4_occupancy + n_c2_occupancy = 1.0 */
 _RHS1(0) =  1.0;
 _MATELM1(0, 0) = 1;
 _RHS1(0) -= n_c2_occupancy ;
 _MATELM1(0, 3) = 1;
 _RHS1(0) -= n_c4_occupancy ;
 _MATELM1(0, 4) = 1;
 _RHS1(0) -= n_c3_occupancy ;
 _MATELM1(0, 1) = 1;
 _RHS1(0) -= n_o2_occupancy ;
 _MATELM1(0, 2) = 1;
 _RHS1(0) -= n_o1_occupancy ;
 _MATELM1(0, 5) = 1;
 _RHS1(0) -= n_c1_occupancy ;
 /*CONSERVATION*/
   } return _reset;
 }
 
static int  rates ( _threadargsproto_ ) {
   double _lcaConc ;
 _lcaConc = cai ;
   n_q10Settings_q10 = pow( n_q10Settings_q10Factor , ( ( temperature - n_q10Settings_experimentalTemp ) / n_q10Settings_TENDEGREES ) ) ;
   n_c1_q = n_c1_relativeConductance * n_c1_occupancy ;
   n_c2_q = n_c2_relativeConductance * n_c2_occupancy ;
   n_c3_q = n_c3_relativeConductance * n_c3_occupancy ;
   n_c4_q = n_c4_relativeConductance * n_c4_occupancy ;
   n_o1_q = n_o1_relativeConductance * n_o1_occupancy ;
   n_o2_q = n_o2_relativeConductance * n_o2_occupancy ;
   n_alpha_c1_c2_rate_r = n_rateScale * ( n_alpha_c1_c2_rate_scale / n_alpha_c1_c2_rate_CONC_SCALE * ( _lcaConc / n_alpha_c1_c2_rate_diff ) ) ;
   n_alpha_c1_c2_rf0 = n_alpha_c1_c2_rate_r ;
   n_alpha_c1_c2_rf = n_alpha_c1_c2_rf0 ;
   n_alpha_c1_c2_rr = 0.0 / n_alpha_c1_c2_SEC ;
   n_beta_c1_c2_rate_r = n_rateScale * ( n_beta_c1_c2_rate_scale ) ;
   n_beta_c1_c2_rr0 = n_beta_c1_c2_rate_r ;
   n_beta_c1_c2_rr = n_beta_c1_c2_rr0 ;
   n_beta_c1_c2_rf = 0.0 / n_beta_c1_c2_SEC ;
   n_alpha_c2_c3_rate_r = n_rateScale * ( n_alpha_c2_c3_rate_scale / n_alpha_c2_c3_rate_CONC_SCALE * ( _lcaConc / n_alpha_c2_c3_rate_diff ) ) ;
   n_alpha_c2_c3_rf0 = n_alpha_c2_c3_rate_r ;
   n_alpha_c2_c3_rf = n_alpha_c2_c3_rf0 ;
   n_alpha_c2_c3_rr = 0.0 / n_alpha_c2_c3_SEC ;
   n_beta_c2_c3_rate_r = n_rateScale * ( n_beta_c2_c3_rate_scale ) ;
   n_beta_c2_c3_rr0 = n_beta_c2_c3_rate_r ;
   n_beta_c2_c3_rr = n_beta_c2_c3_rr0 ;
   n_beta_c2_c3_rf = 0.0 / n_beta_c2_c3_SEC ;
   n_alpha_c3_c4_rate_r = n_rateScale * ( n_alpha_c3_c4_rate_scale / n_alpha_c3_c4_rate_CONC_SCALE * ( _lcaConc / n_alpha_c3_c4_rate_diff ) ) ;
   n_alpha_c3_c4_rf0 = n_alpha_c3_c4_rate_r ;
   n_alpha_c3_c4_rf = n_alpha_c3_c4_rf0 ;
   n_alpha_c3_c4_rr = 0.0 / n_alpha_c3_c4_SEC ;
   n_beta_c3_c4_rate_r = n_rateScale * ( n_beta_c3_c4_rate_scale ) ;
   n_beta_c3_c4_rr0 = n_beta_c3_c4_rate_r ;
   n_beta_c3_c4_rr = n_beta_c3_c4_rr0 ;
   n_beta_c3_c4_rf = 0.0 / n_beta_c3_c4_SEC ;
   n_alpha_c3_o1_rate_r = n_rateScale * ( n_alpha_c3_o1_rate_scale ) ;
   n_alpha_c3_o1_rf0 = n_alpha_c3_o1_rate_r ;
   n_alpha_c3_o1_rf = n_alpha_c3_o1_rf0 ;
   n_alpha_c3_o1_rr = 0.0 / n_alpha_c3_o1_SEC ;
   n_beta_c3_o1_rate_r = n_rateScale * ( n_beta_c3_o1_rate_scale ) ;
   n_beta_c3_o1_rr0 = n_beta_c3_o1_rate_r ;
   n_beta_c3_o1_rr = n_beta_c3_o1_rr0 ;
   n_beta_c3_o1_rf = 0.0 / n_beta_c3_o1_SEC ;
   n_alpha_c4_o2_rate_r = n_rateScale * ( n_alpha_c4_o2_rate_scale ) ;
   n_alpha_c4_o2_rf0 = n_alpha_c4_o2_rate_r ;
   n_alpha_c4_o2_rf = n_alpha_c4_o2_rf0 ;
   n_alpha_c4_o2_rr = 0.0 / n_alpha_c4_o2_SEC ;
   n_beta_c4_o2_rate_r = n_rateScale * ( n_beta_c4_o2_rate_scale ) ;
   n_beta_c4_o2_rr0 = n_beta_c4_o2_rate_r ;
   n_beta_c4_o2_rr = n_beta_c4_o2_rr0 ;
   n_beta_c4_o2_rf = 0.0 / n_beta_c4_o2_SEC ;
   n_rateScale = n_q10Settings_q10 ;
   n_q = n_c1_q + n_c2_q + n_c3_q + n_c4_q + n_o1_q + n_o2_q ;
   n_fcond = pow( n_q , n_instances ) ;
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
 
/*CVODE ode begin*/
 static int _ode_spec1(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<6;_i++) _p[_dlist1[_i]] = 0.0;}
 rates ( _threadargs_ ) ;
 /* ~ n_c1_occupancy <-> n_c2_occupancy ( n_alpha_c1_c2_rate_r , n_beta_c1_c2_rate_r )*/
 f_flux =  n_alpha_c1_c2_rate_r * n_c1_occupancy ;
 b_flux =  n_beta_c1_c2_rate_r * n_c2_occupancy ;
 Dn_c1_occupancy -= (f_flux - b_flux);
 Dn_c2_occupancy += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ n_c2_occupancy <-> n_c3_occupancy ( n_alpha_c2_c3_rate_r , n_beta_c2_c3_rate_r )*/
 f_flux =  n_alpha_c2_c3_rate_r * n_c2_occupancy ;
 b_flux =  n_beta_c2_c3_rate_r * n_c3_occupancy ;
 Dn_c2_occupancy -= (f_flux - b_flux);
 Dn_c3_occupancy += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ n_c3_occupancy <-> n_c4_occupancy ( n_alpha_c3_c4_rate_r , n_beta_c3_c4_rate_r )*/
 f_flux =  n_alpha_c3_c4_rate_r * n_c3_occupancy ;
 b_flux =  n_beta_c3_c4_rate_r * n_c4_occupancy ;
 Dn_c3_occupancy -= (f_flux - b_flux);
 Dn_c4_occupancy += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ n_c3_occupancy <-> n_o1_occupancy ( n_alpha_c3_o1_rate_r , n_beta_c3_o1_rate_r )*/
 f_flux =  n_alpha_c3_o1_rate_r * n_c3_occupancy ;
 b_flux =  n_beta_c3_o1_rate_r * n_o1_occupancy ;
 Dn_c3_occupancy -= (f_flux - b_flux);
 Dn_o1_occupancy += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ n_c4_occupancy <-> n_o2_occupancy ( n_alpha_c4_o2_rate_r , n_beta_c4_o2_rate_r )*/
 f_flux =  n_alpha_c4_o2_rate_r * n_c4_occupancy ;
 b_flux =  n_beta_c4_o2_rate_r * n_o2_occupancy ;
 Dn_c4_occupancy -= (f_flux - b_flux);
 Dn_o2_occupancy += (f_flux - b_flux);
 
 /*REACTION*/
   /* n_c1_occupancy + n_o1_occupancy + n_o2_occupancy + n_c3_occupancy + n_c4_occupancy + n_c2_occupancy = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1(void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<6;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 rates ( _threadargs_ ) ;
 /* ~ n_c1_occupancy <-> n_c2_occupancy ( n_alpha_c1_c2_rate_r , n_beta_c1_c2_rate_r )*/
 _term =  n_alpha_c1_c2_rate_r ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 0 ,5)  -= _term;
 _term =  n_beta_c1_c2_rate_r ;
 _MATELM1( 5 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ n_c2_occupancy <-> n_c3_occupancy ( n_alpha_c2_c3_rate_r , n_beta_c2_c3_rate_r )*/
 _term =  n_alpha_c2_c3_rate_r ;
 _MATELM1( 0 ,0)  += _term;
 _MATELM1( 4 ,0)  -= _term;
 _term =  n_beta_c2_c3_rate_r ;
 _MATELM1( 0 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ n_c3_occupancy <-> n_c4_occupancy ( n_alpha_c3_c4_rate_r , n_beta_c3_c4_rate_r )*/
 _term =  n_alpha_c3_c4_rate_r ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  n_beta_c3_c4_rate_r ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ n_c3_occupancy <-> n_o1_occupancy ( n_alpha_c3_o1_rate_r , n_beta_c3_o1_rate_r )*/
 _term =  n_alpha_c3_o1_rate_r ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 2 ,4)  -= _term;
 _term =  n_beta_c3_o1_rate_r ;
 _MATELM1( 4 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ n_c4_occupancy <-> n_o2_occupancy ( n_alpha_c4_o2_rate_r , n_beta_c4_o2_rate_r )*/
 _term =  n_alpha_c4_o2_rate_r ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 1 ,3)  -= _term;
 _term =  n_beta_c4_o2_rate_r ;
 _MATELM1( 3 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
   /* n_c1_occupancy + n_o1_occupancy + n_o2_occupancy + n_c3_occupancy + n_c4_occupancy + n_c2_occupancy = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 6;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  cai = _ion_cai;
  cao = _ion_cao;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 6; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _cvode_sparse_thread(&_thread[_cvspth1]._pvoid, 6, _dlist1, _p, _ode_matsol1, _ppvar, _thread, _nt);
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
  cai = _ion_cai;
  cao = _ion_cao;
 _ode_matsol_instance1(_threadargs_);
 }}
 
static void _thread_cleanup(Datum* _thread) {
   _nrn_destroy_sparseobj_thread(_thread[_spth1]._pvoid);
   _nrn_destroy_sparseobj_thread(_thread[_cvspth1]._pvoid);
 }
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 1);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 1, 2);
   nrn_update_ion_pointer(_k_sym, _ppvar, 2, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 3, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  n_o2_occupancy = n_o2_occupancy0;
  n_o1_occupancy = n_o1_occupancy0;
  n_c4_occupancy = n_c4_occupancy0;
  n_c3_occupancy = n_c3_occupancy0;
  n_c2_occupancy = n_c2_occupancy0;
  n_c1_occupancy = n_c1_occupancy0;
 {
   ek = - 84.69 ;
   temperature = celsius + 273.15 ;
   rates ( _threadargs_ ) ;
   rates ( _threadargs_ ) ;
    _ss_sparse_thread(&_thread[_spth1]._pvoid, 6, _slist1, _dlist1, _p, &t, dt, activation, _linmat1, _ppvar, _thread, _nt);
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 6; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
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
  cai = _ion_cai;
  cao = _ion_cao;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   fopen = n_fcond ;
   g = fopen * conductance ;
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
  cai = _ion_cai;
  cao = _ion_cao;
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
double _dtsav = dt;
if (secondorder) { dt *= 0.5; }
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
  cai = _ion_cai;
  cao = _ion_cao;
 {  sparse_thread(&_thread[_spth1]._pvoid, 6, _slist1, _dlist1, _p, &t, dt, activation, _linmat1, _ppvar, _thread, _nt);
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 6; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 } }}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(n_c2_occupancy) - _p;  _dlist1[0] = &(Dn_c2_occupancy) - _p;
 _slist1[1] = &(n_o2_occupancy) - _p;  _dlist1[1] = &(Dn_o2_occupancy) - _p;
 _slist1[2] = &(n_o1_occupancy) - _p;  _dlist1[2] = &(Dn_o1_occupancy) - _p;
 _slist1[3] = &(n_c4_occupancy) - _p;  _dlist1[3] = &(Dn_c4_occupancy) - _p;
 _slist1[4] = &(n_c3_occupancy) - _p;  _dlist1[4] = &(Dn_c3_occupancy) - _p;
 _slist1[5] = &(n_c1_occupancy) - _p;  _dlist1[5] = &(Dn_c1_occupancy) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
