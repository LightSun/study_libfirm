/**
 * @file
 * @brief Contains additional external requirements defs for external includes.
 * @note   DO NOT EDIT THIS FILE, your changes will be lost.
 *         Edit /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/ia32/ia32_spec.pl instead.
 *         created by: /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/scripts/generate_regalloc_if.pl /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/ia32/ia32_spec.pl /home/heaven7/heaven7/temp/build-cparser-Desktop_Qt_5_14_2_GCC_64bit-Debug/libfirm/gen/ir/be/ia32
 * @date   Mon Aug  8 09:46:25 2022
 */
#ifndef FIRM_BE_IA32_GEN_IA32_REGALLOC_IF_H
#define FIRM_BE_IA32_GEN_IA32_REGALLOC_IF_H

#include "bearch.h"

/** global register indices for ia32 registers */
enum reg_indices {
	REG_EFLAGS,
	REG_ST0,
	REG_ST1,
	REG_ST2,
	REG_ST3,
	REG_ST4,
	REG_ST5,
	REG_ST6,
	REG_ST7,
	REG_FP_NOREG,
	REG_FPCW,
	REG_EDX,
	REG_ECX,
	REG_EAX,
	REG_EBX,
	REG_ESI,
	REG_EDI,
	REG_EBP,
	REG_ESP,
	REG_GP_NOREG,
	REG_XMM0,
	REG_XMM1,
	REG_XMM2,
	REG_XMM3,
	REG_XMM4,
	REG_XMM5,
	REG_XMM6,
	REG_XMM7,
	REG_XMM_NOREG,

	N_IA32_REGISTERS
};

/** local register indices for ia32 registers */
enum {
	REG_FLAGS_EFLAGS,
};

enum {
	REG_FP_ST0,
	REG_FP_ST1,
	REG_FP_ST2,
	REG_FP_ST3,
	REG_FP_ST4,
	REG_FP_ST5,
	REG_FP_ST6,
	REG_FP_ST7,
	REG_FP_FP_NOREG,
};

enum {
	REG_FPCW_FPCW,
};

enum {
	REG_GP_EDX,
	REG_GP_ECX,
	REG_GP_EAX,
	REG_GP_EBX,
	REG_GP_ESI,
	REG_GP_EDI,
	REG_GP_EBP,
	REG_GP_ESP,
	REG_GP_GP_NOREG,
};

enum {
	REG_XMM_XMM0,
	REG_XMM_XMM1,
	REG_XMM_XMM2,
	REG_XMM_XMM3,
	REG_XMM_XMM4,
	REG_XMM_XMM5,
	REG_XMM_XMM6,
	REG_XMM_XMM7,
	REG_XMM_XMM_NOREG,
};


/** number of registers in ia32 register classes. */
enum {
	N_ia32_flags_REGS = 1,
	N_ia32_fp_REGS = 9,
	N_ia32_fpcw_REGS = 1,
	N_ia32_gp_REGS = 9,
	N_ia32_xmm_REGS = 9,

};

enum {
	CLASS_ia32_flags,
	CLASS_ia32_fp,
	CLASS_ia32_fpcw,
	CLASS_ia32_gp,
	CLASS_ia32_xmm,
	N_IA32_CLASSES = 5
};

extern const arch_register_req_t ia32_class_reg_req_flags;
extern const arch_register_req_t ia32_single_reg_req_flags_eflags;
extern const arch_register_req_t ia32_class_reg_req_fp;
extern const arch_register_req_t ia32_single_reg_req_fp_st0;
extern const arch_register_req_t ia32_single_reg_req_fp_st1;
extern const arch_register_req_t ia32_single_reg_req_fp_st2;
extern const arch_register_req_t ia32_single_reg_req_fp_st3;
extern const arch_register_req_t ia32_single_reg_req_fp_st4;
extern const arch_register_req_t ia32_single_reg_req_fp_st5;
extern const arch_register_req_t ia32_single_reg_req_fp_st6;
extern const arch_register_req_t ia32_single_reg_req_fp_st7;
extern const arch_register_req_t ia32_single_reg_req_fp_fp_NOREG;
extern const arch_register_req_t ia32_class_reg_req_fpcw;
extern const arch_register_req_t ia32_single_reg_req_fpcw_fpcw;
extern const arch_register_req_t ia32_class_reg_req_gp;
extern const arch_register_req_t ia32_single_reg_req_gp_edx;
extern const arch_register_req_t ia32_single_reg_req_gp_ecx;
extern const arch_register_req_t ia32_single_reg_req_gp_eax;
extern const arch_register_req_t ia32_single_reg_req_gp_ebx;
extern const arch_register_req_t ia32_single_reg_req_gp_esi;
extern const arch_register_req_t ia32_single_reg_req_gp_edi;
extern const arch_register_req_t ia32_single_reg_req_gp_ebp;
extern const arch_register_req_t ia32_single_reg_req_gp_esp;
extern const arch_register_req_t ia32_single_reg_req_gp_gp_NOREG;
extern const arch_register_req_t ia32_class_reg_req_xmm;
extern const arch_register_req_t ia32_single_reg_req_xmm_xmm0;
extern const arch_register_req_t ia32_single_reg_req_xmm_xmm1;
extern const arch_register_req_t ia32_single_reg_req_xmm_xmm2;
extern const arch_register_req_t ia32_single_reg_req_xmm_xmm3;
extern const arch_register_req_t ia32_single_reg_req_xmm_xmm4;
extern const arch_register_req_t ia32_single_reg_req_xmm_xmm5;
extern const arch_register_req_t ia32_single_reg_req_xmm_xmm6;
extern const arch_register_req_t ia32_single_reg_req_xmm_xmm7;
extern const arch_register_req_t ia32_single_reg_req_xmm_xmm_NOREG;


extern const arch_register_t ia32_registers[N_IA32_REGISTERS];

extern arch_register_class_t ia32_reg_classes[N_IA32_CLASSES];

void ia32_register_init(void);

#endif
