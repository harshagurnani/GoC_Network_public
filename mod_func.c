#include <stdio.h>
#include "hocdec.h"
#define IMPORT extern __declspec(dllimport)
IMPORT int nrnmpi_myid, nrn_nobanner_;

extern void _GJ_0_reg();
extern void _GolgiBK_reg();
extern void _GolgiCaHVA_reg();
extern void _GolgiCaLVA_reg();
extern void _GolgiHCN1f_reg();
extern void _GolgiHCN1s_reg();
extern void _GolgiHCN2f_reg();
extern void _GolgiHCN2s_reg();
extern void _GolgiKA_reg();
extern void _GolgiKM_reg();
extern void _GolgiKV_reg();
extern void _GolgiNa_reg();
extern void _GolgiNaP_reg();
extern void _GolgiNaR_reg();
extern void _GolgiSK2_reg();
extern void _Golgi_CALC_reg();
extern void _LeakConductance_reg();
extern void _MFGoC_Syn_reg();
extern void _MF_Burst_reg();
extern void _MF_Poisson_reg();

void modl_reg(){
	//nrn_mswindll_stdio(stdin, stdout, stderr);
    if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
	fprintf(stderr, "Additional mechanisms from files\n");

fprintf(stderr," GJ_0.mod");
fprintf(stderr," GolgiBK.mod");
fprintf(stderr," GolgiCaHVA.mod");
fprintf(stderr," GolgiCaLVA.mod");
fprintf(stderr," GolgiHCN1f.mod");
fprintf(stderr," GolgiHCN1s.mod");
fprintf(stderr," GolgiHCN2f.mod");
fprintf(stderr," GolgiHCN2s.mod");
fprintf(stderr," GolgiKA.mod");
fprintf(stderr," GolgiKM.mod");
fprintf(stderr," GolgiKV.mod");
fprintf(stderr," GolgiNa.mod");
fprintf(stderr," GolgiNaP.mod");
fprintf(stderr," GolgiNaR.mod");
fprintf(stderr," GolgiSK2.mod");
fprintf(stderr," Golgi_CALC.mod");
fprintf(stderr," LeakConductance.mod");
fprintf(stderr," MFGoC_Syn.mod");
fprintf(stderr," MF_Burst.mod");
fprintf(stderr," MF_Poisson.mod");
fprintf(stderr, "\n");
    }
_GJ_0_reg();
_GolgiBK_reg();
_GolgiCaHVA_reg();
_GolgiCaLVA_reg();
_GolgiHCN1f_reg();
_GolgiHCN1s_reg();
_GolgiHCN2f_reg();
_GolgiHCN2s_reg();
_GolgiKA_reg();
_GolgiKM_reg();
_GolgiKV_reg();
_GolgiNa_reg();
_GolgiNaP_reg();
_GolgiNaR_reg();
_GolgiSK2_reg();
_Golgi_CALC_reg();
_LeakConductance_reg();
_MFGoC_Syn_reg();
_MF_Burst_reg();
_MF_Poisson_reg();
}
